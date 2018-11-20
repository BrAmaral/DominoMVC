#ifndef DOMINOVIEW_H_INCLUDED
#define DOMINOVIEW_H_INCLUDED

#include "dominoModel.h"

//FUNCOES TIPO VOID
void regrasJogo();                          // Imprime as regras do jogo.
void mostrarPecas(tipo_Peca pecas[28]);     // Mostra todas as pecas do jogo.
void mensagemDeAdeus();                     // Imprime uma breve mensagem de agradecimento.
void mostrarMesa(tipo_Peca pecas[28], int pecasMesa[56]);      // Imprime as pecas na mesa
void mostrarPecasJogador(tipo_Peca pecas[28], int pecasJogador[21]);       // Imprime as pecas na mao do jogador
void pausaEstrategica();                    // Pausa o programa e espera o usuario apertar enter.
void escolhaPeca();                         // Jogador escolhe uma peca que esta em sua mao.
void mensagemDePrimeiro(int comeco);        // Imprime uma mensagem dizendo quem comecou o jogo.
void mensagemFinalJogo(int vencedor);       // Imprime uma mensagem de fim de jogo.

//FUNCOES TIPO INT
int mostrarMenuPrincipal();             // Imprime o menu principal.
int modoJogo();                         // Imprime menu de selecao do modo de jogo (Singleplayer ou Multiplayer) e retorna 1 para Singleplayer e 2 para Multiplayer.
int menuJogada(int acaoJogo);           // Imprime o menu de jogada (Opcoes que o jogador tem durante o jogo).
int ladoDaMesa(int pecasMesa[56], pecasJogador[21], int *PmesaDireita, int *PmesaEsquerda);

#endif // DOMINOVIEW_H_INCLUDED
