/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MFA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 18:47:40 by cebouhad          #+#    #+#             */
/*   Updated: 2026/06/06 09:40:03 by cebouhad         ###   ########.fr       */
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

void print_bit(uint16_t v)
{
    int bit;
    
    bit = 15;
    while (bit >= 0)
    {
        printf("%d", (v >> bit) & 1);
        bit--;
    }
    printf("\n");
}

// void convert_char_to_byte(unsigned char *buffer)
// {
//     int bit;
//     uint16_t value;
//     int idx;
    
//     bit = 15;
//     idx = 0;
//     value = 0;
//     while (bit >= 0)
//     {
//         value |= (buffer[idx] >> bit) & 1;
//         if(bit == 8)
//             idx++;
//         value = value << 1;
//         bit--;
//     }
//     print_bit(value);
// }
void convert_char_to_byte(unsigned char *buffer)
{
    uint16_t value;
    
    value = buffer[0] << 8 | buffer[1] ;
    print_bit(value);
    printf("value %d\n", value);
}

int read_mfa(char *path)
{
    int b_read;
    //char *str;
    int fd;
    unsigned char buffer[BUFFER_SIZE + 1];
    
    fd = get_mfa_fd(path);
    if(fd < 0)
    {
        perror("Open:");
        return (ERR);
    }
    lseek(fd, 16, SEEK_SET);
    b_read = read(fd, buffer, 4);
    buffer[b_read] = '\0';


    convert_char_to_byte(buffer);
    
    return (OK);
}
/*
    https://mfa.ilikefemboys.com/
    https://mfa.ilikefemboys.com/types/banks/image/cimagebank/
*/

int main(int argc, char **argv)
{
    

    if(argc < 2)
        return (1);
    
    read_mfa(argv[1]);
    return (0);
}