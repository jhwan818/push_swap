/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 22:56:44 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/31 12:52:05 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

# define TRUE 1
# define FALSE 0

typedef unsigned char	t_byte;
typedef short int		t_lbyte;

union u_flag
{
	t_byte	byte;
	struct {
		t_byte	minus: 1;
		t_byte	zero: 1;
		t_byte	hashtag: 1;
		t_byte	space: 1;
		t_byte	plus: 1;
		t_byte	precition: 1;
		t_byte	err: 1;
	};
	t_byte	f_check: 6;
};

union u_conversion
{
	t_lbyte	lbyte;
	struct {
		t_byte	character: 1;
		t_byte	string: 1;
		t_byte	pointer: 1;
		t_byte	decimal: 1;
		t_byte	integer: 1;
		t_byte	udecimal: 1;
		t_byte	hexa_low: 1;
		t_byte	hexa_up: 1;
		t_byte	percent: 1;
		t_byte	err: 1;
	};
};

typedef struct s_flag
{
	union u_flag		flag;
	unsigned int		f_width;
	unsigned int		p_width;
	unsigned int		char_read;
	union u_conversion	conv;
}	t_flag;

int		ft_printf(const char *str, ...);
int		ft_print_format(t_flag f, va_list ap);
char	*ft_getstr(t_flag f, char *s);
char	*ft_getpointer(t_flag f, size_t p);
char	*ft_getdecimal(t_flag f, int d);
char	*ft_getinteger(t_flag f, int i);
char	*ft_getudecimal(t_flag f, unsigned int u);
char	*ft_gethexa_low(t_flag f, unsigned int hl);
char	*ft_gethexa_up(t_flag f, unsigned int hu);

int		ft_putchar(char c);
int		ft_putstr(char *s);
char	*ft_utoa(unsigned int u);
char	*ft_hltoa(size_t hl);
char	*ft_hutoa(size_t hu);
char	*ft_htoa_base(size_t h, char *base);

/*bonus*/
t_flag	ft_parse_format(const char *str);
int		ft_getmin(int a, int b);
int		ft_getmax(int a, int b);
char	*set_sign(char *str, char *sign, t_flag f);
char	*ft_strappend(char c, char *s2);
char	*fill_zero(char	*str, int width);
#endif
