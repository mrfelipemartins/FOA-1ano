#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <locale.h>

main (){
	
	setlocale (LC_ALL, "Portuguese");
	
	int a , b, c, x;
	// X � um valor pra manter armazenamento e compara��o, ele vai fazer a organiza��o dos valores.
	
	printf ("Entre com o valor de A: ");
	scanf ("%i",&a);
	printf ("Entre com o valor de B: ");
	scanf ("%i",&b);
	printf ("Entre com o valor de C: ");
	scanf ("%i",&c);

	if (a > b){
		
		x = a;
		a = b;
		b = x;
	}
	if (b > c){
		
		x = b;
		b = c;
		c = x;
	}
	if (a > b){
		
		x = a;
		a = b;
		b = x;
	}
	
	printf ("A ordem crescente dos n�meros �: %i, %i, %i", a, b, c);
	
	if (a == b && b == c){
		
		printf ("Dois valores lidos iguais.");
	}
	getch ();
}
