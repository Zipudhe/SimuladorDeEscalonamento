
typedef struct tNode { struct tNode* prox;
                 int TempoChegada;
                 int TempoExecucao;
                 int DeadLine;
                 int Prioridade;
                 int exec = 0;
                 int TempoNoSistema = 0;
               } Processo;

Processo* createNode(int tempochegada,int tempoexecucao,int deadline,int prioridade);
//************************************************

void limpaLista(Processo** L);
// ***********************************************

void initLista( Processo** L);
// ***********************************************

//insere o processo de acordo com o seu tempo de Execução.
//podemos fazer uma função dessa para cada Algoritimo.
bool insereProcesso(Processo** L, Processo P);
//*************************************************

bool removeProcesso(Processo** L);
//*************************************************

void imprimeListaProcessos(Processo *L);

void BuscaMenorTempoChegada(Processo *L);

void Fifo(Processo *L);

void RoundRobin(Processo *L);

void Sjf(Processo *L);

void EDF(Processo *L);
