#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 6
struct plato{
	char nombre[40];
	char es_entrada;
	char es_plato_ppal;
	char es_postre;
	int calorias;
};

void combinaciones(struct plato V[], int);

int main(){
	
	struct plato VEC[N];
	
	int I;
	char NOMBRE[][20] = { "MILANESA" , "SPAGHETTI" , "ENSALADA" , "EMPANADA" , "HELADO" , "FLAN"};
	
	for(I=0 ; I<6 ; I++){
		strcpy(VEC[I].nombre, NOMBRE[I]);
		printf("%i. %s\n", I+1 , VEC[I].nombre);
	}
	
	for(I=0 ; I<N ; I++){
		if(strcmp(VEC[I].nombre, "MILANESA")==0 || strcmp(VEC[I].nombre, "SPAGHETTI")==0){
			VEC[I].es_plato_ppal = 'T';
			printf(" %c \n", VEC[I].es_plato_ppal);
		}
		else if(strcmp(VEC[I].nombre, "ENSALADA")==0 || strcmp(VEC[I].nombre, "EMPANADA")==0){
			VEC[I].es_entrada = 'T';
			printf(" %c \n", VEC[I].es_entrada);
		}
		else {
			VEC[I].es_postre = 'T';
			printf(" %c \n", VEC[I].es_postre);
		}
	}
	
	for(I=0 ; I<N ; I++){
		if(strcmp(VEC[I].nombre, "MILANESA")==0 || strcmp(VEC[I].nombre, "EMPANADA")==0){
			VEC[I].calorias = 500;
		}	
		else if(strcmp(VEC[I].nombre, "SPAGHETTI")==0 || strcmp(VEC[I].nombre, "FLAN")==0){
			VEC[I].calorias = 350;
		}
		else{
			VEC[I].calorias = 150;
		}
	}
	
	for(I=0 ; I<N ; I++){
		printf("%i", VEC[I].calorias);
		printf("\n");	
	}
	
	combinaciones( VEC , N );
}

void combinaciones(struct plato V[], int num){
	
	int I , J ; 
	int X , Z;
	int A , B;
	int FLAG=0 , FLAG2=0 , FLAG3=0;
	int L , L2;
	int SUMA = 0;
	char plato1[40];
	char plato2[40];
	char plato3[40];
	
	/*
		-- MILANESA -0
		-- ESPAGHETTI -1
		-- ENSALADA -2
		-- EMPANADA
		-- HELADO
		-- FLAN
	*/
	for(I=0 ; I<N ; I++){
		printf("\n b");
		FLAG = 0;
		FLAG2 = 0;
		if( V[I].es_entrada == 'T' ){
			printf("\n hola");
			printf("\n %i  %i ", FLAG, FLAG2);
			strcpy(plato1, V[I].nombre);
			for(J=0 ; J<N ; J++){
				if ( FLAG == 0 && V[J].es_plato_ppal == 'T' ){
					
					strcpy(plato2, V[I].nombre);
					FLAG++;
					L = J;
				}
				else if ( FLAG2 == 0 && V[J].es_postre == 'T' ){
					
					strcpy(plato3, V[I].nombre);
					FLAG2++;
					L2 = J;
				}
				
				else if(FLAG == 1 && FLAG2 == 1){
					
					printf( "\n %s  ,  %s  , %s ", V[I].nombre , V[L].nombre , V[L2].nombre);
				}
				
			}
		}
	}
	
	for(I=0 ; I<N ; I++){
		printf("\n b");
		if( V[I].es_plato_ppal == 'T' ){
			printf("\n hola");
			FLAG = 0;
			FLAG2 = 0;
			printf("\n %i  %i ", FLAG, FLAG2);
			strcpy(plato1, V[I].nombre);
			for(J=0 ; J<N ; J++){
				if ( FLAG == 0 && V[J].es_entrada == 'T' ){
					
					strcpy(plato2, V[I].nombre);
					FLAG++;
					L = J;
				}
				else if ( FLAG2 == 0 && V[J].es_postre == 'T' ){
					
					strcpy(plato3, V[I].nombre);
					FLAG2++;
					L2 = J;
				}
				
				else if(FLAG == 1 && FLAG2 == 1){
					
					printf( "\n %s  ,  %s  , %s ", V[L].nombre , V[I].nombre , V[L2].nombre);
				}
			}
		}
	}
	
	for(I=0 ; I<N ; I++){
		printf("\n b");
		if( V[I].es_postre == 'T' ){
			printf("\n hola");
			FLAG = 0;
			FLAG2 = 0;
			strcpy(plato1, V[I].nombre);
			for(J=0 ; J<N ; J++){
				if ( FLAG == 0 && V[J].es_plato_ppal == 'T' ){
					
					strcpy(plato2, V[I].nombre);
					FLAG++;
					L = J;
				}
				else if ( FLAG2 == 0 && V[J].es_entrada == 'T' ){
					
					strcpy(plato3, V[I].nombre);
					FLAG2++;
					L2 = J;
				}
				
				else if(FLAG == 1 && FLAG2 == 1){
					
					printf( "\n %s  ,  %s  , %s ", V[L2].nombre , V[L].nombre , V[I].nombre);
				}
			}
		}
	}
}
	
	

