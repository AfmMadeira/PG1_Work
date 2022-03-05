/** 
 * Autor : 
 * 	 - André Filipe Marques Madeira - 46951 - LT11N
 * 
 * Programa :
 *  
 * 	 - Implementar o calculo da nota final em PG1. 
 * 	 - O programa começa por ler do standard input (teclado) os valores reais t1, t2, t3, que correspondem às três notas dos
 * 	trabalhos práticos, para calcular a sua média, onde cada trabalho terá de ser uma nota superior a 9,5 valores caso 		   
 * 	contrário o programa termina com a indicação de “Aluno Reprovado”			  
 * 	 - Em seguida é lido do standard input (teclado) a nota do teste e se esta for inferior a 9,5 o programa termina com a 
 * indicação de “Aluno Reprovado”.
 *   - Após o sucesso da leitura das notas anteriores o programa verifica se o aluno ou o docente desejam fazer discussão, lendo
 * do standard input (teclado) as opções S/N e no caso de ter sido escolhido a opção S será lida a nota discussão válida.
 * 
 * Estado:
 * 
 * 	 - Finalizado	   
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){ 
	
	while(1){
	
	// Declaração das variaveis
	float trab1, trab2, trab3;		// Variaveis destinadas ao calculo da media dos trabalhos. 
	float testeFinal;				// Para calcular a nota final Teorica
	float notaPratica;				// Para calcular a nota final pratica
	float notaProvisoria;			// Para calcular a nota final provisora
	float notaFinal;				// para calcular a nota final de PG1
	char discussao_s_n;				// Para saber se houve ou nao discussao
	float notaDiscussao;			// Para calcular a nota de discussao
	

	// Introdução ao programa
	printf("Bem vindos ao Programa!\n------------------------------\n");
	printf("Este programa tem como objetivo calcular a nota final de PG1.\n");
	printf("--------------------------------------------------------\n");
	
	// E pedido ao utlizador que insira as notas dos trabalhos, caso alguma seja inferior a 9.5 o programa da erro. 
	printf("Insira as notas do Trabalho 1,2 e 3 ?  ");
	if(scanf("%f %f %f", &trab1, &trab2, &trab3) !=3){
			printf("Insira apenas 3 notas\n");
			return 0;
	}else{
		if ( (trab1 < 0 || trab1 > 20) || (trab2 < 0 || trab2 > 20) || (trab3 < 0 || trab3 > 20) ){
			printf("As notas sao dadas entre os valores 0 e 20\n");
			return 0;
		}else{
			if ( trab1 < 9.5 || trab2 < 9.5 || trab3 < 9.5){
				printf("Aluno Reprovado\n");
				return 0;	
			}
		}
	}
	// Calculo da media da nota Pratica
	notaPratica = 0.2*trab1 + 0.3*trab2 + 0.5*trab3;
	printf("Media dos trabalhos = %.2f\n",notaPratica);
		
	// Nota do teste Final
	printf("Digite a nota do teste Final ?  ");	
		if(scanf("%f", &testeFinal) !=1){
			printf("Insira O valor correto da nota\n");
		}else{
			if ( testeFinal < 9.5){
				printf("Aluno Reprovado\n");
			}
		}
			
	//Calculo da nota Final Provisoria
	notaProvisoria = 0.5*testeFinal + 0.5*notaPratica;
	printf("Nota final provisoria = %.2f\n", notaProvisoria);
		
	// Discussao
	printf("Requer discussao ? [s/n] ");
	scanf(" %c", &discussao_s_n);
		
	// Se o input for sim calcula a nota final. 
	while(strcmp(&discussao_s_n, "s") !=0 && strcmp(&discussao_s_n, "n") !=0 ){
		printf("Requer discussao ? [s/n]");
		scanf(" %c", &discussao_s_n);			
	}
		
	// Quando strcmp = 0 e TRUE, quando for = -5 FALSE.  
	if(strcmp(&discussao_s_n, "s") == 0){
		printf("Qual a nota ? ");
		scanf(" %f", &notaDiscussao);
		
		// Calculo da nota final
		notaFinal = 0.5*testeFinal + 0.5*notaDiscussao;
		printf("A nota final com Discussao é : %.2f\n",notaFinal);
		return 0;
	}else{
		printf("A Nota final sem discussao é = %.2f\n", notaProvisoria);
		return 0;
		}
	}
}	
		
				
		
		
			
	
		
				
				 






