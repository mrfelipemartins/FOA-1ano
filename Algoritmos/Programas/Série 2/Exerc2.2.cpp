#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <locale.h>

main (){
		
	setlocale (LC_ALL, "Portuguese");
	int value;
	
	printf("Entre com um valor: ");
	scanf("%i", &value);
	
	if (value == 2){
		
		printf("O número %i é par", value);
		
	}
	else if ((value % 2) == 0){
		
		printf("O número %i é par", value);
	}
	else {
		
		printf ("O número %i é ímpar", value);
	}
	
	getch();
}
