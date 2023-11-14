#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "models/BookWiseStructs.c"
#include "src/getEbook.c"
#include "src/options.c"
#include "src/saveEbook.c"

void carregar()
{
  // Implemente a lógica para carregar aqui
    printf("Carregando...\n");
}

void mostrar()
{
    struct Livro *auxiliaryLivro;

    if (initialLivro == NULL)
    {
        printf("\tERRO: Lista de livros vazia\n");
        return;
    }

    auxiliaryLivro = initialLivro;

    while (auxiliaryLivro != NULL)
    {
        printf("\nTitulo: %s", auxiliaryLivro->titulo);
        printf("\nAutor: %s", auxiliaryLivro->autor);
        printf("\nAno de Publicacao: %d", auxiliaryLivro->anoPublicacao);
        printf("\nGenero: %s", auxiliaryLivro->genero);
        printf("\nDisponivel: %d", auxiliaryLivro->disponivel);
        printf("\nISBN: %d", auxiliaryLivro->isbn);

        auxiliaryLivro = auxiliaryLivro->next;
    }
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
