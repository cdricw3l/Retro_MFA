/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MFA.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cebouhad <cebouhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 18:48:05 by cebouhad          #+#    #+#             */
/*   Updated: 2026/06/05 21:18:19 by cebouhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MFA_H
#define MFA_H

#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <bsd/string.h>

#define C_RED "\e[0;31;1m"
#define C_GREEN "\e[0;32;1m"
#define C_CYAN "\e[0;36;1m"
#define C_YBG "\e[0;43;1m" //yellow bg
#define C_BBG "\e[0;44;1m" // blue bg
#define C_GBG "\e[2;42;1m" //green bg
#define C_PBG "\e[0;45;1m" //purple bg
#define C_RESET "\e[0m"

#define ERR 1
#define OK  0
#define DEBUGG printf(C_RED"Here"C_RESET"\n")
#define BUFFER_SIZE 4

#endif