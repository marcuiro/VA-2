#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Matheus do Nascimento Saito - 2020262
// Marco Antônio Martins - 1910497
// Pedro Wilson Rodrigues de Lima - 2020267
// Alexandre Silva Oliveira - 2111127
// Guilherme Gomes de Almeida - 2020890
// Marcos Vinicius Fernandes Alves - 2021030

typedef struct Node {
	int PID;
	int tamanho;
	char nome [32];
	struct Node *next;
} Node;

typedef struct Fila {
	Node *ini;
	Node *end;
}Fila;

//protótipos de funções
void verificarPrioridade(bool prioridade, int t, int f);
void enfileirarProcesso(int PID, int tamanho, char nome[32], Fila *f1, Fila *f2);
void liberarPrrocessosF1 (Fila *f1);
void liberarPrrocessosF1 (Fila *f2);
void imprimirF1 (Fila *f1);
void imprimirF2 (Fila *f2);
void RemoveProcessoPorPID(int numPID);

int main() {

	setlocale(LC_ALL, "Portuguese");
	
	bool prioridade;
	int t, f, numPID, PID, tamanho, select;
	char nome[32];
	
    void inicializar(Fila * f1, Fila * f2);
	
	
do{
		printf("\n0 - Sair \n1 - Criar Processo \n2 - Remover Processo F1 \n3 - Remover Processo F2 \n4 - Exibir fila F1 \n5 - Exibir fila F2 \n6 - Remover Processo Específico com Prioridade \n");
		scanf("%d", &select);
		
		switch(select){
			case 0:
				printf("Obrigado por utilizar o programa!");
				break;
			case 1:
				verificarPrioridade(prioridade, t, f);
				
				printf("Prioridade? \n1 - Sim \n0 - Não\n");
				scanf("%d", &prioridade);
				printf("Nome do Processo: \n");
				scanf("%s", &nome[32]);
				printf("ID do processo: \n");
				scanf("%d", &PID);
				printf("Tamanho do processo: \n");
				scanf("%d", &tamanho);
				verificarPrioridade(prioridade, t, f);
				void enfileirarProcesso(int PID, int tamanho,  char nome[32], Fila *f1, Fila f2);
				break;
			case 2:
				void liberarPrrocessosF1 (Fila *f1);
				break;
			case 3:
				void liberarPrrocessosF12 (Fila *f2);
				break;
			case 4:
				void imprimirF1 (Fila *f1);
				break;
			case 5:
				void imprimirF2 (Fila *f2);
				break;
			case 6:
				printf("Insira o numero do PID que deve ser removido \n");
				scanf("%d", &numPID);
				void RemoveProcessoPorPID(int NumPID);
				break;
			default:
				if(select != 0)
					printf("Opção invalida!");
		}
	} while (select != 0);
	
	return 0;

}

void inicializar(Fila *f1, Fila *f2) {
	f1->ini = NULL;
	f1->end = NULL;
	f2->ini = NULL;
	f2->end = NULL;
}

void verificarPrioridade(bool prioridade, int t, int f) {
	t = 1;
	f = 0;
	if (prioridade == t) {
		//printf("Good! ");
		return ;
	} if(prioridade == f) {
		//printf("Not good! ");
		return;
		}
}

void enfileirarProcesso(int PID, int tamanho, char nome[32], Fila *f1, Fila *f2) {
	Node *ptr = (Node*) malloc(sizeof(Node));
	
	bool prioridade;
	int t, f;
	
	verificarPrioridade(prioridade, t, f);
	if(ptr == NULL){
		printf("FALHA NA ALOCAÇÂO!!! /n");
		} if (prioridade == f) {
			ptr->PID = PID;
			ptr->tamanho = tamanho;
			ptr->nome[32] = nome[32];
			ptr->next = NULL;
			if(f1->ini == NULL) {
				f1->ini = ptr;
			} else {
				f1->end->next = ptr;
			}
			f1->end = ptr;
			return;
		} else if (prioridade == t) {
			ptr->PID = PID;
			ptr->tamanho = tamanho;
			ptr->nome[32] = nome[32];
			ptr->next = NULL;
			if(f2->ini == NULL) {
				f2->ini = ptr;
			} else {
				f2->end->next = ptr;
			}
			f2->end = ptr;
			return;
		}
		
}

void liberarPrrocessosF1(Fila *f1) {
	Node *ptr = f1->ini;
	int PID;
	int tamanho;
	char nome[32];
	if(ptr != NULL) { // Se o ponteiro não esta apontando para algo que seja NULL.
		f1->ini = ptr->next; // Fila f1 no inicio se torna ponteiro apontando proximo
		PID = ptr->PID; // Ponteiro apontando dados.
		nome[32] = ptr->nome[32]; // Ponteiro apontando dados.
		tamanho = ptr->tamanho; // Ponteiro apontando dados.		
		free(ptr); // Liberando ponteiro
		if(f1->ini == NULL) {
			f1->end = NULL;
		}
		return;
	} else { // se tiver algo no ponteiro.
		printf("Fila Vazia!!! \n");
		return;
	}
}

void liberarPrrocessosF2(Fila *f2) {
	Node *ptr = f2->ini;
	int PID;
	int tamanho;
	char nome[32];
	if(ptr != NULL) { // Se o ponteiro não esta apontando para algo que seja NULL.
		f2->ini = ptr->next; // Fila f1 no inicio se torna ponteiro apontando proximo
		PID = ptr->PID; // Ponteiro apontando dados.
		nome[32] = ptr->nome[32]; // Ponteiro apontando dados.
		tamanho = ptr->tamanho; // Ponteiro apontando dados.		
		free(ptr); // Liberando ponteiro
		if(f2->ini == NULL) {
			f2->end = NULL;
		}
		return;
	} else { // se tiver algo no ponteiro.
		printf("Fila Vazia!!! \n");
		return;
	}
}

void imprimirF1 (Fila *f1) {
	Node *ptr = f1->ini;
	if(ptr != NULL) {
		while(ptr != NULL) {
			printf("%s ", ptr->nome[32]);
			printf("%d ", ptr->PID);
			printf("%d ", ptr->tamanho);
			ptr = ptr->next;
		}	
	} else {
		printf("Fila Vazia!!! \n");
	}
}

void imprimirF2 (Fila *f2) {
	Node *ptr = f2->ini;
	if(ptr != NULL) {
		while(ptr != NULL) {
			printf("%s ", ptr->nome[32]);
			printf("%d ", ptr->PID);
			printf("%d ", ptr->tamanho);
			ptr = ptr->next;
		}	
	} else {
		printf("Fila de Prioridades Vazia!!! \n");
	}
}

void RemoveProcessoPorPIDF1(int NumPID, Fila *f1) {
	Node *ptr = f1->ini;
	Node *anterior = f1->ini = NULL;
	int PID;
	int tamanho;
	char nome[32];
	if (ptr != NULL) {
		f1->ini = ptr->next;
		if (ptr->PID == NumPID) {
			PID = ptr->PID; // Ponteiro apontando dados.
			nome[32] = ptr->nome[32]; // Ponteiro apontando dados.
			tamanho = ptr->tamanho; // Ponteiro apontando dados.		
			free (ptr);
			anterior->next = ptr->next; // Refazendo encadeamento (Eu acho).
	 	}
	}
	return;
}

void RemoveProcessoPorPIDF2(int numPID, Fila *f2) {
	Node *ptr = f2->ini;
	Node *anterior = f2->ini = NULL;
	int PID;
	int tamanho;
	char nome[32];
	if (ptr != NULL) {
		f2->ini = ptr->next;
		if (ptr->PID == numPID) {
			PID = ptr->PID; // Ponteiro apontando dados.
			nome[32] = ptr->nome[32]; // Ponteiro apontando dados.
			tamanho = ptr->tamanho; // Ponteiro apontando dados.		
			free (ptr);
			anterior->next = ptr->next; // Refazendo encadeamento (Eu acho).
	 	}
	}
	return;
}
