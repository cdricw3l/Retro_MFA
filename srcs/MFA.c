/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MFA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 18:47:40 by cebouhad          #+#    #+#             */
/*   Updated: 2026/06/05 20:03:25 by cebouhad         ###   ########.fr       */
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

void read_buffer(unsigned char buffer[BUFFER_SIZE])
{
    int i;
    char c;

    i = 0;
    while (i < BUFFER_SIZE)
    {
        c = buffer[i];
        printf("%d", c);
        i++;
    }
    printf("\n");
}

int read_mfa(char *path)
{
    int b_read;
    int fd;
    unsigned char buffer[BUFFER_SIZE];
    
    fd = get_mfa_fd(path);
    b_read = 1;
    while (b_read)
    {
        b_read = read(fd, buffer, BUFFER_SIZE - 1);
        buffer[b_read] = '\0';
        read_buffer(buffer);
    }
    return (OK);
}


int main(int argc, char **argv)
{

    if(argc < 2)
        return (1);
    
    read_mfa(argv[1]);
    return (0);
}