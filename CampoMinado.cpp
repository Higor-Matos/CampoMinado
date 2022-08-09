// Higor de Deus Matos - 6372
// Gustavo Rodrigues Marques - 6375

//---------------------------------------------------------------------Bibliotecas utilizadas---------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
//---------------------------------------------------------------------Fim das bibliotcas--------------------------------------------------------------------



//----------------------------------------------------------------------------In�cio do c�digo------------------------------------------------------------------------------------------
int main(){
    
    //-----------------------------------------------------------------Deixando a linguagem em portugu�s-------------------------------------------------------------------------------------------
    
    setlocale(LC_ALL, "Portuguese");

    //------------------------------------------------------------------Iniciando as vari�veis--------------------------------------------------------------------------------------------------------
    
    int opcao,i,lin,col,lin_s,col_s,abr_ou_band,col_bomb,lin_bomb,bomb_ale,cont_bomb = 0;
    char camp_pad[9][9],camp_padinvi[9][9];
    
    //------------------------------------------------------------------Fim das vari�veis----------------------------------------------------------------------------------------------------
    
	//------------------------------------------------------------------Preenchendo campo padr�o------------------------------------------------------------------------------------------
	
	for(lin=0;lin<9;lin++)
	{
		for(col=0;col<9;col++)
		{
			camp_pad[lin][col] = '#';
			camp_padinvi[lin][col] = '#';
		}
	}
	
	//------------------------------------------------------------------Fim do campo padr�o------------------------------------------------------------------------------------------------
	
	//------------------------------------------------------------------------Fun��es-------------------------------------------------------------------------------------------------------------
	
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
		
	//---------------------------------------------------------------------------Fim das fun��es-------------------------------------------------------------------------------------------------
	
        //--------------------------------------------------------------------In�cio do Menu----------------------------------------------------------------------------------------------------
        do
        {
            printf("\t\tMenu");
            printf("\n 1 - Novo jogo\n");
            printf (" 2 - Como jogar\n");
            printf(" 3 - Personalizar o tabuleiro\n");
            printf(" 4 - Recordes\n");
            printf(" 5 - Sair\n");

            printf("\n Op��o: ");
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
                		printf ("\nSelecione o que for desejado conforme o menu e siga a instru��o:\n\n# Quadrado fechado\n\nB Bandeira\n\n* Bomba\n\n- Quadrado aberto sem bomba adjacente\n");
                		break;
                case 1:
                        system("cls");
                        printf("\n\t\tNovo jogo - Campo padr�o 9x9 10 bombas\n");
                        
                        //------------------------------------------------------------------- Apresentar Campo pad�o ---------------------------------------------------------------------
                        
                        printf("\n\t -------------------- Campo padr�o --------------------- \n \n");
                    
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
						// ----------------------------------------------------------------------- Fim da apresenta��o ----------------------------------------------------------------------------------------------
						
						while(true) //--------------------------------------- Menu de escolha para adicionar bandeira ou abrir espa�o --------------------------------------------------------------------
						{
							printf ("\n\tDeseja adicionar uma bandeira ou abrir um espa�o?\n\n\t0 - Adicionar bandeira\n\t1 - Abrir espa�o\n ");
							scanf ("%d", &abr_ou_band);
							
							if (abr_ou_band == 1) // -------------------------------------------------- MENU - Abrir espa�o: ----------------------------------------------------------------------------
							{
								printf("\n\tDigite a linha desejada para abrir: ");
								scanf ("%d", &lin_s);
								
								printf("\n\1Digite a coluna desejada para abrir: ");
								scanf ("%d", &col_s);							
								// ---------------------------------------------- Verific�o: Campo vis�vel com campo padr�o ** = bomba com bandeira marcada e * = bomba -------------------------
								if(
									camp_padinvi[lin_s][col_s] == '*'|| 
									camp_padinvi[lin_s][col_s] == '**' // CASO O JOGADOR RESOLVA ABRIR UM ESPA�O QUE TENHA UMA BANDEIRA E UMA BOMBA, O JOGO N�O PERDE A LOCALIZA��O DA BOMBA.
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
									camp_pad[lin_s][col_s] = '-';	// CAMPO VISIVEL RECEBE - referente a ESPA�O ABERTO!
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
									
								}else if(camp_pad[lin_s][col_s] != '-') // IMPEDIR QUE O JOGADOR COLOQUE UMA BANDEIRA EM UM ESPA�O ABERTO
								{
									camp_pad[lin_s][col_s] = '-';
									camp_padinvi[lin_s][col_s] = '-';
								}									
							}
							
							system("cls");
							// ---------------------------------------------- APRESENTA��O DO STATUS DA JOGATINA -----------------------------------------------------------------
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
							// ---------------------------------------- FIM DA APRESENTA��O DO STATUS DA JOGATINA -------------------------------------------------------
                    break;    
                default:
                        system("cls");
                        printf("Op��o inv�lida! Tente novamente.\n");
            }
        } while(opcao < 1 || opcao > 4);
}

        //--------------------------------------------------------------Fim do Menu------------------------------------------------------------------------


