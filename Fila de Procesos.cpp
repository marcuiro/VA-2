#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


struct Node {
	int PID;
	char name [32];
	struct Node *next;
};

typedef struct Node node;

//protótipos de funções
int menu(void);

int main() {

	setlocale(LC_ALL, "Portuguese");

	int select;
	
	do{
		select=menu();
		//opcao(FILA, select);
	} while(select);
	
	return 0;

}

int menu(void) {
	
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
}
