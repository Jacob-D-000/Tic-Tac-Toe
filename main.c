#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <sys/types.h>
#include <unistd.h>

  //int w = 119;
  //int s = 115;
int main()
{
  int menu;
  int play = 0;
  int rules = 1;
  int exit = 2;
  int stats = 3;
  char input;

  char rulesS[255] = "Play\n-> Rules\nStats\nExit\n";
  char exitS[255] = "Play\nRules\nStats\n-> Exit\n";
  char playS[255] = "-> Play\nRules\nStats\nExit\n";
  char statsS[255] = "Play\nRules\n-> Stats\nExit\n";
  menu = play;
  printf("||-----TIK TAC TOE-----||\n\n");
  printf("||---------MENU--------||\n");
  printf("|-print w to go up and s to go down and enter to use options and confirm input-|\n\n");
  printf("%s",playS);
  do
  {
      input = menuInput(input);
      switch(input)
      {
      case 'w':
        system("cls");
        printf("||-----TIK TAC TOE-----||\n\n");
        printf("||---------MENU--------||\n");
        printf("|-print w to go up and s to go down and enter to use options and confirm input-|\n\n");
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
        system("cls");
        printf("||-----TIK TAC TOE-----||\n\n");
        printf("||---------MENU--------||\n");
        printf("|-print w to go up and s to go down and enter to use options and confirm input-|\n\n");
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
        system("cls");
        printf("||-----TIK TAC TOE-----||\n\n");
        printf("||---------MENU--------||\n");
        printf("!!---it didnt work---!!\n");
        printf("|-print w to go up and s to go down and enter to use options and confirm input-|\n\n");
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
    system("cls");
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
        showstsminue();
    }
}

struct stats
{
    // get info from win prog
    int winPvar;
    int winBvar;
    int winX;
    int winO;
    char playerName[255];
    char Pchar;
    int winPVP;
} s1;

int showstsminue()
{
    int menuS;
    int Xs = 0;
    int Os = 1;
    int User = 2;
    int back = 3;
    char inputS;

    int X = 0;
    int O = 1;

    char XS[255] = "-> X\nO\n\nChange Usename\nBack to menu\n";
    char OS[255] = "X\n-> O\n\nChange Usename\nBack to menu\n";
    char UserS[255] = "X\nO\n\n-> Change Usename\nBack to menu\n";
    char backS[255] = "X\nO\n\nChange Usename\n-> Back to menu\n";

    printf("||-----TIK TAC TOE-----||\n\n");
    printf("||---------STATS--------||\n");
    printf("||--Look at over all Stats\n");
    printf("|-print w to go up and s to go down and enter to use options and confirm input-|\n");
    printf("press enter on X or O to play as that character and Change Name to change your Username\n\n");

    menuS = Xs;
    showsts(s1);
    printf("%s", XS);

    do
  {
      inputS = menuInput(inputS);
      switch(inputS)
      {
      case 'w':
        system("cls");
        printf("||-----TIK TAC TOE-----||\n\n");
        printf("||---------STATS--------||\n");
        printf("||--Look at over all Stats\n");
        printf("|-print w to go up and s to go down and enter to use options and confirm input-|\n");
        printf("press enter on X or O to play as that character and Change Name to change your Username\n\n");
        showsts();
        if (menuS == Xs)
        {
            menuS = back;
            printf("%s", backS);
        }
        else if (menuS == back)
        {
            menuS = User;
            printf("%s", UserS);
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
        break;

      case 's':
        system("cls");
        printf("||-----TIK TAC TOE-----||\n\n");
        printf("||---------STATS--------||\n");
        printf("||--Look at over all Stats\n");
        printf("|-print w to go up and s to go down and enter to use options and confirm input-|\n");
        printf("press enter on X or O to play as that character and Change Name to change your Username\n\n");
        showsts(s1);
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
            menuS = back;
            printf("%s", backS);
        }
        else if (menuS == back)
        {
            menuS = Xs;
            printf("%s", XS);
        }
        break;

      default:
        system("cls");
        printf("||-----TIK TAC TOE-----||\n\n");
        printf("||---------STATS--------||\n");
        printf("||--Look at over all Stats\n");
        printf("|-print w to go up and s to go down and enter to use options and confirm input-|\n");
        printf("press enter on X or O to play as that character and Change Name to change your Username\n\n");
        showsts(s1);
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
        break;
      }
  }while (inputS != 13);

  if (menuS == Xs)
  {
      fflush(stdin);
      s1.Pchar = 'X';
      system("cls");
      showstsminue();
  }
  else if (menuS == Os)
  {
      fflush(stdin);
      s1.Pchar = 'O';
      system("cls");
      showstsminue();
  }
  else if (menuS == back)
  {
      system("cls");
      main();
  }
  else if (menuS == User)
  {
      getname();
      system("cls");
      showstsminue();
  }

}

void showsts()
{
    printf("  You are: %s\n", s1.playerName);
    printf("  you are playing as %c\n\n", s1.Pchar);

    printf("  Player wins: %d\n", s1.winPvar);
    printf("  Bot wins: %d\n", s1.winBvar);

    printf("  X wins: %d\n", s1.winX);
    printf("  O wins: %d\n", s1.winO);

    printf("  PvP wins: %d\n\n", s1.winPVP);
    return 0;
}

int getname()
{
    char input;
    printf("type your name:");

    fflush(stdin);
    s1.playerName[255];
    gets(s1.playerName);
    return s1.playerName;
}

int FPorE()
{
  int menu2;
  int PvE = 0;
  int PvP = 1;

  char PvES[255] = "-> PvE\nPvP\n";
  char PvPS[255] = "PvE\n-> PvP\n";

  char input2;

  menu2 = PvE;
  printf("||-----TIK TAC TOE-----||\n\n");
  printf("||----Play Options-----||\n");
  printf("|-print w to go up and s to go down and enter to use options and confirm input-|\n");
  printf("||--what mode do you want--||\n\n");
  printf("%s",PvES);

    do
      {
      input2 = menuInput(input2);
      switch(input2)
      {
      case 'w':
        system("cls");
        printf("||-----TIK TAC TOE-----||\n\n");
        printf("||----Play Options-----||\n");
        printf("|-print w to go up and s to go down and enter to use options and confirm input-|\n");
        printf("||--what mode do you want--||\n\n");
        if (menu2 == PvE)
        {
            menu2 = PvP;
            printf("%s", PvPS);
        }
        else if (menu2 == PvP)
        {
            menu2 = PvE;
            printf("%s", PvES);
        }
        break;

      case 's':
        system("cls");
        printf("||-----TIK TAC TOE-----||\n\n");
        printf("||----Play Options-----||\n");
        printf("|-print w to go up and s to go down and enter to use options and confirm input-|\n");
        printf("||--what mode do you want--||\n\n");
        if (menu2 == PvE)
        {
            menu2 = PvP;
            printf("%s", PvPS);
        }
        else if (menu2 == PvP)
        {
            menu2 = PvE;
            printf("%s", PvES);
        }
        break;

      default:
        system("cls");
        printf("||-----TIK TAC TOE-----||\n\n");
        printf("||----Play Options-----||\n");
        printf("!!---it didnt work---!!\n");
        printf("|-print w to go up and s to go down and enter to use options and confirm input-|\n");
        printf("||--what mode do you want--||\n\n");
        if (menu2 == PvE)
        {
            printf("%s", PvES);
        }
        else if (menu2 == PvP)
        {
            printf("%s", PvPS);
        }
        break;
      }
  }while (input2 != 13);
  system("cls");

}

int FRules()
{
  do
  {
   printf("1. The game is played on a grid that's 3 squares by 3 squares.\n2. You are X, your friend (or the computer) is O. Players take turns putting their marks in empty squares.\n3. The first player to get 3 of there marks in a row (up, down, across, or diagonally) is the winner.\n4. When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie.\n ||--press enter to go beck to menu--||\n");
  }while (!getch());
  system("cls");
  main();
}

int BotSeting()
{
  int menu3;
  int Easy = 0;
  int Medium = 1;
  int Hard = 2;

  char EasyS[255] = "||--Easy: Good for beginners to learn the basics of the game--||\n\n-> Easy\nMedium\nHard\n";
  char MediumS[255] = "||--Medium: A fun chalenge--||\n\nEasy\n-> Medium\nHard\n";
  char HardS[255] = "||--Hard: The most challenging. Face Me MORTAL--||\n\nEasy\nMedium\n-> Hard\n";

  char input3;

  int dif;
  menu3 = Easy;
  printf("||-----TIK TAC TOE-----||\n\n");
  printf("||----Bot Diffculty-----||\n");
  printf("|-print w to go up and s to go down and enter to use options and confirm input-|\n");
  printf("%s",EasyS);

    do
      {
      input3 = menuInput(input3);

      switch(input3)
      {
      case 'w':
        system("cls");
        printf("||-----TIK TAC TOE-----||\n\n");
        printf("||----Bot Difficlty-----||\n");
        printf("|-print w to go up and s to go down and enter to use options and confirm input-|\n");
        if (menu3 == Easy)
        {
            menu3 = Hard;
            printf("%s", HardS);
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
        break;

      case 's':
        system("cls");
        printf("||-----TIK TAC TOE-----||\n\n");
        printf("||----Bot Difficlty-----||\n");
        printf("|-print w to go up and s to go down and enter to use options and confirm input-|\n");
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
            menu3 = Easy;
            printf("%s", EasyS);
        }
        break;

      default:
        system("cls");
        printf("||-----TIK TAC TOE-----||\n\n");
        printf("||----Bot Difficlty-----||\n");
        printf("!!---it didnt work---!!\n");
        printf("|-print w to go up and s to go down and enter to use options and confirm input-|\n");
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
        break;
      }
  }while (input3 != 13);
  system("cls");
  printf("set dif");
}

int FPvP()
{
  printf("End of Program\n");
}

int menuInput()
{
    char input;

    fflush(stdin);
    input = getch();
    if (input == '\n')
    {
        system("cls");
    }
    return input;
}
