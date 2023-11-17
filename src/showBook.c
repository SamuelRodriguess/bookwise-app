void mostrar()
{
    struct Livro *auxiliaryLivro;

    // Verifica se a fila está vazia e tenta carregar do arquivo se necessário
    if (initialLivro == NULL)
    {
        printf("\tERRO: Lista de livros vazia\n");
        carregarDoArquivo(); // Carrega do arquivo
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