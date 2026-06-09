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

