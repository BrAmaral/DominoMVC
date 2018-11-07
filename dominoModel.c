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

void embaralharPecas(int PID[28]) // pecas[28] se refere ao ID das peças. Usado sempre que peças serão mostradas na tela
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
        PID[i] = PID[randomico]; // Erro de segmentacao aqui
		PID[randomico] = aux;
	}
}

void distribuirPecas(tipo_Peca pecas[28], int PID[28], int pecasJogador[21], int pecasComp[21], int pecasCompra[14])
{
	int i;
	int k = 0;

	for(i = 0; i < 7 ; i++){              //distribui as 7 primeiras pe�as para o jogador
		pecasJogador[i] = PID[i];
	}

	for(i = 7; i < 14 ; i++){             //distribui as 7 seguintes pe�as para o computador

		pecasComp[k] = PID[i];
		k++;
	}

    k = 0;

    for(i = 14; i < 28; i++){
        pecasCompra[k] = PID[i];
        k++;
    }

}

void desembaralharPecas(int PID[28]) // pecas[28] se refere ao ID das peças
{
	int i;

	for(i = 0; i < 28; i++){
		PID[i] = i;
	}

}

void jogoSingleplayerVirgem()
{
    tipo_Peca pecas[28];       //Criacao do struct dentro do jogo
    int PID[28];   // Criacao do ID de cada peca
    int pecasJogador[21];  // Criacao do vetor que armazena as pecas do jogador
    int pecasComp[21];     //Criacao do vetor que armazena as pecas do computador
    int pecasCompra[14];

    // 1) Gerar pecas dos jogadores
    gerarPecas(pecas);

    // 2) Embaralhar Pecas
    embaralharPecas(PID);

    // 3) Distribuir Pecas
    distribuirPecas(pecas, PID, pecasJogador, pecasComp, pecasCompra);

    // 4) Escolher qual jogador comeca primeiro  (regra do 6:6 ou maior numero de repetidas)

    // 5) Rola o jogo       (Uma funcao com um conjunto de condicionais exercendo as regras do jogo)
    // 6) Desembaralha as pecas
    desembaralharPecas(PID);

    // 7) Recomeca ou termina o jogo    (A ser implementada)
    ///Dar opcao de parar no meio e salvar o progresso do jogo
}

void jogoMultiplayerVirgem()
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
