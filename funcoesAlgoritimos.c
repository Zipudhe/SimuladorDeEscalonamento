#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include "funcoesAlgoritimos.h"

// void initLista(Processo* L){
//
// }

Processo* createNode(int tempochegada,int tempoexecucao,int deadline,int prioridade) {
	Processo* novo = (Processo*) malloc(sizeof(Processo));
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


bool insereProcesso(Processo* L, int TempoChegada,int TempoExecucao,int DeadLine,int Prioridade){
  if(L == NULL ){
    L = createNode(TempoChegada, TempoExecucao, DeadLine, Prioridade);
    return true;
  }
  return insereProcesso(L->prox,TempoChegada, TempoExecucao, DeadLine, Prioridade);
}
//
// bool removeProcesso(Processo* L, Processo valor) {
//
// }
//
// void imprimeListaProcessos(Processo *L){
//   Processo atual = L;
//   while(atual != NULL){
//     printf("%d",L->TempoChegada);
//     atual = atual->prox;
//   }
// }
//
void Fifo(Processo *L,int NumProcessos,int QuantumSistema,int Sobrecarga,char *vet){
  printf("ZAP\n");
  // Cada processo vai ser uma linha da matriz para fazer a impressão do gráfico de Gantt
//   Processo atualG = L;
//   Processo atualL = L;
//   Processo menor;
//   int tempoTotal = 0;
//   int count = 0;
//   int j = 0;
//   while(atualG->prox != NULL){
//     if(atual->TempoChegada > atual->prox->TempoChegada){
//       menor =  atual;
//     }
//     else menor = atual->prox;
//     atual =  atual->prox;
//   }
//   menor->exec = 1;
//   // while(atual != NULL){
//   //   tempoTotal = tempoTotal + L->TempoExecucao;
//   //   atual =  atual->prox;
//   // }
//   for(int i = 0; i < tempoTotal; i++){ // percorre as colunas
//     count++;
//     // while(atualG->prox != NULL){
//     //   if(atual->TempoChegada == 0 && atual->TempoExecucao < menor->TempoExecucao){
//     //     menor =  atual;
//     //   }
//     //   else atual =  atual->prox;
//     // }
//     // menor->exec = 1;
//     while(atualL != NULL){
//       if(atual->exec == 1){
//         vet[j][i] = "+";
//         atual->TempoNoSistema++;
//       }
//       else if(atual->TempoChegada <=  0 && atual->TempoExecucao != 0){
//         vet[j][i] =  "-";
//         atual->TempoNoSistema++;
//       }
//       else if(atual->TempoChegada <= 0 && atual->TempoExecucao == 0){
//         vet[j][i] = " ";
//       }
//
//       if(atual->exec = 1 && count == QuantumSistema){
//         atual->TempoExecucao -= QuantumSistema;
//         count = 0;
//       }
//       if(atual->exec == 1 && atual->TempoExecucao == 0){
//         while(atualG->prox != NULL){
//           if(atual->TempoNoSistema > atual->prox->TempoNoSistema){
//             menor =  atual;
//           }
//           else menor = atual->prox;
//           atual =  atual->prox;
//         }
//         atual->exec = 0;
//       menor->exec = 1;
//     }
//     atual =  atual->prox;
//     j++; // percorre as linhas;
//   }
//   count = 0;
//   tempoTotal = tempoTotal + NumProcessos*Sobrecarga + 20;
//   for(int i; i < NumProcessos; i++){
//     for(int j; j < tempoTotal; j++){
//
//     }
//   }
// }
}

// void RoundRobin(Processo *L,NumProcessos, QuantumSistema, Sobrecarga,char* vet){
//   // Cada processo vai ser uma linha da matriz para fazer a impressão do gráfico de Gantt
//   Processo atualG = L;
//   Processo atualL = L;
//   Processo menor;
//   int tempoTotal = 0;
//   int count = 0;
//   int j = 0;
//   while(atualG->prox != NULL){
//     if(atual->TempoChegada > atual->prox->TempoChegada){
//       menor =  atual;
//     }
//     else menor = atual->prox;
//     atual =  atual->prox;
//   }
//   menor->exec = 1;
//   // while(atual != NULL){
//   //   tempoTotal = tempoTotal + L->TempoExecucao;
//   //   atual =  atual->prox;
//   // }
//   for(int i = 0; i < tempoTotal; i++){ // percorre as colunas
//     count++;
//     // while(atualG->prox != NULL){
//     //   if(atual->TempoChegada == 0 && atual->TempoExecucao < menor->TempoExecucao){
//     //     menor =  atual;
//     //   }
//     //   else atual =  atual->prox;
//     // }
//     // menor->exec = 1;
//     while(atualL != NULL){
//       if(atual->exec == 1){
//         vet[j][i] = "+";
//         atual->TempoNoSistema++;
//       }
//       else if(atual->TempoChegada <=  0 && atual->TempoExecucao != 0){
//         vet[j][i] =  "-";
//         atual->TempoNoSistema++;
//       }
//       else if(atual->TempoChegada <= 0 && atual->TempoExecucao == 0){
//         vet[j][i] = " ";
//       }
//
//       if(atual->exec = 1 && count == QuantumSistema){
//         atual->TempoExecucao -= QuantumSistema;
//         count = 0;
//       }
//       if(atual->exec == 1 && atual->TempoExecucao == 0){
//         while(atualG->prox != NULL){
//           if(atual->TempoNoSistema > atual->prox->TempoNoSistema){
//             menor =  atual;
//           }
//           else menor = atual->prox;
//           atual =  atual->prox;
//         }
//         atual->exec = 0;
//       menor->exec = 1;
//     }
//     atual =  atual->prox;
//     j++; // percorre as linhas;
//   }
//   count = 0;
//   tempoTotal = tempoTotal + NumProcessos*Sobrecarga + 20;
//   for(int i; i < NumProcessos; i++){
//     for(int j; j < tempoTotal; j++){
//
//     }
//   }
// }
// }
//
// void Sjf(Processo *L,NumProcessos, QuantumSistema, Sobrecarga,char* vet){
//   // Cada processo vai ser uma linha da matriz para fazer a impressão do gráfico de Gantt
//   Processo atualG = L;
//   Processo atualL = L;
//   Processo menor = L;
//   int tempoTotal = 0;
//   int count = 0;
//   int j = 0;
//   while(atualG->prox != NULL){
//     if(atual->TempoChegada == 0 && atual->TempoExecucao < menor->TempoExecucao){
//       menor =  atual;
//     }
//     else atual =  atual->prox;
//   }
//   menor->exec = 1;
//   // while(atual != NULL){
//   //   tempoTotal = tempoTotal + L->TempoExecucao;
//   //   atual =  atual->prox;
//   // }
//   for(int i = 0; i < tempoTotal; i++){ // percorre as colunas
//     count++;
//     // while(atualG->prox != NULL){
//     //   if(atual->TempoChegada == 0 && atual->TempoExecucao < menor->TempoExecucao){
//     //     menor =  atual;
//     //   }
//     //   else atual =  atual->prox;
//     // }
//     // menor->exec = 1;
//     while(atualL != NULL){
//       if(atual->exec == 1){
//         vet[j][i] = "+";
//         atual->TempoNoSistema++;
//       }
//       else if(atual->TempoChegada <=  0 && atual->TempoExecucao != 0){
//         vet[j][i] =  "-";
//         atual->TempoNoSistema++;
//       }
//       else if(atual->TempoChegada <= 0 && atual->TempoExecucao == 0){
//         vet[j][i] = " ";
//       }
//
//       if(atual->exec = 1 && count == QuantumSistema){
//         atual->TempoExecucao -= QuantumSistema;
//         count = 0;
//       }
//       if(atual->exec == 1 && atual->TempoExecucao == 0){
//         while(atualG->prox != NULL){
//           if(atual->TempoNoSistema > atual->prox->TempoNoSistema){
//             menor =  atual;
//           }
//           else menor = atual->prox;
//           atual =  atual->prox;
//         }
//         atual->exec = 0;
//       menor->exec = 1;
//     }
//     atual =  atual->prox;
//     j++; // percorre as linhas;
//   }
//   count = 0;
//   tempoTotal = tempoTotal + NumProcessos*Sobrecarga + 20;
//   for(int i; i < NumProcessos; i++){
//     for(int j; j < tempoTotal; j++){
//
//     }
//   }
// }
// }
//
// void EDF(Processo *L,NumProcessos, QuantumSistema, Sobrecarga,char* vet){
//   // Cada processo vai ser uma linha da matriz para fazer a impressão do gráfico de Gantt
//   Processo atualG = L;
//   Processo atualL = L;
//   Processo menor;
//   int tempoTotal = 0;
//   int count = 0;
//   int j = 0;
//   while(atualG->prox != NULL){
//     if(atual->TempoChegada == 0 && atual->DeadLine < menor->DeadLine){
//       menor =  atual;
//       atual =  atual->prox;
//     }
//     else atual =  atual->prox;
//   }
//   menor->exec = 1;
//   // while(atual != NULL){
//   //   tempoTotal = tempoTotal + L->TempoExecucao;
//   //   atual =  atual->prox;
//   // }
//   for(int i = 0; i < tempoTotal; i++){ // percorre as colunas
//     count++;
//     // while(atualG->prox != NULL){
//     //   if(atual->TempoChegada == 0 && atual->TempoExecucao < menor->TempoExecucao){
//     //     menor =  atual;
//     //   }
//     //   else atual =  atual->prox;
//     // }
//     // menor->exec = 1;
//     while(atualL != NULL){
//       if(atual->exec == 1){
//         vet[j][i] = "+";
//         atual->TempoNoSistema++;
//       }
//       else if(atual->TempoChegada <=  0 && atual->TempoExecucao != 0){
//         vet[j][i] =  "-";
//         atual->TempoNoSistema++;
//       }
//       else if(atual->TempoChegada <= 0 && atual->TempoExecucao == 0){
//         vet[j][i] = " ";
//       }
//
//       if(atual->exec = 1 && count == QuantumSistema){
//         atual->TempoExecucao -= QuantumSistema;
//         count = 0;
//       }
//       if(atual->exec == 1 && atual->TempoExecucao == 0){
//         while(atualG->prox != NULL){
//           if(atual->TempoNoSistema > atual->prox->TempoNoSistema){
//             menor =  atual;
//           }
//           else menor = atual->prox;
//           atual =  atual->prox;
//         }
//         atual->exec = 0;
//       menor->exec = 1;
//     }
//     atual =  atual->prox;
//     j++; // percorre as linhas;
//   }
//   count = 0;
//   tempoTotal = tempoTotal + NumProcessos*Sobrecarga + 20;
//   for(int i; i < NumProcessos; i++){
//     for(int j; j < tempoTotal; j++){
//
//     }
//   }
// }
// }
