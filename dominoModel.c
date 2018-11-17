/*Integrantes:
Breno Goes do Amaral        RA00212782
Gabrielle Ramos da Silva    RA00207256
Victor Barbosa Bulhoes      RA00207194
*/

#include "dominoView.h"
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
	
	printf("\nPecas geradas;");
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
	printf("\nPecas embaralhadas;");
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
	printf("\nPecas distribuidas;");
}


void desembaralharPecas(int PID[28]) // pecas[28] se refere ao ID das peças
{
	int i;

	for(i = 0; i < 28; i++){
		PID[i] = i;
	}

}


int comecarPrimeiro(int pecasJogador[21], int pecasComp[21], int pecasCompra[14]){

    int i, j, k = 1;
	int maiorPecaJog1 = -1, maiorPecaComp = -1; // para decidir quem é o primeiro a jogar, comparar e ver qual é maior

	for(i = 27; i >= 0; i = i - k){

		for(j = 0; j < 7; j ++){

			if(i == pecasJogador[j]){

				maiorPecaJog1 = i;
				break;

			}
		}
		if(maiorPecaJog1 > -1){
            break;
		}
        k++;
	}

	k = 1;

	for(i = 27; i >= 0; i = i - k){

		for(j = 0; j < 7; j ++){

			if(i == pecasComp[j]){

				maiorPecaComp = i;
				break;

			}
		}
		if(maiorPecaComp > -1){
            break;
		}
        k++;
	}

	if(maiorPecaJog1 > maiorPecaComp){
        return 1;
	}
	else if (maiorPecaJog1 < maiorPecaComp){
        return 2;
	}

}


int jogadas(tipo_Peca pecas[28]; int PID[28]; int pecasJogador[21]; int pecasComp[21], int pecasCompra[14]; int PrimeiroJogador){
	
	bool fimDoJogo = 0, fimDaRodada = 0;
	
	while(!fim){
		
		
		
	}
	
}


void jogoSingleplayerVirgem()
{
    tipo_Peca pecas[28];	// Criacao do struct dentro do jogo
    int PID[28];			// Criacao do ID de cada peca
    int pecasJogador[21];	// Criacao do vetor que armazena as pecas do jogador
    int pecasComp[21];		// Criacao do vetor que armazena as pecas do computador
    int pecasCompra[14];	// Vetor que armazena o ID das pecas disponiveis para compra
    int PrimeiroJogador = 0;
    int vencedor;			// Variavel que armazena o vencedor da partida

    // Procedimentos para iniciar o jogo
    gerarPecas(pecas);
    mostrarPecas(pecas);        // arrumar
    embaralharPecas(PID);
    distribuirPecas(pecas, PID, pecasJogador, pecasComp, pecasCompra);
    PrimeiroJogador = comecarPrimeiro(pecasJogador, pecasComp, pecasCompra);
    
	// Comeco efetivo do jogo
	vencedor = jogadas(pecas; PID; pecasJogador; pecasComp; pecasCompra; PrimeiroJogador);
	
	desembaralharPecas(PID);
    
	///Dar opcao de parar no meio e salvar o progresso do jogo
    getchar();
}

/*void jogoMultiplayerVirgem()
{

}*/
