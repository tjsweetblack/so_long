/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badriano <badriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:38:36 by badriano          #+#    #+#             */
/*   Updated: 2024/05/30 13:37:25 by badriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../minilibx-linux/mlx.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct t_image
{
	void	*player[8];
	void	*wall;
	void	*background;
	void	*exit;
	void	*coin;
}			t_image;

typedef struct t_game
{
	void	*init;
	void	*window;
	char	**map;
	int		move_count;
	int		current_frame;// Add this to track the animation frame
	int		frame_count;
	t_image	image;
}			t_game;

//----------store map in a matrix----------------
char	**ft_get_map(int fd); // main function
size_t	ft_strlen(char *s);
int		num_sub_str(char const *s, char c);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
//---------------find map size-------------------
int		*ft_map_size(char **map); // return matrix position[y.length][x.length]
int		ft_check_map_error(char **map, int *size);// validate all map error
//--------------run map veriication--------------
int		render_map(t_game *game);
int		render_loop(t_game *game);
void	store_to_struct(t_game *game);
void	free_map(char **map);
//--------------ERROS-------------------------------
int		ft_equal_lines(char **map, int *size, int y_count, int x_count);
int		ft_first_and_last(char **map, int *size, int y_count);
int		ft_first_and_last_line(char **map, int x_count);
int		ft_forbiden_elements(char **map, int y_count, int x_count);
int		ft_forbiden(char **map, int y_count, int x_count);
int		ft_number_of_elements(char **map);
int		ft_is_rectangle(char **map, int *size);
int		charector_count_c(char **map, int y_count, int x_count);
int		charector_count_e(char **map, int y_count, int x_count);
int		charector_count_p(char **map, int y_count, int x_count);
//-------------events-------------------------
int		move_player(int key_sym, void *param);
void	close_game(t_game *game);
int		end_of_game(t_game *game, int x, int y);
int		is_map_playable(char **map);
//--------------utils----------------------------
int		num_sub_str(char const *s, char c);
size_t	ft_strlen(char *s);
char	*ft_copy_str(char *s1, char *s2, char *result);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	**ft_split(char *s, char c);
void	free_game_resources(t_game *game);
void	free_images(t_game *game);
void	is_valid_map_file(const char *filename);
char	*ft_strdup(char *s1);
void	*ft_memcpy(void *dst, void *src, size_t n);
//---------------------move function--------------
void	move_right(t_game *game, int y, int x);
void	move_left(t_game *game, int y, int x);
void	move_down(t_game *game, int y, int x);
void	move_up(t_game *game, int y, int x);
//-------------------ft_printf------------------------
int		ft_putchar_len(char c, int current_len);
int		ft_print_num(int num, int current_len);
int		num_len(int num, int current_len);
int		ft_putstr(char *str, int current_len);
int		ft_printf(const char *str, ...);
int		ft_atoi(const char *str);
#endif
