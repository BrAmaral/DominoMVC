#ifndef DOMINOMODEL_H_INCLUDED
#define DOMINOMODEL_H_INCLUDED


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <ctype.h>
#include <time.h>

//Declaracao do struct para armazenar as pecas do jogo
typedef struct Peca{

	int num1;	// Numero de um lado da peca
	int num2;	// Numero do outro lado da peca

}tipo_Peca;

//Funcoes do Model
void gerarPecas(tipo_Peca pecas[28]);
void embaralharPecas(int PID[28]);
void distribuirPecas(tipo_Peca pecas[28], int PID[28], int pecasJogador[21], int pecasComp[21], int pecasCompra[14]);
void desembaralharPecas(int PID[28]);
void jogoSingleplayerVirgem();        // "main" do jogo singleplayer virgem
void jogoSingleplayerCarregado();     // "main" do jogo carregado por arquivo singleplayer  (A ser implementada)
void jogoMultiplayerVirgem();         // "main" do jogo multiplayer
void jogoMultiplayerCarregado();      // "main" do jogo carregado por arquivo multiplayer   (A ser implementada)
#endif
