#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <locale.h>

main (){
	
	setlocale (LC_ALL, "Portuguese");
	
	float numA, numB, numC, totalNum, media;
	
	printf("Entre com o primeiro n�mero: ");
	scanf("%f", &numA);
	printf("Entre com o segundo n�mero: ");
	scanf("%f", &numB);
	printf("Entre com o terceiro n�mero: ");
	scanf("%f", &numC);
	
	media = (numA + numB + numC) / totalNum;
	
	printf("A m�dia dos valores = %.4f", media);
	
}
