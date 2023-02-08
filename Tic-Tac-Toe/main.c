#include <stdio.h>
#include <stdlib.h>

int main()
{
    // top and botten of the grid array
    char tline [] = {"   ___1_____2_____3___\n"};
    char eline [] = {"   |=====|=====|=====|\n"};
    // blank left side
    char aside [] =
    char bside [] =
    char cside [] =
    char mblank [] =
    // Grid array for users to input
    char grid[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    // art for x and o's
    char O[3][5] = {"", "", ""};
    char X[3][5] = {{'', '', '', '', ''}, {'', '', '', '', ''}, {'', '', '', '', ''}};
    // array to hold y - axis values
    char yaxis[3] = {'A', 'B', 'C'};
    //control varibles
    int i;
    int j;
    // k will be used spefcifkly for the user input grid
    int k = 0;
    // l will be used to thorugh an array of letters
    int l = 0;
    // print top of grid before you loop
    printf(tline);
    printf(t2andeline);
    // start for loop the print each line
    for (i=0; i <11; i++)
    {
        if (i == 3 || i == 7)
            printf(eline);
        else
        {
            if (i == 1 || i == 5 || i == 9 );
                printf(" %c|", yxais[l]);
                l++;
            if ()
            for (j = 0; j < 3; j++)
                if (grid[k][j] == x)


                else if ( (grid[k][j] == y)

                else
        }

        if (i == )
    }
    printf(eline);
}
