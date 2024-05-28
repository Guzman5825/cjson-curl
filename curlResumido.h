#ifndef CURLRESUMIDO_H_INCLUDED
#define CURLRESUMIDO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

#define NO_PUDO_CARGAR -1
#define TODO_OK 1
#define ERROR_SOLICITUD 500

#define TAM_BUFFER_JSON 100000

typedef struct
{
    char buffer[TAM_BUFFER_JSON];
    size_t cantBytesCargados;
}tDataWriteCallback;

typedef int (*Procesar)(void* datoDestino,size_t tamDatoDestino,const void* dataCallBack,size_t tamCallBack);

int cargarCURL(CURL** cURL,const char* URLconsultado);
int pedirYProcesarInformacionCurl(CURL** curl,void *datoDestino,size_t tamDestino,Procesar procesar);
void liberarCurl(CURL** cURL);

#endif // CURLRESUMIDO_H_INCLUDED
