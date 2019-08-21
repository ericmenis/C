#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
 
#define MAX 16
#define MAXNOTA 6
 
struct ALUMNO {
        char NOM[20] ;
        char SEX ;
        int NOTA[MAXNOTA] ;
}  ;
 
void CARGAR ( struct ALUMNO [] , int );
void MIRAR  ( struct ALUMNO [] , int );
void ORD_S_NOM ( struct ALUMNO [] , int );
void INGR_COD ( struct ALUMNO [] , int );
float PROMEDIO ( struct ALUMNO );
void ORD_PROM ( struct ALUMNO [] , int );
void COD_COMPETENCIA ( struct ALUMNO [] , int ) ;
 
main()
{
    struct ALUMNO VEC[MAX] ;
       
    CARGAR ( VEC , MAX );
    MIRAR  ( VEC , MAX );
    ORD_S_NOM ( VEC , MAX );
    MIRAR  ( VEC , MAX );
    INGR_COD ( VEC , MAX );
    MIRAR  ( VEC , MAX );
    ORD_PROM ( VEC , MAX );
    MIRAR  ( VEC , MAX );
    COD_COMPETENCIA (VEC,MAX) ;
   
    printf("\n\n\n FIN DEL PROGRAMA \n\n");
}
 
 
void CARGAR ( struct ALUMNO V[] , int N ) //CARGA DATOS AUTOMATICAMENTE
{
    srand(time(NULL)) ;//time(NULL)
    char NOM[][20] = {"PEPE","LOLA","PACO","LUIS",
                      "ANA","LAURA","MATIAS","CARLOS",
                      "ROBERTO","MARIA","CAROLINA","ESTEFANIA",
                      "EDUARDO","LUCRECIA","MONICA","EDELMIRO"};
    char S[] = {'M','F','M','M','F','F','M','M',
                'M','F','F','F','M','F','F','M'};
    float PROM [N] ;
    int I , J  ;
       
    for ( I = 0 ; I < N ; I++ ) {
        strcpy( V[I].NOM , NOM[I] );
        V[I].SEX = S[I] ;
        PROM [I] = PROMEDIO (V[I]) ;
        for ( J = 0 ; J < MAXNOTA ; J++ )
                V[I].NOTA[J] = 2 + rand()%9 ;
    }  
}
 
 
 
void MIRAR ( struct ALUMNO V[] , int N ) //IMPRIME EN PANTALLA LOS DATOS INGRESADOS
{
    int I , J ;
   
    /*  IMPRESION  */
    printf("\n\n\n  %-10s   %8s \t%7s\t\t      %s\n" , "NOMBRE","SEXO","NOTAS","PROMEDIO" );
    for ( I = 0 ; I < N ; I++ ) {
            printf("\n   %-10s %8c \t" ,V[I].NOM , V[I].SEX );
            for ( J = 0 ; J < MAXNOTA ; J++ )
                printf("%4d" , V[I].NOTA[J]) ;
            printf ("\t%.2f" , PROMEDIO(V[I]) ) ;  
    }
    printf("\n");
    getch();
}
 
 
void ORD_S_NOM ( struct ALUMNO V[] , int N ) //ORDENA LA LISTA POR SEXO Y LUEGO POR NOMBRE
{
    int I , J ;
    struct ALUMNO AUX ;
   
    printf ("\nLISTA ORDENADA POR SEXO Y NOMBRE:") ;
    for ( I = 0 ; I < N-1 ; I++ )
            for ( J = 0 ; J < N-I-1 ; J++ )
                    if ( V[J].SEX > V[J+1].SEX || V[J].SEX==V[J+1].SEX && strcmp ( V[J].NOM , V[J+1].NOM ) > 0  ) {
                        AUX    = V[J] ;
                        V[J]   = V[J+1] ;
                        V[J+1] = AUX ;
                    }
    getch() ;
}
 
/*
CODIGO ()
{
    char MATERIA[][20] = {"FISICA","QUIMICA","LOGICA",
                          "GEOMETRIA","MATEMATICA","ESTADISTICA"};
}
*/
void INGR_COD ( struct ALUMNO V[] , int N ) //INGRESA UN CODIGO DE MATERIA Y ORDENA LA LISTA POR LAS
{                                           //NOTAS DE ESA MATERIA DE FORMA DECRECIENTE
    int I , J , COD ;
    struct ALUMNO AUX ;
   
    printf ("\n\n\nINGRESE CODIGO DE MATERIA  (DE 0 A %d) : " , MAXNOTA-1 ) ;
    scanf ("%d" , &COD) ;
    printf ("\n\nLISTA ORDENADA POR NOTAS DE MATERIA NRO %d" , COD ) ;
 
    for ( I = 0 ; I < N-1 ; I++ )
            for ( J = 0 ; J < N-I-1 ; J++ )
                    if (V[J].NOTA[COD] < V[J+1].NOTA[COD]) {
                        AUX    = V[J] ;
                        V[J]   = V[J+1] ;
                        V[J+1] = AUX ;
                    }
}
 
float PROMEDIO ( struct ALUMNO A ) //INGRESA UN VECTOR DE ESTRUCTURA Y DEVUELVE EL PROMEDIO DE NOTAS
{
    int J , SUM=0 ;
    float PROM ;
   
    for ( J=0 ; J<MAXNOTA ; J++)
        SUM = SUM + A.NOTA[J] ;
   
    PROM = (float) SUM/MAXNOTA ;
    return PROM ;      
}
 
 
void ORD_PROM ( struct ALUMNO V[] , int N ) //ORDENA LA LISTA POR EL PROMEDIO DE FORMA DECRECIENTE
{
    int I,J ;
    struct ALUMNO AUX ;
    printf ("\nLISTA ORDENADA POR PROMEDIO:") ;
    for ( I = 0 ; I < N-1 ; I++ )
        for ( J = 0 ; J < N-I-1 ; J++ )
            if ( PROMEDIO(V[J]) < PROMEDIO(V[J+1]) ) {
                AUX    = V[J] ;
                V[J]   = V[J+1] ;
                V[J+1] = AUX ;
            }
}
 
void COD_COMPETENCIA ( struct ALUMNO V[] , int N ) //INGRESA UNA MATERIA Y RETORNA LOS ALUMNOS CON MAYOR
                                                  //NOTA EN ESA MATERIA
{
    char MATERIA [][20] = {"FISICA","QUIMICA","LOGICA","GEOMETRIA","MATEMATICA","ESTADISTICA"} ;
    char INGRESO [20] ;
    int I,COD, FLAG ;
   
    printf ("\n\nINGRESE MATERIA: ") ;
    fflush (stdin) ;
    gets (INGRESO) ;
   
   
    //PONER UN WHILE
    for ( I=0 ; I<MAXNOTA ; I++ ) {
        if ( strcmp(MATERIA[I],INGRESO)==0 )
            COD = I ;
            FLAG = 1 ;
    }
    if ( FLAG == 0 ){
   
        printf ("\n\nLA MATERIA INGRESADA NO EXISTE") ;
       
   
}
   
    int  MAX_POS_F=0, MAX_POS_M=0,MAYORM=0,MAYORF=0 ;
   
    for ( I=0 ; I<N ; I++ ) {
        if ( V[I].SEX=='F' && V[I].NOTA[COD] > V[MAYORF].NOTA[COD] ) {
            MAYORF= I;//V[I].NOTA[COD];
        /*  MAX_POS_F = I ;*/}
        //SI EL ALUMNO ES MUJER Y TIENE UNA MAYOR NOTA EN MATERIA[COD] (CODIGO QUE LE CORRESPONDE A LA
        //MATERIA) TIENE QUE SER MATIAS Y ANA!!!!
        else {
            if ( V[I].SEX=='F' && V[I].NOTA[COD] >= V[MAYORF].NOTA[COD] )
                if ( PROMEDIO(V[I]) > PROMEDIO(V[I+1]))
                    MAYORF = I ;
            //SI SUS NOTAS SON IGUALES, SE DECIDE POR EL MEJOR PROMEDIO
            }
    }
    for ( I=0 ; I<N ; I++) {
        if ( V[I].SEX=='M' && V[I].NOTA[COD] > V[MAYORM].NOTA[COD] ){
            MAYORM=I;//V[I].NOTA[COD];
            /*MAX_POS_M = I ;*/}
        else {
            if ( V[I].SEX=='M' && V[I].NOTA[COD] >= V[MAYORM].NOTA[COD] )
                if ( PROMEDIO(V[I]) > PROMEDIO(V[I+1]))
                    MAYORM=I;
                    /*MAX_POS_M = I */;
        //LO MISMO PARA LOS VARONES
        }
    }
    printf ("\n\n\nLA PAREJA MAS CALIFICADA PARA PARTICIPAR EN LA COMPETICION DE %s\nES: %s Y %s\n\n",
            MATERIA[COD], V[MAYORF].NOM, V[MAYORM].NOM) ;
//  printf ("\n\n\nLA PAREJA MAS CALIFICADA PARA PARTICIPAR EN LA COMPETICION DE %s\nES: %s Y %s\n\n",
    //      MATERIA[COD], V[MAX_POS_F].NOM, V[MAX_POS_M].NOM) ;
    //ERROR!! NO IMPRIME LO QUE PIDE
    getch() ;
}
