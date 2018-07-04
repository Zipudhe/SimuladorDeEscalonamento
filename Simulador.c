#include <stdio.h>

#include "funcoesAlgoritimos.h"

int main(){
  int TempoChegada,TempoExecucao,DeadLine, Prioridade; //aspectos do Processo.
  int NumProcessos, QuantumSistema, Sobrecarga; // aspectos do sistema.
  int Algoritimo;
  printf("============= Bem-vindo ao Simulador de Escalonamento =============\n");
  printf("Insira a quantidade de Processos, Quantum do sistema e Sobrecarga do sistema:");
  scanf("%d %d %d", &NumProcessos,&QuantumSistema,&Sobrecarga);
  printf("Para cada processo diga Tempo de chegada, Tempo de Execução,\n DeadLine e Prioridade.\n");
  // Cada processo vai ser um Nó de uma lista.
  for(int i = 1; i <= NumProcessos; i++){
    printf("PROCESSO %d\n",i);
    printf("Tempo de chegada:");
    scanf("%d\n",&TempoChegada);
    // Guarda o tempo de chegada desse processo em uma lista, que é organizada de acordo com o tempo de chegada.
    printf("Tempo de Execução:");
    scanf("%d\n",&TempoExecucao);
    printf("DeadLine:");
    scanf("%d\n",&DeadLine);
    printf("Prioridade:");
    scanf("%d\n",&Prioridade);
  }
  printf("Para testar o Algoritimo FIFO digite 1, para SJF digite 2, para Round Robin digite 3\n e para EDF digite 4");
  printf("\n");
  scanf("%d\n",&Algoritimo);


}
