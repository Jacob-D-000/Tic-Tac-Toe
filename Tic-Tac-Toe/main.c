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

int *player_input()
{
    // control variables
    int convarx = 0;
    int convary = 0;
    // define input varialbes
    int x;
    char y;
    int xnum;
    int ynum;
    // gird that is returned into at the end of function. Will contain the x and y coords.
    static int inparray[2] = {0, 0};
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
    // xnum and ynum are inputed into inparray
    inparray[0] = ynum;
    inparray[1] = xnum;
    return inparray;
}

int grid_input(int *gridput, char (*p_grid)[3], int turn)
{
    // varaibles to pop values out of the grid
    int y;
    int x;
    //int i;
    //for (i = 0; i < 3; i++)

    y = *(gridput + 0);
    x = *(gridput + 1);
    printf("Y: %d\n", y);
    printf("X: %d\n", x);
    // deinitialize pointer into varaible
    printf("%c\n", *(p_grid[y] + x));
    if (*(p_grid[y] + x) == ' ')
    {
        if (turn == 1 || turn == 3 || turn == 5 || turn == 7 || turn == 9)
        {
            *(p_grid[y] + x) = 'x';
            turn++;
            return turn;
        }
        else
        {
            *(p_grid[y] + x) = 'o';
            turn++;
            return turn;
        }
    }
    else
    {
        printf("That spot is already taken\n");
        return turn;
    }
}

int main()
{
    char grid[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    //p_grid = &grid;
    //turn varaible
    int turns = 1;
    // win variable
    int winvar = 0;
    int *p_gridput;
    int y;
    int x;
    // gird input to go into the validadtion function
    do {
        printf("\nIn order to play you will be promted to write two values. The first should be a letter corresponding  letter on the y-axis. Then you will type a number that corrisponds to a number on the x-axis.\n");
        table_print(grid);
        printf("\n");
        p_gridput = player_input();
        y = *(p_gridput + 0);
        x = *(p_gridput + 1);
        turns = grid_input(p_gridput, grid, turns);
        printf("\n%d\n", turns);
        printf("%c\n", grid[y][x]);
        /* Check for win, change winvar to 1 to leave game loop */
    } while (winvar != 1);

}
