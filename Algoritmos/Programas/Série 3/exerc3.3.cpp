#include <conio.h>
#include <stdio.h>
#include <locale.h>

main (){
	
	setlocale(LC_ALL, "Portuguese");
	
	int option;
	int a, b, c;
	
	printf ("Entre com o valor de A: ");
	scanf ("%i", &a);
	printf ("Entre com o valor de B: ");
	scanf ("%i", &b);
	printf ("Entre com o valor de C: ");
	scanf ("%i", &c);
	printf ("Entre com uma opção de 1 a 3: ");
	scanf ("%i", &option);
	
	switch (option){
		
		case 1:
			
			printf ("%i", a);
			break;
		case 2:
			
			printf ("%i", b);
			break;
		case 3:
			
			printf ("%i", c);
			break;
		default:
			
			printf ("Opção inválida");
			break;
	}
	
	getch();
}
