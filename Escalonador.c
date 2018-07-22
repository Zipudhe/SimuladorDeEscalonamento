#include <stdio.h>
#include <stdlib.h>

#define Quantum 2
#define Sobrecarga 1
#define MAX 100

typedef struct
{
    int pid;
    int chegada;
    int execucao;
    int espera;
    int prioridade;
    int deadline;    
    int turnaround;
    int executado;
} Processo;

Processo p[MAX];

int algoritimo;

void print_table(Processo p[], int n);
void print_gantt_chart(Processo p[], int n);

int main()
{
    Processo p[MAX];
    int i, j, n, a;
    int soma_espera = 0, soma_turnaround = 0;
    printf("Digite o número total de processos: ");
    scanf("%d", &n);
    printf("Digite o tempo de chegada de cada processo:\n");
    for(i=0; i<n; i++) {
        p[i].pid = i+1;
        printf("P[%d] : ", i+1);
        scanf("%d", &p[i].chegada);
        p[i].espera = p[i].turnaround = 0;
    }
    printf("Digite o tempo de execução de cada processo:\n");
    for(i=0; i<n; i++) {
        p[i].pid = i+1;
        printf("P[%d] : ", i+1);
        scanf("%d", &p[i].execucao);
    }
    //printf("Digite a prioridade de cada processo:\n");
    //for(i=0; i<n; i++) {
    //    p[i].pid = i+1;
    //    printf("P[%d] : ", i+1);
    //    scanf("%d", &p[i].prioridade);
    //}
    //printf("Digite o deadline de cada processo:\n");
    //for(i=0; i<n; i++) {
    //    p[i].pid = i+1;
    //    printf("P[%d] : ", i+1);
    //    scanf("%d", &p[i].deadline);
    //}
    printf("Qual algorítmo deseja executar?:\n");
    printf("1) FIFO:\n");
    printf("2) Round-Robin:\n");
    printf("3) EDF:\n");
    printf("4) SJF:\n");
    scanf("%d", &a);
    if (a == 1 ) { //Executa o FiFo
        //Calcular espera e Turnaround
        p[0].turnaround = p[0].chegada+p[0].execucao;
        for(i=1; i<n; i++) {
            p[i].espera = p[i].chegada + p[i-1].turnaround;
            p[i].turnaround = p[i].execucao + p[i-1].turnaround;
        }
        //Calcular a soma da espera e turnaround
        for(i=0; i<n; i++) {
            soma_espera += p[i].espera;
            soma_turnaround += p[i].turnaround;
    	}

    // Tabela
        puts(""); // Linha vazia
        print_table(p, n);
        puts(""); // Linha vazia
        printf("Tempo total de espera      : %-2d\n", soma_espera);
        printf("Tempo de espera médio    : %-2.2lf\n", (double)soma_espera / (double) n);
        printf("Turnaround total   : %-2d\n", soma_turnaround);
        printf("Turnaround médio : %-2.2lf\n", (double)soma_turnaround / (double) n);
    // printar gantt
        puts(""); // linha vazia
        puts("          GRÁFICO DE GANTT          ");
        puts("          ****************          ");
        print_gantt_chart(p, n);
        return 0;
    }

    // Tabela
        puts(""); // Linha vazia
        print_table(p, n);
        puts(""); // Linha vazia
        printf("Tempo toal de espera      : %-2d\n", soma_espera);
        printf("Tempo de espera médio    : %-2.2lf\n", (double)soma_espera / (double) n);
        printf("Turnaround total   : %-2d\n", soma_turnaround);
        printf("Turnaround médio : %-2.2lf\n", (double)soma_turnaround / (double) n);
    // printar gantt
        puts(""); // linha vazia
        puts("          GRÁFICO DE GANTT          ");
        puts("          ****************          ");
        print_gantt_chart(p, n);
        return 0;
}
void print_table(Processo p[], int n)
{
    int i;

    puts("+-----+------------+----------+------------+----------+--------------+-----------------+");
    puts("| PID |  Chegada   | Execução | Prioridade | Deadline |    Espera    |    Turnaround   |");
    puts("+-----+------------+----------+------------+----------+--------------+-----------------+");

    for(i=0; i<n; i++) {
        printf("| %2d  |     %2d     |   %2d     |     %2d     |    %2d    |      %2d      |        %2d       |\n"
               , p[i].pid, p[i].chegada, p[i].execucao,  p[i].prioridade, p[i].deadline, p[i].espera, p[i].turnaround );
          puts("+-----+------------+----------+------------+----------+--------------+-----------------+");
    }

}


void print_gantt_chart(Processo p[], int n)
{
    int i, j;
    // Barra de Cima
    printf(" ");
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].turnaround; j++) printf("--");
        printf(" ");
    }
    printf("\n|");

    // Printar processos do meio
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].execucao - 1; j++) printf(" ");
        printf("P%d", p[i].pid);
        for(j=0; j<p[i].execucao - 1; j++) printf(" ");
        printf("|");
    }
    printf("\n ");
    // Printar Barra de Baixo
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].turnaround; j++) printf("--");
        printf(" ");
    }
    printf("\n");

    // Pintar a timeline
    printf("0");
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].execucao; j++) printf("  ");
        if(p[i].turnaround > 9) printf("\b");
        printf("%d", p[i].turnaround);

    }
    printf("\n");

}
    