#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Estrutura para armazenar os dados da resposta HTTP
struct MemoryStruct {
    char *memory;
    size_t size;
};

// Função de callback chamada pelo libcurl para escrever dados recebidos na resposta HTTP
static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *)userp;

    mem->memory = realloc(mem->memory, mem->size + realsize + 1);
    if (mem->memory == NULL) {
        // Se a alocação de memória falhar, retorne 0 para indicar um erro ao libcurl
        return 0;
    }

    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    return realsize;
}

// Função para obter informações sobre um livro usando a API do Google Books
void obter_informacoes_livro(const char *isbn) {
    CURL *curl;
    CURLcode res;

    // Inicializa o libcurl
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    
    if (curl) {
        // URL base da API do Google Books
        char url[256];
        snprintf(url, sizeof(url), "https://www.googleapis.com/books/v1/volumes?q=isbn:%s", isbn);

        // Estrutura para armazenar a resposta HTTP
        struct MemoryStruct chunk;
        chunk.memory = malloc(1);
        chunk.size = 0;

        // Configuração da solicitação HTTP
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

        // Executa a solicitação HTTP
        res = curl_easy_perform(curl);

        // Verifica se a solicitação foi bem-sucedida (CURLE_OK = 0)
        if (res == CURLE_OK) {
            printf("Resposta da API:\n%s\n", chunk.memory);
        } else {
            fprintf(stderr, "Erro ao fazer a solicitação HTTP: %s\n", curl_easy_strerror(res));
        }

        // Libera a memória alocada
        free(chunk.memory);

        // Finaliza o libcurl
        curl_easy_cleanup(curl);
    }

    // Finaliza o libcurl globalmente
    curl_global_cleanup();
}

