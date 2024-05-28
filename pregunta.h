#ifndef PREGUNTA_H_INCLUDED
#define PREGUNTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "miCJSON.h"

#define TODO_OK 1
#define MAX_PREGUNTA 256
#define MAX_RESPUESTA 128
#define CANT_RESPUESTA 4

typedef struct{
    char enunciado[MAX_PREGUNTA];
    char respuesta[CANT_RESPUESTA][MAX_RESPUESTA];
    char opcionCorrecta;
}tPregunta;

void mostrarPregunta(const void* dato);

int pasearDatosCJSONaTPREGUNTA(void* datoDestino,size_t tamDestino,const void* datoOrigen,size_t tamOrigen);

#endif // PREGUNTA_H_INCLUDED
