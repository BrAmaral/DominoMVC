/*Integrantes:
Breno Goes do Amaral        RA00212782
Gabrielle Ramos da Silva    RA00207256
Victor Barbosa Bulhoes      RA00207194
*/

#include "dominoView.h"
#include "dominoModel.h"

int mostrarMenuDomino()
{
    bool Opvalido = true;
    int Op = 0;

    do
    {
        printf("\n\t\t\t Menu do Jogo\n");
        printf("****************************************************************\n\n");
        printf(" 1 - Regras do jogo\n");
        printf(" 2 - Iniciar jogo\n");
        printf(" 3 - Carregar jogo\n");
        printf(" 4 - Sair do jogo\n");
        printf("\n");
        printf(" Entre com uma das opções: ");
        scanf("%d", &Op);
        if (Op < 1 || Op > 4){
            printf("\n*******************OPCAO INVALIDA!*******************\n");
            Opvalido = false;
        }
        else{
            Opvalido = true;
        }
        setbuf(stdin,NULL);

    }while(!Opvalido);
    return Op;
}

int modoJogo()
{
    bool modovalido = true;
    int modo = 0;
    do{
        printf("\n\t\t\t Modo de Jogo\n");
        printf("****************************************************************\n\n");
        printf(" 1 - Singleplayer\n");
        printf(" 2 - Multiplayer\n");
        printf(" Entre com um dos modos: ");
        scanf("%d", &modo);
        if (modo < 1 || modo > 2){
            modovalido = false;
            printf("\n*******************OPCAO INVALIDA!*******************\n");
        }
        else{
            modovalido = true;
        }
        setbuf(stdin,NULL);
    }while (!modovalido);
    return modo;
}

void regrasJogo()
{
	printf("\n\t\t\t Regras do Jogo\n");
	printf("----------------------------------------------------------------\n\n");
	printf(" Cada jogador deve iniciar o jogo com 7 peças.\n");
	printf(" O jogo jogador que inicia é aquele que possui a peça 6:6.\n Caso não tenha, inicia aquele com o dobre mais alto.\n");
	printf(" O jogo ocorre em sentido anti-horário.\n");
	printf(" Os jogadores devem colocar peças que tenham os mesmos números\n das peças que se encontram nas pontas do jogo.\n");
    printf("\nAperte a tecla ENTER para retornar ao menu...");
}


void mostrarPecasJogador(tipo_Peca Peca, int pecasJogador, int qtdPecas)
{

	int i;

	printf("\n");

	for(i = 0; i < qtdPecas; i++){ // Display das pe�as da mesa

		printf("|%d|%d|\t", Peca.num1, Peca.num2);

	}

	printf("\n");

}



void mostrarBaralho(tipo_Peca Ppeca) // Onde essa funcao for chamada deve ter um loopdos IDs das pecas para mostrar todas as pecas
{

		printf("|%d|%d|\t", Ppeca.num1, Ppeca.num2);
		
}






