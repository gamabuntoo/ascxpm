/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asxpm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <gule-bat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:47:16 by gule-bat          #+#    #+#             */
/*   Updated: 2026/04/17 16:41:01 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASXPM_HPP
# define ASXCPM_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#define SCALE_FAC 1

struct	vec
{
	int x;
	int y;
};

class tty_infos
{
	private:
		int	get_tty_size(char **env);
	public:
		vec tty_s;
		tty_infos(char **env);
		~tty_infos();
};

class	Picture
{
	private:
		vec xy_pic; // x pixels y pixels		done
		int size_xpm; // size of xpm file		done
		tty_infos tty_i; // tty x and y 		
		int infos[4]; // x, y, nb of colors, char/color
		std::string *bf_text;
		std::string *colors;
		std::string *bf_pic;
		std::string last; // buffer ready to be writter by write (max speed efficiency atm	)
	public:
		Picture(std::string name, char **env);
		~Picture();
		void get_xpm_buffer(std::string name);
		void	get_file(std::string name);
		void	get_info_image();
		void	get_pic_buffer();
		void	get_ascii_buffer();
		std::string	print_pixel_ascii(int y, int x);
};



#endif