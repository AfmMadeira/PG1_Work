/** 
 * Autor: 
 * 		- André Filipe Marques Madeira - 46951 - LT11N
 * 
 * Programa:
 * 		- Programa que leia do standard input (teclado) três valores inteiros positivos l1, l2, l3 que correspondem
 * 	às medidas dos três lados dum triângulo. O programa deve verificar se com esses valores é possível formar,
 *	geometricamente, um triângulo e neste caso calcular a sua área e classificá-lo quanto aos lados (equilátero, isósceles ou 
 *	escaleno) e quanto aos ângulos (retângulo, acutângulo ou obtusângulo) 
 *		- A verificação da possibilidade de formar um retângulo é realizada verificando se o maior lado é menor que a soma dos 
 *  dois outros lados.
 *		- No cálculo da área do triângulo use o teorema de Heron com a seguinte expressão: 𝐴 = √𝑆(𝑆 − 𝑙1)(𝑆 − 𝑙2)(𝑆 −𝑙3), 
 *	onde S representa o semiperímetro (metade do perímetro) do triângulo de lados l1, l2, l3.
 *		- Na classificação quanto aos ângulos use o teorema de Pitágoras ℎ2 = 𝑙1² + 𝑙2² considerando que o l3 é o lado de maior 
 *	dimensão, onde temos:
 * 		Retângulo – se o valor h coincidir com o valor do maior lado;
 * 		Acutângulo – se o valor h for menor que o valor do maior lado;
 * 		Obtusângulo – se o valor h for maior que o valor do maior lado.
 *	Na classificação em relação aos lados recorde:
 * 		Equilátero – três lados iguais;	
 * 		isósceles – dois quaisquer lados iguais;
 * 		Escaleno – três lados diferentes.
 * 
 * Estado:
 * 		- Finalizado
 * 
*/

#include <stdio.h>
#include <math.h>

int main(){
	
	// Declaração de variaveis
	int lado1, lado2, lado3;		// Lados do triangulo
	int perimetro;					// Para calcular o perimetro
	double h;						// Para calcular a hipotenusa
	double semiPerimetro;			// Para calcular o semiPerimetro
	double area;					// Para calcular a area

	// Introdução ao programa
	printf("\n");
	printf("Bem Vindos ao Programa!\n-----------------------\n");
	printf("Este programa tem como objetivo receber 3 valores inteiros inseridos pelo utilizador e verificar se com esses valores e possivel formar um triangulo e depois classifica-lo.\n");
	printf("-------------------------------------------------\n");
	
	// é pedido ao utilizador que insira 3 valores numericos, caso insira mais da erro. 
	printf("Insira os 3 lados de um triangulo\n");
	if (scanf("%d %d %d", &lado1, &lado2, &lado3) !=3){
		printf("Insira 3 valores inteiros\n");
		return 0;
	}
	
	// ordenar os valores inseridos lado 3 > lado2 > lado1
	int aux;
	if (lado3 < lado2){
		aux = lado3;
		lado3 = lado2;
		lado2 = aux;
	}
	if (lado3 < lado1){
		aux = lado3;
		lado3 = lado1;
		lado1 = aux;	
	}
	if(lado2 < lado1){
		aux = lado2;
		lado2 = lado1;
		lado1 = aux;
	}
		
	// Verificar se é possivel formar um triangulo sabendo que o lado maior < lado menor1 + lado menor2
	if ( lado1 <= 0 || lado2 <= 0 || lado3 <= 0 || lado1 >= lado2+lado3 || lado2 >= lado1+lado3 || lado3 >= lado1+lado2){
		printf("Lados invalidos para um triangulo\n");
		return 0;
		
	// Avaliar se o triangulo é equilatero, isosceles ou escaleno	
	}else{
		if ( lado1 == lado2 && lado1 == lado3){
			printf(" O Triangulo é : Equilatero\n");
		}else{
			if ( lado1 == lado2 || lado1 == lado3 || lado2 == lado3){
				printf("O Triangulo é : Isosceles\n");
			}else{
				printf("O Triangulo é: Escaleno\n");
			}
		}
	}
	
	// calculo do perimetro, semi Perimetro e area
	perimetro = lado1 + lado2 + lado3;
	semiPerimetro = (double)perimetro/2;
	area = (double)sqrt(semiPerimetro*(semiPerimetro-lado1)*(semiPerimetro-lado2)*(semiPerimetro-lado3));
	printf("A área do triangulo é : %.2fm²\n", area);
	
	//Classificação em relação aos angulo
	
		// Teorema de pitagoras
		h = pow(lado1,2) + pow(lado2,2);
		h = sqrt(h);

		// Condiçoes para o triangulo ser retangulo, acuntagulo ou obtunsagulo
		if ( h == lado3 ){
			printf(" O seu angulo forma um triangulo : Retangulo\n");
		}else{
			if ( h < lado3 ){
				printf("O seu angulo forma um triangulo : Obtunsagulo\n");
			}else{
				printf("O seu angulo forma um triangulo : Acuntagulo\n");
			}
		}
}

	


	
	
	
