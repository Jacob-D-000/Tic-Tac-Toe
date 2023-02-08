#include <stdio.h>
#include <stdlib.h>

int main()
{
    // top and botten of the grid array
    char tline [] = {"   ___1_____2_____3___\n"};
    char eline [] = {"   |=====|=====|=====|"};
    // Grid array for users to input
    char grid[3][3] = {{'x', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    // art for x and o's
    char O[3][6] = {" / \\ ", "(   )", " \\_/ "};
    char X[3][6] = {" \\ / ", "  X  ", " / \\ "};
    char wspc[6] = "     ";
    // array to hold y - axis values
    char yaxis[3] = {'A', 'B', 'C'};
    //control varibles
    int i;
    int j;
    // k will be used specially for the user input grid
    int k = 0;
    // l will be used to through an array of letters
    int l = 0;
    // print top of grid before you loop
    printf(tline);
    printf("%s\n", eline);
    // start for loop the print each line
    for (i=0; i <11; i++)
    {
        // if it's a line between cells
        if (i == 3 || i == 7)
        {
            printf(eline);
            k++;
        }
        else
        {
            // if it's the middle of the cell
            if (i == 1 || i == 5 || i == 9 )
            {
                printf(" %c||", yaxis[l]);
                l++;
            }
            // if its not the middle of a cell
            else
                printf("   |");
            for (j = 0; j < 3; j++)
            {
                if (grid[k][j] == 'x')
                    if (i == 0 || i == 4 || i == 8 )
                        printf("%s|", X[0] );
                    else if (i == 1 || i == 5 || i == 9)
                        printf("%s|", X[1]);
                    // if top or bottom of cell
                    else
                        printf("%s|",X[2]);
                else if (grid[k][j] == 'o')
                    if (i == 0 || i == 4 || i == 8 )
                        printf("%s|", O[0] );
                    else if (i == 1 || i == 5 || i == 9)
                        printf("%s|", O[1]);
                    // if bottom of the cell
                    else
                        printf("%s|", O[2]);
                // if input is blank
                else
                    printf("%s|", wspc);
            }
            // End of line
            //printf("|");
        }
        printf("\n");
    }
    printf(eline);
}
