

/*
|-----------------------------------------------------------------------------|
|                                   ALUNO                                     |
|                         Higor de Deus Matos - 6372                          |
|                                                                             |
|-----------------------------------------------------------------------------|
|                               PROFESSORA                                    |
|                            Rachel dos Reis                                  |
|                      UNIVERSIDADE FEDERAL DE VIÇOSA                         |
|                          CAMPOS RIO PARANAIBA                               |
|-----------------------------------------------------------------------------|
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

//-------------------------------------------------------------------------- Armazenamento do Jogo ----------------------------------------------------------------------------------------------

 typedef struct rotulo_campominado{
 	char **camp_pad;          // Campo que é apresentado para o jogador
	char **camp_padinvi;      // Campo que recebe as bombas aleatroriamente
	char opcao;               // Variável de seleção nos menus
	char dicas;               // Variável que armazena as dicas para jogatina
 	int lin;                  // Variável que indica o numero de linhas
 	int col;                  // Variável que indica o numero de colunas
 	int lin_s;		          // Variável que indica a linha selecionada
 	int col_s;				  // Variável que indica a coluna selecionada
	int corder_lin;           // Variável que indica as coordenadas
	int corder_col;           // Variável que indica as coordenadas
	int bandeiras;            // Variável que indica quantas bandeiras foram colocadas
	int quantidade_bombas;    // Variável para quantidade de bombas
	int quantidade_ganhou;    // Variável para verificar se o usuário ganhou
	int cont;				  // Contador para gerar as linhas
	int cont2;                // Contador para gerar as colunas
	int bombas;				  // Numero de bombas
	clock_t cronometro;		  // Marcar o tempo jogado
 	char nome[30];			  // Nome para recordes
	float tempo;			  // Melhores tempos no personalizado
	int pers_ou_pad;		  // Criar os recoredes personalizados ou padrão
	char tecla;
 }Campominado;

 typedef struct rotulo_recordes{
	float tempo; // Guardar os tempos
	char nome[30]; // Guardar os nomes

 }Recordes;
  //----------------------------------------------------------------------- Fim Armazenamento do Jogo ----------------------------------------------------------------------------------------------

 // ------------------------------------------------------------ Declaração das funções para utilizar em todo escopo -----------------------------------------------------------------------

void menu(Campominado*s);                     // MENU PRINCIPAL PARA ESCOLHA
void progresso_jogatina(Campominado*s);       // EXIBIÇÃO DO PROGRESSO DO JOGO, DICAS, BANDEIRAS COLOCADAS, ESPAÇOS ABERTOS
void bomba(Campominado*s);                    // GERAÇÃO DAS BOMBAS EM LOCAIS ALEATÓRIOS
void apres_camp(Campominado*s);               // APRESENTAÇÃO DO CAMPO PADRÃO PARA INÍCIO
void game_over(Campominado*s);                // ABERTURA DOS ESPAÇOS SEM BOMBA E APRESENTAÇÃO DO GAME OVER

int abr_espaco(Campominado*s);                // SELEÇÃO DO CAMPO PARA ABERTURA

void colocar_bandeira(Campominado*s);         // SELEÇÃO DO CAMPO PARA COLOCAR BANDEIRA
void abrir_ou_bandeira(Campominado*s);        // MENU DE ESCOLHA PARA ABRIR OU COLOCAR BANDEIRA
void preenche(Campominado*s);                 // PREENCHE OS CAMPOS COM # SIMBOLIZANDO FECHADO
void novojogo(Campominado*s);                 // INICIA O NOVO JOGO COM O CAMPO PADRÃO 9X9 10 BOMBAS
void verif_ganhou(Campominado*s);             // VERIFICA SE O JOGADOR GANHOU OU SE ELE EXPLODIU UMA BOMBA
void apresen_arte_campominado(Campominado*s); // APRESENTA A ARTE "CAMPO MINADO" COM OS COMANDOS PUTS
void apresen_arte_you_win(Campominado*s);     // APRESENTA A ARTE "VOCÊ VENCEU" COM OS COMANDOS PUTS
void apresen_arte_game_over(Campominado*s);   // APRESENTA A ARTE "VOCÊ PERDEU" COM OS COMANDOS PUTS
void comojogar(Campominado*s);                // TUTORIAL DE COMO JOGAR
void apresen_dicas(Campominado*s);            // APRESENTAR DICAS DE QUANTAS BOMBAS EXISTEM NOS QUADRADOS ADJACENTE
void bandeiras_colocadas(Campominado*s);      // CONTAR QUANTAS BANDEIRAS FORAM COLOCADAS E LIMITAR
void abrir_campos_fim_de_jogo(Campominado*s); // ABRIR OS CAMPOS QUE NÃO POSSUEM BOMBAS QUANDO DER GAME-OVER
void you_win(Campominado*s);                  // APRESENTA VITÓRIA E SELEÇÃO DE MENU PARA SAIR OU VONTALR
void digitar_coordenada(Campominado*s);	 	  // SELECIONAR A COORDENADA PARA ABRIR OU COLOCAR BANDEIRA
void apresen_dicas_local(Campominado*s);      // JOGADOR ABRIR UM ESPAÇO NO QUAL ELE COLOCOU UMA BANDEIRA MAS NÃO HAVIA UMA LÁ
void personalizar_jogo(Campominado*s);        // JOGADOR ESCOLHE QUANTAS BOMBAS E TAMANHO DO CAMPO
void criar_campo(Campominado*s);	     	  // CRIAR CAMPO COM O TAMANHO DESEJADO
void zerar_campo(Campominado*s);		      // ZERAR TODO O CAMPO PARA JOGAR NOVAMENTE
int  abrir_envolta(Campominado*s);            // ABRIR CAMPOS ENVOLTA QUE NÃO POSSUEM BOMBA
void recordes(Campominado*s);		          // MONTA RECORDES DOS JOGOS
void apres_arte_recordes(Campominado*s);	  // APRESENTA A ARTE "RECORDES" COM OS COMANDOS PUTS

// ------------------------------------------------------------ Fim Declaração das funções para utilizar em todo escopo -----------------------------------------------------------------------

// ---------------------------------------------------------------------------  Funções Utilizadas  ---------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------- ARTES Recordes ------------------------------------------------------------------------------------------------------
void apres_arte_campominado2 (Campominado*s)
{
	fflush(stdin);
	printf("                                                      	                                                       c=====e\n");
	printf("                                                                                                                  H\n");
	printf("                                                         ____________                                         _,,_H__\n");
	printf("                                                        (__((__((___()                                       //|     |\n");
	printf("                                                       (__((__((___()()_____________________________________// |!!!!!|\n");
	printf("                                                      (__((__((___()()()------------------------------------'  |_____|\n");
}

void apres_arte_recordes (Campominado*s)
{
	printf("\n\n");
	puts("                                                      ----------------------------------------------------");
	puts("                                                      | .---.  .--.  .--.  .--. .---. .---.  .--.  .--.  |");
	puts("                                                      | : .; :: .--': .--': ,. :: .; :: .  :: .--': .--' |");
	puts("                                                      | :   .': `;  : :   : :: ::   .': :: :: `;  `. `.  |");
	puts("                                                      | : :.`.: :__ : :__ : :; :: :.`.: :; :: :__  _`, : |");
	puts("                                                      | :_;:_;`.__.'`.__.'`.__.':_;:_;:___.'`.__.'`.__.' |");
    puts("                                                      ----------------------------------------------------");
    printf("\n\n");


	fflush(stdin);
}
//--------------------------------------------------------------------------------- FIM ARTES Recordes ------------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------- Recordes ------------------------------------------------------------------------------------------------------
void recordes (Campominado*s)
{
	fflush(stdin);
	Recordes MELHORES[6]; // Definir o typdef
	int i = 0;
	s->tempo = (float)s->cronometro/CLOCKS_PER_SEC;
	FILE* arquivo;

	for(i=0;i<6;i++)
	{
		MELHORES[i].tempo = 90000/CLOCKS_PER_SEC;
	}

	if(s->pers_ou_pad == 1) // JOGO PERSONALIZADO
	{
		arquivo = fopen("recordes_personalizados.txt","r");

	}else if(s->pers_ou_pad == 0) // JOGO PADRÃO
	{
		arquivo = fopen("recordes_padrao.txt","r");
	}

	for(i=0;i<5;i++)
	{
		fflush(stdin);
		fscanf(arquivo,"%f %s\n",&MELHORES[i].tempo,MELHORES[i].nome); //RECEBER OS DADOS QUE ESTAVAM GRAVADOS NO ARQUIVOS
	}

	fclose(arquivo);

	strcpy(MELHORES[5].nome,s->nome);
	MELHORES[5].tempo = s->tempo;

  	int j, tam = 6;
	int min;
	Recordes swap;

  	for (i = 0; i < (tam-1); i++)
    {
    	min = i;

		for (j = (i+1); j < tam; j++)
		{
	      if(MELHORES[j].tempo < MELHORES[min].tempo)
			{
	        	min = j;
     		}
    	}

    	if (MELHORES[i].tempo != MELHORES[min].tempo)
		{
	      swap = MELHORES[i];
	      MELHORES[i] = MELHORES[min];
	      MELHORES[min] = swap;
		}
	}

	for(i=0;i<6;i++)
	{
		if(MELHORES[i].tempo == 0)
		{
			(MELHORES[i].tempo = (float)90000/CLOCKS_PER_SEC); // EVITAR BUG COM METODO DE ORGANIZAÇÃO
		}
	}

	if(s->pers_ou_pad == 1)
	{
		arquivo = fopen("recordes_personalizados.txt","w");
	}else
	{
		arquivo = fopen("recordes_padrao.txt","w");
	}

	if(arquivo == NULL)
	{
		printf("\n\tErro ao criar os recordes\n");
		system("pause");
		exit(1);
	}else
	{
		system ("cls || clear");
		apres_arte_recordes(s);
		printf("\n\t\t\t\t\t\tArquivo de recordes criado com sucesso! Verifique a pasta raiz.\n\n");
	}

	for(i=0;i<5;i++)
	{
		if(MELHORES[i].tempo != 90000/CLOCKS_PER_SEC && MELHORES[i].tempo != 0)
		{
			fprintf(arquivo,"%f %s\n",MELHORES[i].tempo, MELHORES[i].nome);
		}
	}

	fclose(arquivo);
	system("pause");
	fflush(stdin);
	strcpy(MELHORES[5].nome,"                                                   "); //"LIMPAR" VARIAVEL UTILIZADA
	s->cronometro = 90000; //ZERA O CRONOMETRO
	menu(s);
}


//------------------------------------------------------------------------- Fim Recordes ---------------------------------------------------------------------------------------------


//------------------------------------------------------------------------- Criar campo ------------------------------------------------------------------------------------------------

void criar_campo(Campominado*s)
{
	fflush(stdin);
	s->camp_pad = (char**) malloc (s->lin * sizeof(char*));
	s->camp_padinvi = (char**) malloc (s->lin * sizeof(char*));

	if(s->camp_pad == NULL)
	{
		printf("\n Impossível alocar na memória, coloque um número menor");

		exit (1);
	}

		if(s->camp_padinvi == NULL)
	{
		printf("\n Impossível alocar na memória, coloque um número menor");
		exit (1);
	}

	for(s->cont=0;s->cont<s->lin;s->cont++)
	{
		s->camp_pad[s->cont] = (char*) malloc (s->col*sizeof(char));

		if(s->camp_pad == NULL)
		{
			printf("\n Impossível alocar na memória, coloque um número menor");

			exit (1);
		}

		s->camp_padinvi[s->cont] = (char*) malloc (s->col*sizeof(char));

		if(s->camp_padinvi == NULL)
		{
			printf("\n Impossível alocar na memória, coloque um número menor");
			exit (1);
		}
	}
	fflush(stdin);
}
//------------------------------------------------------------------------- Fim Criar campo -----------------------------------------------------------------------------------------

//------------------------------------------------------------------------- Zerar campo -----------------------------------------------------------------------------------------
void zerar_campo(Campominado*s)
{
	fflush(stdin);
	for(s->cont=0;s->cont<s->lin;s->cont++)
	{
		for(s->cont2=0;s->cont2<s->col;s->cont2++)
		{
			s->camp_padinvi[s->cont][s->cont2] = ' ';
			s->camp_pad[s->cont][s->cont2] = ' ';
		}
	}
	fflush(stdin);
}
//------------------------------------------------------------------------- Fim Zerar campo -----------------------------------------------------------------------------------------

void personalizar_jogo(Campominado*s)
{
	fflush(stdin);
	printf ("\n\n====================================================================== Personalização ====================================================================================== \n ");
	printf ("\n\n Número de LINHAS do campo: ");
	scanf("%d",&s->lin);

	if(s->lin == 0 )
	{
		system ("cls || clear");
		printf ("\n\n  Número de linhas não pode ser igual a 0, tente novamente!\n\n");
		personalizar_jogo(s);
	}
	printf ("\n\n Número de COLUNAS do campo: ");
	scanf("%d",&s->col);

	if(s->col == 0)
	{
		system ("cls || clear");
		printf ("\n\n  Número de colunas não poder ser igual a 0, tente novamente!\n\n");
		personalizar_jogo(s);
	}
	printf ("\n\n Quantidade de bombas: ");
	scanf("%d",&s->quantidade_bombas);

	fflush(stdin);

	if(s->quantidade_bombas > ((s->lin) * (s->col)))
	{
		system ("cls || clear");
		printf ("\n\n  Quantidade de bombas maior do que tamanho do campo ou opção inválida, tente novamente!\n\n");
		personalizar_jogo(s);
	}

	system ("cls || clear");
	s->pers_ou_pad = 1;
	novojogo(s);
	fflush(stdin);
}

//------------------------------------------------------------------------- Fim Personalizar Jogo -----------------------------------------------------------------------------------------


//------------------------------------------------------------------------- Apresentar dicas depois de abrir bandeira sem bomba -----------------------------------------------------------------------------------------
void apresen_dicas_local(Campominado*s)
{
	fflush(stdin);
	s->dicas = '0';

		if(((s->lin_s-1) >= 0)      &&
		((s->col_s-1) >= 0)        &&
		(s->camp_padinvi[s->lin_s-1][s->col_s-1] == '*'))
		{
			s->dicas++;
		}

		if(((s->lin_s-1) >= 0)      &&
		((s->col_s) >= 0)          &&
		(s->camp_padinvi[s->lin_s-1][s->col_s] == '*'))

		{
			s->dicas++;
		}

		if(((s->col_s+1) < s->col) &&
		((s->lin_s-1) >= 0)         &&
		(s->camp_padinvi[s->lin_s-1][s->col_s+1] == '*'))
		{
			s->dicas++;
		}

		if(((s->col_s-1) < s->col) &&
		((s->lin_s) < s->lin)       &&
		(s->camp_padinvi[s->lin_s][s->col_s-1] == '*'))
		{
			s->dicas++;
		}

		if(((s->col_s+1) < s->col) &&
		(s->camp_padinvi[s->lin_s][s->col_s+1] == '*'))
		{
			s->dicas++;
		}

		if(((s->lin_s+1) < s->lin) &&
		((s->col_s-1) >= 0)       &&
		(s->camp_padinvi[s->lin_s+1][s->col_s-1] == '*'))
		{
			s->dicas++;
		}

		if(	((s->lin_s+1) < s->lin)&&
	 	(s->camp_padinvi[s->lin_s+1][s->col_s] == '*'))
		{
			s->dicas++;
		}

		if(((s->col_s+1) < s->col)&&
		((s->lin_s+1) < s->lin)    &&
		(s->camp_padinvi[s->lin_s+1][s->col_s+1] == '*'))
		{
			s->dicas++;
		}

		if (s->dicas == '0')
		{
			s->dicas = ' ';
		}

	s->camp_pad[s->lin_s][s->col_s] = s->dicas;
	s->camp_padinvi[s->lin_s][s->col_s] = s->dicas;
	fflush(stdin);
	abr_espaco(s);
}



//------------------------------------------------------------------------- Apresentar dicas depois de abrir bandeira sem bomba -----------------------------------------------------------------------------------------

//---------------------------------------------------------------------------- Selecionar Coordenada ------------------------------------------------------------------------------------------------------------------
 void digitar_coordenada(Campominado*s)
 {
 	fflush(stdin);
 	printf("\n LINHA desejada para abrir ou colocar bandeira: ");
	scanf ("%d", &s->lin_s);
	s->lin_s--;
	fflush(stdin);

	if(s->lin_s > (s->lin-1) || s->lin_s < 0) // Evitar que o usuário selecione um espaço inexistente
	{
	printf ("\n\nDigite uma coordenada válida\n\n");
	digitar_coordenada(s);
	}

	printf("\n COLUNA desejada para abrir ou colocar bandeira: ");
	scanf ("%d", &s->col_s);
	s->col_s--;
	fflush(stdin);

	if( s->col_s > (s->col-1) || s->col_s < 0 ) // Evitar que o usuário selecione um espaço inexistente
	{
		printf ("\n\nDigite uma coordenada válida\n\n");
		digitar_coordenada(s);
	}

	s->pers_ou_pad = 1; // JOGO PERSONALIZADO
	abrir_ou_bandeira(s);
	fflush(stdin);
 }
//---------------------------------------------------------------------------- Fim Selecionar Coordenada -----------------------------------------------------------------------------------------

// --------------------------------------------------------------------------- Abrir todos os campos no game-over -----------------------------------------------------------------------------------

void abrir_campos_fim_de_jogo(Campominado*s)
{
	fflush(stdin);
	for(s->cont=0;s->cont<s->lin;s->cont++)
	{
		for(s->cont2=0;s->cont2<s->col;s->cont2++)
		{
			s->camp_pad[s->cont][s->cont2] = s->camp_padinvi[s->cont][s->cont2];
		}
	}
	fflush(stdin);
}
// ---------------------------------------------------------------------- Fim Abrir todos os campos no game-over ------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------- Apresentar Dicas ------------------------------------------------------------------------------------
void apresen_dicas(Campominado*s)
{
	fflush(stdin);
	for(s->cont=0;s->cont<s->lin;s->cont++)
	{
		for(s->cont2=0;s->cont2<s->col;s->cont2++)
		{
			if(s->camp_padinvi[s->cont][s->cont2] != '*')
			{
				s->camp_padinvi[s->cont][s->cont2] = '0';
			}
		}
	}

	for(s->cont=0;s->cont < s->lin;s->cont++)
	{
		for(s->cont2=0;s->cont2 < s->col;s->cont2++)
		{
			if(s->camp_padinvi[s->cont][s->cont2] == '*')
			{
				if(((s->cont-1) >= 0)         &&
				((s->cont2-1) >= 0)        &&
				(s->camp_padinvi[s->cont-1][s->cont2-1] != '*'))
				{
					s->camp_padinvi[s->cont-1][s->cont2-1]++;
				}

				if(((s->cont-1) >= 0)      &&
				((s->cont2) >= 0)       &&
				(s->camp_padinvi[s->cont-1][s->cont2] != '*'))

				{
					s->camp_padinvi[s->cont-1][s->cont2]++;
				}

				if(((s->cont2+1) < s->col)&&
				((s->cont-1) >= 0)      &&
				(s->camp_padinvi[s->cont-1][s->cont2+1] != '*'))
				{
					s->camp_padinvi[s->cont-1][s->cont2+1]++;
				}

				if(((s->cont2-1) < s->col)&&
				((s->cont) < s->lin) &&
				(s->camp_padinvi[s->cont][s->cont2-1] != '*'))
				{
					s->camp_padinvi[s->cont][s->cont2-1]++;
				}

				if(((s->cont2+1) < s->col)&&
				(s->camp_padinvi[s->cont][s->cont2+1] != '*'))
				{
					s->camp_padinvi[s->cont][s->cont2+1]++;
				}

				if(((s->cont+1) < s->lin)&&
				((s->cont2-1) >= 0)    &&
				(s->camp_padinvi[s->cont+1][s->cont2-1] != '*'))
				{
					s->camp_padinvi[s->cont+1][s->cont2-1]++;
				}

				if(	((s->cont+1) < s->lin) &&
			 	(s->camp_padinvi[s->cont+1][s->cont2] != '*'))
				{
					s->camp_padinvi[s->cont+1][s->cont2]++;
				}

				if(((s->cont2+1) < s->col)&&
				((s->cont+1) < s->lin)&&
				(s->camp_padinvi[s->cont+1][s->cont2+1] != '*'))
				{
					s->camp_padinvi[s->cont+1][s->cont2+1]++;
				}
			}
		}
	}

	for(s->cont=0;s->cont<s->lin;s->cont++)
	{
		for(s->cont2=0;s->cont2<s->col;s->cont2++)
		{
			if(s->camp_padinvi[s->cont][s->cont2] == '0' )
			{
				s->camp_padinvi[s->cont][s->cont2] = ' ';
			}
		}
	}
	fflush(stdin);
}

// ------------------------------------------------------------------------ Fim Apresentar Dicas -----------------------------------------------------------------------------------------


// ------------------------------------------------------------------------ Apresentar arte campo minado ------------------------------------------------------------------------------------
void apresen_arte_campominado(Campominado*s)
{
	fflush(stdin);
	printf("\n\n");
	puts("                                              ---------------------------------------------------------------------------------");
	puts("                                              |     .--.                               .-..-. _                 .-.           |");
	puts("                                              |    : .--'                              : `' ::_;                : :           |");
	puts("                                              |    : :    .--.  ,-.,-.,-..---.  .--.   : .. :.-.,-.,-. .--.   .-' : .--.      |");
	puts("                                              |    : :__ ' .; ; : ,. ,. :: .; `' .; :  : :; :: :: ,. :' .; ; ' .; :' .; :     |");
	puts("                                              |    `.__.'`.__,_;:_;:_;:_;: ._.'`.__.'  :_;:_;:_;:_;:_;`.__,_;`.__.'`.__.'     |");
	puts("                                              |                          : :                                                  |");
	puts("                                              |                          :_;                                                  |");
	puts("                                              ---------------------------------------------------------------------------------");
	fflush(stdin);
}
// ------------------------------------------------------------------- Fim apresentar arte campo minado ------------------------------------------------------------------------------------

// ------------------------------------------------------------------------ Apresentar arte you win ------------------------------------------------------------------------------------
void apresen_arte_you_win(Campominado*s)
{
	fflush(stdin);
	printf("\n\n");
	puts("");
	puts("                                              |-----------------------------------------------------------------------------|");
	puts("                                              | .--.   .--.             ^       .----.               ,-.                    |");
	puts("                                              | :  :   :  :            ^ ^     :  .--'               : :                    |");
	puts("                                              | :  :._.:  : .--. .---..---.    :  :  __  .--.  ,-.,-.: :,-. .--.  _   _     |");
	puts("                                              |  :        :' .; :: :: : :-'    :  :__:: ' .; ; : ,. :: :  :' .; :' '.; '    |");
	puts("                                              |   :..__..: `.__.'`.__,`.__;    `.____.' `.__,_;:_;:_;:_;:_;`.__.'`.___.'    |");
	puts("                                              |                                                                             |");
	puts("                                              |                                                                             |");
	puts("                                              |-----------------------------------------------------------------------------|");

	printf("                                                                              ___________      \n");
	printf("                                                                             '._==_==_=_.'     \n");
	printf("                                                                             .-\\:      /-.    \n");
	printf("                                                                            | (|:.     |) |    \n");
	printf("                                                                             '-|:.     |-'     \n");
	printf("                                                                               \\::.    /      \n");
	printf("                                                                                '::. .'        \n");
	printf("                                                                                  ) (          \n");
	printf("                                                                                _.' '._        \n");
	printf("                                                                               '-------'       \n\n");
	fflush(stdin);
}
// ------------------------------------------------------------------------ Fim Apresentar arte you win ------------------------------------------------------------------------------------


// ------------------------------------------------------------------- Apresentar arte gaem over ------------------------------------------------------------------------------------
void apresen_arte_game_over(Campominado*s)
{
	fflush(stdin);
	printf("\n\n");
	puts("");
	puts("                                              |-----------------------------------------------------------------------------|");
	puts("                                              | .--.   .--.             ^       ,----.              .-.                     |");
	puts("                                              | :  :   :  :            ^ ^     :      :             : :                     |");
	puts("                                              | :  :._.:  : .--. .---..---.    :  ,__:.---.,----, .-' :.---.  _   _         |");
	puts("                                              |  :        :' .; :: ::': :-'    :  :   : :-': ;-; ' .; :: :-''' .;  '        |");
	puts("                                              |   :..__..: `.__.'`.__,`.__;    :__:   `.__;:_:   `.__.'`.__; `.___.'        |");
	puts("                                              |                                                                             |");
	puts("                                              |                                                                             |");
	puts("                                              |-----------------------------------------------------------------------------|");


	printf("                                                                               _______________         \n");
	printf("                                                                              /               \\       \n");
	printf("                                                                             /                 \\      \n");
	printf("                                                                           //                   \\/\\  \n");
	printf("                                                                           \\|   XXXX     XXXX   | /   \n");
	printf("                                                                            |   XXXX     XXXX   |/     \n");
	printf("                                                                            |   XXX       XXX   |      \n");
	printf("                                                                            |                   |      \n");
	printf("                                                                            \\__      XXX      __/     \n");
	printf("                                                                              |\\     XXX     /|       \n");
	printf("                                                                              | |           | |        \n");
	printf("                                                                              | I I I I I I I |        \n");
	printf("                                                                              |  I I I I I I  |        \n");
	printf("                                                                              \\_             _/       \n");
	printf("                                                                                \\_         _/         \n");
	printf("                                                                                  \\_______/           \n");
	fflush(stdin);
}
// ------------------------------------------------------------------- Fim apresentar arte gaeme over ------------------------------------------------------------------------------------
void comojogar(Campominado*s)
{
	fflush(stdin);
	printf ("\n\n======================================================================== Como Jogar =================================================================================== \n ");
	printf ("\n Selecione o que for desejado conforme o menu e siga a legenda:");
	printf("\n\n\t# Quadrado fechado");
	printf("\n\n\tB Bandeira com bomba encontrada");
	printf("\n\n\tX Bandeira sem bomba encontrada (Apenas em game over)");
	printf("\n\n\t* Bomba");
	printf("\n\n\t' ' Quadrado aberto sem bomba adjacente");
	printf ("\n\n \t\t Ao selecionar um campo em que não tenha bomba mas os espaços adjacentes tenham, será mostrado o número de bombas envolta com dica.");
	printf ("\n\n \t\t\t Não se preocupe em digitar as letras em maiusculo, o programa aceita de qualquer modo :D !");
	printf ("\n\n=========================================================================================================================================================================== \n ");
	printf("\n\n S - Sair \n V - Voltar ao menu principal \n");

	scanf ("%c",&s->opcao);
	if(s->opcao == 's' || s->opcao == 'v') // Caso o jogador digite a letra em minusculo
	{
			s->opcao = s->opcao-32;
	}
	switch (s->opcao) // Depois do Você ganhou o jogador tem a opção de voltar pro menu ou sair do jogo
	{
		case 'S':
			system("cls || clear");
			exit (1);
			break;

		case 'V':
			system("cls || clear");
			menu(s);
			break;

		default:
		    system("cls || clear");
		    printf ("\n\nDigite uma opção válida!\n\n");
		    comojogar(s);
		    break;
	}
	fflush(stdin);
}

// ------------------------------------------------------------------- Quantidade de Bandeiras Colocadas ------------------------------------------------------------------------------------
void bandeiras_colocadas(Campominado*s)
{
	fflush(stdin);
	s->bandeiras = 0; //EVITAR QUE CONTE A MESMA 2 VEZES
	for(s->cont=0;s->cont<s->lin;s->cont++)
	{
		for(s->cont2=0;s->cont2<s->col;s->cont2++)
		{
			if(s->camp_pad[s->cont][s->cont2] == 'B')
			{
				s->bandeiras++;
			}
		}
	}
}
// ------------------------------------------------------------------- Fim Quantidade de Bandeiras Colocadas ------------------------------------------------------------------------------------

// ------------------------------------------------------------------- Apresentar que o jogador ganhou ------------------------------------------------------------------------------------
void you_win(Campominado*s)
{
	fflush(stdin);

		abrir_campos_fim_de_jogo(s);
		progresso_jogatina(s);
		s->cronometro = clock() - s->cronometro;
		printf("\n");
		apresen_arte_you_win(s);
		printf("\n\n");

		printf("\n\n Tempo de jogo: %f segundos, vá até a opção RECORDES no menu e veja se você está entre os melhores :D \n", (float)s->cronometro/CLOCKS_PER_SEC);
		printf("\n Digite seu nome: ");
		fflush(stdin);
		gets(s->nome);
		recordes(s);

		for(s->cont = 0; s->cont < s->lin; s->cont++)
		{
			free(s->camp_pad[s->cont]);
			free(s->camp_padinvi[s->cont]);
		}
		free(s->camp_pad);
		free(s->camp_padinvi);

		printf("\n S - Sair \n V - Voltar ao menu principal \n");
		scanf ("%c",&s->opcao);
		if(s->opcao == 's' || s->opcao == 'v') // Caso o jogador digite a letra em minusculo
		{
			s->opcao = s->opcao-32;
		}
		switch (s->opcao) // Depois do Você ganhou o jogador tem a opção de voltar pro menu ou sair do jogo
		{
			case 'S':
				system("cls || clear");
				exit (1);
				break;

			case 'V':
				system("cls || clear");
				menu(s);
				break;

			default:
	            system("cls || clear");
	            verif_ganhou(s);
	            break;
		}
	fflush(stdin);
}
// ------------------------------------------------------------------- Fim Apresentar que o jogador ganhou ------------------------------------------------------------------------------------

// -------------------------------------------------------------- Verificar se o jogador ganhou ou não ---------------------------------------------------------------------------------
void verif_ganhou(Campominado*s)
{
	fflush(stdin);
	s->quantidade_ganhou = ((s->lin * s->col) - s->bombas);

	for(s->cont=0;s->cont<s->lin;s->cont++)
	{
		for(s->cont2=0;s->cont2<s->col;s->cont2++)
		{
			if(s->camp_pad[s->cont][s->cont2] == '1')
			{
				s->quantidade_ganhou--;
			}
			if(s->camp_pad[s->cont][s->cont2] == '2')
			{
				s->quantidade_ganhou--;
			}
			if(s->camp_pad[s->cont][s->cont2] == '3')
			{
				s->quantidade_ganhou--;
			}
			if(s->camp_pad[s->cont][s->cont2] == '4')
			{
				s->quantidade_ganhou--;
			}
			if(s->camp_pad[s->cont][s->cont2] == '5')
			{
				s->quantidade_ganhou--;
			}
			if(s->camp_pad[s->cont][s->cont2] == '6')
			{
				s->quantidade_ganhou--;
			}
			if(s->camp_pad[s->cont][s->cont2] == '7')
			{
				s->quantidade_ganhou--;
			}
			if(s->camp_pad[s->cont][s->cont2] == '8')
			{
				s->quantidade_ganhou--;
			}
			if(s->camp_pad[s->cont][s->cont2] == ' ')
			{
				s->quantidade_ganhou--;
			}

			if(s->camp_padinvi[s->cont][s->cont2] == 'X') // ESPAÇO MARCADO COM BANDEIRA MAS SEM BOMBA, IMPOSSÍVEL GANHAR SEM ABRIR
			{
				s->quantidade_ganhou++;
			}
		}
	}

	if(s->quantidade_ganhou == 0)
	{
		you_win(s);
	}else
	{
		progresso_jogatina(s);
		digitar_coordenada(s);
	}
	fflush(stdin);
}
// -------------------------------------------------------------- Fim Verificar se o jogador ganhou ou não ---------------------------------------------------------------------------------

//  -------------------------------------------------------------------  Apresentar progresso de jogatina  ----------------------------------------------------------------------------------
void progresso_jogatina(Campominado*s)
{
	fflush(stdin);
	system ("clear || cls");
    fflush(stdin);
	s->corder_lin = 0;
    printf("\n----------------------------------------------------------------------- Campo %dX%d - %d BOMBAS --------------------------------------------------------------------------------- \n \n",s->lin,s->col,s->bombas);

	printf("\n\n");
	printf("                                                           "); // Coordenadas superiores das colunas para deixar o campo melhor visualmente
	for(s->corder_col=0;s->corder_col<s->col;s->corder_col++)
	{
		if(s->corder_col<9)
		{
			printf("%d     ", s->corder_col+1);

		}else if(s->corder_col<99)
		{
			printf(" %d   ", s->corder_col+1);
		}else
		{
			printf("%d   ", s->corder_col+1);
		}

	}
	printf("\n\n");

    for(s->cont=0;s->cont<s->lin;s->cont++)
	{
		if(s->cont<9)
		{
			printf ("\t                                            %d  ", s->cont+1); // Coordenadas da esquerda das linhas para deixar o campo melhor visualmente
			printf (" |");
		}else if (s->cont<99)
		{
			printf ("\t                                           %d  ", s->cont+1); // Coordenadas da esquerda das linhas para deixar o campo melhor visualmente
			printf (" |");
		}else
		{
			printf ("\t                                           %d ", s->cont+1); // Coordenadas da esquerda das linhas para deixar o campo melhor visualmente
			printf (" |");
		}

    	for(s->cont2=0;s->cont2<s->col;s->cont2++)
    	{
    		printf("  %c ",s->camp_pad[s->cont][s->cont2]);
    		printf (" |");
		}

		if(s->cont<=9)
		{
			printf ("   %d                                            ", s->cont+1); // Coordenadas da direita das linhas para deixar o campo melhor visualmente
		}else if(s->cont<=99)
		{
			printf ("   %d                                           ", s->cont+1); // Coordenadas da direita das linhas para deixar o campo melhor visualmente
		}else
		{
			printf ("  %d                                          ", s->cont+1); // Coordenadas da direita das linhas para deixar o campo melhor visualmente
		}

		printf ("\n\n");
	}

	printf("                                                           "); // Coordenadas inferiores das colunas para deixar o campo melhor visualmente
	for(s->corder_col=0;s->corder_col<s->col;s->corder_col++)
	{
		if(s->corder_col<=9)
		{
			printf("%d     ", s->corder_col+1);

		}else if(s->corder_col<=99)
		{
			printf("%d    ", s->corder_col+1);
		}else
		{
			printf("%d    ", s->corder_col+1);
		}

	}
	bandeiras_colocadas(s);
	printf ("\n\n\n\t\t\t\t\t\t\t    Quantidade de bandeiras colocadas: %d/%d\n", s->bandeiras,s->bombas);
	fflush(stdin);
}
//------------------------------------------------------------------- FIM DA APRESENTAÇÃO DO STATUS DA JOGATINA -----------------------------------------------------------------------------

//------------------------------------------------------------------------- Gerar bombas aleatórias -------------------------------------------------------------------------------------
void bomba(Campominado *s)
{
	fflush(stdin);
	srand(time(NULL));

	s->bombas = s->quantidade_bombas;

	for (s->quantidade_bombas;s->quantidade_bombas>0;s->quantidade_bombas--)
	{
		s->cont = rand() % s->lin;
		s->cont2 = rand() % s->col;

		if(s->camp_padinvi[s->cont][s->cont2] != '*') // Evitar que ele coloque uma bomba onde já foi colocada - Chance baixa mas tem!
		{
			s->camp_padinvi[s->cont][s->cont2] = '*';
		}else
		{
			s->quantidade_bombas++;
		}
	}
	s->bandeiras = 0; // Zerar quantidade de bandeiras para iniciar o jogo!
	fflush(stdin);
}
//--------------------------------------------------------------------------- Fim Gerar bombas aleatórias --------------------------------------------------------------------------------

//----------------------------------------------------------------------------- Apresentar Campo padrão ------------------------------------------------------------------------------------------
void apres_camp(Campominado *s)
{
    fflush(stdin);
	s->corder_lin = 0;
    printf("\n----------------------------------------------------------------------- Campo %dX%d - %d BOMBAS --------------------------------------------------------------------------------- \n \n",s->lin,s->col,s->bombas);

	printf("\n\n");
	printf("                                                           "); // Coordenadas superiores das colunas para deixar o campo melhor visualmente
	for(s->corder_col=0;s->corder_col<s->col;s->corder_col++)
	{
		if(s->corder_col<9)
		{
			printf("%d     ", s->corder_col+1);

		}else if(s->corder_col<99)
		{
			printf(" %d   ", s->corder_col+1);
		}else
		{
			printf("%d   ", s->corder_col+1);
		}

	}
	printf("\n\n");

    for(s->cont=0;s->cont<s->lin;s->cont++)
	{
		if(s->cont<9)
		{
			printf ("\t                                            %d  ", s->cont+1); // Coordenadas da esquerda das linhas para deixar o campo melhor visualmente
			printf (" |");
		}else if (s->cont<99)
		{
			printf ("\t                                           %d  ", s->cont+1); // Coordenadas da esquerda das linhas para deixar o campo melhor visualmente
			printf (" |");
		}else
		{
			printf ("\t                                           %d ", s->cont+1); // Coordenadas da esquerda das linhas para deixar o campo melhor visualmente
			printf (" |");
		}

    	for(s->cont2=0;s->cont2<s->col;s->cont2++)
    	{
    		printf("  %c ",s->camp_pad[s->cont][s->cont2]);
    		printf (" |");
		}

		if(s->cont<=9)
		{
			printf ("   %d                                            ", s->cont+1); // Coordenadas da direita das linhas para deixar o campo melhor visualmente
		}else if(s->cont<=99)
		{
			printf ("   %d                                           ", s->cont+1); // Coordenadas da direita das linhas para deixar o campo melhor visualmente
		}else
		{
			printf ("   %d                                          ", s->cont+1); // Coordenadas da direita das linhas para deixar o campo melhor visualmente
		}

		printf ("\n\n");
	}

	printf("                                                           "); // Coordenadas inferiores das colunas para deixar o campo melhor visualmente
	for(s->corder_col=0;s->corder_col<s->col;s->corder_col++)
	{
		if(s->corder_col<=9)
		{
			printf("%d     ", s->corder_col+1);

		}else if(s->corder_col<=99)
		{
			printf("%d    ", s->corder_col+1);
		}else
		{
			printf("%d   ", s->corder_col+1);
		}

	}

	printf ("\n\n\n\t\t\t\t\t\t\t    Quantidade de bandeiras colocadas: %d/%d\n", s->bandeiras,s->bombas);
	fflush(stdin);
}
//---------------------------------------------------------------------------- Fim Apresentar Campo padão -------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------- Apresentar Game Over ---------------------------------------------------------------------------------------
void game_over(Campominado *s)
{
	fflush(stdin);
	system ("clear || cls");
	abrir_campos_fim_de_jogo(s); // Abrir campos fechados sem bombas no campo visível, onde tiver bandeira permanece
	progresso_jogatina(s);
	apresen_arte_game_over(s);

	printf ("\n S - Sair \n V - Voltar ao menu principal\n");
	fflush(stdin);
	scanf ("%c", &s->opcao);
	fflush(stdin);
	if(s->opcao == 's' || s->opcao == 'v') // Caso o jogador digite a letra em minusculo
	{
		s->opcao = s->opcao-32;
	}
	switch (s->opcao) // Depois do GAME OVER o jogador tem a opção de voltar pro menu ou sair do jogo
	{
		case 'S':
			system("cls || clear");
			exit (1);
			break;

		case 'V':
			system("cls || clear");
			menu(s);
			break;

		default:
            system("cls || clear");
            game_over(s);
            break;
	}

	for(s->cont = 0; s->cont < s->lin; s->cont++)
	{
		free(s->camp_pad[s->cont]);
		free(s->camp_padinvi[s->cont]);
	}
	free(s->camp_pad);
	free(s->camp_padinvi);

	fflush(stdin);
}
//-------------------------------------------------------------------------------------- Fim Apresentar Game Over -----------------------------------------------------------------------------

//--------------------------------------------------------------------------------------- Abrir espaço selecionada ------------------------------------------------------------------------------------
int abr_espaco(Campominado*s)
{
	fflush(stdin);
	int i,j;

	if(s->lin_s >= 0 && s->lin_s < s->lin && s->col_s >= 0  && s->col_s < s->col && s->camp_padinvi[s->lin_s][s->col_s] == '*' || s->camp_padinvi[s->lin_s][s->col_s] == 'B')
	{
		game_over(s);
	}

	if(s->lin_s >= 0 && s->lin_s < s->lin && s->col_s >= 0  && s->col_s < s->col && s->camp_padinvi[s->lin_s][s->col_s] == 'X') //CAMPO SEM BOMBA MAS ANTES MARCADO COM BOMBA
	{
		apresen_dicas_local(s);
	}

	if(s->lin_s >= 0 && s->lin_s < s->lin && s->col_s >= 0  && s->col_s < s->col && s->camp_padinvi[s->lin_s][s->col_s] >= 48 && s->camp_padinvi[s->lin_s][s->col_s] <= 57) // entre 48 e 57 estão os numeros na tabela asci
	{
		s->camp_pad[s->lin_s][s->col_s] = s->camp_padinvi[s->lin_s][s->col_s];
		verif_ganhou(s);
		progresso_jogatina(s);
		digitar_coordenada(s);
	}

	for(i=s->lin_s-1;i<s->lin_s+2;i++)
	{
		for(j=s->col_s-1;j<s->col_s+2;j++)
		{
			if(i >= 0 && j >= 0 && i < s->lin && j < s->col && s->camp_padinvi[i][j] == ' ' && s->camp_pad[i][j] != ' ' )
			{
				s->camp_pad[i][j] = ' ';
				s->lin_s = i;
				s->col_s = j;
				abr_espaco(s);
			}
			else if (i>= 0 && j >= 0 && i < s->lin && j < s->col && s->camp_padinvi[i][j] >= 48 && s->camp_pad[i][j] < 48)
			{
				s->camp_pad[i][j] = s->camp_padinvi[i][j];
				s->lin_s = i;
				s->col_s = j;
				abr_espaco(s);
			}
		}
	}
	fflush(stdin);
}
//-------------------------------------------------------------------------------------- Fim Abrir espaço selecionado -------------------------------------------------------------------

//--------------------------------------------------------------------------------- Colocar uma bandeira no local selecionado ----------------------------------------------------------------
void colocar_bandeira(Campominado*s)
{
	fflush(stdin);

	if(s->bandeiras == s->bombas)
	{
		printf ("\n\n Limite de bandeiras atingido, abra um espaço que contenha uma bandeira para liberar mais!\n\n");
		digitar_coordenada(s);

	}else

	{
		if(s->camp_pad[s->lin_s][s->col_s]  == 'B') // CAMPO QUE JÁ TEM UMA BANDEIRA
		{
			printf("\n\n Campo já possui uma bandeira, selecione outro ou abra o selecionado\n\n");
			digitar_coordenada(s);
		}

		if(s->camp_padinvi[s->lin_s][s->col_s] == '*' ) // Campo Fechado com bomba
		{
			s->camp_pad[s->lin_s][s->col_s]  = 'B';
			s->camp_padinvi[s->lin_s][s->col_s]  = 'B'; // CAMPO INVISÍVEL RECEBE O REFERENTE A BANDEIRA MARCADA ONDE HÁ BOMBA
			progresso_jogatina(s);
			digitar_coordenada(s);
		}

		if(s->camp_pad[s->lin_s][s->col_s]  != '#') // IMPEDIR QUE O JOGADOR COLOQUE UMA BANDEIRA EM UM ESPAÇO ABERTO
		{
			printf("\nImpossível colocar uma bandeira em um local aberto\n\t");
			digitar_coordenada(s);
		}

		if((s->camp_padinvi[s->lin_s][s->col_s]  != '*') && // CAMPO FECHADO SEM BOMBA
		(s->camp_pad[s->lin_s][s->col_s]  != 'B'))
		{
			s->camp_pad[s->lin_s][s->col_s]  = 'B';
			s->camp_padinvi[s->lin_s][s->col_s]  = 'X'; // CAMPO INVISÍVEL RECEBE X REFERENTE A BANDEIRA MARCADA ONDE NÃO HÁ BOMBA

			progresso_jogatina(s);
			digitar_coordenada(s);
		}
	}
	fflush(stdin);
}
//------------------------------------------------------------------------------- Fim Colocar uma bandeira no local selecionado -------------------------------------------------------------------------

//------------------------------------------------------------------------ Selecionar se quer abrir um espaço ou colocar uma bandeira ---------------------------------------------------------------
void abrir_ou_bandeira(Campominado*s)
{
	fflush(stdin);
	printf ("\n A - Abrir espaço\n B - Adicionar bandeira\n ");
	scanf ("%c", &s->opcao);

    if(s->opcao == 'a' || s->opcao == 'b') // Caso o jogador digite a letra em minusculo
	{
		s->opcao = s->opcao-32;
	}

	if (s->opcao == 'A') // Abrir espaço
	{
		abr_espaco(s);

	}else if (s->opcao == 'B') // Colocar bandeira
	{
		colocar_bandeira(s);

	}else if (s->opcao != 'A' || s->opcao != 'B')
	{
		printf ("\nDigite uma opção válida!\n");
		abrir_ou_bandeira(s);

	}else if (s->camp_pad[s->cont][s->cont2] == ' ') // Evitar que o usuário coloque uma bandeira em um lugar aberto
	{
		printf ("Não é possível colocar uma bandeira em um campo já aberto\n");
		system("cls || clear");
	}
	fflush(stdin);
}
//------------------------------------------------------------------ Fim Selecionar se quer abrir um espaço ou colocar uma bandeira -------------------------------------------------------------

//---------------------------------------------------------------------------- Preenchendo campo padrão ------------------------------------------------------------------------------------------------------------
void preenche(Campominado *s)
{
	fflush(stdin);
	for(s->cont=0;s->cont<s->lin;s->cont++)
	{
		for(s->cont2=0;s->cont2<s->col;s->cont2++)
		{
			s->camp_pad[s->cont][s->cont2] = '#';
		}
	}
	fflush(stdin);
}
//------------------------------------------------------------------------ Fim do campo padrão------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------- Iniciar um novo Jogo --------------------------------------------------------------------------------------------------
void novojogo(Campominado *s)
{
	fflush(stdin);
	system("cls || clear");

	criar_campo(s);

	zerar_campo(s);

	bomba(s);

	preenche(s);

	apresen_dicas(s);

	s->cronometro = clock(); // Tempo de jogo
    apres_camp(s);
    digitar_coordenada(s);
    fflush(stdin);
}
//----------------------------------------------------------------------- Fim Iniciar um novo Jogo ---------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------- Menu Principal --------------------------------------------------------------------------------------------
void menu(Campominado *s)
{
	char teclar;
	fflush(stdin);
	system("cls || clear");
	apresen_arte_campominado(s);
	        printf("\n\n\t\t\t\t\t\t\t\t\t N - Novo jogo\n\n");
	        printf ("\n\t\t\t\t\t\t\t\t\t C - Como jogar\n\n");
	        printf("\n\t\t\t\t\t\t\t\t\t P - Personalizar\n\n");
	        printf("\n\t\t\t\t\t\t\t\t\t R - Recordes\n\n");
	        printf("\n\t\t\t\t\t\t\t\t\t S - Sair\n\n");

	        apres_arte_campominado2(s);
	        printf("\n\n\t\t\t\t\t\t\t\t\t     ");
	do{
			if(kbhit()){
				teclar = getch();

		        if(teclar > 91)// Caso o jogador digite a letra em minusculo
		        {
		        	teclar = teclar-32;
				}

		        switch(teclar)
		        {
		            case 'S':
		                    system("cls || clear");
		                    printf("Saindo do menu...\n");
		                    exit(1);
		                    break;
		            case 'R':
		                    system("cls || clear");
		                    fflush(stdin);
		                    apres_arte_recordes(s);
		                    recordes(s);
		                    break;

		            case 'P':
		                    system("cls || clear");
		                    fflush(stdin);
		                    personalizar_jogo(s);
		                    break;

		            case 'C':
		            		system("cls || clear");
		            		comojogar(s);
		            		break;

		            case 'N':
		            		s->lin = 9;
						    s->col = 9;
						    s->quantidade_bombas = 10;
						    s->pers_ou_pad = 0; //Jogo padrão
		                    novojogo (s);
		                	break;

		            default:
		                    system("cls || clear");
		                    printf("\nOpção inválida! Tente novamente.\n\n");
		                    menu(s);
		                    break;
				}
			}
	}while(teclar != 'S' || teclar != 'R' || teclar != 'P' || teclar != 'C' || teclar != 'N');
}
//----------------------------------------------------------------------------------------- Fim Menu Principal -----------------------------------------------------------------------------------------

int main(){
	system("mode con:cols=10000 lines=10000"); // TAMANHO DA TELA

	keybd_event ( VK_MENU, 0x38, 0, 0 ); //TELA CHEIA
	keybd_event ( VK_SPACE, 0x39, 0, 0 );
	keybd_event(0x58,0,0,0);
	keybd_event ( VK_MENU, 0x38, KEYEVENTF_KEYUP, 0 );
	keybd_event ( VK_SPACE, 0x39, KEYEVENTF_KEYUP, 0 );
	keybd_event(0x58,0,KEYEVENTF_KEYUP,0);

	setlocale(LC_ALL, "Portuguese"); // Colocar o código em português

	Campominado NOTAMAXIMA; // Definir o typdef

	menu(&NOTAMAXIMA);



	return 0;
}

