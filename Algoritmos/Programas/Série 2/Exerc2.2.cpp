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
		
		printf("O n�mero %i � par", value);
		
	}
	else if ((value % 2) == 0){
		
		printf("O n�mero %i � par", value);
	}
	else {
		
		printf ("O n�mero %i � �mpar", value);
	}
	
	getch();
}
