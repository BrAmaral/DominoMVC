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

void embaralharPecas(int PID[28]) // pecas[28] se refere ao ID das peÃ§as. Usado sempre que peÃ§as serÃ£o mostradas na tela
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

void distribuirPecas(int PID[28], int pecasJogador[21], int pecasComp[21], int pecasCompra[14])
{
	int i;
	int k = 0;

	for(i = 0; i < 7 ; i++){              //distribui as 7 primeiras peï¿½as para o jogador
		pecasJogador[i] = PID[i];
	}

	for(i = 7; i < 14 ; i++){             //distribui as 7 seguintes peï¿½as para o computador

		pecasComp[k] = PID[i];
		k++;
	}

    k = 0;

    for(i = 14; i < 28; i++){
        pecasCompra[k] = PID[i];
        k++;
    }

}

void desembaralharPecas(int PID[28]) // pecas[28] se refere ao ID das peÃ§as
{
	int i;

	for(i = 0; i < 28; i++){
		PID[i] = i;
	}

}

int comecarPrimeiro(tipo_Peca pecas[28], int pecasJogador[21], int pecasComp[21], int pecasCompra[14], int pecasMesa[56], int *PvalorEsquerda, int *PvalorDireita, int *PqtdPecasJogador, int *PqtdPecasComp){

    int i, j, k = 1;
	int maiorPecaJog1 = -1, maiorPecaComp = -1;     // para decidir quem Ã© o primeiro a jogar, comparar e ver qual Ã© maior
	int posPecaJogador = -1 , posPecaComp  = -1;    // Pega as posicoes das maiores pecas de cada jogador.
	int comeco = 0;                                 // Imprime uma mensagem sobre quem comeca primeiro.
	int x;
    int auxValorCanto;

	for(i = 27; i >= 0; i = i - k){

		for(j = 0; j < 7; j ++){

			if(i == pecasJogador[j]){

				maiorPecaJog1 = i;
				posPecaJogador = j;
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
				posPecaComp = j;
				break;

			}
			else if (maiorPecaJog1 == i){
                break;
			}
		}
		if(maiorPecaComp > -1){
            break;
		}
        k++;
	}

	if(maiorPecaJog1 > maiorPecaComp){
        pecasMesa[27] = maiorPecaJog1;
        for(x = posPecaJogador; x < 7; x++)
        {
            pecasJogador[x] = pecasJogador[x+1];
        }
        pecasJogador[6] = -1;
        comeco = 1;
        auxValorCanto = pecasMesa[27];
        *PvalorEsquerda = pecas[auxValorCanto].num1;
        *PvalorDireita = *PvalorEsquerda;
        *PqtdPecasJogador = 6;
        mensagemDePrimeiro(comeco);
        return 1;
	}
	else if (maiorPecaJog1 < maiorPecaComp){
        pecasMesa[27] = maiorPecaComp;
        for(x = posPecaComp; x < 7; x++)
        {
            pecasComp[x] = pecasComp[x+1];
        }
        pecasComp[6] = -1;
        comeco = 2;
        auxValorCanto = pecasMesa[27];
        *PvalorEsquerda = pecas[auxValorCanto].num1;
        *PvalorDireita = *PvalorEsquerda;
        *PqtdPecasComp = 6;
        mensagemDePrimeiro(comeco);
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
    int pecasMesa[56];         // Criacao do vetor que armazena as pecas jogadas em campo
    int posicaoPecasMesa[56];   // Criacao do vetor que determina qual numero da peca esta do lado esquerdo (1 para num1 na esquerda, e 2 para num2 na esquerda)
    int PrimeiroJogador = 0;   // Variavel que determina qual eh o primeiro jogador
    int vencedor = 0;          // Variavel que determina qual eh o vencedor ( 1 para jogador1 e 2 para jogador2 ou Comp)
    int valorEsquerda = -999, valorDireita = -999;
    int qtdPecasJogador = 7;
    int qtdPecasComp = 7;

    // Procedimentos para iniciar o jogo
    zerarVetorPecas(pecasMesa);
    zerarVetorPecas(pecasComp);
    zerarVetorPecas(pecasCompra);
    zerarVetorPecas(pecasJogador);
    zerarVetorPecas(posicaoPecasMesa);
    gerarPecas(pecas);
    mostrarPecas(pecas);
    pausaEstrategica();
    embaralharPecas(PID);
    distribuirPecas(PID, pecasJogador, pecasComp, pecasCompra);
    PrimeiroJogador = comecarPrimeiro(pecas, pecasJogador, pecasComp, pecasCompra, pecasMesa, &valorEsquerda, &valorDireita, &qtdPecasJogador, &qtdPecasComp);

    // Jogo
    vencedor = JogoSingle(pecas, PID, pecasJogador, pecasComp, pecasCompra, pecasMesa, PrimeiroJogador, posicaoPecasMesa, &valorEsquerda, &valorDireita, &qtdPecasJogador, &qtdPecasComp);
    pausaEstrategica();
    limparTelaHibrido();
}

int JogoSingle(tipo_Peca pecas[28],int PID[28], int pecasJogador[21], int pecasComp[21], int pecasCompra[14], int pecasMesa[56], int PrimeiroJogador, int posicaoPecasMesa[56], int *PvalorEsquerda, int *PvalorDireita, int *PqtdPecasJogador,int *PqtdPecasComp)
{
    int vencedor = 0, acaoJogo = 0, mesaDireita = 28, mesaEsquerda = 26, escolha = 0;
    int i, j, k;
    int aux;
    bool fimDoJogo = false;
    bool fimDaJogadaJog = false;
    bool fimDaJogadaComp = false;
    int auxJogadaComp;
    posicaoPecasMesa[27] = 1;
    int passouVezJog = 0;   // Determina se o jogador passou a vez
    int passouVezComp = 0;  // Determina se o computador passou a vez
    int passouVez = 0;      // Determina se os dois passaram a vez (se os dois passarem a vez, o jogo acaba e quem tiver menos peças ganha)
    int qtdPecasCompra = 0;

    while(!fimDoJogo){
        fimDaJogadaJog = false;
        fimDaJogadaComp = false;
        while(!fimDaJogadaJog){
            passouVezJog = 0;
            fimDaJogadaJog = false;
            limparTelaHibrido();
            mostrarMesa(pecas, pecasMesa, posicaoPecasMesa);
            mostrarPecasJogador(pecas, pecasJogador);
            acaoJogo =  menuJogada(acaoJogo);
            switch(acaoJogo){
                case 1:         // Jogar peca
                    // Retirei escolhaPeca() e coloquei dentro de jogarPeca, porque precisa estar dentro de um loop
                    jogarPeca(pecas, pecasJogador, pecasMesa, &mesaEsquerda, &mesaDireita, &PvalorEsquerda, &PvalorDireita, posicaoPecasMesa, &PqtdPecasJogador);
                    setbuf(stdin, NULL);
                    fimDaJogadaJog = true;
                    //Logo em seguida deve vir a jogada do computador
                    break;

                case 2:         //  Comprar peca
                    comprarPeca(pecasJogador, pecasCompra, &PqtdPecasJogador);
                    //Mostrar aviso quando o jogador nao puder comprar mais, por ter pecas que podem ser jogadas
                    break;

                case 3:         // Salvar (Arquivo)
                    break;

                case 4:         // Menu principal
                    desembaralharPecas(PID);
                    fimDaJogadaJog = true;
                    fimDoJogo = true;
                    break;

                case 5:
                    passarVez();
                    passouVezJog = 1;
                    pausaEstrategica();
                    fimDaJogadaJog = true;
            }


        }


        for(k = 0; k < 14; k++){
            if(pecasCompra[k] != -1){
                qtdPecasCompra++;
            }
        }

        while(!fimDaJogadaComp){
            passouVezComp = 0;


            for(i = 0; i < *PqtdPecasComp; i++){    // Jogada da peça do Computador (tentativa na esquerda)
                auxJogadaComp = pecasComp[i];
                if(pecas[auxJogadaComp].num1 == *PvalorEsquerda){       // Se o num1 da peça atual for igual ao valor da esquerda
                    posicaoPecasMesa[*PmesaEsquerda] = 2;
                    pecasMesa[*PmesaEsquerda] = auxJogadaComp;
                    *PmesaEsquerda = *PmesaEsquerda - 1;
                    aux = pecas[auxJogadaComp].num2;
                    **PvalorEsquerda = aux;
                    fimDaJogadaComp = true;
                    break;
                }else if(pecas[auxJogadaComp].num2 == *PvalorEsquerda){ // Se o num2 da peça atual for igual ao valor da esquerda
                    posicaoPecasMesa[*PmesaEsquerda] = 1;
                    pecasMesa[*PmesaEsquerda] = auxJogadaComp;
                    *PmesaEsquerda = *PmesaEsquerda - 1;
                    aux = pecas[auxJogadaComp].num1;
                    **PvalorEsquerda = aux;
                    fimDaJogadaComp = true;
                    break;
                }else if(pecas[auxJogadaComp].num1 == *PvalorDireita){ // Se o num1 da peça atual for igual ao valor da direita
                    posicaoPecasMesa[*PmesaDireita] = 1;
                    pecasMesa[*PmesaDireita] = auxJogadaComp;
                    *PmesaDireita = *PmesaDireita + 1;
                    aux = pecas[auxJogadaComp].num2;
                    **PvalorDireita = aux;
                    fimDaJogadaComp = true;
                    break;
                }else if(pecas[auxJogadaComp].num2 == *PvalorDireita){ // Se o num2 da peça atual for igual ao valor da direita
                    posicaoPecasMesa[*PmesaDireita] = 2;
                    pecasMesa[*PmesaDireita] = auxJogadaComp;
                    *PmesaDireita = *PmesaDireita + 1;
                    aux = pecas[auxJogadaComp].num1;
                    **PvalorDireita = aux;
                    fimDaJogadaComp = true;
                    break;
                }
            }

            if(fimDaJogadaComp = false){
                if(qtdPecasCompra != 0){
                    comprarPeca(pecasComp, pecasCompra, &PqtdPecasComp);
                } else{
                    passouVezComp = 1;
                }
            }



            //fimDaJogadaComp = true;
        }


        passouVez = passouVezComp + passouVezJog;

        if(passouVez == 2){
            fimDoJogo = true;
            //QUEM TIVER MAIS PEÇAS PERDE
        }
    }

    return vencedor;

}

void jogarPeca(tipo_Peca pecas[28], int pecasJogador[21], int pecasMesa[56], int *PmesaEsquerda, int *PmesaDireita, int **PvalorEsquerda, int **PvalorDireita, int posicaoPecasMesa[56], int **PqtdPecasJogador)
{
	int escolha;
    int lado = -1;
    int aux = -1, aux2 = -1;
    int i;
    bool jogadaPossivel = false;
    do{
        escolha = escolhaPeca();
        if(escolha == 0){
        	break;
		}
    	lado = ladoDaMesa(); // Determina o lado em que o jogador vai jogar a peça

    	setbuf(stdin, NULL);

    	if(lado == 0){ // Se a jogada ocorrer na esquerda
    		aux = pecasJogador[escolha - 1]; // Auxiliar assume o ID da peça jogada
    		if(pecas[aux].num1 == **PvalorEsquerda){
    			posicaoPecasMesa[*PmesaEsquerda] = 2;
    			pecasMesa[*PmesaEsquerda] = aux;
    			setbuf(stdin, NULL);
    			*PmesaEsquerda = *PmesaEsquerda - 1;
                aux2 = pecas[aux].num2;
                setbuf(stdin, NULL);
    			**PvalorEsquerda = aux2;
    			jogadaPossivel = true;
			}else if(pecas[aux].num2 == **PvalorEsquerda){
    			posicaoPecasMesa[*PmesaEsquerda] = 1;
    			pecasMesa[*PmesaEsquerda] = aux;
    			setbuf(stdin, NULL);
    			*PmesaEsquerda = *PmesaEsquerda - 1;
                aux2 = pecas[aux].num1;
                **PvalorEsquerda = aux2;
    			jogadaPossivel = true;
			}
		}
		if(lado == 1){ // Se a jogada ocorrer na direita
    		aux = pecasJogador[escolha - 1]; // Auxiliar assume o ID da peça jogada
    		if(pecas[aux].num1 == **PvalorDireita){
    			posicaoPecasMesa[*PmesaDireita] = 1; // O valor da esquerda eh o num1
    			pecasMesa[*PmesaDireita] = aux;
    			setbuf(stdin, NULL);
    			*PmesaDireita = *PmesaDireita + 1;
    			aux2 = pecas[aux].num2;
    			setbuf(stdin, NULL);
    			**PvalorDireita = aux2;
    			jogadaPossivel = true;
			}else if(pecas[aux].num2 == **PvalorDireita){
    			posicaoPecasMesa[*PmesaDireita] = 2; // O valor da esquerda eh o num2
    			pecasMesa[*PmesaDireita] = aux;
    			setbuf(stdin, NULL);
    			*PmesaDireita = *PmesaDireita + 1;
    			aux2 = pecas[aux].num1;
    			setbuf(stdin, NULL);
    			**PvalorDireita = aux2;
    			jogadaPossivel = true;
			}
		}

		if(jogadaPossivel == true){
			for(i = escolha - 1; i < **PqtdPecasJogador; i++){
				pecasJogador[i] = pecasJogador[i + 1];
				pecasJogador[**PqtdPecasJogador] = -1;
				setbuf(stdin, NULL);
			}
			**PqtdPecasJogador = **PqtdPecasJogador - 1;

		}

		if(jogadaPossivel == false){
			jogadaImpossivel();
		}

	}while(!jogadaPossivel);

}

int ladoDaMesa()
{
	int ladoEscolhido;
	bool possivel = false;

	do{
		perguntarLado();
		scanf("%d", &ladoEscolhido);
		if((ladoEscolhido == 0) || (ladoEscolhido == 1)){
			possivel = true;
		}
		setbuf(stdin, NULL);
	}while(!possivel);

	return ladoEscolhido;
}

void comprarPeca(int pecasJogador[21], int pecasCompra[14], int **PqtdPecasJogador)
{
    int x = 0, qtdPecasCompra = 0, aux  = 0;

    for(x = 0; x < 14; x++)
    {
        if (pecasCompra[x] != -1)
        {
            qtdPecasCompra++;
        }
    }
    if (qtdPecasCompra != 0){
        pecasJogador[**PqtdPecasJogador] = pecasCompra[qtdPecasCompra-1];
        pecasCompra[qtdPecasCompra - 1] = -1;
        **PqtdPecasJogador = **PqtdPecasJogador + 1;
    }

}

void zerarVetorPecas(int vetor[28])
{
    int i = 0;
    for(i = 0; i < 56; i++)
    {
        vetor[i] = -1;
    }

}

void limparTelaHibrido()
{
    #if defined(_WIN32)
        system("cls");
    #elif defined(__linux__)
        system("clear");
    #endif
}
