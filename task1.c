/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htkachuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 16:45:59 by htkachuk          #+#    #+#             */
/*   Updated: 2018/08/22 16:46:08 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
// #include <stdlib.h>


#include <stdio.h>

 void reverse(char s[])
 {
     int i, j;
     char c;
 
     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
 }

 /* itoa:  конвертируем n в символы в s */
 int itoa(int n, char s[])
 {
     int i, sign;
 
     if ((sign = n) < 0)  /* записываем знак */
         n = -n;          /* делаем n положительным числом */
     i = 0;
     do {       /* генерируем цифры в обратном порядке */
         s[i++] = n % 10 + '0';   /* берем следующую цифру */
     } while ((n /= 10) > 0);     /* удаляем */
     if (sign < 0)
         s[i++] = '-';
     s[i] = '\0';
     reverse(s);
     return (i);
 }

int	main(void)
{
	char		str[100];
	char		res_c[3];
	int			fd_in;
	int			fd_o;
	int			i;
	int			res;

	i = 0;
	res = 0;
	bzero(str, 100);
	bzero(res_c, 3);
	fd_in = open("INPUT.TXT", O_RDONLY);
	read(fd_in, str, 100);
	while (str[i])
	{
		if (str[i] == '1')
			res++;
		i++;
	}
	fd_o = open("OUTPUT.TXT", O_WRONLY);
	if (fd_o == -1)
	{
		printf("Create OUTPUT.TXT\n");
		return (1);
	}
	i = itoa(res, res_c);
	write(fd_o, res_c, i);
	return (0);
}
