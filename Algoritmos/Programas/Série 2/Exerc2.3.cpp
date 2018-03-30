#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <locale.h>

main (){
	
	setlocale (LC_ALL, "Portuguese");
		
	float raio;
	float high;
	float vol;
	
	printf ("Entre com o valor de raio: ");
	scanf ("%f", &raio);
	printf ("Entre com o valor de altura: ");
	scanf ("%f", &high);
	
	if (raio > 0 && high > 0){
		
		vol = (3.14 * pow (raio, 2) * high);
		printf ("O volume do cilindro é igual a %.2f", vol);
	}
	else {
		
		printf ("Cálculo impossibilitado devido os valores de raio e/ou altura");
	}
	
	getch();
}
