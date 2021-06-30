/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:54:46 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/06/29 21:03:52 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.f"

// Conversões a manusear: csdiupxX%
// Sinalizadores a manusear: 0 -. *
// Valor a devolver : comprimento da string impressa (int).

t_print *ft_initialise(t_print *arrow)			     
{			     
	arrow->wdt = 0;	  # colocamos tudo apontando para 0, false	  
	arrow->prc = 0;
	arrow->zero = 0;
	arrow->pnt = 0;
	arrow->sign = 0;
	arrow->tl = 0;
	arrow->is_zero = 0;
	arrow->dash = 0;
	arrow->perc = 0;
	arrow->sp = 0;			  
	return (arrow);			     
}

int	ft_printf(const char *sms, ...)
{
    t_print		*content;
	int			nothing; //printf retorna um int
	int			count;

    if (sms == NULL)
	  return (-1);
	content = (t_print *)malloc(sizeof(t_print));
	if (content == NULL)
		return (-1);
	ft_initialise(content);
	va_start(content->args, sms);
	count = 0;
	nothing = 0;
	while (sms[count])
	{
		if (sms[count] == '%')
			count = ft_verific_symb(content, sms, count + 1);
		else
			write(1, &sms[count], 1);
	  count++;
	}
	va_end(content->args);
	free(content);
	return (nothing);
}