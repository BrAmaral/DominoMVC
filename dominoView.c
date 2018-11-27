/*Integrantes:
Breno Goes do Amaral        RA00212782
Gabrielle Ramos da Silva    RA00207256
Victor Barbosa Bulhoes      RA00207194
*/

#include "dominoView.h"
#include "dominoModel.h"

int mostrarMenuPrincipal()
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
        if (Op < 1 || Op > 4)
        {
            limparTelaHibrido();
            printf("\n*******************OPÇÃO INVÁLIDA!*******************\n");
            printf("Pressione Enter para continuar...");
            setbuf(stdin,NULL);
            getchar();
            limparTelaHibrido();
            Opvalido = false;
        }
        else
        {
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
    do
    {
        printf("\n\t\t\t Modo de Jogo\n");
        printf("****************************************************************\n\n");
        printf(" 1 - Singleplayer\n");
        printf(" 2 - Multiplayer\n");
        printf(" Entre com um dos modos: ");
        scanf("%d", &modo);
        if (modo < 1 || modo > 2)
        {
            limparTelaHibrido();
            printf("\n*******************OPÇÃO INVÁLIDA!*******************\n");
            printf("Pressione Enter para continuar...");
            setbuf(stdin,NULL);
            getchar();
            limparTelaHibrido();
            modovalido = false;

        }
        else
        {
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
	printf(" O jogador que possuir a peça 6:6 faz a primeira jogada.\n Caso nenhum jogador possua a peça 6:6, inicia aquele com o dobre\n(1:1, 2:2, 3:3, 4:4, 5:5) mais alto.\n");
	printf(" O jogo ocorre em sentido anti-horário.\n");
	printf(" Os jogadores devem colocar peças que tenham os mesmos números\n das peças que se encontram nas pontas do jogo.\n");
    printf("\nAperte a tecla ENTER para retornar ao menu...");
}

int menuJogada(int acaoJogo)
{
	printf("1) Jogar Peça   2) Comprar Peça   3) Salvar   4) Menu Principal\n");
	printf(">> ");
	scanf("%d", &acaoJogo);
	return acaoJogo;

}

void mostrarPecas(tipo_Peca pecas[28])
{
	int i, j, k = 0, o = 0;

	printf("Peças do jogo: \n");
	for(i = 0; i < 7; i++)
	{
		printf("\n");
		for(j = k; j < 7; j++)
		{
			printf("\t|%d|%d|", pecas[o].num1, pecas[o].num2);
            o++;
		}
		k = k + 1;

	}
}

void mostrarMesa(tipo_Peca pecas[28], int pecasMesa[56], int posicaoPecasMesa[56])
{
    int i = 0;
    int p = 0;

    printf("MESA:\n\n");
    for(i; i < 56; i++)
    {
        if (pecasMesa[i] != -1)
        {
        	if(posicaoPecasMesa[i] == 1){
            	p = pecasMesa[i];
            	printf(" |%d|%d|", pecas[p].num1, pecas[p].num2);
            	
        	}else if(posicaoPecasMesa[i] == 2){
        		p = pecasMesa[i];
            	printf(" |%d|%d|", pecas[p].num2, pecas[p].num1);
			}
        }
    }
}

void mostrarPecasJogador(tipo_Peca pecas[28], int pecasJogador[21])
{
    int i = 0;
    int p = 0;

    printf("\n\n**********************************************\n\nSUAS PEÇAS:\n\n");
    for(i; i < 21; i++)
    {
        if (pecasJogador[i] != -1)
        {
            p = pecasJogador[i];
            printf("%d) |%d|%d|\n", i+1, pecas[p].num1, pecas[p].num2);
        }
    }
    printf("\n\n");
}

void pausaEstrategica()
{
    printf("\n\nPressione ENTER para continuar...\n\n");
    setbuf(stdin,NULL);
    getchar();
}

int escolhaPeca()
{
    int escolha = 0;
    printf("\nQual peca voce deseja jogar? (0 se deseja cancelar)\n>> ");
    scanf("%d", &escolha);
    return escolha;
}

void mensagemDePrimeiro(int comeco){

	switch(comeco){
		case 1:
			printf("\nVocê jogou a primeira peça!\n\n");
			pausaEstrategica();
			limparTelaHibrido();
			break;
		case 2:
			printf("\nComputador jogou a primeira peça\n\n");
			pausaEstrategica();
			limparTelaHibrido();
			break;
	}
}

void mensagemFinalJogo(int vencedor){

	switch(vencedor){
		case 1:
			printf("\n\n\t\tVOCÊ GANHOU!!!");
			break;
		case 2:
			printf("\n\n\t\tVOCÊ PERDEU!!!");
			break;
	}

}

void modoIndisponivel(){

	printf("\n\n\tMODO DE JOGO INDISPONÍVEL");
	pausaEstrategica();
	limparTelaHibrido();
}

void jogadaImpossivel(){
	printf("\n\nJOGADA IMPOSSÍVEL\n");
}

void perguntarLado()
{
	printf("\n\nJogar a peça em que lado? (esquerda = 0; direita = 1)");
	printf("\n>> ");
}
