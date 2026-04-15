/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tty.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gule-bat <gule-bat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 23:38:16 by gule-bat          #+#    #+#             */
/*   Updated: 2026/04/15 02:24:56 by gule-bat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asxpm.hpp"

static vec read_size(int &fd)
{
	std::string otp;
	vec res;
	size_t len = 0;
	char *st = NULL;
	
	res.x = 0;
	res.y = 0;
	if (fd <= -1)
		return res;

	FILE *str = fdopen(fd, "r");
	if (!str)
		return res;
	if (getline(&st, &len, str) == -1)
		return (fclose(str), free(st), res);

	otp = st;
	fclose(str);
	free(st);
	
	std::stringstream s(otp);
	s >> res.y >> res.x;

	return res;
}

int	tty_infos::get_tty_size(char **env)
{
	pid_t pid = -1;
	int fd[2];
	char *str[] = {(char *)"/usr/bin/stty", (char *)"size", NULL};

	if (env == NULL)
		return (perror("env, probably stty missing"),-1);
	if (pipe(fd) == -1)
		return (perror("error pipe"), -1);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execve(str[0], str, env);
		exit(0);
	}
	close(fd[1]);
	waitpid(pid, NULL, 0);
	tty_s = read_size(fd[0]);
	return (1);
}

tty_infos::tty_infos(char **env)
{
	get_tty_size(env);	
	std::cout << "tty size:" << " x " << tty_s.x << " y " << tty_s.y << std::endl;
}

tty_infos::~tty_infos()
{

}