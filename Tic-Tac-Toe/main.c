#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
/*
**Project: Tic-Tac-Toe
**Author: Jacob Dimoff
**Date: 09/02/23
**Filename: main.c (tic_tac_toe_game.c)
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
    printf("Where would you like to put your your mark on the Y-axis? (A,B,C) or (a,b,c)");
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
            //if value is not a, b, c, print error and execute a sleep function to give user time to process
            default:
                printf("error unknown value please try again");
                Sleep(1000);
        }
    }
    // start of input validation loop for X
    printf("Where would you like to put your your mark on the X-axis? (1,2,3)");
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
                Sleep(1000);
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
    // dereference the grid input pointer into x and y. These coorspond to ynum and xnum from player_input
    y = *(gridput + 0);
    x = *(gridput + 1);
    printf("Y: %d\n", y);
    printf("X: %d\n", x);
    // deinitialize pointer into varaible for 2d array "grid"
    printf("%c\n", *(p_grid[y] + x));
    if (*(p_grid[y] + x) == ' ')
    {
        if (turn == 1 || turn == 3 || turn == 5 || turn == 7 || turn == 9)
        {
            *(p_grid[y] + x) = 'x';
            turn++;
        }
        else
        {
            *(p_grid[y] + x) = 'o';
            turn++;
        }
    }
    // calls else iv grid[y][x] already contains an x or o
    else
    {
        printf("That spot is already taken\n");
    }
    return turn;
}

// define the function to test whether its a win or not at the end of mains do ... while
int win_check(char grid[3][3])
{
    int winvar;
    if(grid[0][0] == grid[0][1] && grid[0][1] == grid[0][2] && grid[0][0] != ' ' && grid[0][1] != ' ' && grid[0][2] != ' ')
        winvar = 1;
    else if(grid[1][0] == grid[1][1] && grid[1][1] == grid[1][2] && grid[1][0]  != ' ' && grid[1][1] != ' ' && grid[1][2] != ' ')
        winvar = 1;
    else if(grid[2][0] == grid[2][1] && grid[2][1] == grid[2][2] && grid[2][0] != ' ' && grid[2][1] != ' ' && grid[2][2] != ' ')
        winvar = 1;
    else if(grid[0][0] == grid[1][0] && grid[1][0] == grid[2][0] && grid[0][0] != ' ' && grid[1][0]  != ' ' && grid[2][0]  != ' ')
        winvar = 1;
    else if(grid[0][1] == grid[1][1] && grid[1][1] == grid[2][1] && grid[0][1] != ' ' && grid[1][1] != ' ' && grid[02][1] != ' ')
        winvar = 1;
    else if(grid[0][2] == grid[1][2] && grid[1][2] == grid[2][2] && grid[0][2] != ' ' && grid[1][2] != ' ' && grid[2][2] != ' ')
        winvar = 1;
    else if(grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != ' ' && grid[1][1] != ' ' && grid[2][2] != ' ')
        winvar = 1;
    else if(grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[2][0] != ' ' && grid[1][1] != ' ' && grid[2][0] != ' ')
        winvar = 1;
    // if there is no win
    else
        winvar = 0;
    return winvar;
}

/* Defintion of "main" This function should be renamed once this is turned into a library to be called in the menu file*/
char main()
{
    // define the array used to show grid and to check for winner
    char grid[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    //turn varaible
    int turns = 1;
    // win variable
    int winvar = 0;
    // create a pointer for player input array to be stored in
    int *p_gridput = NULL;
    // variable that contains the value a value that determines who won
    char whoWon;
    printf("\nIn order to play you will be promted to write two values. The first should be a letter corresponding  letter on the y-axis. Then you will type a number that corrisponds to a number on the x-axis.\n");
    do {
        // gird input to go into the validadtion function
        table_print(grid);
        printf("\n");
        // get player input for
        p_gridput = player_input();
        turns = grid_input(p_gridput, grid, turns);
        system("cls");
        winvar = win_check(grid);
        /* Check for win, change winvar to 1 to leave game loop */
    } while (winvar != 1);
    table_print(grid);
    // subtract 1 from turn because turn is increased inside the function, causing its value to be one large then it should be
    turns--;
    // print how many turns the game lasted. This is not nesscary for the function and can be delated
    printf("\nThe matach was one on turn %d", turns);
    // check to see if the winer was x or o based on the turn number. Determines what the value based on the turn number
    if (turns == 5 || turns == 7 || turns == 9)
        whoWon = 'x';
    else
        whoWon = 'o';
    printf("\n%c Won!", whoWon);
    // returns the winner. This means main must return a char. Do not change unless whoWon and mains data type match.
    return whoWon;
}
