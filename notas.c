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

