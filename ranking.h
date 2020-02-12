struct Pontos
{
    char name[14];
    int pontos;
};


/*
** Salvar os pontos do jogador.
*/

void SalvarPontuacao(char name[14], int pontos);

/*
** Adicionar os pontos do jogador.
*/
void GravarDados (int pontos);

/*
** Contar quantas linhas existem no ranking.
*/
int QuantiaPlayers();

/*
** Forma o ranking.
*/
void MostrarRanking(struct Pontos jogador[20]);

/*
** Lê o ranking;
*/
void LerRanking();










