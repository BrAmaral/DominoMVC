#ifndef DOMINOMODEL_H_INCLUDED
#define DOMINOMODEL_H_INCLUDED


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <ctype.h>
#include <time.h>
#include <locale.h>


// DECLARACAO DO STRUCT PARA ARMAZENAR AS PECAS DO JOGO
typedef struct Peca{

	int num1;	// Numero de um lado da peca
	int num2;	// Numero do outro lado da peca

}tipo_Peca;

//FUNCOES TIPO VOID
void gerarPecas(tipo_Peca pecas[28]);           // Gera as pecas de domino.
void embaralharPecas(int PID[28]);              // Embaralha as pecas de domino.
void distribuirPecas(tipo_Peca pecas[28], int PID[28], int pecasJogador[21], int pecasComp[21], int pecasCompra[14]);        // Distribue as pecas de domino para cada jogador
void desembaralharPecas(int PID[28]);           // Desembaralha as pecas de domino.
void jogoSingleplayerVirgem();                  // "main" do jogo singleplayer virgem.
void jogoSingleplayerCarregado();               // "main" do jogo carregado por arquivo singleplayer  (A ser implementada)
void jogoMultiplayerVirgem();                   // "main" do jogo multiplayer.
void jogoMultiplayerCarregado();                // "main" do jogo carregado por arquivo multiplayer   (A ser implementada)
void limparTelaHibrido();                       // Limpa a tela para os sistemas operacionais Windows e Linux.
void zerarVetorPecas(int vetor[28]);            // Atribui -1 para todas as posicoes do vetor pecasMesa.
void comprarPeca(int pecasJogador[21], int pecasCompra[14]);    // Jogador compra pecas ate nao poder comprar mais.

//FUNCOES TIPO INT
int comecarPrimeiro(int pecasJogador[21], int pecasComp[21], int pecasCompra[14], int pecasMesa[56]);      // Decide qual jogador comeca primeiro de acordo com as regras de inicio de jogo.
int JogoSingle(tipo_Peca pecas[28],int PID[28], int pecasJogador[21], int pecasComp[21], int pecasMesa[56], int pecasCompra[14], int PrimeiroJogador);
#endif
