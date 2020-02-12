struct Blocos
{

    char blocos[5];
    char apagado;
    char verificador;
    char coordenadaX;
    char coordenadaY;

};
struct Blocos bloco[9][9];

/*
** Fun��o auxiliar para esconder o cursor.
*/
void HideCursor();

/*
** Fun��o auxiliar para posicionar o cursor em determinada posi��o.
*/
void gotoxy(int x, int y);

/*
** Desenha as paredes.
*/
void Tabuleiro();

/*
** Desenha os blocos.
*/
void construirblocos();

/*
** Apaga os blocos que a bola tocou.
*/
void checablocos();

/*
** Mostra a pontua��o e a quantidade de vidas restantes.
*/
void Placar();

/*
** Permite o usu�rio escolher o que deseja fazer ap�s o fim de jogo.
*/
void GameOver();

/*
** Permite que o usu�rio escolha a velocidade da bola.
*/
void Dificuldade();

/*
** Move a barra horizontalmente de acordo com o comando do usu�rio.
*/
void MoverBarra();

/*
** Detecta se a bola toca na barra, e rebate, caso toque.
*/
void colisaoBarra();

/*
** Permite que a bola se mova e detecta colis�o com os lados.
*/
void Bola();

/*
** Fun��o que ativa as outras.
*/
int jogar();

