#include <stdio.h>
#include <stdlib.h>

#define MAX_ASIGNATURAS 3

// 1. Estructuras anidadas 
typedef struct {
    float notas[MAX_ASIGNATURAS];
} RegistroAcademico;

typedef struct {
    int id;
    RegistroAcademico academico;
} Estudiante;

// 2. Prototipos de funciones que reciben punteros a la estructura
void cargarNotas(Estudiante *estudiantes, int total_estudiantes);
void promediosPorEstudiante(Estudiante *estudiantes, int total_estudiantes);
void promediosPorAsignatura(Estudiante *estudiantes, int total_estudiantes);
void altaBajaPorEstudiante(Estudiante *estudiantes, int total_estudiantes);
void altaBajaPorAsignatura(Estudiante *estudiantes, int total_estudiantes);
void estadisticasAprobacion(Estudiante *estudiantes, int total_estudiantes);

int main() {
    int total_estudiantes;
    
    printf("SISTEMA DE GESTION DE CALIFICACIONES\n");
    printf("Cantidad de estudiantes a registrar: ");
    scanf("%d", &total_estudiantes);

    // Creamos el arreglo de estructuras
    Estudiante listaEstudiantes[total_estudiantes];

    // Pasamos el arreglo (que decae en puntero) a las funciones
    cargarNotas(listaEstudiantes, total_estudiantes);
    promediosPorEstudiante(listaEstudiantes, total_estudiantes);
    promediosPorAsignatura(listaEstudiantes, total_estudiantes);
    altaBajaPorEstudiante(listaEstudiantes, total_estudiantes);
    altaBajaPorAsignatura(listaEstudiantes, total_estudiantes);
    estadisticasAprobacion(listaEstudiantes, total_estudiantes);

    return 0;
}

// 3. Implementación de funciones usando acceso por punteros ( -> )
void cargarNotas(Estudiante *estudiantes, int total_estudiantes) {
    for (int i = 0; i < total_estudiantes; i++) {
        (estudiantes + i)->id = i + 1;
        printf("\nNotas del Estudiante %d\n", (estudiantes + i)->id);
        
        for (int j = 0; j < MAX_ASIGNATURAS; j++) {
            float nota_ingresada;
            do {
                printf("Asignatura %d (0-10): ", j + 1);
                scanf("%f", &nota_ingresada);
                if (nota_ingresada < 0 || nota_ingresada > 10) {
                    printf("Error: La nota debe estar entre 0 y 10. Intenta otra vez.\n");
                }
            } while (nota_ingresada < 0 || nota_ingresada > 10);
            
            // Guardar usando el puntero a la estructura anidada
            (estudiantes + i)->academico.notas[j] = nota_ingresada;
        }
    }
    void promediosPorEstudiante(Estudiante *estudiantes, int total_estudiantes) {
    printf("\nPROMEDIO POR ESTUDIANTE\n");
    for (int i = 0; i < total_estudiantes; i++) {
        float suma = 0;
        for (int j = 0; j < MAX_ASIGNATURAS; j++) {
            suma += (estudiantes + i)->academico.notas[j];
        }
        printf("Estudiante %d: %.2f\n", (estudiantes + i)->id, suma / MAX_ASIGNATURAS);
    }
}

void promediosPorAsignatura(Estudiante *estudiantes, int total_estudiantes) {
    printf("\nPROMEDIO POR ASIGNATURA\n");
    for (int j = 0; j < MAX_ASIGNATURAS; j++) {
        float suma = 0;
        for (int i = 0; i < total_estudiantes; i++) {
            suma += (estudiantes + i)->academico.notas[j];
        }
        printf("Asignatura %d: %.2f\n", j + 1, suma / total_estudiantes);
    }
}

void altaBajaPorEstudiante(Estudiante *estudiantes, int total_estudiantes) {
    printf("\nNOTA ALTA Y BAJA POR ESTUDIANTE\n");
    for (int i = 0; i < total_estudiantes; i++) {
        float alta = (estudiantes + i)->academico.notas[0];
        float baja = (estudiantes + i)->academico.notas[0];
        
        for (int j = 1; j < MAX_ASIGNATURAS; j++) {
            float actual = (estudiantes + i)->academico.notas[j];
            if (actual > alta) alta = actual;
            if (actual < baja) baja = actual;
        }
        printf("Estudiante %d -> Nota Mas Alta: %.2f | Nota Mas Baja: %.2f\n", (estudiantes + i)->id, alta, baja);
    }
}

void altaBajaPorAsignatura(Estudiante *estudiantes, int total_estudiantes) {
    printf("\nNOTA ALTA Y BAJA POR ASIGNATURA\n");
    for (int j = 0; j < MAX_ASIGNATURAS; j++) {
        float alta = (estudiantes + 0)->academico.notas[j];
        float baja = (estudiantes + 0)->academico.notas[j];
        
        for (int i = 1; i < total_estudiantes; i++) {
            float actual = (estudiantes + i)->academico.notas[j];
            if (actual > alta) alta = actual;
            if (actual < baja) baja = actual;
        }
        printf("Asignatura %d -> Nota Mas Alta: %.2f | Nota Mas Baja: %.2f\n", j + 1, alta, baja);
    }
}