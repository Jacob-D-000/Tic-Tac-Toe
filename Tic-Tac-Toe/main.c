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
                    if (i == 0 || i == 4 || i == 8 )
                        printf("%s|", X[0] );
                    else if (i == 1 || i == 5 || i == 9)
                        printf("%s|", X[1]);
                    if (i == 0 || i == 4 || i == 8 )
                        printf("%s|", X[0] );
                    else if (i == 1 || i == 5 || i == 9)
                        printf("%s|", X[1]);
                    // if top or bottom of cell
                    else
                        printf("%s|",X[2]);
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

int playerinput()
{
    // control variables
    int convarx = 0;
    int convary = 0;
    // defineinput varialbes
    int x;
    char y;
    char yupper[1];
    int ynum;
    //int inparray[2] = {0, 0};
    // instructions
    printf("Where would you like to put your your mark?\n");
    // start of four loop
    while(convary == 0)
    {
        printf("y-axis: ");
        fflush(stdin);
        yupper = getchar();
        // formats character to lower for consistancy
        //yupper = toupper(y);
        printf("%c", yupper);
        if (yupper == 'A' || yupper == 'B' || yupper == 'C')
        {
            if(y == 'a')
                y = 0;
            else if(y == 'b')
                y = 1;
            // if y = c
            else
                y = 2;
            convary++;
        }
        // if valid input
        else
        {
            printf("error unknown value please try again");
        }
    }
    while (convarx == 0)
    {
        printf("x-axis: ");
        //fflush(stdin);
        //x = get

        x = toupper(x);
        if(x != 1 || x != 2 || x != 3)
            printf("error unknown value please try again.\n");
        else
        {
            if(x == 1)
                x = 0;
            else if(x == 2)
                x = 1;
            // if x = 3
            else
                x = 2;
        }
            convarx ++;
    }
    int inparray[2] = {x , y};
    return inparray;
}

char player_o()
{

}

int main()
{
    // Grid array for users to input
    char grid[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    //turn varaible
    int turns = 1;
    // win variable
    int winvar = 0;
    //

    printf("\nIn order to play you will be promted to write two values. The first should be a letter corrsponding letter on the y-axis. Then you will type a number that corrisponds to a number on the x-axis.\n");
    table_print(grid);
    printf("\n");
    char gridput = playerinput();


}
