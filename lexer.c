#include <stdio.h>
#include <stdlib.h>

#define SIZE_LINHA 50

typedef struct{
	char *buffer;
	int n_linhas;
	int pos;
}TBuffer;

void check_parameters(int argc){
	switch(argc){
		case 1: printf("Entre com o nome do arquivo\n");
			break;
		case 2: return;
			break;
		default: printf("Entre apenas com o nome do arquivo\n");
	}

	exit(0);
}

FILE *open_file(char *argv){
	FILE *arq = fopen(argv,"r");
	if(arq==NULL){
		printf("Arquivo entrada nao encontrado");
		exit(0);
	}
	return arq;
}

TBuffer *start_buffer(FILE *in){
	TBuffer *buffer=(TBuffer*)malloc(sizeof(TBuffer));
	buffer->buffer=(char*)malloc(SIZE_LINHA*sizeof(char));
	buffer->n_linhas=1;
	buffer->pos=0;
	if(!fgets(buffer->buffer,SIZE_LINHA,in)){
		printf("Arquivo vazio\n");
		exit(0);
	}
	return buffer;
}

void free_buffer(TBuffer* buffer){
	free(buffer->buffer);
	free(buffer);
}

char prox_char(TBuffer *buffer, FILE *in){
	char charAux;
	charAux = buffer->buffer[buffer->pos];
	
	if(charAux=='\n'){
		if(!fgets(buffer->buffer,SIZE_LINHA,in)){
			return EOF;
		}
		buffer->pos=0;
		buffer->n_linhas++;
	}else buffer->pos++;
	
	return charAux;	
}

int check_letra(char c){
	if((c>=65&&c<=90)||(c>=97&&c<=122)) return 1;
	return 0;
}

int check_digito(char c){
	if(c>=48&&c<=57) return 1;
	return 0;
}


int main(int argc, char** argv){
	
	check_parameters(argc);
	FILE *in = open_file(argv[1]);
	//FILE *out = fopen("out.txt","w");
	
	int T[4][3]={
	/*            A 0 #   */
		/*0*/(1,0,0),
		/*1*/(2,0,0),
		/*2*/(2,2,3),
		/*3*/(0,0,0)
	};

	int Avance[4][3]={
	/**/
		/*0*/(0,1,1),
		/*1*/(1,0,0),
		/*2*/(1,1,0),
		/*3*/(0,0,0)
	};

	int Aceita[4]={(0,0,0,1)};

	TBuffer *buffer = start_buffer(in);
	
	int estado = 1;
	char charAtual=prox_char(buffer,in);
	
	while(charAtual!=EOF){
		if(!check_letra(charAtual)){
		
		}
	}
	/*
	for(char charAtual=prox_char(buffer,in);charAtual!=EOF;charAtual=prox_char(buffer,in))
		printf("%c",charAtual);
	*/
	
	
	


	
	printf("\n%d linhas\n",buffer->n_linhas);
	
	fclose(in);
	//fclose(out);

	free_buffer(buffer);
	return 0;
}
