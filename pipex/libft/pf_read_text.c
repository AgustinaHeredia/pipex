/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 09:01:13 by agheredi          #+#    #+#             */
/*   Updated: 2023/09/15 11:56:51 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pf_read_text(t_sc *sc, char format)
{
	if (write(1, &format, 1) == -1)
	{
		sc->error = -1;
		return (-1);
	}
	sc->len++;
	return (1);
}
