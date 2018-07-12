 #include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#include "funcoesAlgoritimos.h"
Processo* createNode(int tempochegada,int tempoexecucao,int deadline,int prioridade) {
	Processo* novo = (Processo) malloc(sizeOf(Processo));
	if(novo != NULL){
		novo->TempoChegada = tempochegada;
    novo->DeadLine = deadline;
    novo->TempoExecucao = tempoexecucao;
    novo->Prioridade = prioridade;
		novo->prox =  NULL;
		return novo;
	}
	return NULL;
}

bool insereOrdenadoLista(Processo** L, Processo novo) {

}

bool insereProcesso(Processo** L, Processo novo) {
  if((*L) == NULL ){
    (*L) = novo;
    return true;
  }
  return insereProcesso((*L)->prox, novo);
}

bool removeProcesso(Processo* L, Processo valor) {

}

void imprimeListaProcessos(Processo *L){
  Processo atual = L;
  while(atual != NULL){
    printf("%d",L->TempoChegada);
    atual = atual->prox;
  }
}

void Fifo(Processo *L){
  
}

void RoundRobin(Processo *L){

}

void Sjf(Processo *L){

}

void EDF(Processo *L){

}
