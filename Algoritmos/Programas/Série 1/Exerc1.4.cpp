#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <locale.h>

main (){
	
	setlocale (LC_ALL, "Portuguese");
	
	float numA, numB, numC, totalNum, media;
	
	printf("Entre com o primeiro número: ");
	scanf("%f", &numA);
	printf("Entre com o segundo número: ");
	scanf("%f", &numB);
	printf("Entre com o terceiro número: ");
	scanf("%f", &numC);
	
	media = (numA + numB + numC) / totalNum;
	
	printf("A média dos valores = %.4f", media);
	
}
