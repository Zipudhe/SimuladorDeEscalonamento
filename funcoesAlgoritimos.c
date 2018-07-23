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
    novo->TempoExecucao = tempoexecucao;
    novo->DeadLine = deadline;
    novo->Prioridade = prioridade;
    novo->executando = 0;
    novo->TempoNoSistema = 0;
		novo->prox = NULL;
		return novo;
	}
	return NULL;
}
//
// bool initFila(Processo** L){
//   (*L)= NULL;
//   L->NumProc = 0;
// }


bool insereProcesso(Processo** L, int TempoChegada,int TempoExecucao,int DeadLine,int Prioridade){
  // printf("hum\n");
  if( (*L) == NULL ){
    (*L) = createNode(TempoChegada, TempoExecucao, DeadLine, Prioridade);
    return true;
  }
  return insereProcesso(&(*L)->prox,TempoChegada, TempoExecucao, DeadLine, Prioridade);
}
//
// bool removeProcesso(Processo* L, Processo valor) {
//
// }
//
// void imprimeListaProcessos(Processo *L){
//   Processo atual = L->inicio;
//   while(atual != NULL){
//     printf("%d",L->TempoChegada);
//     atual = atual->prox;
//   }
// }
//
void Fifo(Processo **L,int NumProcessos,int QuantumSistema,int Sobrecarga){
  Processo *atual = *L;
  // Cada processo vai ser uma linha da matriz para fazer a impressão do gráfico de Gantt
  Processo *atualG = *L;
  Processo *atualL = *L;
  Processo *menor = *L;
  int tempoTotal = 0;
  int count = 0;
  int j = 0;
  int i;
  char matriz[100][100];
  while(atualL != NULL){
    tempoTotal = tempoTotal + atualL->TempoExecucao;
    atualL =  atualL->prox;
  }
  // printf("%d\n",tempoTotal);
  for(i = 0; i < tempoTotal; i++){ // percorre as colunas
    while(atualG != NULL){
      if(menor->TempoChegada > atualG->TempoChegada){
        menor =  atualG;
        atualG = atualG->prox;
        // printf("Zap");
      }
      else{
        atualG =  atualG->prox;
        // printf("zap\t");
      }
    }
    menor->executando = 1;
    atualG = *L;
    // printf("%d",menor->TempoChegada);
    while(atualG != NULL){
      if(atualG->TempoChegada == menor->TempoChegada && atualG->TempoChegada <= count && menor->executando){
        // printf("executando -- ");
        matriz[j][i] = '+';
				// printf("%c",matriz[j][i]);
        menor->TempoNoSistema = atualG->TempoNoSistema+1;
        menor->TempoExecucao = atualG->TempoExecucao-1;
			}
      else if(atualG->TempoChegada <= count && atualG->executando == 0){
        // printf("Chegada <= count e n executando 0\t");
        // printf("count:%d tempo:%d", count, atualG->TempoChegada);
        matriz[j][i] =  '-';
        atualG->TempoNoSistema+1;
      }
      else if(atualG->TempoChegada > count || atualG->TempoExecucao == 0 && atualG->executando == 0){
				// printf("%d --",atualG->TempoExecucao);
				// printf("Nada acontece --  ");
        // printf("count: %d tempo: %d", count, atualG->TempoChegada);
        matriz[j][i] = ' ';
				// printf("%c",matriz[j][i]);
			}
      // printf("\t");
      // if(atualG->executando = 1 && count == QuantumSistema){
      //   atual->TempoExecucao -= QuantumSistema;
      //   count = 0;
      // }
      // printf("%d \t %d", j, i);
      if(menor->TempoExecucao == 0 && atualG->TempoChegada == menor->TempoChegada && atualG->Prioridade == menor->Prioridade){
        atualG->executando = menor->executando = 0;
        atualG->TempoChegada = menor->TempoChegada = 10000;
			}
      atualG =  atualG->prox;
      j++; // percorre as linhas;
    }
		atualG = *L;
    count++;
		for(int linha = 0; linha < NumProcessos; linha++){
			printf("cu\n");
		}
    // menor = *L;
		// printf("\n");
	}
  // printf("%d\n",NumProcessos);
  // for (j = 0; j < NumProcessos; j++) {
  //   for (i = 0; i < tempoTotal; i++) {
  //     printf("%c",matriz[j][i]);
  //   }
  //   printf("\n");
  // }
}

// void RoundRobin(Processo *L,NumProcessos, QuantumSistema, Sobrecarga,char* matriz){
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
//   menor->executando = 1;
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
//     // menor->executando = 1;
//     while(atualL != NULL){
//       if(atual->executando == 1){
//         matriz[j][i] = "+";
//         atual->TempoNoSistema++;
//       }
//       else if(atual->TempoChegada <=  0 && atual->TempoExecucao != 0){
//         matriz[j][i] =  "-";
//         atual->TempoNoSistema++;
//       }
//       else if(atual->TempoChegada <= 0 && atual->TempoExecucao == 0){
//         matriz[j][i] = " ";
//       }
//
//       if(atual->executando = 1 && count == QuantumSistema){
//         atual->TempoExecucao -= QuantumSistema;
//         count = 0;
//       }
//       if(atual->executando == 1 && atual->TempoExecucao == 0){
//         while(atualG->prox != NULL){
//           if(atual->TempoNoSistema > atual->prox->TempoNoSistema){
//             menor =  atual;
//           }
//           else menor = atual->prox;
//           atual =  atual->prox;
//         }
//         atual->executando = 0;
//       menor->executando = 1;
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
// void Sjf(Processo *L,NumProcessos, QuantumSistema, Sobrecarga,char* matriz){
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
//   menor->executando = 1;
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
//     // menor->executando = 1;
//     while(atualL != NULL){
//       if(atual->executando == 1){
//         matriz[j][i] = "+";
//         atual->TempoNoSistema++;
//       }
//       else if(atual->TempoChegada <=  0 && atual->TempoExecucao != 0){
//         matriz[j][i] =  "-";
//         atual->TempoNoSistema++;
//       }
//       else if(atual->TempoChegada <= 0 && atual->TempoExecucao == 0){
//         matriz[j][i] = " ";
//       }
//
//       if(atual->executando = 1 && count == QuantumSistema){
//         atual->TempoExecucao -= QuantumSistema;
//         count = 0;
//       }
//       if(atual->executando == 1 && atual->TempoExecucao == 0){
//         while(atualG->prox != NULL){
//           if(atual->TempoNoSistema > atual->prox->TempoNoSistema){
//             menor =  atual;
//           }
//           else menor = atual->prox;
//           atual =  atual->prox;
//         }
//         atual->executando = 0;
//       menor->executando = 1;
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
// void EDF(Processo *L,NumProcessos, QuantumSistema, Sobrecarga,char* matriz){
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
//   menor->executando = 1;
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
//     // menor->executando = 1;
//     while(atualL != NULL){
//       if(atual->executando == 1){
//         matriz[j][i] = "+";
//         atual->TempoNoSistema++;
//       }
//       else if(atual->TempoChegada <=  0 && atual->TempoExecucao != 0){
//         matriz[j][i] =  "-";
//         atual->TempoNoSistema++;
//       }
//       else if(atual->TempoChegada <= 0 && atual->TempoExecucao == 0){
//         matriz[j][i] = " ";
//       }
//
//       if(atual->executando = 1 && count == QuantumSistema){
//         atual->TempoExecucao -= QuantumSistema;
//         count = 0;
//       }
//       if(atual->executando == 1 && atual->TempoExecucao == 0){
//         while(atualG->prox != NULL){
//           if(atual->TempoNoSistema > atual->prox->TempoNoSistema){
//             menor =  atual;
//           }
//           else menor = atual->prox;
//           atual =  atual->prox;
//         }
//         atual->executando = 0;
//       menor->executando = 1;
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
