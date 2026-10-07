/**********************************************************/
/*           Programación para mecatrónicos               */
/*  Nombre:    Eddie Bryan Burgos Furgencio               */
/*  Matricula: 2019-8108                                  */
/*  Seccion:   miercoles                                  */
/*  Practica:  Examnen 1                                  */
/*  Fecha:     07/10/2026                                 */                       
/**********************************************************/




/* Reto 02 - Produccion: ventanas de operacion aceptable
 

#include <stdio.h>                       /* Libreria para scanf y printf */

int main(void)                           /* Funcion principal del programa */
{
    int N, M, L, U;                      /* Filas, columnas, limite inferior y superior */
    int mat[30][30];                     /* Matriz de produccion (maximo 30 x 30) */
    int evF[30];                         /* Cantidad de eventos por fila */
    int impF[30];                        /* Suma de impactos por fila */
    int rachaF[30];                      /* Longitud de la mayor racha por fila */
    int inicioF[30];                     /* Inicio (1-based) de la mayor racha por fila */
    int evC[30];                         /* Cantidad de eventos por columna */
    int i, j;                            /* Indices de fila y columna (empiezan en 0) */
    int actual, inicioActual;            /* Racha en curso: longitud e inicio */
    int totalEventos = 0;                /* Total de eventos de toda la matriz */
    int mejorFila, mejorCol;             /* Indices de fila prioritaria y columna destacada */

    if (scanf("%d %d %d %d", &N, &M, &L, &U) != 4) {   /* Lee N M L U; si falla la lectura... */
        printf("ERROR\n");               /* ...imprime solo ERROR */
        return 0                       /* ...y termina */
    }
    if (N < 1 || N > 30 || M < 1 || M > 30) {          /* Valida dimensiones antes de leer la matriz */
        printf("ERROR\n");               /* Dimension invalida: solo ERROR */
        return 0                        /* Termina el programa */
    }
    if (L < 0 || U > 1000 || L > U) {    /* Valida limites: 0 <= L <= U <= 1000 */
        printf("ERROR\n");               /* Limites invalidos: solo ERROR */
        return 0;                        /* Termina el programa */
    }

    for (i = 0; i < N; i++) {            /* Recorre las filas para leer la matriz */
        for (j = 0; j < M; j++) {        /* Recorre las columnas de la fila actual */
            if (scanf("%d", &mat[i][j]) != 1) {        /* Lee un valor; si falla la lectura... */
                printf("ERROR\")      /* ...imprime solo ERROR */
                return 0;                /* ...y termina */
            }
            if (mat[i][j] < 0 || mat[i][j] > 1000) {   /* Valida 0 <= valor <= 1000 */
                printf("ERROR\n");       /* Valor invalido: solo ERROR (nada se ha impreso antes) */
                return 0              /* Termina el programa */
          

    return 0;                            /* Fin correcto del programa */
}
