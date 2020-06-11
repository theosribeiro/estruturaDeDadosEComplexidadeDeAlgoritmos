#include <stdio.h>

char arquivoentrada[] = "dij10.txt";
char arquivosaida[] = "";

void insertionSort(int original[], int length) {
	int i, j, atual;

	for (i = 1; i < length; i++) {
		atual = original[i];
		

		for (j = i - 1; (j >= 0) && (atual < original[j]); j--) {
			original[j + 1] = original[j];
        }

		original[j+1] = atual;
	}

}

void Kruskal(int vetor[], int tam){
	int i,j, c = 1, mst = 0;
	int m = vetor[0];
	int vetoraux[tam-1];
	int matriz[m][m];
	int vmst[m];

    //Inicializa o vetor
	for (i = 0; i < m; i++){
		vmst[i] = 0;
	}

	//Monta a matriz
	for(i = 0; i < m;i++){
		matriz[i][i] = 0;
		for(j = 0; j < m; j++){
			if(i < j){
				matriz[i][j] = vetor[c];
				matriz[j][i] = vetor[c];
				c++; 
			}
			printf("%d(%d,%d)    ",matriz[i][j],i,j);
		}
		printf("\n");
	}

    //Ignora o numero de arestas e 
    //preenche vetoraux com os conteudos
	for(j = 1; j < tam; j++){
		vetoraux[j-1] = vetor[j];
	}

    //Ordena para pegar as menores arestas inicialmente
	insertionSort(vetoraux, (tam-1));
	printf("\n");	
	for(j = 0; j < tam-1; j++){
		printf("%d ",vetoraux[j]);
	}

	printf("\n");
	printf("\n");
	//Percorre o vetor auxiliar ordenado
	for (i = 0; i < (tam-1); i++){
		
		if(vetoraux[i] != 0){
			
			//Percorre a matriz
			for (j = 0; j < m; j++){
				for (c = 0; c < m; c++){
					//Checa para usar so os valores acima da diagonal principal
					if(j < c){
						
						if(matriz[j][c] == vetoraux[i]){
							

							printf("\nvmst = %d\n",vmst[c]);
							if (vmst[c] == 0){ //so entra se nao tiver nenhum caminho ate o nó
								vmst[c] = j; // c-> pra onde quer ir, j-> de onde vem
								printf("Vetor atualizado!\n");
								printf("(");
								int k;
								for(k = 0; k < m; k++)
								{
									printf("%d ", vmst[k]);
								}
								printf(")\n");
								printf("(%d,%d) valor: %d so o mst %d",vmst[c],c,vetoraux[i],vmst[c]);			

							}							
							printf("\nentrei e sou o %d\n",vetoraux[i] );			
						}		
					}
				}
			}


		}
	}//fim for


	for (i = 0; i < m; i++){
		mst += matriz[vmst[i]][i];
	}
	printf("\n");
	for (i = 0; i < m ; i++){
		printf("(%d,%d) ",vmst[i],i);
	}
	


	printf("\nVMST: %d", mst);
}


int QtdeElementos(){
    FILE *arquivo = fopen(arquivoentrada, "r");
    int existe_linhas = 0, numCaracteres=0, numPalavras=0, numLinhas=0, comecouPalavra=0;
    int caractere;
   
    while ((caractere = fgetc(arquivo)) != EOF) {
        numCaracteres++;
        if  ((caractere!=' ') && (caractere!='\n') && (!comecouPalavra)) {
            comecouPalavra = 1;
        }
        if  (((caractere==' ') || (caractere == '\n')) && (comecouPalavra)) {
            comecouPalavra = 0;
            numPalavras++;
        }
    }           
    
	fclose(arquivo);
  	return numPalavras;
}

void criaVetordeEntrada(int tam){
	FILE *arquivo = fopen(arquivoentrada, "r");
	//FILE *arquivo2 = fopen(arquivosaida, "w");
	int i = 0;
	int aux;
	int vetorentrada[tam];

	if(arquivo == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
	else{
		for (i = 0; i < tam; i++){ 
			fscanf(arquivo,"%d", &aux);
			vetorentrada[i] = aux; 
		}
	}

	Kruskal(vetorentrada, tam);

	/*for(i = 0; i < tam; i++){
		printf("\n %d",vetorentrada[i]);
	}*/
	//for(i = 0; i < tam; i++){
	//	fprintf(arquivo2, "%d\n",vetorentrada[i] );	
	//}
	

	printf("\nvetor criado com sucesso");
	fclose(arquivo);
	//fclose(arquivo2);
}

int main(){
	int tam;

	tam  =  QtdeElementos();
	criaVetordeEntrada(tam);
	//printf("\nQuantidade de elementos: %d\n", tam);

	return 0;
}