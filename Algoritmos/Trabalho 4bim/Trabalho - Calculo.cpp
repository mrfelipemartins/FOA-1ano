#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <math.h>

float raizCubo(float _elev);
float areaTrap(float _bmaior, float _bmenor, float _h);
float volCilindro (float _raio, float _h);
float areaEsfera (float _raio);
float volumeEsfera (float _raio);

int main (){
	
	setlocale(LC_ALL, "");
	int menu;
	
	while (menu != 6){
		
		printf ("\t\t\t\t=====================================================\n");
		printf ("\t\t\t\t Raiz Cúbica                                    - [1]\n");
		printf ("\t\t\t\t Área do Trapézio                               - [2]\n");
		printf ("\t\t\t\t Volume do Cilindro                             - [3]\n");
		printf ("\t\t\t\t Área da Esfera                                 - [4]\n");
		printf ("\t\t\t\t Volume da Esfera                               - [5]\n");
		printf ("\t\t\t\t Sair                                           - [6]\n");
		printf ("\t\t\t\t=====================================================\n");
		printf ("\t\t\t\t          Entre com a opção desejada:                \n");
		printf ("\t\t\t\t=====================================================\n");
		scanf ("%i", &menu);
	
		// M_PI = Constante da biblioteca math.h que define o valor de Pi como " 3,14159265358979323846 "
		
		switch (menu){	
	
			case 1: // raiz cubica
				
				float valor, resultado;
				
				do {			
					printf ("Insira um valor positivo: ");
					scanf ("%f", &valor);
					
					if (valor < 0)
						printf ("Valor inserido é negativo, tente novemente... \n");
				} while (valor < 0);
							
				resultado = raizCubo(valor);
				printf ("A raiz cúbica de %.2f é igual a %.2f\n", valor, resultado);
			break;
			
			case 2: // area do trapezio
				
				float area, bmaior, bmenor, h;

				do {
					printf ("Insira a Base Maior: ");
					scanf ("%f", &bmaior);
					printf ("Insira a Base Menor: ");
					scanf ("%f", &bmenor);

					if (bmaior < bmenor)
						printf ("Base Menor é maior do que a Base Maior, entrada inválida...\n");

				} while ( bmaior < bmenor);

				printf ("Insira o valor da Altura: ");
				scanf ("%f", &h);
				
				area = areaTrap(bmaior, bmenor, h);
				printf ("A área do trapézio é igual a %.2f\n", area);
			break;
			
			case 3: // volume do cilindro
				
				float volume, raio, altura;
				
				printf ("Entre com o valor do Raio: ");
				scanf ("%f", &raio);
				printf ("Entre com o valor da Altura: ");
				scanf ("%f", &altura);
				
				volume = volCilindro (raio, altura);
				
				printf ("O volume do cilíndro é equivalente a %.2f\n", volume);
			break;
			
			case 4: // area da esfera
				
				float areaEsf, raioEsf;
				
				printf ("Entre com o valor do Raio: ");
				scanf ("%f", &raio);
				area = areaEsfera(raio);
				
				printf ("A área da Esfera é igual a %.2f\n", area);
			break;
			
			case 5: // volume da esfera
				
				float _areaEsf, _raioEsf;
				
				printf ("Entre com o valor do Raio: ");
				scanf ("%f", &raio);				
				volume = volumeEsfera(raio);
				
				printf ("O volume da Esfera é igual a %.2f\n", volume);
			break;
			
			case 6: break; //sair
			
			default: printf ("Entrada inválida! Insira um valor entre 1 e 6...\n"); break;
		}
	}
}

/* Todas as funções abaixo poderiam dispensar a variavel, e ter seu corpo escrito da seguinte forma:

float nome (parametro) 
	return (Expressão matemática);
	
*/

float raizCubo(float _elev){
	
	float elev = pow(_elev, 0.3333333);
	return elev;
}

float areaTrap(float _bmaior, float _bmenor, float _h){
	
	float area = ((_bmaior + _bmenor) * _h ) / 2;
	return area;
}

float volCilindro (float _raio, float _h){
	
	float volume = M_PI * pow(_raio, 2) * _h;
	return volume;
}

float areaEsfera (float _raio){
	
	float area = 4 * M_PI * pow(_raio, 2);	
	return area;
}

float volumeEsfera (float _raio){
	
	float volume = (4 * M_PI * pow(_raio, 2) / 3);
	return volume;
}
