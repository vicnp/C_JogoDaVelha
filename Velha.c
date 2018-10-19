#include<stdio.h>  
#include<conio.h> 
#include <stdlib.h> 

void inicializa_matriz(char Matriz[3][3]);  
void loop(int l,char Mat[3][3], char O, char X); 
void inicializa_game(char Matriz[3][3]); 
void checar_vencedor(int l,char O, char X,char Matriz[3][3]); 
void menu(int l,char Matriz[3][3], char O, char X); 
void retry();

int main(void){
    char Matriz[3][3]; 
    char O='O', X='X';  
    int l=0;
	menu(l, Matriz, O, X);
	inicializa_matriz(Matriz);
	loop(l, Matriz, O, X);

    getch();
    return(0);
}

void inicializa_matriz(char Matriz[3][3]){
 	int i,j;
 	for(i=0;i<3;i++)
        	for(j=0;j<3;j++)
            	Matriz[i][j]=' ';
}

void loop(int l, char Matriz[3][3], char O, char X){
	int i=0,j=0;
    while(l<=9){
       	inicializa_game(Matriz);
        printf("\n\n\n\n\n\n\n\n\n\n\n\nDigite as cordenadas para sua jogada: \n");
        if(l%2){
			printf(">>>> Jogador 2\n>>>> LINHA: ");
		}else{
			printf(">>>> Jogador 1\n>>>> LINHA: ");
		}
		
        scanf("%d",&i);
        printf(">>>> COLUNA: ");
        scanf("%d",&j);

        if(Matriz[i-1][j-1]==' ')
        {
            if(l%2){
				Matriz[i-1][j-1]=X;
			}
            else{
			 	Matriz[i-1][j-1]=O;
			 }
          l++;
        }
        
		checar_vencedor(l,O,X,Matriz);
		
        if(l==9){
            printf("Houve empate !!! \n\n");
            system("pause");
            retry();
            break;
        }
	system("cls");
    }
}

void inicializa_game(char Matriz[3][3]){
	int i;
 	printf(" Jogo da Velha: \n");

        for(i=0;i<3;i++){ 
            printf("\t\t     %c \xBA %c \xBA %c\n",Matriz[i][0],Matriz[i][1],Matriz[i][2]);
            if(i<3-1)
            {
                printf("\t\t    ÍÍÍ\xCEÍÍÍ\xCEÍÍÍ\n"); 
            }
        }
        
}

void checar_vencedor(int l,char O, char X,char Matriz[3][3]){
	
        if((Matriz[0][0]==O && Matriz[0][1]==O && Matriz[0][2]==O)||
           (Matriz[1][0]==O && Matriz[1][1]==O && Matriz[1][2]==O)||
           (Matriz[2][0]==O && Matriz[2][1]==O && Matriz[2][2]==O)||
           (Matriz[0][0]==O && Matriz[1][0]==O && Matriz[2][0]==O)||
           (Matriz[0][1]==O && Matriz[1][1]==O && Matriz[2][1]==O)||
           (Matriz[0][2]==O && Matriz[1][2]==O && Matriz[2][2]==O)||
           (Matriz[0][0]==O && Matriz[1][1]==O && Matriz[2][2]==O)||
           (Matriz[0][2]==O && Matriz[1][1]==O && Matriz[2][0]==O))
        {
            printf("\n\a\t\tJogador 1 e o vencedor, PARABENS!!!");
            retry();
        }
        if((Matriz[0][0]==X && Matriz[0][1]==X && Matriz[0][2]==X)||
           (Matriz[1][0]==X && Matriz[1][1]==X && Matriz[1][2]==X)||
           (Matriz[2][0]==X && Matriz[2][1]==X && Matriz[2][2]==X)||
           (Matriz[0][0]==X && Matriz[1][0]==X && Matriz[2][0]==X)||
           (Matriz[0][1]==X && Matriz[1][1]==X && Matriz[2][1]==X)||
           (Matriz[0][2]==X && Matriz[1][2]==X && Matriz[2][2]==X)||
           (Matriz[0][0]==X && Matriz[1][1]==X && Matriz[2][2]==X)||
           (Matriz[0][2]==X && Matriz[1][1]==X && Matriz[2][0]==X))
        {
            printf("\n\n\n\n\a\t\tJogador 2 e o vencedor, PARABENS!!!");
            retry();
        }

}

void menu(int l,char Matriz[3][3], char O, char X){
	int op = 0;
	printf("\t\tJogo da velha TADS:");
	printf("\n(1) - Jogar\n");
	printf("\n(2) - Sair\n");
	printf("\nEscolha uma opcao: ");
	scanf("%d", &op);
	
	switch(op){
		case 1:
			system("cls");
			inicializa_matriz(Matriz);
			loop(l, Matriz, O, X);
			break;
		case 2:
			exit(0);
			break;
		default:
			printf("\nOpcao invalida, tente novamente !\n");
			setbuf(stdin, NULL);
			getch();
			system("cls");
			main();
			break;
	}
}


void retry(){
	int op;
	printf("\n \n Desejam jogar novamente ? \n 1 para SIM 0 para NAO \n >>>> ");
	scanf("%d", &op);
	if(op == 1){
		system("cls");
		main();
	}else{
		exit(0);
	}
	
}
