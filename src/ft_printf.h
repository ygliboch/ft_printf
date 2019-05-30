/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 13:30:17 by yhliboch          #+#    #+#             */
/*   Updated: 2019/01/04 13:30:19 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define ABS(x) ((x < 0) ? (-x) : (x))

typedef	struct		s_list
{
	char			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

char				*check_change(char *fmt, va_list ap, t_list **list);
int					ft_printf(const char *format, ...);
char				*ft_itoa_u(unsigned long long int n);
char				*ft_itoa_base(unsigned long long int n, int base);
char				*ft_itoa_f(long double n);

typedef struct		s_flags
{
	int				hyp;
	int				plus;
	int				hesh;
	int				zero;
	int				space;
	int				nul;
}					t_flags;

typedef struct		s_mod
{
	int				width;
	int				preci;
	int				sign;
	int				h;
	int				hh;
	int				l;
	int				ll;
	int				ld;
	int				x;
	int				j;
	int				z;
}					t_mod;

char				*is_fl(char *fmt, t_flags **fl);
char				*is_width(va_list ap, char *fmt, t_mod **md, t_flags **fl);
char				*is_preci(va_list ap, char *fmt, t_mod **md);
char				*is_mod(char *fmt, t_mod **md);
void				make_new_fmt(t_list **list, char *res);
char				*check(va_list ap, char *fmt, t_flags **fl, t_mod **md);
void				make_width_s(char **res, t_flags *fl, t_mod *md);
char				*inf(t_flags *fl, t_mod **md);
void				make_flags_f(char **res, t_flags *fl, t_mod *md);

char				*d_printf(va_list ap, t_flags *fl, t_mod **md);
char				*u_printf(va_list ap, t_flags *fl, t_mod *md);
char				*o_printf(va_list ap, t_flags *fl, t_mod *md);
char				*x_printf(va_list ap, t_flags *fl, t_mod *md);
char				*ft_itoa_x(unsigned long long int n, t_mod *md);
char				*p_printf(va_list ap, t_flags *fl, t_mod *md);
char				*s_printf(va_list ap, t_flags *fl, t_mod *md);
char				*c_printf(va_list ap, t_flags *fl, t_mod *md, char *fmt);
char				*change(char *fmt, va_list ap, t_flags *fl, t_mod **md);
char				*percent(t_flags *fl, t_mod *md);
char				*f_printf(va_list ap, t_flags *fl, t_mod **md);
double				ft_round(double n, t_mod *md);

char				*ft_itoa_d(long long n, t_mod **md);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isdigit(int c);
char				*ft_itoa(long long n);
void				ft_lstaddend(t_list **alst, t_list *new);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				*ft_memalloc(size_t size);
void				ft_putstr(char *s);
char				*ft_strchr(const char *s, int c);
void				ft_strdel(char **ap);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *s);
char				*ft_strnew(size_t size);
void				ft_putchar(char c);
void				*ft_memset(void *b, int c, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);

#endif
