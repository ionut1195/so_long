/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:13:59 by itomescu          #+#    #+#             */
/*   Updated: 2022/01/03 20:47:07 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"


int	main(int argc, char *argv[])
{
	t_vars	vars;
	/*char	*rel_path;
	int		map_fd;
	char	*my_line;
	
	
	int i = 0;
	int st = 0;*/
	vars.map.size = 0;
	//vars.mlx = mlx_init();
	/*rel_path =  "./img/brick_wall.xpm";
	
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "SpaceCow");
	vars.img.img = mlx_xpm_file_to_image(vars.mlx, rel_path, &vars.img.img_height, &vars.img.img_width);*/
	if (argc <= 1)
		return (-1);

	int	map_fd;
	int	itr;
	char **pt;

	itr = 0;
	map_fd = open(argv[1], O_RDONLY);
	while (ft_gnl(map_fd, &pt[itr]))
	{
		printf("%s",pt[itr]);
		itr++;
	}
	printf("%s",pt[itr]);

	/*while (my_line[i] != '\0')
	{
		mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, st,0);
		i++;
		st += vars.img.img_height;
	}
	
	
	mlx_loop(vars.mlx);*/
}