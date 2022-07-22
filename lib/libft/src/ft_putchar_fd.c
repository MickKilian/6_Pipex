/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:38:31 by mbourgeo          #+#    #+#             */
/*   Updated: 2021/11/30 22:53:09 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*int	main(int argc, char **argv)
{
	int	fd;

	(void)argc;
	fd = open("test.txt", O_RDWR);
	if (fd != -1)
		ft_putchar_fd(argv[1][0], fd);
	close (fd);
	return (0);
}
*/
