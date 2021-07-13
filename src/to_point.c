/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 15:19:31 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/07/12 16:21:20 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void ft_to_pointer(t_print *content)
{
	unsigned long	p;
	int				len;

	len = 2;
	p = (unsigned long)va_arg(content->args, void *);
	if (!p && content->pnt)
	{
		ft_nullp(content);
		return ;
	}
	else
		len += ft_numlen_base(p, 16);
	if (content->wdt > content->prc)
		ft_update_lenght(content, len);
	content->prc = content->prc + 2 - len;
	ft_right(content);
	content->tl += write(1, "0x", 2);
	if (content->prc)
	{
		while (content->prc -- > 0)
			content->tl += write(1, "0", 1);
	}
	content->tl += ft_putnbr_base(p, "0123456789abcdef");
	ft_left(content); 	
}


void	ft_nullp(t_print *content)
{
	if (content->wdt > content->prc)
	{
		while (content->wdt-- > (content->prc + 2))
		content->tl += write(1, " ", 1);
	}
	content->tl += write(1, "0x", 2);
	if (content->prc)
	{
		while (content->prc-- > 0)
			content->tl += write(1, "0", 1);
	}
	else
		content->tl += write(1, "0", 1);
}