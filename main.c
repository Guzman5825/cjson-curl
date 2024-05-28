#include <stdio.h>
#include <stdlib.h>
#include "curlResumido.h"
#include "pregunta.h"
// Función que maneja la respuesta de la solicitud HTTP

int main()
{
    CURL *cURL;
    cargarCURL(&cURL,"https://6638e0d14253a866a24f8585.mockapi.io/recursos/preguntas");
    pedirYProcesarInformacionCurl(&cURL,NULL,0,pasearDatosCJSONaTPREGUNTA);
    liberarCurl(&cURL);
    return 0;
}
/**
tPregunta
pregunta
opcion_1
opcion_2
opcion_3
opcion_4
opcion_correcta: A-D
dificultad:

*/
