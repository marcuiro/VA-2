#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>



void verificarPrioridade(bool prioridade, int t, int f);

int main() {

	bool prioridade;
	int t, f;
	setlocale(LC_ALL, "Portuguese");
		
	printf("Prioridade? \n1 - Sim \n0 - Não\n");
	scanf("%d", &prioridade);
	verificarPrioridade(prioridade, t, f);
	
	return 0;

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

