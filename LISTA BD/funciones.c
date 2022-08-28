#include "funciones.h"

void constructor_agenda(contacto contact[])
{
    for (int i = 0; i < TAM; i++)
    {
        contact[i].nombres[50] = contact[i].paterno[50] = contact[i].materno[50] = contact[i].correo[100] = contact[i].direction[100] = "NULL";

        contact[i].edad = contact[i].telefono = 0;
    }
}

int funcion_imprimir_menu()
{
    int n;
    printf("\n|---------------------------------------|");
    printf("\n|            ° AGENDA VIRTUAL  °      |");
    printf("\n|--------------------|------------------|");
    printf("\n| 1. AGREGAR CONTACTO| 3.IMPRIMIR AGENDA|");
    printf("\n| 2. ELMINAR CONTACTO| 4. SALIR         |");
    printf("\n|--------------------|------------------|\n");
    printf("NOTA: Tu agenda virtual solo soporta 100 contactos\n");
    puts("\nSelecciona una opcion:");
    printf("-> ");
    scanf("%d", &n);
    return n;
}

void funcion_llenar_agenda(contacto contact[], int cont)
{
    for (int i = 0; i < TAM; i++)
    {
        if (contact[i].edad == 0)
        {
            fflush(stdin);
            printf("Escribe tu nombre en mayusculas: ");
            gets(contact[cont].nombres);

            printf("Escribe tu apellido paterno en mayusculas: ");
            gets(contact[cont].paterno);

            printf("Escribe tu apellido materno en mayusculas: ");
            gets(contact[cont].materno);

            fflush(stdin);
            printf("Digita tu edad: ");
            scanf("%d", &contact[cont].edad);

            fflush(stdin);
            printf("Escribe tu direccion en mayusculas: ");
            gets(contact[cont].direction);

            fflush(stdin);
            printf("Escribe tu correo electronico: ");
            gets(contact[cont].correo);

            fflush(stdin);
            printf("Digita tu numero de telefono: ");
            scanf("%ld", &contact[cont].telefono);

            fflush(stdin);
            // Pasamos a mayuscula
            for (int i = 0; contact[cont].nombres[i] != '\0'; ++i)
            {
                // Nombres
                contact[cont].nombres[i] = toupper(contact[cont].nombres[i]);
            }

            for (int i = 0; contact[cont].paterno[i] != '\0'; ++i)
            {
                // paterno
                contact[cont].paterno[i] = toupper(contact[cont].paterno[i]);
            }

            for (int i = 0; contact[cont].materno[i] != '\0'; ++i)
            {
                // materno
                contact[cont].materno[i] = toupper(contact[cont].materno[i]);
            }

            for (int i = 0; contact[cont].direction[i] != '\0'; ++i)
            {
                // direction
                contact[cont].direction[i] = toupper(contact[cont].direction[i]);
            }

            break;
        }
    }
}

void funcion_eliminar_contacto(contacto contact[])
{
    char nombres[100];
    fflush(stdin);
    printf("Escribe el o los nombres de la persona a eliminar: ");
    gets(nombres);
    // Pasamos a mayuscula
    for (int i = 0; nombres[i] != '\0'; ++i)
    {
        // Nombres
        nombres[i] = toupper(nombres[i]);
    }

    for (int i = 0; i < TAM; i++)
    {
        if (strcmp(contact[i].nombres, nombres) == 0)
        {
            // cadena a eliminar, dato a cambiar, tamanio
            memset(contact[i].nombres, 'N', sizeof(contact[i].nombres) / sizeof(contact[i].nombres[0]));
            memset(contact[i].paterno, 'N', sizeof(contact[i].paterno) / sizeof(contact[i].paterno[0]));
            memset(contact[i].materno, 'N', sizeof(contact[i].materno) / sizeof(contact[i].materno[0]));
            memset(contact[i].direction, 'N', sizeof(contact[i].direction) / sizeof(contact[i].direction[0]));
            memset(contact[i].correo, 'N', sizeof(contact[i].correo) / sizeof(contact[i].correo[0]));
            contact[i].edad = contact[i].telefono = 0;
        }
        else if (i == TAM)
        {
            printf("El numero digitado no se encuentra en la lista.\n");
        }
    }
}

void funcion_imprimir_agenda(contacto contact[])
{
    for (int i = 0; i < TAM; i++)
    {
        if (contact[i].telefono != 0 && contact[i].edad != 0)
        {
            printf("NOMBRE: ");
            puts(contact[i].nombres);
            printf("\n");

            printf("APELLIDO PATERNO: ");
            puts(contact[i].paterno);
            printf("\n");

            printf("APELLIDO MATERNO: ");
            puts(contact[i].materno);
            printf("\n");

            printf("EDAD: ");
            printf("%d", contact[i].edad);
            printf("\n");

            printf("DIRECCION: ");
            puts(contact[i].direction);
            printf("\n");

            printf("CORREO ELECTRONICO: ");
            puts(contact[i].correo);
            printf("\n");

            printf("TELEFONO: ");
            printf("%d", contact[i].telefono);
            printf("\n\n");
        }
    }
}
