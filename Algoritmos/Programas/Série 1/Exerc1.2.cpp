#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <locale.h>

main (){
	
	setlocale (LC_ALL, "Portuguese");
	
	float a, B, b, h;
	
	printf("Entre com o valor da Base Maior: ");
	scanf("%f", &B);
	printf("Entre com o valor da Base Menor: ");
	scanf("%f", &b);
	printf("Entre com a Altura do Trapézio: ");
	scanf("%f", &h);
	
	a = ((B + b) / 2) * h;
	
	printf("As base maior e menor, foram: %.2f, %.2f, e a altura foi: %.2f", B, b, h);
	printf("Para os valores lidos, a Área do Trapézio será = %.2f", a);
}
