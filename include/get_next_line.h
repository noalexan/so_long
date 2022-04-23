/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:09:14 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/23 12:59:50 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1

char	*get_next_line(int fd);
int		there_is_a_end_of_line(char *save);
void	add_buffer(char **save, char *buffer);
char	*get_line(char **save);

#endif
