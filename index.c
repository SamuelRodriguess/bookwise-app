#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "models/BookWiseStructs.c"
#include "src/getEbook.c"

char options()
{
    char opcao;
    printf("\n\n\n");
    printf(" (C)adastrar.\n");
    printf(" (M)ostrar.\n");
    printf(" C(A)arregar.\n");
    printf(" (S)alvar.\n");
    printf(" (D)escrição do livro.\n");
    printf(" (T)erminar.\n");
    fflush(stdin);
    scanf(" %c", &opcao);
    return opcao;
}

void cadastrar()
{
    // Implemente a lógica para cadastrar aqui
    printf("Cadastrando...\n");
}

void mostrar()
{
    // Implemente a lógica para mostrar aqui
    printf("Mostrando...\n");
}

void carregar()
{
    // Implemente a lógica para carregar aqui
    printf("Carregando...\n");
}

void salvar()
{
    // Implemente a lógica para salvar aqui
    printf("Salvando...\n");
}

void descricao()
{
    // Implemente a lógica para a descrição do livro aqui
    printf("Descrição do livro...\n");

    const char *isbn_exemplo = "9780553382563"; // ISBN do livro "The Hitchhiker's Guide to the Galaxy"
    obter_informacoes_livro(isbn_exemplo);
}

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
            carregar();
            break;
        case 'S':
            system("clear");
            salvar();
            break;
        case 'D':
            system("clear");
            descricao();
            break;
        case 'T':
            exit(0);
        default:
            printf("Comando inválido\n");
        }
    } while (opt != 'T');

    return 0;
}
