#include <conio.h>
#include <stdio.h>
#include <locale.h>

/* Fazer as quest�es 1 e 3.
 Quest�o 2 feita em sala de Aula.
 Quest�es 4 e 5 s�o equivalentes a quest�o 1 e 2.*/

main (){
	
	setlocale(LC_ALL, "Portuguese");
		
	int code;
	
	printf ("Selecione uma op��o de 1 a 4:");
	scanf ("%i", &code);
	
	switch (code){
		
		case 1:
			
			printf ("Executa a rotina de Inclus�o de Alunos");
			break;		
		case 2:
			
			printf ("Executa a rotina de Altera��o de Alunos:");			
			break;			
		case 3:
					
			printf ("Executa a rotina de Exclus�o de Alunos");
			break;
		case 4:
			
			printf ("Executa a rotina de Consulta de Alunos");
			break;
		default:
			
			printf ("O valor inserido � invalido");
	}
	
	getch();
}
