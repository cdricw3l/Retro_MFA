/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MFA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 18:47:40 by cebouhad          #+#    #+#             */
/*   Updated: 2026/06/07 09:22:32 by cdric.b          ###   ########.fr       */
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
void print_bit(uint16_t v, int size)
{
    size--;
    while (size >= 0)
    {
        
        printf("%d", (v >> size) & 1);
        // if(size % 8 == 0)
        //     NL;
        size--;
    }
    printf("\n");
}


int get_agmi_flags(int fd)
{
    int b_read;
    char buffer[1];
    char b2[3];

    if(fd < 0)
        return (-1);
    b_read = 0;
    while (1)
    {
        b_read += read(fd, buffer, 1);
        if(buffer[0] == 'A')
        {
            
            b_read += read(fd, b2, 3);
            if(!strncmp("GMI", b2, 3))
                return (b_read - 4);
        }
    }
    return (0);
}



void agmi_flag(int fd)
{
    char buffer[4];
    int agmi;
    
    agmi = get_agmi_flags(fd);
    lseek(fd, agmi, SEEK_SET);
    read(fd, buffer, 4);
    write(STDOUT_FILENO, buffer, 4);
    NL;
    uint16_t v;

    printf("size %d\n", sizeof(uint16_t));
    read(fd, &v, sizeof(uint16_t));
    printf("voici éa version %d\n", v);
    read(fd, &v, sizeof(uint16_t));
    printf("voici la taille %d\n", v);
    read(fd, &v, sizeof(uint16_t));
    printf("voici la taille %d\n", v);

    NL;
}

int read_mfa(char *path)
{
    int fd;
    
    fd = get_mfa_fd(path);
    if(fd < 0)
    {
        perror("Open:");
        return (ERR);
    }
  
    agmi_flag(fd);
    return (OK);
}
/*
    https://mfa.ilikefemboys.com/
    https://mfa.ilikefemboys.com/types/banks/image/cimagebank/
*/

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    if(argc < 2)
        return (1);
    
  
    read_mfa(argv[1]);
    return (0);
}