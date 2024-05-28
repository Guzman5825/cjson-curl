#ifndef MICJSON_H_INCLUDED
#define MICJSON_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define TODO_OK 1
#define SI 1
#define NO 0
#define NO_HAY_MAS_ITEMS 0
#define NO_ENCONTRADO 0
#define TIPO_INT 1
#define TIPO_CHAR 2
#define TIPO_STRING 3


typedef struct{
    const char* buffer;
    unsigned tam;
    const char* itemAct;
}tCJSON;

void crearCJSON(tCJSON* c,const char* buffer,unsigned tam);
int irPrimerItem(tCJSON* c);
int irSiguienteItem(tCJSON* c);
int obtenerDatoItemActual(tCJSON* c,const char *nombreClave,int tipoClave,void *valorDestino);
int esFinCSJON(const tCJSON* c);
//finDeItem()


#endif // MICJSON_H_INCLUDED
