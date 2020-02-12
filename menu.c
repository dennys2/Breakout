#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "jogo.h"
#include "ranking.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ESC 27
#define KEY_ENTER 13

void menu()
{
    HideCursor();
    char bar = 177, lin1 = 200, lin2 = 187, lin6 = 205, lin10 = 186, lin11 = 188, lin12 = 201, esp = 255;
    int contador = 0;
    char setinha;
    //MODIFICAÇÃO
    // inicio das letras do menu
    printf("\n\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
           "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n"
           ,bar,bar,bar,bar,bar,bar,lin2,esp,bar,bar,bar,bar,bar,bar,lin2,esp,bar,bar,bar,bar,bar,bar,bar
           ,lin2,esp,bar,bar,bar,bar,bar,lin2,esp,bar,bar,lin2,esp,esp,bar,bar,lin2,esp,bar,bar,bar,bar
           ,bar,bar,bar,lin2,esp,bar,bar,lin2,esp,esp,esp,bar,bar,lin2,bar,bar,bar,bar,bar,bar,bar,bar,lin2);

    printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
           "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n"
           ,bar,bar,lin12,lin6,lin6,bar,bar,lin2,bar,bar,lin12,lin6,lin6,bar,bar,lin2,bar,bar,lin12,lin6,lin6
           ,lin6,lin6,lin11,bar,bar,lin12,lin6,lin6,bar,bar,lin2,bar,bar,lin10,esp,bar,bar,lin12,lin11,bar,bar
           ,lin12,lin6,lin6,lin6,lin6,bar,bar,lin2,bar,bar,lin10,esp,esp,esp,bar,bar,lin10,lin1,lin6,lin6,bar
           ,bar,lin12,lin6,lin6,lin11);

    printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
           "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n"
           ,bar,bar,bar,bar,bar,bar,lin12,lin11,bar,bar,bar,bar,bar,bar,lin12,lin11,bar,bar,bar,bar,bar,lin2,esp
           ,esp,bar,bar,bar,bar,bar,bar,bar,lin10,bar,bar,bar,bar,bar,lin12,lin11,esp,bar,bar,lin10,esp,esp,esp,esp
           ,bar,bar,lin10,bar,bar,lin10,esp,esp,esp,bar,bar,lin10,esp,esp,esp,bar,bar,lin10);

    printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
           "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n"
           ,bar,bar,lin12,lin6,lin6,bar,bar,lin2,bar,bar,lin12,lin6,lin6,bar,bar,lin2,bar,bar,lin12,lin6,lin6,lin11
           ,esp,esp,bar,bar,lin12,lin6,lin6,bar,bar,lin10,bar,bar,lin12,lin6,bar,bar,lin2,esp,bar,bar,lin10,esp,esp
           ,esp,esp,bar,bar,lin10,bar,bar,lin10,esp,esp,esp,bar,bar,lin10,esp,esp,esp,bar,bar,lin10);

    printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
           "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n"
           ,bar,bar,bar,bar,bar,bar,lin12,lin11,bar,bar,lin10,esp,esp,bar,bar,lin10,bar,bar,bar,bar,bar,bar,bar,lin2
           ,bar,bar,lin10,esp,esp,bar,bar,lin10,bar,bar,lin10,esp,esp,bar,bar,lin2,lin1,bar,bar,bar,bar,bar,bar,bar
           ,lin12,lin11,lin1,bar,bar,bar,bar,bar,bar,lin12,lin11,esp,esp,esp,bar,bar,lin10);

    printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
           "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
           ,lin1,lin6,lin6,lin6,lin6,lin6,lin11,esp,lin1,lin6,lin11,esp,esp,lin1,lin6,lin11,lin1,lin6,lin6,lin6
           ,lin6,lin6,lin6,lin11,lin1,lin6,lin11,esp,esp,lin1,lin6,lin11,lin1,lin6,lin11,esp,esp,lin1,lin6,lin11
           ,esp,lin1,lin6,lin6,lin6,lin6,lin6,lin6,lin11,esp,esp,lin1,lin6,lin6,lin6,lin6,lin6,lin11,esp,esp,esp
           ,esp,lin1,lin6,lin11);
    // fim das letras no menu
    //IMPRESSÃO DAS OPÇÕES
    printf("\n\n\n\n\t\t\t\tJogar \n\t\t\t\tRanking \n\t\t\t\tSair");
    do
    {
        //CONDICIONAIS QUE MOVEM O CURSOR
        if(contador==0)
        {
            gotoxy(30,10);
            printf(">>");
            gotoxy(30,11);
            printf("  ");
            gotoxy(30,12);
            printf("  ");
        }
        else if(contador==1)
        {
            gotoxy(30,10);
            printf("  ");
            gotoxy(30,11);
            printf(">>");
            gotoxy(30,12);
            printf("  ");
        }
        else if(contador==2)
        {
            gotoxy(30,10);
            printf("  ");
            gotoxy(30,11);
            printf("  ");
            gotoxy(30,12);
            printf(">>");
        }
        setinha = getch();
        switch(setinha)
        {
        case 72:
            contador--;
            break;
        case 80:
            contador++;
            break;
        case 13:
            if(contador==0)
            {
                system("cls");
                jogar();

            }
            else if(contador == 1)
            {
                system("cls");
                LerRanking();
            }
            else if(contador == 2)
            {
                exit(0);
            }

            break;
        }
        if(contador < 0)
            contador = 2;
        else if(contador > 2)
            contador = 0;
    }
    while(setinha != KEY_ENTER);


}


