#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

bool prioridade;

bool verificarPrioridade();

int main() {

	setlocale(LC_ALL, "Portuguese");
	
	printf("Prioridade? \n1 - Sim \n2 - Não\n");
	scanf("%d", &prioridade);
	verificarPrioridade();
	//printf("%s", prioridade?"true":"false");
	return 0;

}


bool verificarPrioridade() {
	if (prioridade = 1) {
	return true;
	} else if(prioridade = 0) {
		return false;
	}
}

