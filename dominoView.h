#ifndef DOMINOVIEW_H_INCLUDED
#define DOMINOVIEW_H_INCLUDED

#include "dominoModel.h"

//Funcoes do View
int mostrarMenuDomino();
int modoJogo();
void regrasJogo();
void mostrarPecasJogador(tipo_Peca pecas[28], int pecasJogador, int qtdPecas);    // PUXAR PECASJOGADOR DA FUNCAO PRINCIPAL
void mostrarBaralho(tipo_Peca Ppeca);
int modoJogoSingle();
int modoJogoMulti();
void menuJogada();
void mostrarPecas(tipo_Peca pecas[28]);

#endif // DOMINOVIEW_H_INCLUDED
