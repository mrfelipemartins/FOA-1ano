#include <stdio.h>
#include <conio.h>
#include <locale.h>

main (){
	
	int totalAmount, i;	
	setlocale (LC_ALL, ""); // "" Sys lang	
	printf ("Possibilidade de números divisíveis por 5 entre 1000 (inclusive) e 4999\n");	
	
	for (i = 1000; i < 5000 ; i++) // ou <= 4999
		if ((i % 5) == 0)			
			totalAmount++;
			
	printf ("A possibilidade de números é igual a %i", totalAmount);
}
