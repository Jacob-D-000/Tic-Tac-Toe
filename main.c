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

  char playS[255] = "[Play]\nRules\nExit\n";
  char rulesS[255] = "Play\n[Rules]\nExit\n";
  char exitS[255] = "Play\nRules\n[Exit]\n";
  menu = play;
  printf("print w to go up and s to go down and enter to use options and confirm input\n");
  printf("%s",playS);
  printf("input here:");
  do
  {
      fflush(stdin);
      input = getch();
      if (input == w)
      {
        printf("i see");
        editmenu = 'w';
      }
      else if (input == s)
      {
        printf("i see");
        editmenu = 's';
      }
      else if (input == '\n')
      {
          system("cls");
      }
      else
      {
        printf("not good");
        editmenu = ' ';
      }

      switch(editmenu)
      {
      case 'w':
        system("cls");
        printf("print w to go up and s to go down and enter to use options and confirm input\n");
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
        printf("input here:");
        break;

      case 's':
        system("cls");
        printf("print w to go up and s to go down and enter to use options and confirm input\n");
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
        printf("input here:");
        break;

      default:
        system("cls");
        printf("it didnt work\n");
        printf("print w to go up and s to go down and enter to use options and confirm input\n");
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
        printf("input here:");
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
  printf("what mode do you want");
  int w = 119;
  int s = 115;

  int menu2;
  int PvE = 0;
  int PvP = 1;

  char PvES[255] = "[PvE]\nPvP\n";
  char PvPS[255] = "PvE\n[PvP]\n";

  char input2;

  char editmenu2;

  char up = 'w';
  char dow = 's';
  char run = '\n';

  menu2 = PvE;
  printf("print w to go up and s to go down and enter to use options and confirm input\n");
  printf("%s",PvES);
  printf("input here:");

    do
      {
      fflush(stdin);
      input2 = getch();
      if (input2 == w)
      {
        printf("i see");
        editmenu2 = 'w';
      }
      else if (input2 == s)
      {
        printf("i see");
        editmenu2 = 's';
      }
      else if (input2 == '\n')
      {
          system("cls");
      }
      else
      {
        printf("not good");
        editmenu2 = ' ';
      }

      switch(editmenu2)
      {
      case 'w':
        system("cls");
        printf("print w to go up and s to go down and enter to use options and confirm input\n");
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
        printf("input here:");
        break;

      case 's':
        system("cls");
        printf("print w to go up and s to go down and enter to use options and confirm input\n");
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
        printf("input here:");
        break;

      default:
        system("cls");
        printf("it didnt work\n");
        printf("print w to go up and s to go down and enter to use options and confirm input\n");
        if (menu2 == PvE)
        {
            printf("%s", PvES);
        }
        else if (menu2 == PvP)
        {
            printf("%s", PvPS);
        }
        printf("input here:");
        break;
      }
  }while (input2 != 13);

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
    printf("no rules yet L\n press enter to go beck to menu\n");
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
