/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:37:04 by jabadie           #+#    #+#             */
/*   Updated: 2015/03/25 18:07:25 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] == '\n' || str[i] == '\v' || str[i] == '\t' || str[i] == ' '
			|| str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((48 <= str[i] && str[i] <= 57))
	{
		i++;
	}
	return (i);
}

static long int	ft_power(long int nb, int power)
{
	long int	result;

	if (power == 0)
		result = 1;
	else
		result = nb * ft_power(nb, power - 1);
	return (result);
}

static long int	full(char *str, int len, int i)
{
	long int	result;

	result = 0;
	while (i < len)
	{
		result += (str[i] - 48) * ft_power(10, len - 1 - i);
		i++;
	}
	return (result);
}

long int		ft_atoi(char *str)
{
	int			i;
	int			neg;
	int			len;
	long int	result;

	i = 0;
	neg = 0;
	len = ft_strlen(str);
	while (str[i] == '\n' || str[i] == '\v' || str[i] == '\t' || str[i] == ' '
			|| str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-')
	{
		i++;
		neg = 1;
	}
	if (str[i] == '+')
		i++;
	result = full(str, len, i);
	if (neg)
		result = result * (-1);
	return (result);
}
