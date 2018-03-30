#include <conio.h>
#include <stdio.h>
#include <locale.h>

/* Fazer as questões 1 e 3.
 Questão 2 feita em sala de Aula.
 Questões 4 e 5 são equivalentes a questão 1 e 2.*/

main (){
	
	setlocale(LC_ALL, "Portuguese");
		
	int code;
	
	printf ("Selecione uma opção de 1 a 4:");
	scanf ("%i", &code);
	
	switch (code){
		
		case 1:
			
			printf ("Executa a rotina de Inclusão de Alunos");
			break;		
		case 2:
			
			printf ("Executa a rotina de Alteração de Alunos:");			
			break;			
		case 3:
					
			printf ("Executa a rotina de Exclusão de Alunos");
			break;
		case 4:
			
			printf ("Executa a rotina de Consulta de Alunos");
			break;
		default:
			
			printf ("O valor inserido é invalido");
	}
	
	getch();
}
