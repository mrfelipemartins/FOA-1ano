#include <stdio.h>
#include <locale.h>
#include <conio.h>

main (){
	
	setlocale (LC_ALL, "Portuguese");
		
	const int flag = 0;
	int count;
	float num = 2;
	float mult = 2;
	
	printf (" 0 - Parar \n Entre com um número: ");
	scanf ("%f", &num);

	while (num != flag){
		
		mult = mult * num;
		count = count + 1;
		
		printf ("O número lido foi %.2f", num);
		printf (" 0 - Parar \n Entre com um número: ");
		scanf ("%f", &num);
	}
	
	if (count == 0){
		
		printf ("Para o valor %i lido, não permite continuar o processamento.", flag);
	} else {
		
		printf ("O produto dos valores lidos é: %.2f", mult);
	}
	
	getch ();
}
