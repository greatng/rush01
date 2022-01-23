#include <unistd.h>
#include <stdio.h>
#include "rush01.h"

int    ft_top(int board[N][N], int *clue, int i, int j)
{
    int count;
    int minus;
    while (j != 4)
    {
        minus = 0;
        count = 1;
        while (i < 3 && board[i][j] != 4)
        {
            if (board[i + minus][j] < board[i+1][j])
                count++;
            else
                minus--;
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
    int minus;
    while (j < 4)
    {
        minus = 0;
        count = 1;
        while (i > 0 && board[i][j] != 4)
        {
            if (board[i - minus][j] < board[i-1][j])
                count++;
            else
                minus--;
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
    int minus;
    while (i != 4)
    {
        minus = 0;
        count = 1;
        while (j < 3 && board[i][j] != 4)
        {
            if (board[i][j + minus] < board[i][j+1])
                count++;
            else
                minus--;
            j++;
        }
        if (count != clue[i + 8])
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
    int minus;

    i = 0;
    while (i != 4)
    {
        count = 1;
        minus = 0;
        while (j > 0 && board[i][j] != 4)
        {
            if (board[i][j - minus] < board[i][j-1])
                count++;
            else 
                minus--;
            j--;
        }
        if (count != clue[i+12])
        {
            return (0);
        }
        j = 3;
        i++;
    }
    return (1);
}