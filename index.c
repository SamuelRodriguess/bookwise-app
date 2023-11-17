#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include "models/BookWiseStructs.c"
#include "src/getEbook.c"
#include "src/options.c"
#include "src/saveEbook.c"
#include "src/fetchBookFile.c"
#include "src/searchBook.c"
#include "src/showBook.c"
#include "src/editBook.c"

int main()
{
    char opt;
    do
    {
        opt = options();
        switch (opt)
        {
        case 'C':
            system("clear");
            cadastrar();
            break;
        case 'M':
            system("clear");
            mostrar();
            break;
        case 'A':
            system("clear");
            printf("Digite o critério de busca (Título ou ISBN): ");
            char criterio[100];
            scanf("%s", criterio);
            buscarLivro(criterio);
            break;
        case 'E':
            system("clear");
            printf("Digite o critério de busca (Título ou ISBN): ");
            char criterioEditar[100];
            scanf("%s", criterioEditar);
            editarLivro(criterioEditar);
            break;
        case 'T':
            exit(0);
        default:
            printf("Comando inválido\n");
        }
    } while (opt != 'T');

    return 0;
}
