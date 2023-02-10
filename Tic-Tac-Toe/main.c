#include <stdio.h>
#include <stdlib.h>
/*
**Project: Tic-Tac-Toe
**Author: Jacob Dimoff
**Date: 09/02/23
**Filename: main.c (tic_tac_toe_table.c)
**Purpose: Create a table for tic tac toe and allow users to input values to play
*/

void table_print(char grid[3][3])
{
    // top and botten of the grid array
    char tline [] = {"   ___1_____2_____3___\n"};
    char eline [] = {"   |=====|=====|=====|"};
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
                // if the value is X
                if (grid[k][j] == 'x')
                {
                    if (i == 0 || i == 4 || i == 8 )
                        printf("%s|", X[0] );
                    else if (i == 1 || i == 5 || i == 9)
                        printf("%s|", X[1]);
                    // if top or bottom of cell
                    else
                        printf("%s|",X[2]);
                }
                // if the value is o
                else if (grid[k][j] == 'o')
                    if (i == 0 || i == 4 || i == 8 )
                        printf("%s|", O[0] );
                    else if (i == 1 || i == 5 || i == 9)
                        printf("%s|", O[1]);
                    // if bottom of the cell
                    else
                        printf("%s|", O[2]);
                // if there isn't blank
                else
                    printf("%s|", wspc);
            }
        }
        printf("\n");
    }
    printf(eline);
}

int player_input(char *(p_grid[3]))
{
    // control variables
    int convarx = 0;
    int convary = 0;
    // define input varialbes
    int x;
    char y;
    int xnum;
    int ynum;
    //int inparray[2] = {0, 0};
    // instructions
    printf("Where would you like to put your your mark? (A,B,C) or (a,b,c)");
    // start of input validation loop for Y
    while(convary == 0)
    {
        printf("\ny-axis: ");
        fflush(stdin);
        //y = getchar();
        scanf("%c", &y);
        //formats character to upper for consistency
        // switch case to input variable to get a grid address
        switch(y)
        {
            case 'A':
            case 'a':
                ynum = 0;
                convary ++;
                break;
            case 'B':
            case 'b':
                ynum = 1;
                convary ++;
                break;
            case 'C':
            case 'c':
                ynum = 2;
                convary ++;
                break;
            default:
                printf("error unknown value please try again");
        }
    }
    // start of input validation loop for X
    printf("Where would you like to put your your mark? (1,2,3)");
    while (convarx == 0)
    {
        printf("\nx-axis: ");
        fflush(stdin);
        scanf("%d", &x);
        switch(x)
        {
            case 1:
                xnum = 0;
                convarx ++;
                break;
            case 2:
                xnum = 1;
                convarx ++;
                break;
            case 3:
                xnum = 2;
                convarx ++;
                break;
            default:
                printf("error unknown value please try again");
        }
    }
    *(p_grid[ynum] + xnum);
    printf("\n xnum:%d |ynum:%d \n", xnum, ynum);
    return 0;
}

int main()
{
    // Grid array for users to input
    char grid[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char (*p_grid)[3] = &grid;
    printf("%p", p_grid);
    //turn varaible
    int turns = 1;
    // win variable
    int winvar = 0;
    //
    do {
        printf("\nIn order to play you will be promted to write two values. The first should be a letter corresponding  letter on the y-axis. Then you will type a number that corrisponds to a number on the x-axis.\n");
        table_print(grid);
        printf("\n");
        char gridput = player_input(p_grid);
        /* Check for win, change winvar to 1 to leave game loop */
    } while (winvar != 1);

}
