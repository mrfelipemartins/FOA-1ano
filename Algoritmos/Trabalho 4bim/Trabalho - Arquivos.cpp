#include <stdio.h> // Biblioteca padr�o 
#include <stdlib.h> // Fun��o exit, atoi, rand, system e etc
#include <conio.h> // Getch();
#include <ctype.h> // Library padr�o C ANSI, declara��es para manipula��es de caracteres
#include <locale.h> // Linguagem

// typedef = type definition / substitui o nome pelo pr�ximo (exemplo: typedef int inteiro, inteiro x = 10 � o mesmo que int x = 10)
typedef struct agenda{
    char nome[100];
    char fone[17];
    char email[100];
} T_agenda;

//Globais + Procedimentos
void inclusao();
void menu();
void Listar();
void remover();
char Validaresp();

static int qtd = 0;

T_agenda lista[300];
FILE *fp;

int main (){
	
	setlocale(LC_ALL, "");
    int var; //menu

    printf("\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t              .::AGENDA ELETR�NICA:.  \n\n");
    printf("\t\t\t\t  Veja todas as fun��es dispon�veis no menu   \n");
    printf("\t\t\t\t  Use os n�meros para selecionar a op��o desejada  \n");
    printf("\t\t\t\t  Pressione qualquer tecla para continuar\n\t\t\t\t  ou [ ESC ] para sair do programa agora.");
    
    var = getch(); // Pega o valor da letra em decimal
    
    if(var == 27) // 27 = C�digo do ESC
		exit(0); //exit 0 = sa�da padr�o; 1 = sa�da por erro; Os valores s�o padr�es
		
	menu();
	system("pause"); // Funciona como o Getch();
					 // Fun��es System executam como c�digos de linha do CMD / Prompt de Comando
}

void menu(){
	
	char op; // Op��o do menu
	
	do {
		system("cls"); // Limpa a tela, evita o excesso de informa��es
		printf("\n\t\t(1)\t\tIncluir");
		printf("\n\t\t(2)\t\tListar");
		printf("\n\t\t(3)\t\tRemover");
		printf("\n\t\t(X)\t\tQualquer outra tecla para sair\n\n");
		op = getch();
		
		switch(op){
			case '1': inclusao(); break;
			case '2': Listar(); break;
			case '3': remove ("agenda.txt"); break;			
			default: fclose(fp); exit(1);
		}
	} while (op < '7');

	fclose(fp);
}

void inclusao(){
	
	int total = 0, retorno;
	char op = 's';
	
	if ((fp = fopen("agenda.txt", "a")) == NULL) {
		printf ("O arquivo da lista n�o pode ser aberto!\n");
		printf ("Insira dados!\n");
		getch();
		exit(1);
	}
	
	while ((total < 100) && (op == 's')) {
		
		printf ("Digite o nome: ");
		gets(lista[total].nome);			
		
		printf ("Digite o N�mero: ");
		gets(lista[total].fone);			
	
		printf ("Digite o E-mail (Opcional / [ Enter ] para pular): ");
		gets(lista[total].email);
		
		retorno = fwrite (&lista[total], sizeof(struct agenda), 1, fp); // fwrite = usa buffers ao inves de strings para escrever no arquivo
																		// dessa forma, ele escreve blocos de dados (uma array de char no caso)
																		// os parametros s�o fwrite (buffer, tamanho para ser escrito, n�mero de elementos, arquivo)
																		// &lista[total] = a struct � o buffer.
																		// sizeof(struct agenda) = o tamanho da struct � o equivalente a ser escrito
																		// 1 = n�mero de elementos em cada espa�o da array
																		// fp = nome do arquivo	
		
		if (retorno == 1)
			printf(" \nGrava��o executada com sucesso! ");
		
		total++;
		op = Validaresp();
		qtd++;
	}

	fclose (fp);
}

char Validaresp() { // Facilitar a inclus�o de novos cadastros 
	
	char op;
	
	do {
		
		printf(" \nDeseja inserir novo cadastro? [S ou N] ? " );
		op = getch();
		printf("\n" );
		
	} while (op != 's' && op != 'n');
	
	return op;
}

void Listar(){
	
	int i = 0, retorno;

    if ((fp = fopen("agenda.txt", "r")) == NULL){
		printf ("O arquivo da lista n�o pode ser aberto!\n");
		printf ("Insira dados!\n");
		getch();
		exit(1);
    }

    retorno = fread(&lista[i], sizeof(struct agenda), 1, fp);	// fread retorna a quantidade de itens, sua estrutura � IGUAL a fwrite

   while ( retorno == 1) {
		printf("\n Nome ..: %s", lista[i].nome);
		printf("\n Fone ..: %s", lista[i].fone);
		printf("\n E-mail ..: %s \n", lista[i].email);
		i++;
		retorno = fread(&lista[i], sizeof(struct agenda), 1, fp);  
	}
    
	printf(" \n\n %d Contatos salvos!\n", i);
	getch();
	fclose(fp);
}
