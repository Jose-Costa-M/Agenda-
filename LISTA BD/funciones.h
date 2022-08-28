#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // para pasar a mayusculas
#define TAM 100

typedef struct contacto
{

    char nombres[50], paterno[50], materno[50], direction[100], correo[100];
    int edad;
    long int telefono;

} contacto;

int funcion_imprimir_menu();

void constructor_agenda(contacto contact[]);
void funcion_llenar_agenda(contacto contact[], int cont);
void funcion_eliminar_contacto(contacto contact[]);
void funcion_imprimir_agenda(contacto contact[]);