/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MFA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 18:47:40 by cebouhad          #+#    #+#             */
/*   Updated: 2026/06/05 21:35:59 by cebouhad         ###   ########.fr       */
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

void read_buffer(unsigned char buffer[BUFFER_SIZE], int b_read)
{
    int i;
    char c;

    i = 0;
    while (i < b_read)
    {
        c = buffer[i];
        printf("%c", c);
        i++;
    }
}



char *find_bank_header(char buffer[BUFFER_SIZE])
{
    char *start_str = strnstr((char *)buffer, "AGMI", 4);;
    // if(start_str)
    // {
    //     write(STDOUT_FILENO, start_str, 4);
    //     write(STDOUT_FILENO, "\n", 1);
    // }
    if(start_str)
    {
        start_str = strnstr(start_str, "AGMI", 4);
        write(STDOUT_FILENO, start_str, 4);
        write(STDOUT_FILENO, "\n", 1);
    }
    return (NULL);
}

int read_mfa(char *path)
{
    int b_read;
    //char *str;
    int fd;
    int off_set;
    unsigned char buffer[BUFFER_SIZE + 1];
    
    fd = get_mfa_fd(path);
    if(fd < 0)
    {
        perror("Open:");
        return (ERR);
    }
    b_read = 1;
    //str = NULL;
    off_set = 0;
    while (b_read /*&& !str*/)
    {
        b_read = read(fd, buffer, BUFFER_SIZE);
        buffer[b_read] = '\0';
        read_buffer(buffer, b_read);
        //str = find_bank_header(buffer);
        off_set += b_read;
    }
    
    return (OK);
}
/*
    https://mfa.ilikefemboys.com/

*/

int main(int argc, char **argv)
{
    

    if(argc < 2)
        return (1);
    
    read_mfa(argv[1]);
    return (0);
}