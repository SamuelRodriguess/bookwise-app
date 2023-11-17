void carregarDoArquivo()
{
    FILE *arquivo = fopen("livros.txt", "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo de texto.\n");
        return;
    }

    while (1)
    {
        struct Livro *newLivro = (struct Livro *)malloc(sizeof(struct Livro));

        if (newLivro == NULL)
        {
            printf("Erro ao alocar memoria para Livro\n");
            fclose(arquivo);
            return;
        }

        if (fscanf(arquivo, "Titulo: %[^\n]\n", newLivro->titulo) != 1)
            break;

        fscanf(arquivo, "Autor: %[^\n]\n", newLivro->autor);
        fscanf(arquivo, "Ano de Publicacao: %d\n", &(newLivro->anoPublicacao));
        fscanf(arquivo, "Genero: %[^\n]\n", newLivro->genero);
        fscanf(arquivo, "Disponivel: %d\n", &(newLivro->disponivel));
        fscanf(arquivo, "ISBN: %d\n\n", &(newLivro->isbn));

        newLivro->next = NULL;

        if (initialLivro == NULL)
        {
            initialLivro = newLivro;
        }
        else
        {
            struct Livro *temp = initialLivro;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newLivro;
        }
    }

    fclose(arquivo);
}
