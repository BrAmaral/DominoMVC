/*Integrantes:
Breno Goes do Amaral        RA00212782
Gabrielle Ramos da Silva    RA00207256
Victor Barbosa Bulhoes      RA00207194
*/

#include "dominoView.h"
#include "dominoModel.h"
#include "dominoController.h"

void iniciarController(){
    bool fim = false;
    int acao = 0;

    do{
        acao = mostrarMenuPrincipal();
        limparTelaHibrido();
        fim = switAcao(acao);
    }while(!fim);
}



bool switAcao(int acao)
{

    bool fim = false;
    int modo = 0;

	switch(acao){
        case 1:             //Regras do jogo
            regrasJogo();
            setbuf(stdin,NULL);
            getchar();
            limparTelaHibrido();
            break;

        case 2:             // Iniciar jogo
            modo = modoJogo();
            if (modo == 1)
            {
                limparTelaHibrido();
                jogoSingleplayerVirgem();
            }
            else if (modo == 2)
            {
                limparTelaHibrido();
                modoIndisponivel();
		//jogoMultiplayerVirgem();      //Falta ser implementada
            }
            break;

        case 3:             //Carregar jogo
            modo = modoJogo();
            if (modo == 1)
            {
                limparTelaHibrido();
		modoIndisponivel();
                //jogoSingleplayerCarregado();      //Falta ser implementada
            }
            else if (modo == 2)
            {
                limparTelaHibrido();
		modoIndisponivel();
                //jogoMultiplayerCarregado();       //Falta ser implementada
            }
            break;

        case 4:              //Sair do jogo
            fim = true;
            limparTelaHibrido();
            //mensagemDeAdeus();      //Uma breve mensagem agradecendo o jogador/ os jogadores pelo tempo
            break;
    }
    return fim;
}
