#include <stdio.h>
#include "funcoesAlgoritimos.h"

tNo* alocaNo(int valor) {

	tNo* novo = (tNo *)malloc(sizeof(tNo));

	if (novo != NULL) {
		novo->dado = valor;
		novo->prox = SENTINELA;
		}

	return novo;
}

void initLista(tListaEncadeada* L) {
	L->inicio = NULL;
	L->numElem = 0;
}
bool insereOrdenadoLista(tListaEncadeada* L, int valor) {

}

bool removeProcesso(tListaEncadeada* L, int valor) {

}
