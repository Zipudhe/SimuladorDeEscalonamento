#include <stdio.h>
#include "funcoesAlgoritmos.c"

typedef struct No { int dado;
                 	struct No* prox;
                  } tNo;

typedef struct { tNo* inicio;
                 int numElem;
               } tListaEncadeada;

tNo* alocaNo(int valor);
//************************************************

void limpaLista(tListaEncadeada* L);
// ***********************************************

void initLista( tListaEncadeada* L);
// ***********************************************

//insere o processo de acordo com o seu tempo de Execução.
//podemos fazer uma função dessa para cada Algoritimo.
bool insereProcesso(tListaEncadeada* L, int dado);
//*************************************************

bool removeProcesso(tListaEncadeada* L);
//*************************************************
