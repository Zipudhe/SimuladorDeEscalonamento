#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "funcoesAlgoritimos.c"

int main(){
  int TempoChegada,TempoExecucao,DeadLine, Prioridade; //aspectos do Processo.
  int NumProcessos, QuantumSistema, Sobrecarga; // aspectos do sistema.
  int Algoritimo;
  Processo *root = NULL;
  printf("============= Bem-vindo ao Simulador de Escalonamento =============\n");
  printf("Insira a quantidade de Processos, Quantum do sistema e Sobrecarga do sistema:");
  scanf("%d %d %d", &NumProcessos,&QuantumSistema,&Sobrecarga);
  printf("Para cada processo diga Tempo de chegada, Tempo de Execução,\n DeadLine e Prioridade.\n");
  // Cada processo vai ser um Nó de uma lista.
  for(int i = 1; i <= NumProcessos; i++){
    printf("PROCESSO %d\n",i);
    printf("Tempo de chegada:");
    scanf("%d",&TempoChegada);
    printf("Tempo de Execução:");
    scanf("%d",&TempoExecucao);
    printf("DeadLine:");
    scanf("%d",&DeadLine);
    printf("Prioridade:");
    scanf("%d",&Prioridade);
    insereProcesso(&root, TempoChegada, TempoExecucao, DeadLine, Prioridade); //insere o processo dentro da lista;
  }
  Fifo(&root, NumProcessos, QuantumSistema, Sobrecarga);
}
  // RoundRobin(&root,NumProcessos, QuantumSistema, Sobrecarga);
  // Sjf(&root,NumProcessos, QuantumSistema, Sobrecarga);
  // EDF(&root,NumProcessos, QuantumSistema, Sobrecarga);
// }
