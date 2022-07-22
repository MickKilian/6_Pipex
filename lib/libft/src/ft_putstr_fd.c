/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:38:31 by mbourgeo          #+#    #+#             */
/*   Updated: 2021/12/06 18:34:15 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, ft_strlen(s));
}

/*int	main(int argc, char **argv)
{
	int	fd;

	(void)argc;
	fd = open("test.txt", O_RDWR);
	if (fd != -1)
		ft_putstr_fd(argv[1], fd);
	close (fd);
	return (0);
}
*/
