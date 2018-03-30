#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <locale.h>

main (){
	
	setlocale (LC_ALL, "Portuguese");

	float A, B, C, X;
	
	printf ("Entre com o valor de A:");
	scanf("%f", &A);
	printf ("Entre com o valor de B:");
	scanf("%f", &B);	
	printf ("Entre com o valor de C:");
	scanf("%f", &C);
	
	X = (A * B * (A / B * (B - C)));
	
	printf ("O valor de A foi: %.2f , o valor de B foi: %.2f , o valor de C lido foi: %.2f", A , B, C);
	printf ("O resultado da expressão é igual a %.2f", X);
	
}
