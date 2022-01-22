#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int *clue;
    int i;
    int j;

    i = 0;
    j = 0;
    clue = (int *)malloc(16*sizeof(int));
    while (argv[argc -1][i] != '\0')
    {
        if (argv[argc - 1][i] >= '1' && argv[argc - 1][i] <= '4')
        {
            clue[j++] = argv[argc - 1][i] - 48;
            printf("%d\n", clue[j - 1]);
        }
        else if (argv[argc - 1][i] != ' ')
        printf("Error 1\n"); //Check Error เลขเกิน
        i++;
    }
    if (j != 16) 
    printf("Error 2\n"); //Check Error Argument ไม่ครบ

    ft_iscluevalid //เช็คโจทย์ก่อน
    ft_fillvoid //fillspace -> check condition ต่างๆ
    ft_printboard //print board

}