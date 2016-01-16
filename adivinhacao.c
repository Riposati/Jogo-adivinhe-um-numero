#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int inicializaValor(){
	int num = rand() % 80;
	return num;
}

void mostraQtdVidinhas(int vidinha){

	printf("\n***************************************************\n");
	printf("Vidinhas iniciais = %d\n", vidinha);
	printf("***************************************************\n\n");
}

int mostrarQtdPontosJogador(int pontos){

	printf("\nVOCE MARCOU %d PONTOS PARABENS!\n",pontos);
	pontos = 0;
	return pontos;
}

int main(){

	setlocale(LC_ALL, "Portuguese");
	int num,chute,verificaChute,i,contaIntervaloEntreRespEChute=0,vidinha = 7;
	int qtdPontosJogador=0;
	srand((unsigned)time(NULL)); // pra mudar o valor a todo momento
	num = inicializaValor();

	mostraQtdVidinhas(vidinha);

	while(1){

			if(vidinha==0){

				qtdPontosJogador = mostrarQtdPontosJogador(qtdPontosJogador);
				vidinha = 7;
				puts("FIM DE JOGO...\n");
				mostraQtdVidinhas(vidinha);
				num = inicializaValor();
			}

			printf("*-*-*-*informe um chute (0 - 80) e tecle enter*-*-*-*\n");
			scanf("%d",&chute);

			if(chute==num){
				qtdPontosJogador+=10;
				qtdPontosJogador = mostrarQtdPontosJogador(qtdPontosJogador);	
				printf("Parabens isso ae!\n");
				num = inicializaValor();
				vidinha = 7;
				mostraQtdVidinhas(vidinha);
			}else{

				vidinha--; // errou perde vidinha
				printf("Restam %d vidinhas\n", vidinha);
				contaIntervaloEntreRespEChute = abs(num - chute);

				/*printf("conta = %d\n",conta);
				printf("num = %d\n",num);*/

				if(contaIntervaloEntreRespEChute > 15){ // 15 , 16 , 17 , etc 

					puts("ta congelando\n");
					if(qtdPontosJogador > 0)
						qtdPontosJogador-=3;

				}else{

					if(contaIntervaloEntreRespEChute > 9){ // 10 , 11 , 12 , 13 , 14 , 15

						puts("ta frio");
						if(qtdPontosJogador > 0)
							qtdPontosJogador-=1;

					}else{

						if(contaIntervaloEntreRespEChute >= 5){ // 5 , 6 , 7 , 8 , 9
							
							qtdPontosJogador++; // ta quente recebe 1 ponto
							puts("ta quente\n");

						}else{

							if(contaIntervaloEntreRespEChute < 5) // 0 , 1 , 2 , 3 , 4
								
								qtdPontosJogador +=3; // ta quente recebe 3 pontos
								puts("ta fervendo\n");

						}
					}
				}	
			}
			printf("\\|/ ____ \\|/       \n");
			printf(" @~/ ,. \\~@        \n");
			printf("/_( \\__/ )_\\       \n");
			printf("   \\__U_/\n");						
		}

	return 0;
}