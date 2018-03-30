#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <locale.h>
#include <string.h>

struct Pessoas { //Declaração da struct
	int codigo;
	char nome [50];
};

struct Pessoas vet_pes[5]; //Passando a struct pra vetor[5]

int k; //Variável de contagem dos índices do vetor

void inserir(struct Pessoas vet[5], int *kp); // Função para Inserir no cadastro
void alterar(struct Pessoas vet[5], int *kp); // Função para Alterar nome no cadastro
void consultar(struct Pessoas vet[5], int *kp); // Função para Consultar o cadastro
void imprimir(struct Pessoas vet[5], int *kp); // Função para Imprimir o cadastro
// obs: *kp foi usado como ponteiro para variável k

int main() { // Função main/principal

	setlocale(LC_ALL, "");
	k = 0; // Inicialização da variável de contagem
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
			printf ("\n\t\t          Entre com a opção desejada: ");
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
				printf ("\nOpção inválida! Escolha uma opção válida entre 1 e 5!");
		}	
	} while (menu != 5);
}

void inserir(struct Pessoas vet[5], int *kp) { // Função para Inserir no cadastro
	
	char nomaux[50];
	int codaux, i, j;
	char resp, resp1;
	
	resp = 'S';
	
	if (*kp > 0) // Na primeira inserção no vetor, i será sempre 0. A partir de cada inserção o valor de i aumentará 1, como será visto mais abaixo.
		i = *kp;
	else
		i = 0;
	
	while (resp == 'S' && i < 5) { //Loop de inserção
		
		do { // Código da inserção no cadastro
			printf ("\nEntre com o código: ");
			fflush (stdin);
			scanf ("%d", &codaux);
		} while (codaux <= 0);
		
		do { // Nome da inserção no cadastro
			printf ("\nEntre com o nome: ");
			fflush (stdin);
			gets (nomaux);
		} while (nomaux == "");
		
		j = 0;
		// É feito a verificação para conferir se o código inputado já existe. Lembrando que i = k, na 1ª inserção i = 0,
		// na 2ª i = 1, na 3ª i = 2, na 4ª i = 3, na 5ª i = 4. De início, codaux é comparado a posição dos vetores[0], depois [1], [2], etc
		// enquanto j (inicializado em zero) for menor do que a contagem atual do índice do vetor (i)
		while (codaux != vet[j].codigo && j < i) { 
			j++;
		}
		
		if (j == i) { //Quando j == i, chegamos na próxima posição livre para inserção do vetor  
			
			do {
				printf ("\nConfirma a inclusão (S/N)? ");
				fflush (stdin);
				scanf ("%c", &resp1);
			} while (resp1 != 'S' && resp1 != 'N');
			
			if (resp1 == 'S' || resp1 == 's') { // Caso confirmado, a inserção será feita
				vet[i].codigo = codaux;
				strcpy (vet[i].nome, nomaux);
				printf ("\nInclusão efetuada com sucesso!");
				i++; //Aumento da contagem do i para a próxima posição vazia do vetor
			}
		}
		else { // Caso j != i, significa que codaux == vet[j].codigo, então o código já existe
			printf ("\nCódigo já cadastrado!");
		}
		
		if (i < 5) { // Enquando o vetor não for completo, é permitido inserir
			do {
				printf ("\n\nDeseja continuar incluindo (S/N)? "); // Loop de inclusão pt2
				fflush (stdin);
				scanf ("%c", &resp);
			} while (resp != 'S' && resp != 'N');
		}
	}
	
	*kp = i; //*kp é a variável de verificação global, i é a variável de verificação local. As duas serão iguais
	if (i > 4) { //Quando vetor estiver com os 5 índices completos (0 até 4), o vetor estará cheio
		printf ("\n\nVetor já está cheio! Não é permitido mais armazenas valores!");
	}	
}

void alterar(struct Pessoas vet[5], int *kp) { // Função para Alterar nome no cadastro
	
	char nomaux[50];
	int codaux, j;
	char resp, resp1;
	
	resp = 'S';
	
	if (*kp > 0) { // Só será permitido alterar algum cadastro se existir algum, ou seja, quando a variável de contagem não for mais 0,
	// significa que pelo menos uma inserção foi feita
			
		while (resp == 'S') { // Loop de alteração
			
			do { // Código do cadastro que deseja alterar
				printf ("\nEntre com o código do nome que deseja alterar: ");
				fflush (stdin);
				scanf ("%d", &codaux);
			} while (codaux <= 0);
			
			j = 0; // Mesma função do algoritmo na inserção
			while (codaux != vet[j].codigo && j < 5) {
				j++;
			}
			
			if (codaux == vet[j].codigo) { // A diferença em relação a inserção é que nesse caso nós buscamos que o codaux inputado seja
			//igual ao que está armazenado no vetor
				
				printf ("\nO nome armazenado é: "); // Mostra o nome atual
				puts (vet[j].nome);
				do {
					printf ("\nEntre com o novo nome: "); // Escolha do novo nome para substituição
					fflush (stdin);
					gets (nomaux);
				} while (nomaux == "");
				
				do {
					printf ("\nConfirma a alteração (S/N)? ");
					fflush (stdin);
					scanf ("%c", &resp1);
				} while (resp1 != 'S' && resp1 != 'N');
				
				if (resp1 == 'S') { // Caso confirme, alteração será feita
					strcpy (vet[j].nome, nomaux);
					printf ("\nAlteração efetuada com sucesso!");
				}
			}	
			else // Caso codaux != vet[j].codigo, significa que o codaux inputado não foi inserido no vetor na função de inserir
				printf ("\nCódido não cadastrado!");
						
			do {
				printf ("\n\nDeseja continuar alterando (S/N)? "); // Loop de alteração pt2
				fflush (stdin);
				scanf ("%c", &resp);
			} while	(resp != 'S' && resp != 'N');
		}
	}	
	else // Caso kp = 0, nenhum cadastro foi inserido ainda e o vetor está vazio
		printf ("\nVetor vazio!");
}

void consultar(struct Pessoas vet[5], int *kp) { // Função para Consultar o cadastro
	
	int codaux, j;
	char resp;
	
	resp = 'S';
	
	if (*kp > 0) { // Só será permitido consultar algum cadastro se existir algum, ou seja, quando a variável de contagem não for mais 0,
	// significa que pelo menos uma inserção foi feita
			
		while (resp == 'S') { // Loop de consulta
			
			do {
				printf ("\nEntre com o código do nome que deseja consultar: ");
				fflush (stdin);
				scanf ("%d", &codaux);
			} while (codaux <= 0);
			
			j = 0; // Mesmo caso que o algoritmo da função de alterar
			while (codaux != vet[j].codigo && j < 5) {
				j++ ;
			}
			
			if (codaux == vet[j].codigo) { // Mostra o nome cadastrado no vetor
				printf ("\nO nome armazenado é: ");
				puts (vet[j].nome);	
			}
			else
				printf ("\nCódido não cadastrado!"); // Caso codaux != vet[j].codigo, significa que o codaux inputado não foi 
				//inserido no vetor na função de inserir
			
			do {
				printf ("\n\nDeseja continuar consultando (S/N)? "); // Loop da consulta pt2
				fflush (stdin);
				scanf ("%c", &resp);
			} while	(resp != 'S' && resp != 'N');
		}
	}
		
	else
		printf ("\nVetor vazio!"); // Caso kp = 0, nenhum cadastro foi inserido ainda e o vetor está vazio
}

void imprimir(struct Pessoas vet[5], int *kp) { // Função para Imprimir o cadastro
	
	int j;
	
	if (*kp > 0) { // Só será permitido imprimir o cadastro se existir algum, ou seja, quando a variável de contagem não for mais 0,
	// significa que pelo menos uma inserção foi feita
			
		for (j = 0; j < *kp; j++) { // For p/ percorrer o vetor começando pelo índice 0 até o índice determinado pela variável (kp) de contagem do vetor 
			printf ("\nCódigo: %d", vet[j].codigo);
			printf ("\nNome: ");
			puts (vet[j].nome);
		}
		printf ("\nPressione qualquer tecla para voltar no menu!"); // Voltar para o menu após impressão
		getch();
	}
	else
		printf ("\nVetor vazio!"); // Caso kp = 0, nenhum cadastro foi inserido ainda e o vetor está vazio
}
