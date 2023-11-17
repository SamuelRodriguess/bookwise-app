bool buscarLivro(const char *criterio)
{
    FILE *file = fopen("livros.txt", "r");

    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo de texto.\n");
        return false;
    }

    struct Livro livro;
    bool encontrado = false;

    while (fscanf(file, "Titulo: %[^\n]\n", livro.titulo) != EOF)
    {
        fscanf(file, "Autor: %[^\n]\n", livro.autor);
        fscanf(file, "Ano de Publicacao: %d\n", &(livro.anoPublicacao));
        fscanf(file, "Genero: %[^\n]\n", livro.genero);
        fscanf(file, "Disponivel: %d\n", &(livro.disponivel));
        fscanf(file, "Quem Pegou: %[^\n]\n", livro.quemPegou);
        fscanf(file, "ISBN: %d\n\n", &(livro.isbn));

        // Verificar se o critério de busca corresponde ao título ou ISBN
        if (strstr(livro.titulo, criterio) != NULL || livro.isbn == atoi(criterio))
        {
            printf("\nLivro encontrado:\n");
            printf("Titulo: %s\nAutor: %s\nAno de Publicacao: %d\nGenero: %s\nDisponivel: %d\nQuem Pegou: %s\nISBN: %d\n\n",
                   livro.titulo, livro.autor, livro.anoPublicacao, livro.genero, livro.disponivel, livro.quemPegou, livro.isbn);

            encontrado = true;
        }
    }

    fclose(file);

    if (!encontrado)
    {
        printf("\nLivro nao encontrado.\n");
    }

    return encontrado;
}
