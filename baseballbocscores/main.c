#include <stdio.h>
#include <stdlib.h>

void boxScore(int runs[]);

int main()
{
    int runs[9] = {1,2,3,4,5,6,7,8,9};

    //int inning0, inning1, inning2, inning3, inning4, inning5, inning6, inning7, inning8, inning9;
    //inning0 = 1; inning1 = 2; inning2 = 3; inning3=4; inning4=5; inning5=6; inning6=7; inning7=8; inning8=9; inning9=10;

    boxScore(runs);
    //boxScore(inning0, inning1, inning2, inning3, inning4, inning5, inning6, inning7, inning8);
}

void boxScore(int runs[])
{
    printf("this is box score");
/*
+---------+---+---+---+---+---+---+---+---+---+
| Innings | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
+=========+===+===+===+===+===+===+===+===+===+
| Visitor |   |   |   |   |   |   |   |   |   |
+---------+---+---+---+---+---+---+---+---+---+
| Home    |   |   |   |   |   |   |   |   |   |
+---------+---+---+---+---+---+---+---+---+---+
*/
    for (int i = 0; i < 9; i++)
    {
        printf("%d", runs[i]);
    }
    //printf("%d\n",run1);
    //printf("%d\n",run2);
    //printf("%d\n",run3);
    //printf("%d\n",run4);
    //printf("%d\n",run5);
    //printf("%d\n",run6);
    //printf("%d\n",run7);
    //printf("%d\n",run8);
    //printf("%d\n",run9);

}
