#include <stdio.h>
#define NUMERO_ESTUDIANTES 5
#define NUMERO_ASIGNATURAS 3
int main() {
    float calificaciones[NUMERO_ESTUDIANTES][NUMERO_ASIGNATURAS];
    float promedioEstudiantes[NUMERO_ESTUDIANTES];
    float promedioAsignaturas[NUMERO_ASIGNATURAS];
    float maxEstudiantes[NUMERO_ESTUDIANTES];
    float minEstudiantes[NUMERO_ESTUDIANTES];
    float maxAsignaturas[NUMERO_ASIGNATURAS];
    float minAsignaturas[NUMERO_ASIGNATURAS];
    int aprobados[NUMERO_ASIGNATURAS];
    int reprobados[NUMERO_ASIGNATURAS];
    int i, j;
    float suma, calificacion;
    int valido;
    printf("SISTEMA GESTIONADOR DE CALIFICACIONES ESCOLARES\n"); 
    printf("Ingrese las calificaciones (El rango es de 0-10):\n\n");
    for (i = 0; i < NUMERO_ESTUDIANTES; i++) {
        printf("ESTUDIANTE %d\n", i + 1);
        for (j = 0; j < NUMERO_ASIGNATURAS; j++) {
            valido = 0;
            while (!valido) {
                printf("Asignatura %d: ", j + 1);
                scanf("%f", &calificacion);
                if (calificacion >= 0 && calificacion <= 10) {
                    calificaciones[i][j] = calificacion;
                    valido = 1;
                } else {
                    printf("Error: La calificacion debe estar entre 0 y 10. Ingrese otro valor.\n");
                }
            }
        }
        printf("\n");
    }
    for (i = 0; i < NUMERO_ESTUDIANTES; i++) {
        suma = 0;
        for (j = 0; j < NUMERO_ASIGNATURAS; j++) {
            suma += calificaciones[i][j];
        }
        promedioEstudiantes[i] = suma / NUMERO_ASIGNATURAS;
    }
    for (j = 0; j < NUMERO_ASIGNATURAS; j++) {
        suma = 0;
        for (i = 0; i < NUMERO_ESTUDIANTES; i++) {
            suma += calificaciones[i][j];
        }
        promedioAsignaturas[j] = suma / NUMERO_ESTUDIANTES;
    }
    for (i = 0; i < NUMERO_ESTUDIANTES; i++) {
        maxEstudiantes[i] = calificaciones[i][0];
        minEstudiantes[i] = calificaciones[i][0];
        
        for (j = 1; j < NUMERO_ASIGNATURAS; j++) {
            if (calificaciones[i][j] > maxEstudiantes[i]) {
                maxEstudiantes[i] = calificaciones[i][j];
            }
            if (calificaciones[i][j] < minEstudiantes[i]) {
                minEstudiantes[i] = calificaciones[i][j];
            }
        }
    }
    for (j = 0; j < NUMERO_ASIGNATURAS; j++) {
        maxAsignaturas[j] = calificaciones[0][j];
        minAsignaturas[j] = calificaciones[0][j];
        for (i = 1; i < NUMERO_ESTUDIANTES; i++) {
            if (calificaciones[i][j] > maxAsignaturas[j]) {
                maxAsignaturas[j] = calificaciones[i][j];
            }
            if (calificaciones[i][j] < minAsignaturas[j]) {
                minAsignaturas[j] = calificaciones[i][j];
            }
        }
    }
    for (j = 0; j < NUMERO_ASIGNATURAS; j++) {
        aprobados[j] = 0;
        reprobados[j] = 0;
        for (i = 0; i < NUMERO_ESTUDIANTES; i++) {
            if (calificaciones[i][j] >= 6.0) {
                aprobados[j]++;
            } else {
                reprobados[j]++;
            }
        }
    }
    printf("Resultados\n");
    printf("Calificaciones\n");
    printf("Estudiante");
    for (j = 0; j < NUMERO_ASIGNATURAS; j++) {
        printf("\tAsignatura%d", j + 1);
    }
    printf("\n");
    for (i = 0; i < NUMERO_ESTUDIANTES; i++) {
        printf("Estudiante %d\t\t", i + 1);
        for (j = 0; j < NUMERO_ASIGNATURAS; j++) {
            printf("%.2f\t", calificaciones[i][j]);
        }
        printf("\n");
    }
    printf("\nPROMEDIO POR ESTUDIANTE\n");
    for (i = 0; i < NUMERO_ESTUDIANTES; i++) {
        printf("Estudiante %d: %.2f\n", i + 1, promedioEstudiantes[i]);
    }
    printf("\nMinimos y Maximos\n");
    for (i = 0; i < NUMERO_ESTUDIANTES; i++) {
        printf("Estudiante %d - Maxima: %.2f | Minima: %.2f\n", i + 1, maxEstudiantes[i], minEstudiantes[i]);
    }
    printf("\nPromedio por asignatura\n");
    for (j = 0; j < NUMERO_ASIGNATURAS; j++) {
        printf("Asignatura %d: %.2f\n", j + 1, promedioAsignaturas[j]);
    }
    printf("\nMinimos y maximos\n");
    for (j = 0; j < NUMERO_ASIGNATURAS; j++) {
        printf("Asignatura %d - Maxima: %.2f | Minima: %.2f\n", j + 1, maxAsignaturas[j], minAsignaturas[j]);
    }
    printf("\nAprobados y Reprobados\n");
    for (j = 0; j < NUMERO_ASIGNATURAS; j++) {
        printf("Asignatura %d - Aprobados: %d | Reprobados: %d\n", j + 1, aprobados[j], reprobados[j]);
    }
    return 0;
}