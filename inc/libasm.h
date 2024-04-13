/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerwig- <dgerwig-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:50:53 by dgerwig-          #+#    #+#             */
/*   Updated: 2024/01/22 20:27:11 by dgerwig-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <sys/types.h>

size_t		ft_strlen(const char* s);
char*		ft_strcpy(char* dst, const char* src);
int			ft_strcmp(const char* s1, const char* s2);
ssize_t 	ft_write(int fd, const void* buf, size_t nbyte);
ssize_t 	ft_read(int fd, void* buf, size_t nbyte);
char*		ft_strdup(const char* s);
