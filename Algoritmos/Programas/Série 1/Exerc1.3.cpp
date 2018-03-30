#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <locale.h>

main (){
	
	setlocale (LC_ALL, "Portuguese");
	
	float A, B, C, X;
	
	printf ("Entre com A: ");
	scanf ("%f", &A);
	printf ("Entre com B: ");
	scanf ("%f", &B);
	printf ("Entre com C: ");
	scanf ("%f", &C);
	
	X = (pow (A, 2) + pow (B, 2) + C);
	
	printf("X será = %.2f", X);
}
