/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picture.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <gule-bat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:50:08 by gule-bat          #+#    #+#             */
/*   Updated: 2026/04/17 16:25:49 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asxpm.hpp"




void	Picture::get_file(std::string name)
{
	std::string *file;
	std::ifstream f;
	std::string res;
	int i;

	i = 0;
	file = NULL;
	if (name.find(".xpm") == std::string::npos)
		return (perror("file is not xpm"), exit(127));
	f.open(name.c_str());
	if (!f.is_open())
		return (perror("error file"), exit(0));
	while (std::getline(f, res))
	{
		if ((res.c_str()[0] == '/' && res[1] == '*') && (res.c_str()[res.size()-2] == '*' && res.c_str()[res.size()-1] == '/'))
			continue ;
		i++;
	}
	f.clear();
	f.seekg(0, std::ios::beg); // reset ifstream to 0
	file = new std::string[i];	//allocate file size
	if (!file)
		return (f.close(), delete [] file);
	i = 0;
	while (std::getline(f, res))
	{
		if ((res.c_str()[0] == '/' && res[1] == '*') && (res.c_str()[res.size()-2] == '*' && res.c_str()[res.size()-1] == '/'))
			continue ;
		file[i] = res;
		i++;
	}
	f.close();
	bf_text = file;
	size_xpm = i;
}

void	Picture::get_xpm_buffer(std::string name)
{
	get_file(name);
}

void	Picture::get_pic_buffer()
{
	int x = infos[2]+2;
	int i = 0;
	std::string *bf;

	bf = new std::string[xy_pic.y+1];
	if (!bf)
		return (perror("error alloc image buffer\n"));
	while (x < size_xpm && i < xy_pic.y)
	{
		std::string tmp = &bf_text[x][1];
		tmp[tmp.size()-1] = '\0';
		tmp[tmp.size()-2] = '\0';		// std::cout << tmp << std::endl;
		bf[i] = tmp;
		x++;
		i++;
	}
	bf_pic = bf;
	return ;
}

void Picture::get_info_image()
{
	int i = 1;
	std::string a;
	std::stringstream s;
	std::string *col;
	
	if (!bf_text || !infos)
		return (perror("text buffer error while parsing"));
	/////// image size, color infos etc...
	a = &bf_text[i][1];
	s << a;
	s >> infos[0] >> infos[1] >> infos[2] >> infos[3];	// std::cout << infos[0] << " " << infos[1] << " "<< infos[2] << " " << infos[3];
	col = new std::string[infos[2]+1];
	if (!col)
		return (perror("error alloc colors"));
	for (int x = 0; x <= infos[2]; x++)
	{
		std::string tmp = &bf_text[i+x][1];
		tmp[tmp.size()-1] = '\0';
		tmp[tmp.size()-2] = '\0';
		col[x] = tmp;
	}
	colors = col;// for (int x = 0; x <= infos[2]; x++)// std::cout << colors[x] << std::endl;
	xy_pic.x = infos[0];
	xy_pic.y = infos[1];
	get_pic_buffer();
}



std::string	Picture::print_pixel_ascii(int y, int x)
{
	std::string s;
	std::string find;
	int col;
	int r;
	int g;
	int b;
	std::string res;

	col = 0;
	s = bf_pic[y].substr(x, infos[3]);
	for (int i = 0; i <= infos[2]; i++)
	{
		if (colors[i].substr(0, infos[3]) == s)
		{
			std::stringstream sr;
			int n = 0;
			while (colors[i][n] != '#')
				n++;
			col = (int)strtol(&colors[i][n+1], NULL, 16); // peut etre suspect sur s[x]
			r = (col >> 16) & 0xFF;
			g = (col >> 8) & 0xFF;
			b = col & 0xFF;
			r = (r / 64) * 64;
			g = (g / 64) * 64;
			b = (b / 64) * 64;
			sr << "\033[48;2;" << r << ";" << g << ";" << b << "m" << "  \033[0m";
			res += sr.str();
			return res;
		}
	}
	return "";	
}

void	Picture::get_ascii_buffer()
{
	int i;
	int j;
	int it = infos[3];
	// int grade = 1;
	double scale;
	vec sd;
	vec fsize;
	std::string text;

	i = 0;
	fsize.x = tty_i.tty_s.x;
	fsize.y = tty_i.tty_s.y;
	// text.reserve(1 + bf_pic[0].size() * infos[1]);
	scale = std::min((double)fsize.x / xy_pic.x, (double)fsize.y * 0.5 / xy_pic.y); // scaling pcq y est petit sur le term
	fsize.x = xy_pic.x * scale;
	fsize.y = xy_pic.y * scale;
	fsize.x /= SCALE_FAC; // downscaling pcq trop grand sinon en general
	fsize.y /= SCALE_FAC;
	while (i < fsize.y) // y += 1; x += it
	{
		j = 0;
		sd.y = (i * xy_pic.y / fsize.y); // recalculer la position de y selon la taille du term + image (mm chose pr x + offset pcq it char/couleur)
		if (sd.y >= xy_pic.y)
			sd.y = xy_pic.y - 1;
		while (j < (fsize.x))
		{
			sd.x = (j * xy_pic.x / fsize.x);
			if (sd.x >= xy_pic.x)
				sd.x = xy_pic.x - 1;
			int offst = sd.x * it;
			text += print_pixel_ascii(sd.y, offst);
			j++;
		}
		text += "\n";
		i++;
	}
	last = text;
	write(1, text.c_str(), text.size());
}

Picture::Picture(std::string name, char **env): tty_i(tty_infos(env))
{
	infos[0]= 0;infos[1]= 0;infos[2]= 0;infos[3]= 0;
	get_xpm_buffer(name);/*		std::cout << "xpm file copied;\n";*/
	get_info_image();/*			std::cout << "xpm info: " << "size - x " << xy_pic.x << " - y " << xy_pic.y << " colors nb: " << infos[2] << " char per px: " << infos[3] <<";\n";*/
	get_ascii_buffer();
}

Picture::~Picture()
{
	if (bf_text)
		delete [] bf_text;
	if (colors)
		delete [] colors;
	if (bf_pic)
		delete [] bf_pic;
}