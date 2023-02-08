#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
  int w = 119;
  int s = 115;

  int menu;
  int play = 0;
  int rules = 1;
  int exit = 2;
  char input;

  char editmenu;

  char up = 'w';
  char dow = 's';
  char run = '\n';

  char rulesS[255] = "Play\n-> Rules\nExit\n";
  char exitS[255] = "Play\nRules\n-> Exit\n";
  char playS[255] = "-> Play\nRules\nExit\n";
  menu = play;
  printf("||-----TIK TAC TOE-----||\n\n");
  printf("||---------MENU--------||\n");
  printf("|-print w to go up and s to go down and enter to use options and confirm input-|\n\n");
  printf("%s",playS);
  do

  {
      fflush(stdin);
      input = getch();
      if (input == w)
      {
        editmenu = 'w';
      }
      else if (input == s)
      {
        editmenu = 's';
      }
      else if (input == '\n')
      {
          system("cls");
      }
      else
      {
        editmenu = ' ';
      }

      switch(editmenu)
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
            menu = exit;
            printf("%s", exitS);
        }
        else if (menu == exit)
        {
            menu = play;
            printf("%s", playS);
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
}

int FPorE()
{
  int w = 119;
  int s = 115;

  int menu2;
  int PvE = 0;
  int PvP = 1;

  char PvES[255] = "-> PvE\nPvP\n";
  char PvPS[255] = "PvE\n-> PvP\n";

  char input2;

  char editmenu2;

  char up = 'w';
  char dow = 's';
  char run = '\n';

  menu2 = PvE;
  printf("||-----TIK TAC TOE-----||\n\n");
  printf("||----Play Options-----||\n");
  printf("|-print w to go up and s to go down and enter to use options and confirm input-|\n");
  printf("||--what mode do you want--||\n\n");
  printf("%s",PvES);

    do
      {
      fflush(stdin);
      input2 = getch();
      if (input2 == w)
      {
        editmenu2 = 'w';
      }
      else if (input2 == s)
      {
        editmenu2 = 's';
      }
      else if (input2 == '\n')
      {
          system("cls");
      }
      else
      {
        editmenu2 = ' ';
      }

      switch(editmenu2)
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
  if (menu2 == PvE)
  {
      FPvE();
  }
  else if (menu2 == PvP)
  {
      FPvP();
  }
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

int FPvE()
{
    printf("L you are a bot");
}

int FPvP()
{
    printf("L no homies");
}
