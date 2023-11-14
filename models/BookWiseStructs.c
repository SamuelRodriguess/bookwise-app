struct Livro
{
    char titulo[100];
    char autor[100];
    int anoPublicacao;
    char genero[50];
    int disponivel;
};

struct Biblioteca
{
    char nome[100];
    char endereco[200];
    struct Livro catalogoLivros[1000];
    int totalLivros;
};

struct Cliente
{
    int id;
    char nome[100];
    char endereco[200];
    int numLivrosEmprestados; 
};
