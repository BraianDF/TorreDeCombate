// bibliotecas | library
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// constantes globais | global constants
#define N 20

// structs globais | global structs
struct Tinimigos {
	char nome[N];
	int vida;
	int ataque;
	int defesa;
	int mobilidade;
};

// variaveis globais | global variables
int nivel = 1;

int jogador_vida = 10;
int jogador_ataque = 1;
int jogador_defesa = 0;
int jogador_mobilidade = 5;
int jogador_sorte = 0;

int jogador_vida_atual = 10;
int jogador_ataque_atual = 1;
int jogador_defesa_atual = 0;
int jogador_mobilidade_atual = 5;

char inimigo_nome[N];
int inimigo_vida;
int inimigo_ataque;
int inimigo_defesa;
int inimigo_mobilidade;
int porcentagem_vida = 100;

int inimigo_vida_atual;
int inimigo_ataque_atual;
int inimigo_defesa_atual;
int inimigo_mobilidade_atual;

struct Tinimigos inimigo[1];

// funcoes | functions
int porcentagem(int a, int b);
int aleatorio(int a);
int maior(int a, int b, int c);

int jogador(int a);

int inimigos(int a);

int combate(int a);

int menu(int a);

// funcao principal | main function
int main(void){

	srand(time(NULL));
	
	inimigos(0);
	
	combate(0);
	
	nivel ++;
	
	return 0;
};

int combate(int a){
	
	strcpy(inimigo_nome, inimigo[nivel-1].nome);
	inimigo_vida = inimigo[nivel-1].vida;
	inimigo_ataque = inimigo[nivel-1].ataque;
	inimigo_defesa = inimigo[nivel-1].defesa;
	inimigo_mobilidade = inimigo[nivel-1].mobilidade;
	
	inimigo_vida_atual = inimigo_vida-5;
	inimigo_ataque_atual = inimigo_ataque;
	inimigo_defesa_atual = inimigo_defesa;
	inimigo_mobilidade_atual = inimigo_mobilidade;
	
	printf("\n Voce se depara com %s.\n", inimigo_nome);
	
	porcentagem_vida = porcentagem(inimigo_vida, inimigo_vida_atual);
	if(porcentagem_vida <= 50)
		menu(0);
	else
		menu(1);
		
	if(porcentagem_vida <= 50)
		menu(0);
	else
		menu(1);
	/*
	printf("\n %s", inimigo_nome);
	printf("\n Vida: %d / %d.", inimigo_vida_atual, inimigo_vida);
	printf("\n Defesa: %d / %d.", inimigo_defesa_atual, inimigo_defesa);
	printf("\n Mobilidade: %d / %d.", inimigo_mobilidade_atual, inimigo_mobilidade); */
	
	return 0;
}

int menu(int a){
	int resp, esquivar, fugir;

	jogador(0);
	if(a==1)
		printf("\n\n [1] Atacar.\n [2] Defender.\n [3] Esquivar.\n Resposta: ");
	else
		printf("\n\n [1] Atacar.\n [2] Defender.\n [3] Esquivar.\n [5] Fugir.\n Resposta: ");
	scanf("%d", &resp);
	switch(resp){
		case 1:
			break;
		case 2:
			break;
		case 3:
			esquivar = aleatorio(5);
			jogador_mobilidade_atual += esquivar;
			break;
		case 5:
			if(a==1)
				printf("\n OPCAO INATIVA NO MOMENTO...");
			else{
				fugir = aleatorio(50) + (jogador_sorte*10);
				printf("\n Fugir = %d", fugir);
				if(fugir<=porcentagem_vida)
					printf("\n Voce falhou em fugir do combate...");
				else
					printf("\n Voce fugiu com sucesso...");
			}
			break;
		default:
			printf("\n OPCAO INVALIDA...");
			break;	
	}


}

int inimigos(int a){
	a = 0;
	strcpy(inimigo[a].nome, "LOBO SELVAGEM");
	inimigo[a].vida = 10;
	inimigo[a].ataque = 1;
	inimigo[a].defesa = 0;
	inimigo[a].mobilidade = 3;
	
	a = 1;
	strcpy(inimigo[a].nome, "GOBLIN");
	inimigo[a].vida = 10;
	inimigo[a].ataque = 1;
	inimigo[a].defesa = 0;
	inimigo[a].mobilidade = 5;
	
	
	return 0;
}

int jogador(int a){
	printf("\n JOGADOR:");
	printf("\n Vida: %d / %d.",jogador_vida_atual,jogador_vida);
	printf("\n Ataque: %d / %d.",jogador_ataque_atual,jogador_ataque);
	printf("\n Defesa: %d / %d.",jogador_defesa_atual,jogador_defesa);
	printf("\n Mobilidade: %d / %d.",jogador_mobilidade_atual,jogador_mobilidade);
	return 0;
}

int porcentagem(int a, int b){	
	return b * 100 / a;
}

int aleatorio(int a){	
	return 1 + rand()%(a);
}

int maior(int a, int b, int c){
	if(a>b)
		if(a>c)
			return a;
		else
			return c;
	else if(b>c)
			return b;
		else;
			return c;	
}
