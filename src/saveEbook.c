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
}
