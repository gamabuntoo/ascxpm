/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <gule-bat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:46:38 by gule-bat          #+#    #+#             */
/*   Updated: 2026/04/22 02:10:59 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "../includes/asxpm.hpp"


int main(int argc, char **argv, char **env)
{
	if (argc != 3)
		return (perror("check readme -v folder,  -i file.xpm, to use"),1);
	std::string str = argv[1];
	std::string stri = argv[2];
	// try
	// {
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	Inputs	i(stri, env);
	if (str == "-i")
	{
		// Video v(argv[2], env);
		// v.print_video(env);		
		i.start_video_loop();
	}
	else if (str == "-p")
	{
		// Picture pic(argv[2], env);
		i.start_image();
	}
	else if (str == "-v")
	{
		i.start_video();
	}
	else
	{
		std::cout << "arg[1] :interactive -i/ picture -p/ video -p,\narg[2] : input file or picture, interactive works only with folders\n";
	}
	return (0);	

}