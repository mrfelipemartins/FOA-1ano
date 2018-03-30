#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <locale.h>
#include <string.h>

struct Pessoas { //Declara��o da struct
	int codigo;
	char nome [50];
};

struct Pessoas vet_pes[5]; //Passando a struct pra vetor[5]

int k; //Vari�vel de contagem dos �ndices do vetor

void inserir(struct Pessoas vet[5], int *kp); // Fun��o para Inserir no cadastro
void alterar(struct Pessoas vet[5], int *kp); // Fun��o para Alterar nome no cadastro
void consultar(struct Pessoas vet[5], int *kp); // Fun��o para Consultar o cadastro
void imprimir(struct Pessoas vet[5], int *kp); // Fun��o para Imprimir o cadastro
// obs: *kp foi usado como ponteiro para vari�vel k

int main() { // Fun��o main/principal

	setlocale(LC_ALL, "");
	k = 0; // Inicializa��o da vari�vel de contagem
	int menu;
	
	do {
		printf ("\n\n");
		printf ("\t\t====================================================\n");
		printf ("\t\t Inserir                                       - [1]\n");
		printf ("\t\t Alterar                                       - [2]\n");
		printf ("\t\t Consultar                                     - [3]\n");
		printf ("\t\t Imprimir                                      - [4]\n");
		printf ("\t\t Sair                                          - [5]\n");
		printf ("\t\t====================================================\n");
		
		do {
			printf ("\n\t\t          Entre com a op��o desejada: ");
			scanf ("%i", &menu);
		} while (menu < 1 || menu > 5);	
		
		switch (menu) { // Menu do cadastro
			
			case 1:
				inserir(vet_pes, &k);
				break;
				
			case 2:
				alterar(vet_pes, &k);
				break;
				
			case 3
				consultar(vet_pes, &k);
				break;
				
			case 4:
				imprimir(vet_pes, &k);
				break;
				
			case 5:
				break;
				
			default:
				printf ("\nOp��o inv�lida! Escolha uma op��o v�lida entre 1 e 5!");
		}	
	} while (menu != 5);
}

void inserir(struct Pessoas vet[5], int *kp) { // Fun��o para Inserir no cadastro
	
	char nomaux[50];
	int codaux, i, j;
	char resp, resp1;
	
	resp = 'S';
	
	if (*kp > 0) // Na primeira inser��o no vetor, i ser� sempre 0. A partir de cada inser��o o valor de i aumentar� 1, como ser� visto mais abaixo.
		i = *kp;
	else
		i = 0;
	
	while (resp == 'S' && i < 5) { //Loop de inser��o
		
		do { // C�digo da inser��o no cadastro
			printf ("\nEntre com o c�digo: ");
			fflush (stdin);
			scanf ("%d", &codaux);
		} while (codaux <= 0);
		
		do { // Nome da inser��o no cadastro
			printf ("\nEntre com o nome: ");
			fflush (stdin);
			gets (nomaux);
		} while (nomaux == "");
		
		j = 0;
		// � feito a verifica��o para conferir se o c�digo inputado j� existe. Lembrando que i = k, na 1� inser��o i = 0,
		// na 2� i = 1, na 3� i = 2, na 4� i = 3, na 5� i = 4. De in�cio, codaux � comparado a posi��o dos vetores[0], depois [1], [2], etc
		// enquanto j (inicializado em zero) for menor do que a contagem atual do �ndice do vetor (i)
		while (codaux != vet[j].codigo && j < i) { 
			j++;
		}
		
		if (j == i) { //Quando j == i, chegamos na pr�xima posi��o livre para inser��o do vetor  
			
			do {
				printf ("\nConfirma a inclus�o (S/N)? ");
				fflush (stdin);
				scanf ("%c", &resp1);
			} while (resp1 != 'S' && resp1 != 'N');
			
			if (resp1 == 'S' || resp1 == 's') { // Caso confirmado, a inser��o ser� feita
				vet[i].codigo = codaux;
				strcpy (vet[i].nome, nomaux);
				printf ("\nInclus�o efetuada com sucesso!");
				i++; //Aumento da contagem do i para a pr�xima posi��o vazia do vetor
			}
		}
		else { // Caso j != i, significa que codaux == vet[j].codigo, ent�o o c�digo j� existe
			printf ("\nC�digo j� cadastrado!");
		}
		
		if (i < 5) { // Enquando o vetor n�o for completo, � permitido inserir
			do {
				printf ("\n\nDeseja continuar incluindo (S/N)? "); // Loop de inclus�o pt2
				fflush (stdin);
				scanf ("%c", &resp);
			} while (resp != 'S' && resp != 'N');
		}
	}
	
	*kp = i; //*kp � a vari�vel de verifica��o global, i � a vari�vel de verifica��o local. As duas ser�o iguais
	if (i > 4) { //Quando vetor estiver com os 5 �ndices completos (0 at� 4), o vetor estar� cheio
		printf ("\n\nVetor j� est� cheio! N�o � permitido mais armazenas valores!");
	}	
}

void alterar(struct Pessoas vet[5], int *kp) { // Fun��o para Alterar nome no cadastro
	
	char nomaux[50];
	int codaux, j;
	char resp, resp1;
	
	resp = 'S';
	
	if (*kp > 0) { // S� ser� permitido alterar algum cadastro se existir algum, ou seja, quando a vari�vel de contagem n�o for mais 0,
	// significa que pelo menos uma inser��o foi feita
			
		while (resp == 'S') { // Loop de altera��o
			
			do { // C�digo do cadastro que deseja alterar
				printf ("\nEntre com o c�digo do nome que deseja alterar: ");
				fflush (stdin);
				scanf ("%d", &codaux);
			} while (codaux <= 0);
			
			j = 0; // Mesma fun��o do algoritmo na inser��o
			while (codaux != vet[j].codigo && j < 5) {
				j++;
			}
			
			if (codaux == vet[j].codigo) { // A diferen�a em rela��o a inser��o � que nesse caso n�s buscamos que o codaux inputado seja
			//igual ao que est� armazenado no vetor
				
				printf ("\nO nome armazenado �: "); // Mostra o nome atual
				puts (vet[j].nome);
				do {
					printf ("\nEntre com o novo nome: "); // Escolha do novo nome para substitui��o
					fflush (stdin);
					gets (nomaux);
				} while (nomaux == "");
				
				do {
					printf ("\nConfirma a altera��o (S/N)? ");
					fflush (stdin);
					scanf ("%c", &resp1);
				} while (resp1 != 'S' && resp1 != 'N');
				
				if (resp1 == 'S') { // Caso confirme, altera��o ser� feita
					strcpy (vet[j].nome, nomaux);
					printf ("\nAltera��o efetuada com sucesso!");
				}
			}	
			else // Caso codaux != vet[j].codigo, significa que o codaux inputado n�o foi inserido no vetor na fun��o de inserir
				printf ("\nC�dido n�o cadastrado!");
						
			do {
				printf ("\n\nDeseja continuar alterando (S/N)? "); // Loop de altera��o pt2
				fflush (stdin);
				scanf ("%c", &resp);
			} while	(resp != 'S' && resp != 'N');
		}
	}	
	else // Caso kp = 0, nenhum cadastro foi inserido ainda e o vetor est� vazio
		printf ("\nVetor vazio!");
}

void consultar(struct Pessoas vet[5], int *kp) { // Fun��o para Consultar o cadastro
	
	int codaux, j;
	char resp;
	
	resp = 'S';
	
	if (*kp > 0) { // S� ser� permitido consultar algum cadastro se existir algum, ou seja, quando a vari�vel de contagem n�o for mais 0,
	// significa que pelo menos uma inser��o foi feita
			
		while (resp == 'S') { // Loop de consulta
			
			do {
				printf ("\nEntre com o c�digo do nome que deseja consultar: ");
				fflush (stdin);
				scanf ("%d", &codaux);
			} while (codaux <= 0);
			
			j = 0; // Mesmo caso que o algoritmo da fun��o de alterar
			while (codaux != vet[j].codigo && j < 5) {
				j++ ;
			}
			
			if (codaux == vet[j].codigo) { // Mostra o nome cadastrado no vetor
				printf ("\nO nome armazenado �: ");
				puts (vet[j].nome);	
			}
			else
				printf ("\nC�dido n�o cadastrado!"); // Caso codaux != vet[j].codigo, significa que o codaux inputado n�o foi 
				//inserido no vetor na fun��o de inserir
			
			do {
				printf ("\n\nDeseja continuar consultando (S/N)? "); // Loop da consulta pt2
				fflush (stdin);
				scanf ("%c", &resp);
			} while	(resp != 'S' && resp != 'N');
		}
	}
		
	else
		printf ("\nVetor vazio!"); // Caso kp = 0, nenhum cadastro foi inserido ainda e o vetor est� vazio
}

void imprimir(struct Pessoas vet[5], int *kp) { // Fun��o para Imprimir o cadastro
	
	int j;
	
	if (*kp > 0) { // S� ser� permitido imprimir o cadastro se existir algum, ou seja, quando a vari�vel de contagem n�o for mais 0,
	// significa que pelo menos uma inser��o foi feita
			
		for (j = 0; j < *kp; j++) { // For p/ percorrer o vetor come�ando pelo �ndice 0 at� o �ndice determinado pela vari�vel (kp) de contagem do vetor 
			printf ("\nC�digo: %d", vet[j].codigo);
			printf ("\nNome: ");
			puts (vet[j].nome);
		}
		printf ("\nPressione qualquer tecla para voltar no menu!"); // Voltar para o menu ap�s impress�o
		getch();
	}
	else
		printf ("\nVetor vazio!"); // Caso kp = 0, nenhum cadastro foi inserido ainda e o vetor est� vazio
}
