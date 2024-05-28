#include "miCJSON.h"

void crearCJSON(tCJSON* c,const char* buffer,unsigned tam){
    c->buffer=buffer;
    c->tam=tam;
    c->itemAct=buffer;
}
int irPrimerItem(tCJSON* c){
    c->itemAct=c->buffer;
    while(  c->itemAct<=(c->buffer+c->tam) && *(c->itemAct)!='{' )
        (c->itemAct)++;
    return TODO_OK;
}

int irSiguienteItem(tCJSON* c){
    if( c->itemAct>(c->buffer+c->tam) )
        return NO_HAY_MAS_ITEMS;
    c->itemAct++;
    while(  c->itemAct<=(c->buffer+c->tam) && *(c->itemAct)!='{' )
        (c->itemAct)++;
    return TODO_OK;
}

int esFinCSJON(const tCJSON* c){
    if( c->itemAct>(c->buffer+c->tam) )
        return SI;
    return NO;
}

const char* buscarValorPosPorClave(const char* cad,const char *nombreClave){
    const char *nombreClaveRel;
    while(*cad!='}'){
        while(*cad!='}' && *cad!='"')
            cad++;
        cad++;  //por no me interesa que apunte a la doble comilla, sino al contenido
        nombreClaveRel=nombreClave;
        while(*cad==*nombreClaveRel){
            cad++;
            nombreClaveRel++;
        }
        if(*cad=='"'){
            return cad+2;
        }

        while(*cad!='}' && *cad!=',')
            cad++;
    }

    return NULL;

}

int obtenerDatoItemActual(tCJSON* c,const char *nombreClave,int tipoClave,void *valorDestino){
const char *posValor;
posValor=buscarValorPosPorClave(c->itemAct,nombreClave);
if(posValor==NULL)
    return NO_ENCONTRADO;
if(tipoClave==TIPO_STRING)
    sscanf(posValor, "\"%[^\"]",(char*)valorDestino);
if(tipoClave==TIPO_INT)
    sscanf(posValor, "%d\"",(int*)valorDestino);
return TODO_OK;
}
