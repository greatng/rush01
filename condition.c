#include <unistd.h>
#include <stdio.h>
#include "rush01.h"

int    ft_top(int board[N][N], int *clue, int i, int j)
{
    int count;
    while (j != 4 && board[i][j] != 4)
    {
        count = 1;
        while (i < 3 && board[i][j] != 4)
        {
            if (board[i][j] < board[i+1][j])
            {
                count++;
            }
            i++;
        }
        if (count != clue[j])
        {
            return (0);
        }
        i = 0;
        j++;
    }
    return (1);
}
int    ft_btm(int board[N][N], int *clue, int i, int j)
{
    int count;
    while (j != 4 && board[i][j] != 4)
    {
        count = 1;
        while (i > 0 && board[i][j] != 4)
        {
            if (board[i][j] < board[i-1][j])
            {
                count++;
            }
            i--;
        }
        if (count != clue[j+4])
        {
            return (0);
        }
        i = 3;
        j++;
    }
    return (1);
}
int    ft_left(int board[N][N], int *clue, int i, int j)
{
    int count;
    while (i != 4 && board[i][j] != 4)
    {
        count = 1;
        while (j < 3 && board[i][j] != 4)
        {
            if (board[i][j] < board[i][j+1])
            {
                count++;
            }
            j++;
        }
        if (count != clue[i+8])
        {
            return (0);
        }
        j = 0;
        i++;
    }
    return (1);
}
int    ft_right(int board[N][N], int *clue, int i, int j)
{
    int count;
    i = 0;
    while (i != 4 && board[i][j] != 4)
    {
        count = 1;
        while (j > 0 && board[i][j] != 4)
        {
            if (board[i][j] < board[i][j-1])
            {
                count++;
            }
            j--;
        }
        printf("Test %d\n", count);
        if (count != clue[i+12])
        {
            return (0);
        }
        j = 3;
        i++;
    }
    return (1);
}