/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 20:26:06 by pngamcha          #+#    #+#             */
/*   Updated: 2022/01/23 20:27:00 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01
#define RUSH01
#define N 4
#include <stdbool.h>
void	ft_printboard(int board[N][N]);

void	ft_printerror();

void	ft_fillboard(int board[N][N], int i);

void	ft_check1(int *clue, int board[N][N], int i);

void	ft_start(int *clue);

void    ft_clue(int *clue, int i, int j);

int ft_solve(int board[N][N], int *clue, int i, int j);

int ft_top(int board[N][N], int *clue, int i, int j);

int ft_btm(int board[N][N], int *clue, int i, int j);

int ft_left(int board[N][N], int *clue, int i, int j);

int ft_right(int board[N][N], int *clue, int i, int j);

int ft_checker(int board[N][N], int *clue);
#endif
