/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asxpm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <gule-bat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:47:16 by gule-bat          #+#    #+#             */
/*   Updated: 2026/04/22 14:06:35 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASXPM_HPP
# define ASXPM_HPP

// #pragma GCC optimize("O2") 
// #pragma GCC target("avx,avx2,fma")

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
#include <dirent.h>
#include <sys/stat.h>
#include <termios.h>
#include <pthread.h>

#define SCALE_FAC 1

typedef pthread_mutex_t mutex;

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
		std::string *colors_ansii;
		std::string *bf_pic;
		std::string last; // buffer ready to be writter by write (max speed efficiency atm	)
		void 	get_xpm_buffer(std::string name);
		void	get_file(std::string name);
		void	get_info_image();
		void	get_pic_buffer();
		void	get_ascii_buffer();
		void	get_ansii_colors();
	public:
		Picture(std::string name, char **env);
		~Picture();
		void	print_picture();
		std::string	print_pixel_ascii(int y, int x);
};

class	Video
{
	private:
		// int		_b_pos;
		int		_frames;
		std::string	_folder;
		std::string *_files;
	public:
		Video(std::string folder, char **env);
		~Video();
		std::string get_dir(std::string folder);
		int			print_video(char **env, int i, int l);
		int			print_video_by_frames(char **env, int i);
};

class	Inputs
{
	private:
		// bool ok;
		std::string line;
		std::string _str;
		char **_env;
		// mutex o;
		// pthread_t id;
	public:
		Inputs(std::string str, char **env);
		~Inputs();
		void	start_video_loop();
		void	start_image();
		void	start_video();
};

#endif