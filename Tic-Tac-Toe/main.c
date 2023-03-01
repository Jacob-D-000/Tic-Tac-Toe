#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "ai.h"
#include "game.h"


    //ASCII codes
    //Enter Key = 13
    //w = 119
    //s = 115

    /*
       note that functions Main, showstsmenu, FporE, and BotSettings use the same switch formating but
       with different Arrays and values to show different outputs and get new inputs.
       (the main commits can be used to explain the listed functions)
    */
int BotSetting();

struct stats
{
    // get info for values for all int from win program
    // char values are changed in current program and sent to other programs
    int winPvar;
    int winBvar;
    int winX;
    int winO;
    int Tie;
    char player1Name[255];
    char player2Name[255];
    char Pchar;
    int Player1W;
    int Player2W;

} s1;

void showsts()
{
    //called in showstsmenu
    //prints all stats and player name and if they are X or O
    printf("  You are: %s\n", s1.player1Name);
    printf("  Player 2 is: %s\n", s1.player2Name);
    printf("  you are playing as %c\n\n", s1.Pchar);

    printf("  Player wins: %d\n", s1.winPvar);
    printf("  Bot wins: %d\n", s1.winBvar);

    printf("  X wins: %d\n", s1.winX);
    printf("  O wins: %d\n", s1.winO);
    printf("  Tie games: %d\n", s1.Tie);

    printf("  %s wins: %d\n\n", s1.player1Name, s1.Player1W);
    printf("  %s wins: %d\n\n", s1.player2Name, s1.Player2W);
}

int menuInput()
{
    //get user input and return value to function that it was called from
    char input;

    fflush(stdin);
    input = getch();
    if (input == '\n')
    {
        screenClear();
    }
    return input;
}

//int
char* getname1()
{
    //called if user enters change User name in showstsminue
    //changes playerName value in struct using user input for user 1
    printf("type your name:");

    fflush(stdin);
    // s1.player1Name[255];
    gets(s1.player1Name);
    return s1.player1Name;
}

//int
char* getname2()
{
    //called if user enters change User name in showstsminue
    //changes playerName value in struct using user input for user 2
    printf("type your name:");

    fflush(stdin);
    //s1.player2Name[255];
    gets(s1.player2Name);
    return s1.player2Name;
}

// function to determine how to add x or o into player struct
void main_win_check(char winsts, char PE)
{
    screenClear();
    /* PVP win check */
    if (PE == 1)
    {
        if (winsts == 'x')
        {
            s1.winX++;
            if (s1.Pchar == 'X')
            {
                s1.Player1W++;
            }
            else
                s1.Player2W++;
        }
        else if (winsts == 'o')
        {
            s1.winO++;
            if (s1.Pchar == 'O')
            {
                s1.Player1W++;
            }
            else
                s1.Player2W++;
        }
        else if (winsts == 't')
        {
            s1.Tie++;
        }

    }
    /* PvE Win check "Player vs AI" */
    else
    {
        if (winsts == 'x')
        {
            s1.winX++;
            if (s1.Pchar == 'X' || (s1.Pchar != 'X' || s1.Pchar != 'O') )
            {
                s1.winPvar++;
            }
            else
                s1.winBvar++;
        }
        else if (winsts == 'o')
        {
            s1.winO++;
            if (s1.Pchar == 'O')
            {
                s1.winPvar++;
            }
            else
                s1.winBvar++;
        }
        else if (winsts == 't')
        {
            s1.Tie++;
        }
    }
}
void printstsmenu() {
    printf("||-----TIK TAC TOE-----||\n\n");
    printf("||---------STATS--------||\n");
    printf("||----View all Stats----||\n");
    printf("Print w to go up and s to go down and enter to use options and confirm input\n");
    printf("Press enter on X or O to play as that character and Change Name to change your Username\n\n");
}

void showstsmenu()
{
    int menuS;
    int Xs = 0;
    int Os = 1;
    int User = 2;
    int User2 = 3;
    int back = 4;
    char inputS;

    char XS[255] = "-> X\nO\n\nChange Username P1\nChange Username P2\nBack to menu\n";
    char OS[255] = "X\n-> O\n\nChange Username P1\nChange Username P2\nBack to menu\n";
    char UserS[255] = "X\nO\n\n-> Change Username P1\nChange Username P2\nBack to menu\n";
    char backS[255] = "X\nO\n\nChange Username P1\nChange Username P2\n-> Back to menu\n";
    char User2S[255] = "X\nO\n\nChange Username P1\n->  Change Username P2\nBack to menu\n";

    printstsmenu();

    menuS = Xs;
    showsts();
    printf("%s", XS);

    do
    {
        inputS = menuInput();
        switch(inputS)
        {
          case 'w':
            screenClear();
            printstsmenu();
            showsts();
            if (menuS == Xs)
            {
                menuS = back;
                printf("%s", backS);
            }
            else if (menuS == back)
            {
                menuS = User2;
                printf("%s", User2S);
            }
            else if (menuS == User)
            {
                menuS = Os;
                printf("%s", OS);
            }
            else if (menuS == Os)
            {
                menuS = Xs;
                printf("%s", XS);
            }
            else if (menuS == User2)
            {
                menuS = User;
                printf("%s", UserS);
            }
            break;

          case 's':
            screenClear();
            printstsmenu();
            showsts();
            if (menuS == Xs)
            {
                menuS = Os;
                printf("%s", OS);
            }
            else if (menuS == Os)
            {
                menuS = User;
                printf("%s", UserS);
            }
            else if (menuS == User)
            {
                menuS = User2;
                printf("%s", User2S);
            }
            else if (menuS == back)
            {
                menuS = Xs;
                printf("%s", XS);
            }
            else if (menuS == User2)
            {
                menuS = back;
                printf("%s", backS);
            }
            break;

          default:
            screenClear();
            printstsmenu();
            showsts();
            if (menuS == Xs)
            {
                printf("%s", XS);
            }
            else if (menuS == Os)
            {
                printf("%s", OS);
            }
            else if (menuS == User)
            {
                printf("%s", UserS);
            }
            else if (menuS == back)
            {
                printf("%s", backS);
            }
            else if (menuS == User2)
            {
                printf("%s", User2S);
            }
            break;
          }
      }while (inputS != 13);

  if (menuS == Xs)
  {
      //change struct Pchar value to X
      fflush(stdin);
      s1.Pchar = 'X';
      screenClear();
      showstsmenu();
  }
  else if (menuS == Os)
  {
      //change struct Pchar value to O
      fflush(stdin);
      s1.Pchar = 'O';
      screenClear();
      showstsmenu();
  }
  else if (menuS == back)
  {
      screenClear();
      main();
  }
  else if (menuS == User)
  {
      getname1();
      screenClear();
      showstsmenu();
  }
  else if (menuS == User2)
  {
      getname2();
      screenClear();
      showstsmenu();
  }

}

void printFPorEmenu() {
    printf("||-----TIK TAC TOE-----||\n\n");
    printf("||----Play Options-----||\n");
    printf("||---SELECT YOUR MODE--||\n");
    printf("||-print w to go up and s to go down and enter to use options and confirm input-|\n");
}


void FPorE()
{
  int menu2;
  int PvE = 0;
  int PvP = 1;
  int back = 2;
  // variable is returned to determine whether X or O won
  char winnerchar;

  char PvES[255] = "-> PvE\nPvP\nBack\n";
  char PvPS[255] = "PvE\n-> PvP\nBack\n";
  char BackS[255] = "PvE\nPvP\n-> Back\n";

  char input2;

  menu2 = PvE;
  printFPorEmenu();
  printf("%s",PvES);

    do
      {
      input2 = menuInput();
      switch(input2)
      {
      case 'w':
        screenClear();
        printFPorEmenu();
        if (menu2 == PvE)
        {
            menu2 = back;
            printf("%s", BackS);
        }
        else if (menu2 == PvP)
        {
            menu2 = PvE;
            printf("%s", PvES);
        }
        else if (menu2 == back)
        {
            menu2 = PvP;
            printf("%s", PvPS);
        }
        break;

      case 's':
        screenClear();
        printFPorEmenu();
        if (menu2 == PvE)
        {
            menu2 = PvP;
            printf("%s", PvPS);
        }
        else if (menu2 == PvP)
        {
            menu2 = back;
            printf("%s", BackS);
        }
        else if (menu2 == back)
        {
            menu2 = PvE;
            printf("%s", PvES);
        }
        break;

      default:
        screenClear();
        printFPorEmenu();
        printf("!!---it didn't work---!!\n");
        if (menu2 == PvE)
        {
            printf("%s", PvES);
        }
        else if (menu2 == PvP)
        {
            printf("%s", PvPS);
        }
        else if (menu2 == back)
        {
            printf("%s", BackS);
        }
        break;
      }
  }while (input2 != 13);
  screenClear();

    if (menu2 == PvE)
    {
        int dif = BotSetting();
        winnerchar = game_func(s1.player1Name, s1.player2Name, s1.Pchar, dif);
        main_win_check(winnerchar, menu2);
        main();
    }
    else if (menu2 == PvP)
    {
      //run game program using PvP option
      winnerchar = game_func(s1.player1Name, s1.player2Name, s1.Pchar, 0);
      main_win_check(winnerchar, menu2);
      main();
    }
    else if (menu2 == back)
    {
        main();
    }

}

void FRules()
{
 //display game rules, if user press any key it will clear screen and run main
  do
  {
   printf("1. The game is played on a grid that's 3 squares by 3 squares.\n2. You are X, your friend (or the computer) is O. Players take turns putting their marks in empty squares.\n3. The first player to get 3 of there marks in a row (up, down, across, or diagonally) is the winner.\n4. When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie.\n ||--press enter to go back to menu--||\n");
  }while (!getch());
  screenClear();
  main();
}

void printBotSettingmenu() {
    printf("||-----TIK TAC TOE-----||\n\n");
    printf("||----Bot Difficulty-----||\n");
    printf("|-print w to go up and s to go down and enter to use options and confirm input-|\n");
}

int BotSetting()
{
  int menu3;
  /* Note that the difficulty settings for the bot are 0 for off, 1 for easy , 2 for medium, 3 for Hard */
  int Easy = 0;
  int Medium = 1;
  int Hard = 2;
  int back = 3;

  char EasyS[255] = "||--Easy: Good for beginners to learn the basics of the game--||\n\n-> Easy\nMedium\nHard\nBack\n";
  char MediumS[255] = "||--Medium: A fun challenge--||\n\nEasy\n-> Medium\nHard\nBack\n";
  char HardS[255] = "||--Hard: The most challenging. Face Me MORTAL--||\n\nEasy\nMedium\n-> Hard\nBack\n";
  char BackS[255] = "\nEasy\nMedium\nHard\n-> Back\n";

  char input3;

  int dif;
  menu3 = Easy;
  printBotSettingmenu();
  printf("%s",EasyS);

    do
      {
      input3 = menuInput();

      switch(input3)
      {
      case 'w':
        screenClear();
        printBotSettingmenu();
        if (menu3 == Easy)
        {
            menu3 = back;
            printf("%s", BackS);
        }
        else if (menu3 == Hard)
        {
            menu3 = Medium;
            printf("%s", MediumS);
        }
        else if (menu3 == Medium)
        {
            menu3 = Easy;
            printf("%s", EasyS);
        }
        else if (menu3 == back)
        {
            menu3 = Hard;
            printf("%s", HardS);
        }
        break;

      case 's':
        screenClear();
        printBotSettingmenu();
        if (menu3 == Easy)
        {
            menu3 = Medium;
            printf("%s", MediumS);
        }
        else if (menu3 == Medium)
        {
            menu3 = Hard;
            printf("%s", HardS);
        }
        else if (menu3 == Hard)
        {
            menu3 = back;
            printf("%s", BackS);
        }
        else if (menu3 == back)
        {
            menu3 = Easy;
            printf("%s", EasyS);
        }
        break;

      default:
        screenClear();
        printBotSettingmenu();
        printf("!!---it didn't work---!!\n");
        if (menu3 == Easy)
        {
            printf("%s", EasyS);
        }
        else if (menu3 == Medium)
        {
            printf("%s", MediumS);
        }
        else if (menu3 == Hard)
        {
            printf("%s", HardS);
        }
        else if (menu3 == back)
        {
            printf("%s", BackS);
        }
        break;
      }
  }while (input3 != 13);
  screenClear();
  //run bot and game program using dif value to determine bot difficulty

  if (menu3 == Easy)
  {
      dif = 1;
      //printf("Bot level %d", dif);
      return dif;
  }
  else if (menu3 == Medium)
  {
      dif = 2;
      //printf("Bot level %d", dif);
      return dif;
  }
  else if (menu3 == Hard)
  {
      dif = 3;
      //printf("Bot level %d", dif);
      return dif;
  }
  else if (menu3 == back)
  {
      FPorE();
      return 0;
  }
}

void printmainmenu() {
    printf("||-----TIK TAC TOE-----||\n\n");
    printf("||---------MENU--------||\n");
    printf("|-print w to go up and s to go down and enter to use options and confirm input-|\n\n");
}
int main()
{
    //values for menu options and user input
    int menu;
    int play = 0;
    int rules = 1;
    int exit = 2;
    int stats = 3;
    char input;

    //Array and text for each main menu screen and input directions
    char rulesS[255] = "Play\n-> Rules\nStats\nExit\n";
    char exitS[255] = "Play\nRules\nStats\n-> Exit\n";
    char playS[255] = "-> Play\nRules\nStats\nExit\n";
    char statsS[255] = "Play\nRules\n-> Stats\nExit\n";
    menu = play;
    printmainmenu();
    printf("%s",playS);
    do
    {
        //calls user input Function then put input in switch
        input = menuInput();
        switch(input)
        {
            /*
             Case W: if user press w cycle through Arrays going up based on current displayed Array
             Case S: if user press s cycle through Arrays going down based on current displayed Array
             for each input set menu value equal to current Array name

             For improper input clear screen and print current Array and show error

             If user press enter run function related to the menu value
            */

        case 'w':
            screenClear();
            printmainmenu();
            if (menu == play)
            {
                menu = exit;
                printf("%s", exitS);
            }
            else if (menu == rules)
            {
                menu = play;
                printf("%s", playS);
            }
            else if (menu == exit)
            {
                menu = stats;
                printf("%s", statsS);
            }
            else if (menu == stats)
            {
                menu = rules;
                printf("%s", rulesS);
            }
            break;

          case 's':
            screenClear();
            printmainmenu();
            if (menu == play)
            {
                menu = rules;
                printf("%s", rulesS);
            }
            else if (menu == rules)
            {
                menu = stats;
                printf("%s", statsS);
            }
            else if (menu == exit)
            {
                menu = play;
                printf("%s", playS);
            }
            else if (menu == stats)
            {
                menu = exit;
                printf("%s", exitS);
            }
            break;

          default:
            screenClear();
            printmainmenu();
            printf("!!---it didnt work---!!\n");
            if (menu == play)
            {
                printf("%s", playS);
            }
            else if (menu == rules)
            {
                printf("%s", rulesS);
            }
            else if (menu == exit)
            {
                printf("%s", exitS);
            }
            else if (menu == stats)
            {
                printf("%s", statsS);
            }
            break;
          }
      }while (input != 13);
        screenClear();
        if (menu == play)
        {
            FPorE();
        }
        else if (menu == rules)
        {
            FRules();
        }
        else if (menu == stats)
        {
            showstsmenu();
        }
}
