/*Integrantes:
Breno Goes do Amaral        RA00212782
Gabrielle Ramos da Silva    RA00207256
Victor Barbosa Bulhoes      RA00207194
*/

#include "dominoModel.h"
#include "dominoController.h"


void gerarPecas(tipo_Peca pecas[28])
{

	int i, j;
	int id = 0;
	int k = 0;

	for(i = 0; i < 7; i++){
		for(j = k; j < 7; j++){

			pecas[id].num1 = i;
			pecas[id].num2 = j;

			id++;
			k++;
		}
		k = i + 1;
	}
}

void embaralharPecas(int *PID[28]) // pecas[28] se refere ao ID das peças. Usado sempre que peças serão mostradas na tela
{
	int i;
	int aux;
	int randomico;

	srand (time(NULL));

	for(i = 0; i < 28; i++){

		PID[i] = i;

	}

	for(i = 0; i < 28; i++){
		aux = PID[i];
		randomico = rand() % 27;
        PID[i] = PID[randomico];
		PID[randomico] = aux;
	}
}

void distribuirPecas(tipo_Peca pecas[28], int *PID[28])
{
	int i;
	int pecasJogador[20];
	int pecasComp[20];

	for(i=0; i<7 ; i++){              //distribui as 7 primeiras pe�as para o jogador
		pecasJogador[i] = PID[i];
	}

	for(i=7; i<14 ; i++){             //distribui as 7 seguintes pe�as para o computador

		pecasComp[i] = PID[i];
	}

}

void desembaralharPecas(int *PID[28]) // pecas[28] se refere ao ID das peças
{
	int i;

	for(i = 0; i < 28; i++){
		PID[i] = i;
	}

}

void jogoSingleplayer()
{
    // 1) Gerar pecas dos jogadores
    // 2) Escolher qual jogador comeca primeiro  (regra do 6:6 ou maior numero de repetidas)
    // 3) Embaralhar Pecas
    // 4) Distribuir Pecas
    // 5) Rola o jogo
    // 6) Desembaralha as pecas
    // 7) Recomeca ou termina o jogo
    ///Dar opcao de parar no meio e salvar o progresso do jogo
}

void jogoMultiplayer()
{
    // 1) Gerar pecas dos jogadores
    // 2) Escolher qual jogador comeca primeiro  (regra do 6:6 ou maior numero de repetidas)
    // 3) Embaralhar Pecas
    // 4) Distribuir Pecas
    // 5) Rola o jogo
    // 6) Desembaralha as pecas
    // 7) Recomeca ou termina o jogo
    ///Dar opcao de parar no meio e salvar o progresso do jogo
}
