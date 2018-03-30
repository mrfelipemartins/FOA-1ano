#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <locale.h>

main (){
	
	setlocale (LC_ALL, "Portuguese");
	
	float A, B, X;
	
	printf("Entre com o valor de A: ");
	scanf("%f", &A);
	printf("Entre com o valor de B: ");
	scanf("%f", &B);
	
	X = pow (A, 3) + pow (B, 2);
	
	printf ("O resultado dá expressão é = %.2f", X);
	
}
