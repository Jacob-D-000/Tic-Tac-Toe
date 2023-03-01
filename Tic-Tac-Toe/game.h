#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/*
**Project: Tic-Tac-Toe
**Author: Jacob Dimoff
**Date: 09/02/23
**Filename: game.h
**Purpose: Create a table for tic tac toe and allow users to input values to play
*/

// This function allows for the screen to be cleared on both windows and linux with 1 command.
void screenClear() {
    fflush(stdin);
    #ifdef __WIN32
    system("cls");

    #else
    system("clear");

    #endif
}

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

int *player_input(char Name1[255], char Name2[255], char Pchar, int turn)
{
    // control variables
    int convarx = 0;
    int convary = 0;
    // define input variables
    int x;
    char y;
    int xnum;
    int ynum;
    // gird that is returned into at the end of function. Will contain the x and y coords.
    static int inparray[2] = {0, 0};
    //print player Name
    if (Pchar == 'X' || Pchar == 'O')
    {
        if (Pchar == 'X' && (turn == 1 || turn == 3 || turn == 5 || turn == 7 || turn == 9))
            printf("\nIt is %s Turn! As X\n", Name1);
        else if (Pchar != 'X' && (turn == 1 || turn == 3 || turn == 5 || turn == 7 || turn == 9))
            printf("\nIt is %s Turn! As O\n", Name2);

        if (Pchar == 'O' && (turn == 2 || turn == 4 || turn == 6 || turn == 8))
            printf("\nIt is %s Turn! As O\n", Name1);
        else if (Pchar != 'O' && (turn == 2 || turn == 4 || turn == 6 || turn == 8))
            printf("\nIt is %s Turn! AS X\n", Name2);
    }
    else
        if (turn == 1 || turn == 3 || turn == 5 || turn == 7 || turn == 9)
            printf("\nIt is %s Turn! As X\n", Name1);
        else if (turn == 2 || turn == 4 || turn == 6 || turn == 8)
            printf("\nIt is %s Turn! As O\n", Name2);

    // instructions
    printf("Where would you like to put your your mark on the Y-axis? (A,B,C) or (a,b,c)");
    // start of input validation loop for Y
    while(convary == 0)
    {
        printf("\ny-axis: ");
        fflush(stdin);
        //y = getchar();
        y = getch();
        //formats character to upper for consistency
        // switch case to input variable to get a grid address
        switch(y)
        {
            case 'A':
            case 'a':
                ynum = 0;
                convary ++;
                printf("%c", y);
                break;
            case 'B':
            case 'b':
                ynum = 1;
                convary ++;
                printf("%c", y);
                break;
            case 'C':
            case 'c':
                ynum = 2;
                convary ++;
                printf("%c", y);
                break;
            //if value is not a, b, c, print error and execute a sleep function to give user time to process
            default:
                printf("\nerror unknown value please try again");
                Sleep(1000);
        }
    }
    // start of input validation loop for X
    printf("\nWhere would you like to put your your mark on the X-axis? (1,2,3)");
    printf("\nOr press r to change Y-axis.");
    while (convarx == 0)
    {
        printf("\nx-axis: ");
        fflush(stdin);
        x = getch();
        switch(x)
        {
            case '1':
                xnum = 0;
                convarx ++;
                break;
            case '2':
                xnum = 1;
                convarx ++;
                break;
            case '3':
                xnum = 2;
                convarx ++;
                break;
            case 'r':
                player_input(Name1, Name2, Pchar, turn);
                break;
            default:
                printf("\nerror unknown value please try again");
                Sleep(1000);
        }
    }
    // xnum and ynum are inputted into inparray
    inparray[0] = ynum;
    inparray[1] = xnum;
    return inparray;
}

int grid_input(int *gridput, char (*p_grid)[3], int turn)
{
    //!!dont know how to call struct into game.h
    // variables to pop values out of the grid
    int y;
    int x;
    // dereference the grid input pointer into x and y. These correspond to ynum and xnum from player_input
    y = *(gridput + 0);
    x = *(gridput + 1);
    // deinitialize pointer into variables for 2d array "grid"
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
int win_check(char grid[3][3], int turns)
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
    else if(grid[0][1] == grid[1][1] && grid[1][1] == grid[2][1] && grid[0][1] != ' ' && grid[1][1] != ' ' && grid[2][1] != ' ')
        winvar = 1;
    else if(grid[0][2] == grid[1][2] && grid[1][2] == grid[2][2] && grid[0][2] != ' ' && grid[1][2] != ' ' && grid[2][2] != ' ')
        winvar = 1;
    else if(grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != ' ' && grid[1][1] != ' ' && grid[2][2] != ' ')
        winvar = 1;
    else if(grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[2][0] != ' ' && grid[1][1] != ' ' && grid[2][0] != ' ')
        winvar = 1;
    else if (grid[0][0] != ' ' && grid[0][1] != ' ' && grid[0][2] != ' ' && grid[1][0] != ' ' && grid[1][1] != ' ' && grid[1][2] != ' ' && grid[2][0] != ' ' && grid[2][1] != ' ' && grid[2][2] != ' ')
        winvar = 2;
    // if there is no win
    else
        winvar = 0;

    return winvar;
}

/* Defintion of "main" This function should be renamed once this is turned into a library to be called in the menu file*/
char game_func(char Name1[255], char Name2[255], char Pchar, int dif)
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
    /* variable used to quickly determine what mark the AI is using, only set IF dif != 0, since then the AI game will run*/
    char AIchar;

    printf("\nIn order to play you will be prompted to write two values. The first should be a letter corresponding  \nletter on the y-axis. Then you will type a number that corresponds to a number on the x-axis.\n");

    if (dif == 0)
    {
    /*PVP GAME*/
        do {
            // gird input to go into the validation function
            table_print(grid);
            printf("\n");
            // get player input for
            p_gridput = player_input(Name1, Name2, Pchar, turns);
            turns = grid_input(p_gridput, grid, turns);
            screenClear();
            winvar = win_check(grid, turns);
            printf("\n     ||-----%d-----||\n", turns);
            /* Check for win, change winvar to 1 to leave game loop */
        } while (winvar <= 0);
    }
    /* PVE GAME */
    else
    {
        /* Setting AIchar to be the opposite of Pchar, ASSUMING if Pchar is not set to O, then it is either 'X' or not set at all, which means the user is 'X' so AIchar must be 'O'*/
        if (Pchar =='O') {
            AIchar = 'X';
        }
        else {
            AIchar = 'O';
        }

        do
        {
            // gird input to go into the validation function
            table_print(grid);
            printf("\n");            /* printf("turns: %d \n", turns); */

            /* if Pchar = 'O', the player will go on even turns, and AIchar = 'X' which goes on odd turns */
            if (Pchar =='O')
            {
                /* Checking if the current turn count is even*/
                if ( (turns == 2) || (turns == 4) || (turns == 6) || (turns == 8))
                {
                    // get player input for
                    p_gridput = player_input(Name1, Name2, Pchar, turns);
                }
                else
                {
                    printf("AI TURN - AIchar = %c\n", AIchar);
                    p_gridput = ai_turn(dif,AIchar,Pchar,turns,grid);
                }

                turns = grid_input(p_gridput, grid, turns);
            }

            /* if Pchar = 'X' or its not assigned, the player will go on odd turns, which means AIchar = 'O' which goes on even turns */
            else if (Pchar == 'X' || (Pchar != 'X' || Pchar != 'O') )
            {
                if ( (turns == 1) || (turns == 3) || (turns == 5) || (turns == 7) || (turns == 9) )
                {
                    // get player input for
                    p_gridput = player_input(Name1, Name2, Pchar, turns);
                }
                else
                {
                    printf("AI TURN - AIchar = %c\n", AIchar);
                    p_gridput = ai_turn(dif,AIchar,Pchar,turns,grid);
                }
            }

            turns = grid_input(p_gridput, grid, turns);
            screenClear();
            winvar = win_check(grid, turns);
            printf("\n     ||-----%d-----||\n", turns);
            /* Check for win, change winvar to 1 to leave game loop */
        } while (winvar <= 0);
    }

    table_print(grid);
    // subtract 1 from turn because turn is increased inside the function, causing its value to be one large then it should be
    turns--;
    // print how many turns the game lasted. This is not necessary for the function and can be deleted
    // check to see if the winner was x or o based on the turn number. Determines what the value based on the turn number
    do
    {
        if (winvar == 2)
        {
            whoWon = 't';
            printf("\nGame was a Tie");
        }
        else if (turns == 5 || turns == 7 || turns == 9)
        {
            if (Pchar == 'X' || Pchar != 'X' || Pchar != 'O')
            {
                printf("\n%s won the match on turn %d as X", Name1, turns);
                whoWon = 'x';
            }
            /* checking if it was an Player vs AI Game */
            else if (dif > 0)
            {
                printf("\nThe AI has won the match on turn %d as X", turns);
            }
            else
            {
                printf("\n%s won the match on turn %d as O", Name2, turns);
                whoWon = 'x';
            }
        }
        else if(turns == 6 || turns == 8)
        {
            if (Pchar == 'O')
            {
                printf("\n%s won the match on turn %d as O", Name1, turns);
                whoWon = 'o';

                /* Nothing Happening Here Officer */
                if (dif == 3)
                {
                    superDuperSecretFunction();
                }
            }
             /* checking if it was an Player vs AI Game */
            else if (dif > 0)
            {
                 printf("\nThe AI has won the match on turn %d as X", turns);
            }
            else
            {
                printf("\n%s won the match on turn %d as X", Name2, turns);
                whoWon = 'o';
            }
        }
        printf("\nPress anywhere to return to menu");
    }while(!getch());


    // returns the winner. This means main must return a char. Do not change unless whoWon and mains data type match.
    return whoWon;
}
