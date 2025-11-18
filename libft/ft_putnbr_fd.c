/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosloff <akosloff@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:16:42 by akosloff          #+#    #+#             */
/*   Updated: 2024/11/13 13:16:45 by akosloff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd((n / 10), fd);
	}
	c = (n % 10) + '0';
	write (fd, &c, 1);
}
/*
int main(){
    
    char* fileName = "test.txt";

    int fd = open(fileName, O_RDWR);
    
    if(fd == -1)
	{
        printf("\nError Opening File!!\n");
        exit(1);
    }
    else
	{
        printf("\nFile %s opened successfully!\n", fileName);
    }
	char *string = "test test";
	ft_putnbr_fd(-2147483, fd);

    return 0;
}*/