#include <conio.h>
#include <stdio.h>
#include <locale.h>

main (){
	
	setlocale (LC_ALL, "Portuguese");
	
	int code, amount;
	float price, finalValue;
	
	printf ("Entre com o código do produto de 1 a 5: ");
	scanf ("%i", &code);
	switch (code){
		
		case 1:
			
			price = 1.80;
			break;
		case 2:
		
			price = 2.00;
			break;
		case 3:
		
			price = 2.00;
			break;
		case 4:
		
			price = 0.80;
			break;
		case 5:	
		
			price = 1.50;
			break;
		default:
			
			printf ("Opção de código inválida, entre com um valor de 1 a 5");
			break;
	}
	
	if (code >= 1 && code <= 5){
			
		printf ("Entre com a quantidade desejada:");
		scanf ("%i", &amount);
		
		finalValue = amount * price; 
		
		printf ("A conta é: RS%.f", finalValue);
		}
	
	getch();
}
