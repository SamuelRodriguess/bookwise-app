void cadastrar()
{
    int i, quantity;

    printf("Cadastrando...\n");

    printf("\nDigite a quantidade de livros que deseja cadastrar ex: 2 \n");
    printf("\n:");
    scanf("%d", &quantity);

    for (i = 0; i < quantity; i++)
    {
        struct Livro *newLivro = (struct Livro *)malloc(sizeof(struct Livro));

        if (newLivro == NULL)
        {
            printf("Erro ao alocar memoria para Livro\n");
            return;
        }

        printf("Titulo: ");
        fflush(stdin);
        fgets(newLivro->titulo, sizeof(newLivro->titulo), stdin);

        printf("Autor: ");
        fflush(stdin);
        fgets(newLivro->autor, sizeof(newLivro->autor), stdin);

        printf("Ano de Publicacao: ");
        scanf("%d", &(newLivro->anoPublicacao));

        printf("Genero: ");
        fflush(stdin);
        fgets(newLivro->genero, sizeof(newLivro->genero), stdin);

        printf("Disponivel (1 para Sim, 0 para Nao): ");
        scanf("%d", &(newLivro->disponivel));

        printf("ISBN: ");
        scanf("%d", &(newLivro->isbn));

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

    // Writing to a text file
    FILE *file = fopen("livros.txt", "a"); // 'a' for append mode
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo de texto.\n");
        return;
    }

    struct Livro *temp = initialLivro;
    while (temp != NULL)
    {
        fprintf(file, "Titulo: %sAutor: %sAno de Publicacao: %d\nGenero: %sDisponivel: %d\nISBN: %d\n\n",
                temp->titulo, temp->autor, temp->anoPublicacao, temp->genero, temp->disponivel, temp->isbn);
        temp = temp->next;
    }

    fclose(file);
}