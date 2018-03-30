#include <stdio.h>
#include <locale.h>

int main (){
	
	setlocale (LC_ALL, "");
	
	int userValue;
	int factor = 1;
	
	printf ("Entre com um valor: ");
	scanf ("%i", &userValue);

	for (int x = 1; x <= userValue ; x++){
		
		factor *= x;
	}
	
	printf ("O resultado fatorial de %i é %i", userValue, factor);
	return 0;
}
