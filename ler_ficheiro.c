#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


typedef struct{
  char *nome;
  int quantidade;
}Produto;

typedef struct{
  char *nome;
  int x;
  int y;
  Produto*PRODUTOS;
}Armazem;

typedef struct{
  //Constantes
  char lista_produtos[100];
  int MAX_COMPRIMENTO, MAX_ALTURA,NUM_DRONES, NUM_ARMAZENS, Frequencia_Abastecimento, Quantidade, Uni_Temp;
  //Lista_Armazem ARMAZENS;
}Variaveis;

int main(){
	FILE *file=fopen("config.txt", "r");
	char linha[100];
	char *token;
	int num_linhas=0, i=0;
	Armazem armazens[2];
	Produto prod[100];
	Variaveis var;
	//char *ptr=&var.lista_produtos[100];;
	if(file == NULL){
		printf("\n\nImpossivel abrir o arquivo!\n\n");		
 	}

    while (!feof(file)){
		fgets(linha, 100, file);	
			num_linhas++;
		   	//printf("linha:%d: %s ", i, linha);
			if (num_linhas==1){
				token = strtok(linha, ",");
				var.MAX_COMPRIMENTO=atoi(token);
				token = strtok(NULL, ",");	
				var.MAX_ALTURA=atoi(token);}
			if(num_linhas==2){
				token = strtok(linha, ",");
				for(int x=0; x<99; x++){
					prod[x].nome=token;
					prod[x].quantidade=0;
					while(token != NULL ) {
						token = strtok(NULL, ",");	
	      				prod[x].nome=token;
						prod[x].quantidade=0;
					}
				}
      		}
      		else if (num_linhas==3){
				token = strtok(linha, ",");
				var.NUM_DRONES=atoi(token);}
			else if (num_linhas==4){
				token = strtok(linha, ",");
				var.Frequencia_Abastecimento=atoi(token);
				token = strtok(NULL, ",");	
				var.Quantidade=atoi(token);
				token = strtok(NULL, ",");	
				var.Uni_Temp=atoi(token);}
			else if (num_linhas==5){
				token = strtok(linha, ",");
				var.NUM_ARMAZENS=atoi(token);}
			else if (num_linhas>5){
				token = strtok(linha, " ");
				armazens[i].nome=token;
				token = strtok(NULL, " ");
				token = strtok(NULL, ",");
				armazens[i].x=atoi(token);
				token = strtok(NULL, " ");				
				armazens[i].y=atoi(token);
				token = strtok(NULL, " ");
      			while(token != NULL){
					token = strtok(NULL, ",");
					armazens[i].PRODUTOS[i].nome=token;
					token = strtok(NULL, " ");
					armazens[i].PRODUTOS[i].quantidade=atoi(token);
				}
				i++;
		}	

	}
	printf("A ler ficheiro config.txt... \n");
	printf("Comprimento maximo: %d \n", var.MAX_COMPRIMENTO);
	printf("Altura maximo: %d \n", var.MAX_ALTURA);
	for (int i = 0; i < var.NUM_ARMAZENS-1; i++){
		printf("Lista de Produtos:");
		printf("%s \n", prod[i].nome);
	}
	printf("Numero de drones: %d \n", var.NUM_DRONES);
	printf("Frequencia_Abastecimento (unidades de tempo): %d \n", var.Frequencia_Abastecimento);
	printf("Quantidade: %d \n", var.Quantidade);
	printf("Unidade de Tempo (segundos): %d \n", var.Uni_Temp);
	printf("Numero de armazens: %d \n", var.NUM_ARMAZENS);
	for (int i = 0; i < var.NUM_ARMAZENS-1; i++){
		printf("ARMAZENS:\n");
		printf("%s (%d,%d) \n", armazens[i].nome, armazens[i].x, armazens[i].y);
	}
	
	fclose(file);

	/*
	//char*palavras=(char*)malloc(100*sizeof(char));
	//char palavra[100];
	//char *token;

	while(fscanf(file, "%s", palavras)!=EOF){
		token = strtok(palavras, ",");
		printf("%s\n", token);	
	}*/
	
	return 0;
}