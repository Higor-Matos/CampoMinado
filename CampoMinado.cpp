// Higor de Deus Matos - 6372
// Gustavo Rodrigues Marques - 6375

//---------------------------------------------------------------------Bibliotecas utilizadas---------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
//---------------------------------------------------------------------Fim das bibliotcas--------------------------------------------------------------------



//----------------------------------------------------------------------------Início do código------------------------------------------------------------------------------------------
int main(){
    
    //-----------------------------------------------------------------Deixando a linguagem em português-------------------------------------------------------------------------------------------
    
    setlocale(LC_ALL, "Portuguese");

    //------------------------------------------------------------------Iniciando as variáveis--------------------------------------------------------------------------------------------------------
    
    int opcao,i,lin,col,lin_s,col_s,abr_ou_band,col_bomb,lin_bomb,bomb_ale,cont_bomb = 0;
    char camp_pad[9][9],camp_padinvi[9][9];
    
    //------------------------------------------------------------------Fim das variáveis----------------------------------------------------------------------------------------------------
    
	//------------------------------------------------------------------Preenchendo campo padrão------------------------------------------------------------------------------------------
	
	for(lin=0;lin<9;lin++)
	{
		for(col=0;col<9;col++)
		{
			camp_pad[lin][col] = '#';
			camp_padinvi[lin][col] = '#';
		}
	}
	
	//------------------------------------------------------------------Fim do campo padrão------------------------------------------------------------------------------------------------
	
	//------------------------------------------------------------------------Funções-------------------------------------------------------------------------------------------------------------
	
	//---------------------------------------------------------------Gerar bombas aleatorias----------------------------------------------------------------------------------------------
	srand(time(NULL));
	for (i=0;i<10;i++)
	{
		lin_bomb = rand() % 9;
		col_bomb = rand() % 9;
		
		if(camp_padinvi[lin_bomb][col_bomb] != '*')
		{
			camp_padinvi[lin_bomb][col_bomb] = '*';
		}else
		{
			i--;
		}
	}
		//------------------------------------------------------------------Fim Gerar bombas aleatorias-------------------------------------------------------------------------------------
		
	//---------------------------------------------------------------------------Fim das funções-------------------------------------------------------------------------------------------------
	
        //--------------------------------------------------------------------Início do Menu----------------------------------------------------------------------------------------------------
        do
        {
            printf("\t\tMenu");
            printf("\n 1 - Novo jogo\n");
            printf (" 2 - Como jogar\n");
            printf(" 3 - Personalizar o tabuleiro\n");
            printf(" 4 - Recordes\n");
            printf(" 5 - Sair\n");

            printf("\n Opção: ");
            scanf("%d", &opcao);

            switch( opcao )
            {
                case 5:
                        system("cls");
                        printf("Saindo do menu...\n");
                        break;
                case 4:
                        system("cls");
                        printf(" Recordes! \n");
                        break;
                case 3:
                        system("cls");
                        printf(" Personalizar o tabuleiro \n");
                        break;
                
                case 2:
                		system("cls");
                		printf ("\nComo Jogar\n ");
                		printf ("\nSelecione o que for desejado conforme o menu e siga a instrução:\n\n# Quadrado fechado\n\nB Bandeira\n\n* Bomba\n\n- Quadrado aberto sem bomba adjacente\n");
                		break;
                case 1:
                        system("cls");
                        printf("\n\t\tNovo jogo - Campo padrão 9x9 10 bombas\n");
                        
                        //------------------------------------------------------------------- Apresentar Campo padão ---------------------------------------------------------------------
                        
                        printf("\n\t -------------------- Campo padrão --------------------- \n \n");
                    
                        for(lin=0;lin<9;lin++)
						{
							printf ("\t");
							printf (" |");
                        	for(col=0;col<9;col++)
                        	{
                        		printf("  %c ",camp_pad[lin][col]);
                        		printf (" |");
							}
							printf ("\n");
						}
						// ----------------------------------------------------------------------- Fim da apresentação ----------------------------------------------------------------------------------------------
						
						while(true) //--------------------------------------- Menu de escolha para adicionar bandeira ou abrir espaço --------------------------------------------------------------------
						{
							printf ("\n\tDeseja adicionar uma bandeira ou abrir um espaço?\n\n\t0 - Adicionar bandeira\n\t1 - Abrir espaço\n ");
							scanf ("%d", &abr_ou_band);
							
							if (abr_ou_band == 1) // -------------------------------------------------- MENU - Abrir espaço: ----------------------------------------------------------------------------
							{
								printf("\n\tDigite a linha desejada para abrir: ");
								scanf ("%d", &lin_s);
								
								printf("\n\1Digite a coluna desejada para abrir: ");
								scanf ("%d", &col_s);							
								// ---------------------------------------------- Verificão: Campo visível com campo padrão ** = bomba com bandeira marcada e * = bomba -------------------------
								if(
									camp_padinvi[lin_s][col_s] == '*'|| 
									camp_padinvi[lin_s][col_s] == '**' // CASO O JOGADOR RESOLVA ABRIR UM ESPAÇO QUE TENHA UMA BANDEIRA E UMA BOMBA, O JOGO NÃO PERDE A LOCALIZAÇÃO DA BOMBA.
								)
								{
									system("cls");
									printf("\n \t\t============== GAME OVER ==============\n");
									for(lin=0;lin<9;lin++)
									{
			                        	for(col=0;col<9;col++)
			                        	{
			                        		printf("  %c ",camp_padinvi[lin][col]);
			                        		printf (" |");
										}	
										printf ("\n");									
									}
									break;
									// --------------------------------------------- GAME OVER SE A COORDENADA MARCADA FOR * OU ** ---------------------------------------------------------
								} else
								{
									camp_pad[lin_s][col_s] = '-';	// CAMPO VISIVEL RECEBE - referente a ESPAÇO ABERTO!
								}					
								
							}else // ------------------------------------------------------ MENU - Colocar bandeira: ----------------------------------------------------------------------
							{
								printf("\nDigite a linha desejada para colocar bandeira: ");
								scanf ("%d", &lin_s);
								
								printf("Digite a coluna desejada para colocar bandeira: ");
								scanf ("%d", &col_s);
								
								if(camp_padinvi[lin_s][col_s] == '*')
								{
									camp_pad[lin_s][col_s] = '*';
									camp_padinvi[lin_s][col_s] = '**'; // LOCAL QUE FOI COLOCADO UMA BANDEIRA E HAVIA UMA BOMBA
									
								}else if(camp_pad[lin_s][col_s] != '-') // IMPEDIR QUE O JOGADOR COLOQUE UMA BANDEIRA EM UM ESPAÇO ABERTO
								{
									camp_pad[lin_s][col_s] = '-';
									camp_padinvi[lin_s][col_s] = '-';
								}									
							}
							
							system("cls");
							// ---------------------------------------------- APRESENTAÇÃO DO STATUS DA JOGATINA -----------------------------------------------------------------
							for(lin=0;lin<9;lin++)
							{
		                        for(col=0;col<9;col++)
	                        	{               		
	                        		printf("  %c ",camp_pad[lin][col]);
	                        		printf (" |");
								}
								printf ("\n");
							}
						}
							// ---------------------------------------- FIM DA APRESENTAÇÃO DO STATUS DA JOGATINA -------------------------------------------------------
                    break;    
                default:
                        system("cls");
                        printf("Opção inválida! Tente novamente.\n");
            }
        } while(opcao < 1 || opcao > 4);
}

        //--------------------------------------------------------------Fim do Menu------------------------------------------------------------------------


