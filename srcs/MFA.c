/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MFA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 18:47:40 by cebouhad          #+#    #+#             */
/*   Updated: 2026/06/05 18:59:25 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MFA.h"

int get_mfa_fd(char *path)
{
    int fd;

    fd = open(path, O_RDONLY);
    if(fd < 0)
        return (ERR);
    return (fd);
}

void read_buffer(char buffer[BUFFER_SIZE])
{

}

int read_mfa(int fd)
{
    int b_read;
    char buffer[BUFFER_SIZE];
    
    b_read = 1;
    while (b_read)
    {
        b_read = read(fd, buffer, BUFFER_SIZE - 1);
        buffer[b_read] = '\0';


    }
    
}


int main(int argc, char **argv)
{

    if(argc < 2)
        return (1);
    

    return (0);
}