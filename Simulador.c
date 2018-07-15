#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "funcoesAlgoritimos.c"

int main(){
  int TempoChegada,TempoExecucao,DeadLine, Prioridade; //aspectos do Processo.
  int NumProcessos, QuantumSistema, Sobrecarga; // aspectos do sistema.
  int Algoritimo;
  Processo* root = NULL;
  Processo novo;
  printf("============= Bem-vindo ao Simulador de Escalonamento =============\n");
  printf("Insira a quantidade de Processos, Quantum do sistema e Sobrecarga do sistema:");
  scanf("%d %d %d", &NumProcessos,&QuantumSistema,&Sobrecarga);
  printf("Para cada processo diga Tempo de chegada, Tempo de Execução,\n DeadLine e Prioridade.\n");
  // Cada processo vai ser um Nó de uma lista.
  for(int i = 1; i <= NumProcessos; i++){
    printf("PROCESSO %d\n",i);
    printf("Tempo de chegada:");
    scanf("%d\n",&TempoChegada);
    printf("Tempo de Execução:");
    scanf("%d\n",&TempoExecucao);
    printf("DeadLine:");
    scanf("%d\n",&DeadLine);
    printf("Prioridade:");
    scanf("%d\n",&Prioridade);
    novo = createNode(TempodeChegada,TempoExecucao, DeadLine,Prioridade); //Cria o processo que vai entrar na lista;
    insereProcesso(&root, novo); //insere o processo dentro da lista;
  }
  Fifo(&root,NumProcessos, QuantumSistema, Sobrecarga);
  RoundRobin(&root,NumProcessos, QuantumSistema, Sobrecarga);
  Sjf(&root,NumProcessos, QuantumSistema, Sobrecarga);
  EDF(&root,NumProcessos, QuantumSistema, Sobrecarga);
  for (int i = 0; i < NumProcessos; i++) {
    printf("chamada de função\n", );
  }


}
