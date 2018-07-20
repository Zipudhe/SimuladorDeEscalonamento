
typedef struct tNode { struct tNode* prox;
                 int TempoChegada,
                  TempoExecucao,
                  DeadLine,
                  Prioridade,
                  executando,
                  TempoNoSistema;
               } Processo;

Processo* createNode(int tempochegada,int tempoexecucao,int deadline,int prioridade);
//************************************************

// void limpaLista(Processo* L);
// // ***********************************************
//
// void initLista( Processo* L);
// // ***********************************************
//
//insere o processo de acordo com o seu tempo de Execução.
//podemos fazer uma função dessa para cada Algoritimo.
bool insereProcesso(Processo* L, int TempoChegada,int TempoExecucao,int DeadLine,int Prioridade);
// //*************************************************

void Fifo(Processo *L,int NumProcessos,int QuantumSistema,int Sobrecarga,char *vet);

// void RoundRobin(Processo *L);

// void Sjf(Processo *L);

// void EDF(Processo *L);
