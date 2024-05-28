#include "pregunta.h"

void mostrarPregunta(const void* dato){

    const tPregunta* p=dato;
    printf("pregunta: %s\n",p->enunciado);
    printf("A:%s\n",p->respuesta[0]);
    printf("B:%s\n",p->respuesta[1]);
    printf("C:%s\n",p->respuesta[2]);
    printf("D:%s\n",p->respuesta[3]);
    printf("opcion correcta:%c\n",p->opcionCorrecta);
}

int pasearDatosCJSONaTPREGUNTA(void* datoDestino,size_t tamDestino,const void* datoOrigen,size_t tamOrigen){
    tCJSON cjson;
    tPregunta p;

    crearCJSON(&cjson,datoOrigen,tamOrigen);
    irPrimerItem(&cjson);
    int nivel;
    while(!esFinCSJON(&cjson)){
        obtenerDatoItemActual(&cjson,"nivel",TIPO_INT,&nivel);
        obtenerDatoItemActual(&cjson,"pregunta",TIPO_STRING,&(p.enunciado) );
        obtenerDatoItemActual(&cjson,"resp_correcta",TIPO_STRING,&p.respuesta[0]);
        obtenerDatoItemActual(&cjson,"opcion_1",TIPO_STRING,&p.respuesta[1]);
        obtenerDatoItemActual(&cjson,"opcion_2",TIPO_STRING,&p.respuesta[2]);
        obtenerDatoItemActual(&cjson,"opcion_3",TIPO_STRING,&p.respuesta[3]);
        p.opcionCorrecta='A';
        mostrarPregunta(&p);
        printf("nivel de pregunta: %d\n",nivel);
        irSiguienteItem(&cjson);
    }

    //obtenerDatoItemActual(cjson,nombreClave,tipoClave,valorDestino)
    return TODO_OK;
}
