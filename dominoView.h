#ifndef DOMINOVIEW_H_INCLUDED
#define DOMINOVIEW_H_INCLUDED

#include "dominoModel.h"

//Funcoes do View
int mostrarMenuDomino();
int modoJogo();
void regrasJogo();
void mostrarPecasJogador(tipo_Peca Ppeca, int pecasJogador, int qtdPecas);    // PUXAR PECASJOGADOR DA FUNCAO PRINCIPAL
void mostrarBaralho(tipo_Peca Ppeca);

#endif // DOMINOVIEW_H_INCLUDED
