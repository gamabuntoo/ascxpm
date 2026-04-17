/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <gule-bat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:46:38 by gule-bat          #+#    #+#             */
/*   Updated: 2026/04/17 16:40:00 by gule-bat         ###   ########.fr       */
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
	if (argc != 2)
		return (1);
	(void)argv;	
	Picture pic(argv[1], env);
	
	return (0);	

}