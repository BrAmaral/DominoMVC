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
        PID[i] = PID[randomico];
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

void jogoSingleplayerVirgem()
{
    tipo_Peca pecas[28];       // Criacao do struct dentro do jogo
    int PID[28];               // Criacao do ID de cada peca
    int pecasJogador[21];      // Criacao do vetor que armazena as pecas do jogador
    int pecasComp[21];         // Criacao do vetor que armazena as pecas do computador
    int pecasCompra[14];       // Criacao do vetor que armazena as pecas na mesa
    int PrimeiroJogador = 0;   // Variavel que determina qual eh o primeiro jogador
    int vencedor = 0;          // Variavel que determina qual eh o vencedor ( 1 para jogador1 e 2 para jogador2 ou Comp)

    // Procedimentos para iniciar o jogo
    gerarPecas(pecas);
    mostrarPecas(pecas);
    pausaEstrategica();
    embaralharPecas(PID);
    distribuirPecas(pecas, PID, pecasJogador, pecasComp, pecasCompra);
    PrimeiroJogador = comecarPrimeiro(pecasJogador, pecasComp, pecasCompra);
    //desembaralharPecas(PID);          // Usar quando achar que deve desembaralhar e deixar bonitinho quando o jogo acabar

    // Jogo
    vencedor = JogoSingle(pecas, PID, pecasJogador, pecasComp, pecasCompra, PrimeiroJogador);
    limparTelaHibrido();
}

/*void jogoMultiplayerVirgem()
{

}*/

int JogoSingle(tipo_Peca pecas[28],int PID[28], int pecasJogador[21], int pecasComp[21], int pecasCompra[14], int PrimeiroJogador)
{
    int vencedor = 0, acaoJogo = 0;
    bool fimDoJogo = false;

    while(!fimDoJogo){
       acaoJogo =  menuJogada(acaoJogo);
        switch(acaoJogo){
            case 1:         // Jogar peca

                break;

            case 2:         //  Comprar peca
                break;

            case 3:         // Salvar (Arquivo)
                break;

            case 4:         // Menu principal
                fimDoJogo = true;
                break;

        }


    }
    return vencedor;

}

void pausaEstrategica()
{
    printf("\n\nPressione ENTER para continuar...\n\n");
    setbuf(stdin,NULL);
    getchar();
}

void limparTelaHibrido()
{
    #if defined(_WIN32)
        system("cls");
    #elif defined(__linux__)
        system("clear");
    #endif
}
