#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <locale.h>

main (){
	
	setlocale (LC_ALL, "Portuguese");
	
	float r;
	float area;
	float vol;
	
	printf("Entre com o valor de R: ");
	scanf("%f", &r);
	
	if (r > 0){
		
		area = 4 * 3.14 * pow (r, 2);
		vol = (4 * 3.14 * pow (r, 3)) / 3;
		printf ("A área é igual a %.2f e o volume é igual a %.2f", area, vol);
	}
	else {
		
		printf ("Cálculo impossibilitado devido o valor de R ser menor ou igual a zero.");
	}
	
	getch();
}
