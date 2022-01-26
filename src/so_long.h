/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorreia <ecorreia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:58:49 by ecorreia          #+#    #+#             */
/*   Updated: 2022/01/20 20:09:02 by ecorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 1

typedef struct s_map_data
{
	int		cols;
	int		lns;
	int		clct;
	int		plyr;
	int		ext;
	char	**map;
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	char	p;
	int		pl_x;
	int		pl_y;

	int		fti_x;
	int		fti_y;

}	t_map_data;

size_t	ft_strlen_c(const char *s, char c);
char	*ft_get_next_line(int fd);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_substr_f(char const *s, unsigned int start, size_t len);

//standart input error management
int		ft_arg_errors(int argc, char **argv);

//map errors
int		ft_check_wall(char *line);
void	ft_check_center_lines(char *line, t_map_data *map );
void	ft_check_lenght(char *line, t_map_data	*map);
void	ft_check_colections(t_map_data *map);

//solong
int		ft_putchar(char c);
int		ft_arg_errors(int argc, char **argv);
int		ft_is_ber(char *map_name);
int		ft_general_check(int file, t_map_data *map);

//save map
int		ft_open_file(char *file);
char	**ft_close_file(int fd, char **map[]);
char	*ft_strdup(const char *str);
char	**ft_save_map(char *file, t_map_data *v_map);

//utils
void	ft_put_str(char *str);
int		ft_line_length(char *str);
size_t	ft_strlen(const char *str);
int		ft_putnbr(int n);

//render map
void	ft_render_map(t_map_data *v_map);
void	ft_print_map(t_map_data *v_map, int x, int y);
void	ft_render_ground(t_map_data *v_map, char *img);

//key events
void	ft_move_types(t_map_data *v_map, char mov_x, char mov_y);
int		ft_finish_game(t_map_data *v_map, int state);
int		ft_key_hook(int key, t_map_data *v_map);
void	ft_collect(char *pers, char *col);

//key_events2
int		len(long n);
void	ft_swap(char *pers, char *grn);
char	*ft_itoa(int n);
void	ft_print_movements(t_map_data *v_map);
void	ft_black_footer(t_map_data *v_map);

#endif