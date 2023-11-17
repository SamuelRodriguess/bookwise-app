struct Livro
{
    char titulo[100];
    char autor[100];
    int anoPublicacao;
    char genero[50];
    int disponivel;
    int isbn;
    char quemPegou[100];
    struct Livro *next;
};

typedef struct Livro BookWiseFila;

struct Livro *initialLivro = NULL; // Initialize the head of the linked list

struct Livro *finalLivro = NULL; // Initialize the head of the linked list

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
