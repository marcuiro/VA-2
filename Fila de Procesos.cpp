#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


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
void enfileirar(int PID, int tamanho, char nome[32], Fila *f1, Fila *f2);
//int menu(void);

int main() {

	setlocale(LC_ALL, "Portuguese");

	int select;
	
	return 0;

}

void enfileirar(int PID, int tamanho, char nome[32], Fila *f1, Fila *f2) {
	Node *ptr = (Node*) malloc(sizeof(Node));
	if(ptr == NULL){
		printf("FALHA NA ALOCAÇÂO!!! /n");
		} else {
			ptr->PID = PID;
			ptr->tamanho = tamanho;
			ptr->nome[32] = nome[32];
			ptr->next = NULL;
			if(f1->ini == NULL) {
				f1->ini = ptr;
			}
			
			f1->end = ptr;
	}
}
/*int menu(void) {
	
	int select;
	
	printf("Escolha a opcao\n");
 	printf("0. Sair\n");
 	printf("1. Exibir fila de processos\n");
 	printf("2. Adicionar processos a fila\n");
 	printf("3. Remover processo da fila\n");
	printf("4. Remover processo especifico da fila\n");
	printf("5. Limpar fila");
	printf("Opcao: "); 
	scanf("%d", &select);

 return select;
}*/
