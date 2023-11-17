bool editarLivro(const char *criterio)
{
    FILE *file = fopen("livros.txt", "r+");

    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo de texto.\n");
        return false;
    }

    struct Livro livro;
    long int posicaoInicial = 0;
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

            // Salvar a posição inicial do livro no arquivo
            posicaoInicial = ftell(file) - strlen("ISBN: %d\n\n");

            // Permitir ao usuário editar as informações do livro
            printf("Digite as novas informacoes do livro:\n");
            printf("Novo Titulo: ");
            fflush(stdin);
            fgets(livro.titulo, sizeof(livro.titulo), stdin);
            livro.titulo[strcspn(livro.titulo, "\n")] = '\0';

            printf("Novo Autor: ");
            fflush(stdin);
            fgets(livro.autor, sizeof(livro.autor), stdin);
            livro.autor[strcspn(livro.autor, "\n")] = '\0';

            printf("Novo Ano de Publicacao: ");
            scanf("%d", &(livro.anoPublicacao));

            printf("Novo Genero: ");
            fflush(stdin);
            fgets(livro.genero, sizeof(livro.genero), stdin);
            livro.genero[strcspn(livro.genero, "\n")] = '\0';

            printf("Nova Disponibilidade (1 para Sim, 0 para Nao): ");
            scanf("%d", &(livro.disponivel));

            printf("Nova Quem Pegou: ");
            fflush(stdin);
            fgets(livro.quemPegou, sizeof(livro.quemPegou), stdin);
            livro.quemPegou[strcspn(livro.quemPegou, "\n")] = '\0';

            // Voltar para a posição inicial do livro no arquivo para sobrescrever as informações
            fseek(file, posicaoInicial, SEEK_SET);

            // Sobrescrever as informações do livro no arquivo
            fprintf(file, "Titulo: %s\nAutor: %s\nAno de Publicacao: %d\nGenero: %s\nDisponivel: %d\nQuem Pegou: %s\nISBN: %d\n\n",
                    livro.titulo, livro.autor, livro.anoPublicacao, livro.genero, livro.disponivel, livro.quemPegou, livro.isbn);

            encontrado = true;
            break;  // Encerrar o loop após editar o livro
        }
    }

    fclose(file);

    if (!encontrado)
    {
        printf("\nLivro nao encontrado.\n");
    }
    else
    {
        printf("\nLivro editado com sucesso.\n");
    }

    return encontrado;
}