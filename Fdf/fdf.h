/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:26:41 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/01/19 16:01:19 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# define TOOL 1080
# define AARD 1980

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_ihdatiyat
{
	float	x;
	float	y;
	int		z;
	int		color;
}	t_ihdatiyat;

typedef struct s_data
{
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
	t_ihdatiyat	**matrix;
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*saver;
	float		zoom;
	int			ox;
	int			oy;
	float		xinc;
	float		yinc;
	int			color;
	float		masafax;
	float		masafay;
	int			masafaz;
	float		angle_x;
	float		angle_y;
	float		angle_z;
	float		angle_iso;
	int			flag;
	int			i;
}	t_data;

typedef struct s_list {
	char			*text;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
int		ft_strchr(t_list *head);
int		check_name(char *str);
void	ft_malloc(t_list *head, char **line);
t_list	*ft_lstlast(t_list *lst);
void	free_node(t_list **lst, void (*del)(void*));
void	rest_node(t_list **head);
void	get_line(t_list *head, char **line);
void	read_file2(int fd, t_list **head);
void	node_creat(t_list **buffer, char *buff, int red);

int		get_color(t_ihdatiyat *start, t_ihdatiyat *end, t_data *va);

void	iconix(t_data *datis);
void	iso_view(t_data *datis);
void	pannix(t_data *datis);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_zoom(int keycode, t_data *datix);
size_t	ft_count_strings(char const *str, char c);
//size_t	ft_count_stringss(char const *str, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		closse(int keycode, t_data *datos);
void	ft_move(int keycode, t_data *datax);
void	now_draw(t_data *delta, t_ihdatiyat **matrix);
void	full_matrix(t_data *datas);
void	read_file(t_data *info, char *filename);
void	full_matrix_z(t_data *infoz);
void	allocate_matrix(t_data *dataa);
void	get_width(t_data *infos, int fd);
void	get_char(t_data *data, int fd);
void	give_value(t_data *va, t_ihdatiyat matris, float *x, float *y);
void	give_value2(t_ihdatiyat end, t_ihdatiyat start, int *dx, int *dy);
int		rotation_z(t_ihdatiyat *start, t_ihdatiyat *end, t_data *va);
void	rotation_y(t_ihdatiyat *start, t_ihdatiyat *end, t_data *va);
void	rotation_x(t_ihdatiyat *start, t_ihdatiyat *end, t_data *va);
int		ft_atoi(const char *str);

#endif