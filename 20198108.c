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
        return 0;                        /* ...y termina */
    }
    if (N < 1 || N > 30 || M < 1 || M > 30) {          /* Valida dimensiones antes de leer la matriz */
        printf("ERROR\n");               /* Dimension invalida: solo ERROR */
        return 0;                        /* Termina el programa */
    }
    if (L < 0 || U > 1000 || L > U) {    /* Valida limites: 0 <= L <= U <= 1000 */
        printf("ERROR\n");               /* Limites invalidos: solo ERROR */
        return 0;                        /* Termina el programa */
    }

    for (i = 0; i < N; i++) {            /* Recorre las filas para leer la matriz */
        for (j = 0; j < M; j++) {        /* Recorre las columnas de la fila actual */
            if (scanf("%d", &mat[i][j]) != 1) {        /* Lee un valor; si falla la lectura... */
                printf("ERROR\n");       /* ...imprime solo ERROR */
                return 0;                /* ...y termina */
            }
            if (mat[i][j] < 0 || mat[i][j] > 1000) {   /* Valida 0 <= valor <= 1000 */
                printf("ERROR\n");       /* Valor invalido: solo ERROR (nada se ha impreso antes) */
                return 0;                /* Termina el programa */
            }
        }
    }

    for (j = 0; j < M; j++) {            /* Recorre las columnas */
        evC[j] = 0;                      /* Inicia en 0 el conteo de eventos de cada columna */
    }

    for (i = 0; i < N; i++) {            /* Procesa cada fila */
        evF[i] = 0;                      /* Reinicia eventos de la fila */
        impF[i] = 0;                     /* Reinicia impacto de la fila */
        rachaF[i] = 0;                   /* Reinicia la mayor racha de la fila */
        inicioF[i] = 0;                  /* Reinicia el inicio de la mayor racha */
        actual = 0;                      /* Racha en curso vacia */
        inicioActual = 0;                /* Inicio de la racha en curso */
        for (j = 0; j < M; j++) {        /* Recorre las columnas de la fila (horizontal) */
            if (mat[i][j] >= L && mat[i][j] <= U) {    /* Condicion del evento: x >= L && x <= U */
                evF[i]++;                /* Suma un evento a la fila */
                impF[i] += mat[i][j] - L + 1;          /* Suma el impacto x-L+1 */
                evC[j]++;                /* Suma un evento a la columna */
                totalEventos++;          /* Suma un evento al total general */
                if (actual == 0) {       /* Si empieza una racha nueva... */
                    inicioActual = j + 1;              /* ...guarda su inicio (indice desde 1) */
                }
                actual++;                /* Alarga la racha en curso */
                if (actual > rachaF[i]) {              /* Solo si supera estrictamente (gana la primera) */
                    rachaF[i] = actual;  /* Actualiza la longitud maxima */
                    inicioF[i] = inicioActual;         /* Actualiza el inicio de esa racha */
                }
            } else {                     /* Si la posicion no es evento... */
                actual = 0;              /* ...se interrumpe la racha (aporta 0 al impacto) */
            }
        }
    }

    mejorFila = 0;                       /* Si no hay eventos, la fila prioritaria es 0 */
    mejorCol = 0;                        /* Si no hay eventos, la columna destacada es 0 */
    if (totalEventos > 0) {              /* Solo se eligen si hay al menos un evento */
        mejorFila = 1;                   /* Empieza suponiendo la fila 1 (indice 0) */
        for (i = 1; i < N; i++) {        /* Compara con las demas filas en orden */
            if (rachaF[i] > rachaF[mejorFila - 1]) {   /* 1.o: mayor racha */
                mejorFila = i + 1;       /* Esta fila es mejor */
            } else if (rachaF[i] == rachaF[mejorFila - 1]) {   /* Empate en racha */
                if (impF[i] > impF[mejorFila - 1]) {   /* 2.o: mayor impacto total */
                    mejorFila = i + 1;   /* Esta fila es mejor */
                } else if (impF[i] == impF[mejorFila - 1] &&
                           evF[i] > evF[mejorFila - 1]) {  /* 3.o: mayor cantidad de eventos */
                    mejorFila = i + 1;   /* Esta fila es mejor; 4.o menor fila se cumple al recorrer en orden */
                }
            }
        }
        mejorCol = 1;                    /* Empieza suponiendo la columna 1 */
        for (j = 1; j < M; j++) {        /* Compara con las demas columnas */
            if (evC[j] > evC[mejorCol - 1]) {          /* Mas eventos (empate: se queda la menor) */
                mejorCol = j + 1;        /* Esta columna es la destacada */
            }
        }
    }

    for (i = 0; i < N; i++) {            /* Imprime una linea por fila */
        printf("FILA %d EVENTOS %d IMPACTO %d RACHA %d INICIO %d\n",
               i + 1, evF[i], impF[i], rachaF[i], inicioF[i]);   /* Formato exacto pedido */
    }
    printf("COLUMNAS");                  /* Etiqueta del vector de columnas */
    for (j = 0; j < M; j++) {            /* Recorre las columnas */
        printf(" %d", evC[j]);           /* Imprime el conteo de eventos de cada columna */
    }
    printf("\n");                        /* Salto de linea al final del vector */
    printf("PRIORIDAD %d\n", mejorFila); /* Imprime la fila prioritaria */
    printf("COLUMNA %d\n", mejorCol);    /* Imprime la columna destacada */

    return 0;                            /* Fin correcto del programa */
}
