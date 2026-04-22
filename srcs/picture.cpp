/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picture.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <gule-bat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:50:08 by gule-bat          #+#    #+#             */
/*   Updated: 2026/04/22 02:10:56 by gule-bat         ###   ########.fr       */
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
	for (int x = 0; x <= infos[2]; x++) // get colors
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
	// int col;
	// int r;
	// int g;
	// int b;
	std::string res;

	// col = 0;
	s = bf_pic[y].substr(x, infos[3]);
	for (int i = 0; i <= infos[2]; i++)
	{
		if (colors[i].substr(0, infos[3]) == s)
		{
			// std::stringstream sr;
			// int n = 0;
			// while (colors[i][n] != '#')
			// 	n++;
			// col = (int)strtol(&colors[i][n+1], NULL, 16); // peut etre suspect sur s[x]
			// r = (col >> 16) & 0xFF;
			// g = (col >> 8) & 0xFF;
			// b = col & 0xFF;
			// r = (r / 64) * 64;
			// g = (g / 64) * 64;
			// b = (b / 64) * 64;
			// sr << "\033[48;2;" << r << ";" << g << ";" << b << "m" << "  \033[0m";
			// res += sr.str();
			res += colors_ansii[i];
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
	double scale;
	vec sd;
	vec fsize;
	std::string text;

	i = 0;
	scale = std::min((double)tty_i.tty_s.x / xy_pic.x, (double)tty_i.tty_s.y * 0.5 / xy_pic.y); // scaling pcq y est petit sur le term
	fsize.x = (xy_pic.x * scale) / SCALE_FAC;
	fsize.y = (xy_pic.y * scale) / SCALE_FAC;
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
		text += '\n';
		i++;
	}
	last = text; // could be usable later
	// if (!write(1, text.c_str(), text.size()))
		// return (perror("error write system call to display pic buffer"));
}


void	Picture::get_ansii_colors()
{
	int size = infos[2];
	int x = 0;
	std::stringstream sr;
	std::string *colo = new std::string[size+1];

	if (!colo)
		return ;
	while (x <= size)
	{
		int n = 0;
		while (colors[x][n] && colors[x][n] != '#')
			n++;
		int col = (int)strtol(&colors[x][n+1], NULL, 16); // peut etre suspect sur s[x]
		int r = (((col >> 16) & 0xFF) / 64) * 64;
		int g = (((col >> 8) & 0xFF)/ 64 ) * 64;
		int b = ((col & 0xFF) / 64) * 64;
		sr << "\033[48;2;" << r << ";" << g << ";" << b << "m" << "  \033[0m";
		colo[x] = sr.str();
		sr.str("");
		// sr.clear();
		x++;
	}
	colors_ansii = colo;
}

void	Picture::print_picture()
{
	std::cout << last;
}

Picture::Picture(std::string name, char **env): tty_i(tty_infos(env))
{
	infos[0]= 0;infos[1]= 0;infos[2]= 0;infos[3]= 0;
	get_xpm_buffer(name);/*		std::cout << "xpm file copied;\n";*/
	get_info_image();/*			std::cout << "xpm info: " << "size - x " << xy_pic.x << " - y " << xy_pic.y << " colors nb: " << infos[2] << " char per px: " << infos[3] <<";\n";*/
	get_ansii_colors();
	get_ascii_buffer();
	// delete [] bf_text;
	// delete [] bf_pic;
	// bf_text = NULL;
	// bf_pic = NULL;
}

Picture::~Picture()
{
	if (bf_text != NULL)
		delete [] bf_text;
	if (colors)
		delete [] colors;
	if (colors_ansii)
		delete [] colors_ansii;
	if (bf_pic)
		delete [] bf_pic;
}

//	//	//	//	//	//	//	//	VIDEO + CHECK FRAME DIRECTORY + VIDEO LOOP	//	//	//	//  //	//	//	//
std::string Video::get_dir(std::string folder)
{
	DIR *FD;
	struct dirent *infile;
	std::string res;
	int i = 0;

	if (folder[folder.size()-1] != '/')
		return (perror("error video folder input"), "");
	FD = opendir(folder.c_str());
	if (!FD)
		return (perror("error while opening gif folder"), "");
	while (((infile) = (readdir(FD))))
	{
		std::string bf = folder + "/" + infile->d_name;
		struct stat buff;
		int sta = -1;
		sta = stat(bf.c_str(), &buff);
		if (sta == -1)
			return (perror("error while opening gif folder"), closedir(FD), "");
		if (infile && buff.st_mode & S_IFREG )
		{
			res += bf;
			res += '\n';
			i++;
		}
	}
	closedir(FD);
//	//	//	//	//	//	//	//	//	//	//	//	//	//	//
	std::string *f = new std::string[i+1];
	if (!f)
		return (perror("error while opening gif folder"), "");
	std::stringstream s(res);
	std::string l;
	for (int p = 0; p <= i && std::getline(s, l); p++)
		f[p] = l;
	_files = f;
	_frames = i;
	return ("ok");
}

Video::Video(std::string folder, char **env) : _b_pos(0), _frames(0), _folder(folder)  
{
	_files = NULL;
	if (get_dir(_folder) == "")
		return ;
	(void)env;
	for (int x = 0; x < _frames - 1; x++)
	{
		for (int y = x + 1; y < _frames; y++)
		{
			if (_files[x] > _files[y])
			{
				std::string tmp = _files[x];
				_files[x] = _files[y];
				_files[y] = tmp;
			}
		}
	}
}

Video::~Video()
{
	if (_files)
		delete [] _files;
}


int	Video::print_video(char **env, int i, int l)
{
	if (!_frames)
		return -1;
	std::cout << "\033[1J";
	for (int x = 0; x < _frames; x++)
	{
		if (x >= _frames - 1 && l == 1)
			x = 0;
		// std::cout << "\033[s";
		std::cout << "\033[H";
		Picture p(_files[x], env);
		p.print_picture();
		// std::cout << "\033[u";
		usleep(30000);
		if (i == 1)
			break ;
	}
	return (1);
}

int			Video::print_video_by_frames(char **env, int i)
{
	static int x = 0;

	if (!_frames)
		return -1;
	if (i == 1)
		return (-1);
	std::cout << "\033[1J";
	if (x < _frames)
	{

		// std::cout << "\033[s";
		std::cout << "\033[H";
		Picture p(_files[x], env);
		p.print_picture();
		// std::cout << "\033[u";
		usleep(30000);
		x++;
	}
	if (x >= _frames - 1)
		x = 0;
	return (1);
}

Inputs::Inputs(std::string str, char **env) : _str(str), _env(env)
{

	
}

Inputs::~Inputs()
{

	
}

void	Inputs::start_image()
{
	Picture pic(_str, _env);

	pic.print_picture();
}

void	Inputs::start_video_loop()
{
	std::string str;
	Video v(_str, _env);
	int i = 0;

	while (1)
	{
		// if (!getline(std::cin, str))
		// break;
		// std::cout << "\033[1J";
		std::cout << "p+enter to play video,\t f+enter to play frame by frame,\t q+enter to quit\n";
		// std::cout << "\033[H";
		std::cin >> str;
		if (str == "p")
			v.print_video(_env, i, 0);
		else if ((str == "q") || !str.c_str())
		{
			i = 1;
			break;
		}
		else if (str == "f")
			v.print_video_by_frames(_env, i);
		else if (str == "c")
			std::cout << "\033[2J";
	}


	// !!!!!! SIGNAUX CTRL C MINITALK MINISHELL PTN QUEL CON 
	return ;
}

void	Inputs::start_video()
{
	Video v(_str, _env);
	v.print_video(_env, 0, 1);
}