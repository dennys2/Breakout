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
** Função auxiliar para esconder o cursor.
*/
void HideCursor();

/*
** Função auxiliar para posicionar o cursor em determinada posição.
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
** Mostra a pontuação e a quantidade de vidas restantes.
*/
void Placar();

/*
** Permite o usuário escolher o que deseja fazer após o fim de jogo.
*/
void GameOver();

/*
** Permite que o usuário escolha a velocidade da bola.
*/
void Dificuldade();

/*
** Move a barra horizontalmente de acordo com o comando do usuário.
*/
void MoverBarra();

/*
** Detecta se a bola toca na barra, e rebate, caso toque.
*/
void colisaoBarra();

/*
** Permite que a bola se mova e detecta colisão com os lados.
*/
void Bola();

/*
** Função que ativa as outras.
*/
int jogar();

