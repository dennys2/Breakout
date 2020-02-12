#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "ranking.h"
#include "menu.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ESC 27
#define KEY_ENTER 13

char cenario[24][70];
char barra[15];
char xPos=20, yPos=15;
char key;
char xVel=1,yVel=1;
int i, j, z;
int barraMov=16;
int quantiaBlocos=54;
int Blocos[5];
int pontos=0;
int vidas=3;
int velocidade;

struct Blocos
{

    char blocos[5];
    char apagado;
    char verificador;
    char coordenadaX;
    char coordenadaY;

};
struct Blocos bloco[9][9];

void HideCursor()
{
    CONSOLE_CURSOR_INFO cursor = {1, FALSE};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void gotoxy(int x, int y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD)
    {
        x,y
    });
}

void Tabuleiro()
{
    int i,j;
    for(i=0; i<25; i++)
    {
        for(j=0; j<70; j++)
        {
            if(i==0||j==0||j==49||j==69)
                printf("%c",219);
            else if(i==24 && j>49)
                printf("%c",219);
            else printf(" ");
        }
        printf("\n");
    }

    for(i=0; i<15; i++)
    {
        barra[i]=219;
    }
    gotoxy(barraMov,22);
    puts(barra);
}

void construirblocos()
{
    char posicaoemX=0,posicaoemY=0;
    for(i=0; i<5; i++)
    {
        for(j=0; j<9; j++)
        {
            for(z=0; z<4; z++)
            {
                bloco[i][j].blocos[z]=219;
            }
            bloco[i][j].coordenadaX=0;
            bloco[i][j].coordenadaY=0;
            bloco[i][j].apagado=0;
            bloco[i][j].verificador=1;
        }
    }
    for(i=0; i<5; i++)
    {
        for(j=0; j<9; j++)
        {
            gotoxy(3+posicaoemX,3+posicaoemY);
            puts(bloco[i][j].blocos);
            bloco[i][j].coordenadaX=3+posicaoemX;
            bloco[i][j].coordenadaY=3+posicaoemY;
            posicaoemX+=5;
        }
        posicaoemX=0;
        posicaoemY+=2;
    }
}

void checablocos()
{


    for(i=0; i<5; i++)
    {
        for(j=0; j<9; j++)
        {
            if(bloco[i][j].apagado==0)
            {
                if((xPos>=bloco[i][j].coordenadaX-1)&&(xPos<=bloco[i][j].coordenadaX+4)&&(yPos==bloco[i][j].coordenadaY+1||yPos==bloco[i][j].coordenadaY-1))
                {
                    if(xPos==bloco[i][j].coordenadaX-1||xPos==bloco[i][j].coordenadaX+1)
                        xVel=-xVel;

                    yVel=-yVel;
                    gotoxy(bloco[i][j].coordenadaX,bloco[i][j].coordenadaY);
                    printf("     ");
                    bloco[i][j].apagado=1;
                    quantiaBlocos--;
                    pontos=pontos+10;
                }
            }
        }
    }
}

void Placar()
{
    gotoxy(55,4);
    printf("Pontos: %d", pontos);
    gotoxy(55,6);
    printf("Vidas: %d", vidas);
}

void Dificuldade ()
{
    int contador=0;
    char setinha;

    gotoxy(23,7);
    printf("ESCOLHA A DIFICULDADE!");
    gotoxy(30,10);
    printf("Facil");
    gotoxy(30,11);
    printf("Medio");
    gotoxy(30,12);
    printf("Dificil");
    do
    {
        //CONDICIONAIS QUE MOVEM O CURSOR
        if(contador==0)
        {
            gotoxy(28,10);
            printf(">>");
            gotoxy(28,11);
            printf("  ");
            gotoxy(28,12);
            printf("  ");
        }
        else if(contador==1)
        {
            gotoxy(28,10);
            printf("  ");
            gotoxy(28,11);
            printf(">>");
            gotoxy(28,12);
            printf("  ");
        }
        else if(contador==2)
        {
            gotoxy(28,10);
            printf("  ");
            gotoxy(28,11);
            printf("  ");
            gotoxy(28,12);
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
                velocidade=120;

            }
            else if(contador == 1)
            {
                system("cls");
                velocidade=100;
            }
            else if(contador == 2)
            {
                system("cls");
                velocidade=70;
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

void GameOver()
{
    char opcao;
    system("cls");
    GravarDados(pontos);
    system("cls");
    gotoxy (25,15);
    printf("1. Menu");
    gotoxy (25,16);
    printf("2. Ranking");
    opcao=getch();
    switch (opcao)
    {
    case '1':
        system("cls");
        quantiaBlocos=45;
        pontos=0;
        vidas=3;
        menu();
        break;
    case '2':
        system("cls");
        quantiaBlocos=45;
        pontos=0;
        vidas=3;
        LerRanking();
        break;
    default:
        exit(0);
        break;
    }
}

void MoverBarra()
{
    char key;
    key=getch();
    switch(key)
    {
    case 'A':
    case 'a':
        if(barraMov>2)
            barraMov=barraMov-2;
        gotoxy(barraMov,22);
        puts(barra);
        gotoxy(barraMov+15,22);
        printf("  ");
        break;
    case 'D':
    case 'd':
        if(barraMov<33)
            barraMov=barraMov+2;
        gotoxy(barraMov,22);
        puts(barra);
        gotoxy(barraMov-2,22);
        printf("  ");
        break;
    }
}

void colisaoBarra()
{

    if((xPos >= barraMov+7 && xPos<barraMov+16) && (yPos == 21))  //Lado direito da barra
    {
        yVel=-yVel;
        if (xVel>0)
            xVel=xVel;
        else
            xVel=-xVel;
    }

    if((xPos > barraMov-3 && xPos < barraMov+7) && (yPos == 21))  //Lado esquerdo barra
    {
        yVel=-yVel;
        if (xVel<0)
            xVel=xVel;
        else
            xVel=-xVel;
    }
}

void Bola()
{
    gotoxy(xPos,yPos);
    putchar(' ');
    if(xPos==1||xPos==48)
        xVel=-xVel;
    if(yPos==1)
        yVel=-yVel;
    if (yPos>23) //Se a bola passar da barra, ela volta no sentido contrário, o jogador perde uma vida
    {
        xPos = 25, yPos=17;
        vidas=vidas-1;
        yVel=-yVel;
    }
    xPos+=xVel;
    yPos+=yVel;
    gotoxy(xPos,yPos);
    printf("%c", 4);
    Sleep(velocidade);
}

int jogar()
{
    Dificuldade();
    system("pause");
    system("cls");
    Tabuleiro();
    construirblocos();
    while(1)
    {
        if (kbhit())
        {
            MoverBarra();
        }

        Bola();
        colisaoBarra();
        checablocos();
        Placar();
        if(vidas==0)
        {
            gotoxy(54,8);
            printf("VOCE PERDEU!");
            Sleep(2000);
            break;
        } else if(quantiaBlocos==0){
            gotoxy(54,8);
            printf("PARABENS");
            gotoxy(54,9);
            printf("VOCE GANHOU!");
            Sleep(2000);
            break;
        }
    }
    GameOver();
    return 0;
}
