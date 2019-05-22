/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 14:38:29 by rsteigen      #+#    #+#                 */
/*   Updated: 2019/02/03 17:15:54 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

static int	is_longlong_pos(char *s, int i)
{
	if (i >= 19 && s[0] == '9')
		return (1);
	else
		return (0);
}

static int	is_longlong_neg(char *s, int i)
{
	if (i > 19 && s[0] == '-')
		return (1);
	else
		return (0);
}

static int	check_space(char *s, int i)
{
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'\
		|| s[i] == '\r' || s[i] == '\v' || s[i] == '\f')
		i++;
	return (i);
}

int			ft_atoi(const char *s)
{
	int			i;
	long long	res;
	long long	mod;

	i = 0;
	mod = 1;
	res = 0;
	i = check_space((char*)s, i);
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			mod = -mod;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		if (is_longlong_pos((char*)s, i) == 1)
			return (-1);
		if (is_longlong_neg((char*)s, i) == 1)
			return (0);
		res = (res * 10) + (s[i] - '0');
		i++;
	}
	return (res * mod);
}
