#include "curlResumido.h"

size_t WriteCallback(void* contents, size_t tamanyo, size_t nmemb, void *userp)
{
    tDataWriteCallback *info=userp;

    info->cantBytesCargados=tamanyo * nmemb;
    memcpy(info->buffer, contents, info->cantBytesCargados);

    return info->cantBytesCargados;
}

int cargarCURL(CURL** cURL,const char* URLconsultado)
{
    struct curl_slist* headers = NULL;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    *cURL = curl_easy_init();

    if(cURL == NULL)
        return NO_PUDO_CARGAR;

    headers=curl_slist_append(headers,"");  //esto serviria si el url tiene algun codigo o contraseña

    curl_easy_setopt(*cURL, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(*cURL, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(*cURL, CURLOPT_WRITEFUNCTION, WriteCallback);  //le mandamos la funcion y que es lo que va a hacer
    curl_easy_setopt(*cURL, CURLOPT_TIMEOUT, 10L); // Establecer un tiempo de espera de 10 segundos
    curl_easy_setopt(*cURL, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(*cURL, CURLOPT_URL, URLconsultado);    //que url va a consultar

    return TODO_OK;
}


int pedirYProcesarInformacionCurl(CURL** cURL,void *datoDestino,size_t tamDestino,Procesar procesar)     //esto se usa en el medio
{
    CURLcode res;
    tDataWriteCallback data;

    curl_easy_setopt(*cURL, CURLOPT_WRITEDATA, &data);      //donde guardar la informacion del url dado
    res = curl_easy_perform(*cURL);     //esto da el envio

    if (res != CURLE_OK)
    {
        fprintf(stderr, "Error en la solicitud: %s\n", curl_easy_strerror(res));
        return ERROR_SOLICITUD;
    }

    procesar(NULL,0,data.buffer,data.cantBytesCargados);
    printf("%.*s", (int)data.cantBytesCargados, (char *)data.buffer);

    //parsearPregunta(userData.json, preguntas);
    //mezclar(preguntas, cantRounds, mezclarPreguntas);



    return TODO_OK;
}


void liberarCurl(CURL** cURL)
{
    if(*cURL != NULL)
    {
        curl_easy_cleanup(*cURL);
        curl_global_cleanup();
    }
}
