#include <stdio.h>
#include <stdlib.h>
/*

Reference List for Grid Positions and the actual grid locaitons for them. Starting from top left ([0][0]) reading to the right to bottom right ([2][2])
Sides: [0][1],[1][0],[1][2],[2][1]
Middle: [1][1]
Corners: [0][0],[0][2],[2][0],[2][2]

AI Breakdown in Words

Step 1 | Recieves the following information from game.h from game_func (FunctionCall ->  p_gridput = ai_turn(dif,AIchar,turns,grid);)
    - Difficulty                | (dif in game.h)   | difficulty in ai.h
    - What Mark it is           | (AIchar in game.h)| mark in ai.h
    - The current turn count    | (turns in game.h) | turnCount in ai.h
    - Board State               | (grid in game.h)  | board in ai.h

Step 2 | Determines if it can make a winning move on its turn
        IF ANY of the following conditions are met the AI returns the cordinates for the empty spot to function game_func in game.h, stored into p_gridput

    2.1| Loops through each row, IF any row contains 2 of its own mark AND an empty spot
    2.2| Loops through each column, checking if any column contains 2 of its own mark AND an empty spot
    2.3| IF two of the following, board[0][0], board[1][1], board[2][2] are equal to AIchar and 1 is equal to ' '. Return the cordinates for the empty spot (Checking Diagonally Top Left to Bottom Right)
    2.4| IF two of the following, board[0][2], board[1][1], board[2][0] are equal to AIchar and 1 is equal to ' '. Return the cordinates for the empty spot (Checking Diagonally Top Right to Bottom Left)

    If none of these checks succeed, proceed to step 3

Step 3. Determines if the enemy player will win on their next move if they dont stop it. HOWEVER, if the difficulty is set to EASY (difficulty = 1), then it proceededs to the next step

    3.1| Check IF difficulty = 1, IF TRUE: Move to Step 4, ELSE: Continue Step 3
    3.2| Loops through each row, IF any row contains 2 of its own mark AND an empty spot
    3.3| Loops through each column, checking if any column contains 2 of its own mark AND an empty spot
    3.4| IF two of the following, board[0][0], board[1][1], board[2][2] are equal to AIchar and 1 is equal to ' '. Return the cordinates for the empty spot (Checking Diagonally Top Left to Bottom Right)
    3.5| IF two of the following, board[0][2], board[1][1], board[2][0] are equal to AIchar and 1 is equal to ' '. Return the cordinates for the empty spot (Checking Diagonally Top Right to Bottom Left)

Step 4. Pick randomly from a list from the perfered choice of cordinates

Easy AI Priority - Sides | Medium AI Priority - Middle | Hard AI Priority -Corner

Step 5. Return chosen cordinates to game_func

Horizontal Checks
(board[row][0] = mark) && (board[row][1] = mark) && (board[row][2] = ' ')
(board[row][0] = mark) && (board[row][1] = ' ') && (board[row][2] = mark)
(board[row][0] = ' ') && (board[row][1] = mark) && (board[row][2] = mark)

Vertical Checks
(board[0][col] = mark) && (board[1][col] = mark) && (board[2][col] = ' ')
(board[0][col] = mark) && (board[1][col] = ' ') && (board[2][col] = mark)
(board[0][col] = ' ') && (board[1][col] = mark) && (board[2][col] = mark)
*/

/* Just a fun funciton, used to show that the program is still running while the AI is making its decisions */
void Sleep();
void scheming()
{
    printf("\n Plotting your Demise");
    for (int plotting = 0; plotting < 3; plotting++)
    {
        Sleep(200);
        printf(".");
    }
    printf("\n");
}

int * ai_turn(int difficulty, char mark, char enemyMark, int turnCount, char board[3][3] )
{
    int row = 0;
    int col = 0;
    int randomNumber;
    int sides[4][2] = {{0,1},{1,0},{1,2},{2,1}};
    int corners[4][2] = {{0,0},{0,2},{2,0},{2,2}};
    /* Translating uppercase ASCII to lowercase equivlent*/
    mark = tolower(mark);
    enemyMark = tolower(enemyMark);
    static int aiMove[2] = {0,0};

    /* Check Row for Wins */
    for (row = 0; row < 3; row++)
    {
        /* IF/ELSE structure for each combination that leads to a win in 1 move */
        if (board[row][0] == mark && board[row][1] == mark && board[row][2] == ' ' )
        {
            aiMove[1] = 2;
            aiMove[0] = row;
            return aiMove;
        }
        else if (board[row][0] == mark && board[row][1] == ' ' && board[row][2] == mark  )
        {
            aiMove[1] = 1;
            aiMove[0] = row;
            return aiMove;
        }
        else if (board[row][0] == ' ' && board[row][1] == mark && board[row][2] == mark )
        {
            aiMove[1] = 0;
            aiMove[0] = row;
            return aiMove;
        }
    }

    /* Check Columns for Wins */
    for (col = 0; col < 3; col++)
    {
        /* IF/ELSE structure for each combination that leads to a win in 1 move */
        if (board[0][col] == mark && board[1][col] == mark && board[2][col] == ' ' )
        {
            aiMove[1] = col;
            aiMove[0] = 2;
            return aiMove;
        }
        else if (board[0][col] == mark && board[1][col] == ' ' && board[2][col] == mark  )
        {
            aiMove[1] = col;
            aiMove[0] = 1;
            return aiMove;
        }
        else if (board[0][col] == ' ' && board[1][col] == mark && board[2][col] == mark )
        {
            aiMove[1] = col;
            aiMove[0] = 0;
            return aiMove;
        }

    }

    /* Checking Top Left to Bottom Right diagonal */
    if (board[0][0] == mark && board[1][1] == mark && board[2][2] == ' ')
    {
        aiMove[1] = 2;
        aiMove[0] = 2;
        return aiMove;
    }
    else if (board[0][0] == mark && board[1][1] == ' ' && board[2][2] == mark)
    {
        aiMove[1] = 1;
        aiMove[0] = 1;
        return aiMove;
    }
    else if (board[0][0] == ' ' && board[1][1] == mark && board[2][2] == mark)
    {
        aiMove[1] = 0;
        aiMove[0] = 0;
        return aiMove;
    }

    /* Checking Top Right to Bottom Left diagonal */
    if (board[2][0] == mark && board[1][1] == mark && board[0][2] == ' ')
    {
        aiMove[1] = 2;
        aiMove[0] = 0;
        return aiMove;
    }
    else if (board[2][0] == mark && board[1][1] == ' ' && board[0][2] == mark)
    {
        aiMove[1] = 1;
        aiMove[0] = 1;
        return aiMove;
    }
    else if (board[2][0] == ' ' && board[1][1] == mark && board[0][2] == mark)
    {
        aiMove[1] = 0;
        aiMove[0] = 2;
        return aiMove;
    }

    scheming();

    /* LOSE CHECKING */

    /* If on EASY, skip checking for opponents wins*/
    if (difficulty != 1)
    {
            /* Check Row for Enemy Wins */
        for (row = 0; row < 3; row++)
        {
            /* IF/ELSE structure for each combination that leads to the enemy winning in 1 move */
            if ( board[row][0] == enemyMark && board[row][1] == enemyMark && board[row][2] == ' ' )
            {
                aiMove[1] = 2;
                aiMove[0] = row;
                return aiMove;
            }
            else if ( board[row][0] == enemyMark && board[row][1] == ' ' && board[row][2] == enemyMark  )
            {
                aiMove[1] = 1;
                aiMove[0] = row;
                return aiMove;
            }
            else if ( board[row][0] == ' ' && board[row][1] == enemyMark && board[row][2] == enemyMark )
            {
                aiMove[1] = 0;
                aiMove[0] = row;
                return aiMove;
            }
        }

        /* Check Columns for Wins */
        for (col = 0; col < 3; col++)
        {
            /* IF/ELSE structure for each combination that leads to a winning in 1 move */
            if ( board[0][col] == enemyMark && board[1][col] == enemyMark && board[2][col] == ' ' )
            {
                aiMove[1] = col;
                aiMove[0] = 2;
                return aiMove;
            }
            else if ( board[0][col] == enemyMark && board[1][col] == ' ' && board[2][col] == enemyMark  )
            {
                aiMove[1] = col;
                aiMove[0] = 1;
                return aiMove;
            }
            else if ( board[0][col] == ' ' && board[1][col] == enemyMark && board[2][col] == enemyMark )
            {
                aiMove[1] = col;
                aiMove[0] = 0;
                return aiMove;
            }
        }

        /* Checking Top Left to Bottom Right diagonal */
        if (board[0][0] == enemyMark && board[1][1] == enemyMark && board[2][2] == ' ')
        {
            aiMove[1] = 2;
            aiMove[0] = 2;
            return aiMove;
        }
        else if (board[0][0] == enemyMark && board[1][1] == ' ' && board[2][2] == enemyMark)
        {
            aiMove[1] = 1;
            aiMove[0] = 1;
            return aiMove;
        }
        else if (board[0][0] == ' ' && board[1][1] == enemyMark && board[2][2] == enemyMark)
        {
            aiMove[1] = 0;
            aiMove[0] = 0;
            return aiMove;
        }

        /* Checking Top Right to Bottom Left diagonal */
        if (board[2][0] == enemyMark && board[1][1] == enemyMark && board[0][2] == ' ')
        {
            aiMove[1] = 2;
            aiMove[0] = 0;
            return aiMove;
        }
        else if (board[2][0] == enemyMark && board[1][1] == ' ' && board[0][2] == enemyMark)
        {
            aiMove[1] = 1;
            aiMove[0] = 1;
            return aiMove;
        }
        else if (board[2][0] == ' ' && board[1][1] == enemyMark && board[0][2] == enemyMark)
        {
            aiMove[1] = 0;
            aiMove[0] = 2;
            return aiMove;
        }
    }


    switch(difficulty)
    {
        /* Easy and Medium use the same random number generaor, but easy doesnt check for wins*/
        case 1:
        {
            if (board[0][1] == ' ' || board[1][0] == ' ' || board[1][2] == ' ' || board [2][1] == ' ')
            {
                /* Should be changed to remove all filled sides*/
                randomNumber = rand() % 4;
                aiMove[0] = sides[randomNumber][0];
                aiMove[1] = sides[randomNumber][1];
                break;
            }
            /* Randomly pick if sides are already gone*/
        }

        case 2:
        {
            if (board[1][1] == ' ')
            {
                aiMove[0] = 1;
                aiMove[1] = 1;
                break;
            }
            /* Randomly pick if middle is already gone*/
        }

        case 3:
        {
            if (board[0][0] == ' ' || board[0][2] == ' ' || board[2][0] == ' ' || board[2][2] == ' ')
            {
                randomNumber = rand() % 4;
                aiMove[0] = corners[randomNumber][0];
                aiMove[1] = corners[randomNumber][1];
                break;
            }
            /* Randomly pick if corners are already gone, will never matter due to anti-win checks*/
        }

        /*The option selected if the difficulty's if statement evaluates to false*/
        default:
            {
                aiMove[0] = rand() % 3;
                aiMove[1] = rand() % 3;
                break;
            }
    }
    return aiMove;
}

void superDuperSecretFunction()
{
    printf("YOU SHOULDNT BE HERE - THIS SHOULD BE IMPOSSIBLE TO REACH \n");
    for (int outsideCount = 0; outsideCount < 10; outsideCount++)
    {
        int randomColorBackground;
        int randomColorText;
        int randomSleepTime;
        randomColorBackground = rand() % 16;
        randomColorText = rand() % 16;

        char scaryCommand[50];
        sprintf(scaryCommand, "color %X%X", randomColorBackground, randomColorText);
        system(scaryCommand);
        for(int runawayCount = 0; runawayCount < (rand() % 20) + 1; runawayCount++)
        {
            randomSleepTime = (((rand() % 4) + 1) * 50); /* Generates either 50, 100, 150, 200 to be used as milliseconds*/
            Sleep(randomSleepTime);
            printf("RUN ITS COMING ");
            if (runawayCount % 5 == 0)
            {
                printf("\n");
            }
        }
    }
    system("color 07");
    screenClear();
    printf("Everything is fine");
}
