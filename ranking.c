#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "menu.h"

struct Pontos
{
    char name[14];
    int pontos;
};

int i;


void SalvarPontuacao(char name[14], int pontos)
{
    FILE *arquivo;
    arquivo = fopen("ranking.Score", "a");
    if(arquivo == NULL)
    {
        printf("Nao foi possivel abrir o arquivo");
        exit(0);
    }
    fprintf(arquivo, "\n%s - %i", name, pontos);

    fclose(arquivo);
}

void GravarDados (int pontos)   //funcao para adicionar os pontos
{
    char jogador[14];
    printf("Digite seu nome: ");
    fgets(jogador, 11*sizeof(char), stdin);
    SalvarPontuacao(jogador, pontos);

}

int QuantiaPlayers()
{
    int c = 0, i=1;
    FILE *arquivo;
    arquivo = fopen("ranking.Score","r");

    if(arquivo == NULL)
    {
        printf("Nao foi possivel abrir o arquivo");
        exit(0);
    }

    do
    {
        c = getc(arquivo);
        i++;
    }
    while(c != EOF);

    fclose(arquivo);
    return i;
}

void MostrarRanking(struct Pontos jogador[20])
{
    int i;
    char opcao;

    if(QuantiaPlayers() > 10)
    {
        FILE *arquivo;
        arquivo = fopen("ranking.Score", "w");

        if(arquivo == NULL)
        {
            printf("Nao foi possivel abrir o arquivo");
            exit(0);
        }

        for(i=0; i<9; i++)
        {
            if(strlen(jogador[i].name)<=1)
            {
                printf("\n\t\t");
            }
            else
                fprintf(arquivo, "%s - %i\n", jogador[i].name, jogador[i].pontos);

        }
        fprintf(arquivo, "%s - %i", jogador[i].name, jogador[i].pontos);
        fclose(arquivo);
    }


    do
    {
        system("cls");
        for(i=0; i<10; i++)
        {
            if(strlen(jogador[i].name)<=1)
            {
                printf("\n\t\t");
            }
            else
            {
                printf("\n\t\t%s -> %i Pontos",jogador[i].name, jogador[i].pontos);
            }
        }

        printf("\n\t\t1. Voltar\n");
        opcao=getch();

    }
    while(opcao!= '1');
    system("cls");
    menu();
}

void LerRanking()  //funcao para ler o ranking
{
    int pontos;
    struct Pontos jogador[20];
    char nome[14];


    for(i=0; i<20; i++)
    {
        strcpy(jogador[i].name, " ");
        jogador[i].pontos= 0;
    }
    FILE *arquivo;
    arquivo = fopen("ranking.Score", "r");

    if(arquivo == NULL)
    {
        fclose(arquivo);
        arquivo = fopen("ranking.Score", "w");

        if(arquivo == NULL)
        {
            printf("Nao foi possivel abrir o arquivo");
            exit(0);
        }
        fclose(arquivo);
        arquivo = fopen("ranking.Score", "r");
    }
    i=0;

    while((fscanf(arquivo, "%s - %i", &nome, &pontos)!=EOF))
    {
        if(i<15)
        {
            strcpy(jogador[i].name, nome);
            jogador[i].pontos = pontos;
            i++;
        }
    }

    fclose(arquivo);
    MostrarRanking(jogador);
}
