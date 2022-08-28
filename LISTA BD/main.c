#include "funciones.h"

int main()
{
    int size, opcion, contador_agenda = 0;
    contacto contact[TAM];
    constructor_agenda(contact);
    do
    {
        opcion = funcion_imprimir_menu();

        switch (opcion)
        {

        case 1:
            system("cls");
            // agregar contacto
            if (contador_agenda < TAM)
            {
                funcion_llenar_agenda(contact, contador_agenda);
                contador_agenda++;
            }
            else
            {
                system("cls");
                printf("Agenda llena.\n");
                system("pause");
            }
            break;
        case 2:
            system("cls");
            // eliminar contacto
            funcion_eliminar_contacto(contact);
            contador_agenda--;

            break;

        case 3:
            system("cls");
            // imprimir agenda
            funcion_imprimir_agenda(contact);

            break;
        case 4:
            system("cls");

            break;

        default:
            printf("La opcion elegida no esta en el menu, intentalo de nuevo");
        }

    } while (opcion != 4);

    return 0;
}