#include <stdio.h>
#include <locale.h>

#define MAX_FILIAIS 10
#define MAX_LIVROS 100

// Estrutura para representar um livro
typedef struct {
    int codigo;
    int num_paginas;
    float valor_pagina;
    int tipo_encadernacao;
} Livro;

// Estrutura para representar um livro importado
typedef struct {
    int codigo;
    float valor_compra_dolar;
    int regiao_origem;
} LivroImportado;

// Funções
float calcularValorVendaNacional(Livro livro);
float calcularValorVendaImportado(LivroImportado livro_importado, float taxa_dolar);
void lerLivrosNacionais(Livro livros_nacionais[], int *total_livros_nacionais);
void lerLivrosImportados(LivroImportado livros_importados[], int *total_livros_importados, float taxa_dolar);
void calcularEstatisticas(Livro livros_nacionais[], int total_livros_nacionais, LivroImportado livros_importados[], int total_livros_importados, float taxa_dolar);

int main()
{
    float taxa_dolar;
    printf("Informe o valor do dolar: ");
    scanf("%f", &taxa_dolar);

    Livro livros_nacionais[MAX_LIVROS];
    LivroImportado livros_importado[MAX_LIVROS];
    
    int total_livros_nacionais = 0;
    int total_livros_importados = 0;
    int opcao;
    
    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar livros Nacionais\n");
        printf("2. Cadastrar livros importados\n");
        printf("3. Calcular estatísticas\n");
        printf("4. Sair\n");
        printf("Escolhar uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            lerLivrosNacionais(livros_nacionais, &total_livros_nacionais);
            break;
        case 2:
            lerLivrosImportados(livros_importado, &total_livros_importados, taxa_dolar);
            break;
        case 3:
            calcularEstatisticas(livros_nacionais, total_livros_nacionais, livros_importado, total_livros_importados, taxa_dolar);
            break;
        case 4:
            printf("Encerrando o Programa.\n");
            break;
        default:
            printf("Opção inválida. Tente Novamente!");
        }
    } while (opcao != 4);
    {
        return 0;
    }
    
}
//Função para calcular o valor de venda de um livro nacional
float calcularValorVendaNacional(Livro livro) {
        float valor_encadernacao = 0.0;
    // Verificar o tipo de encadernação
    if (livro.tipo_encadernacao == 1) {
        // Tipo 1: valor básico de 18.00 até 10 páginas, 0.1% para páginas acima de 10
        valor_encadernacao = (livro.num_paginas <= 10) ? 18.0 : 18.0 + (0.001 * livro.num_paginas);
    } else if (livro.tipo_encadernacao == 2) {
        // Tipo 2: valor básico de 22.00, 0.3% acrescimo
        valor_encadernacao = 22.0 + (0.003 * livro.num_paginas);
    }

    return livro.num_paginas * livro.valor_pagina + valor_encadernacao;   
}

// Função para calcular o valor de venda de um livro importado

float calcularValorVendaImportado(LivroImportado livro_importado, float taxa_dolar) {
    float taxa_importacao;
    // Definir a taxa de importação com base na região de origem
    switch (livro_importado.regiao_origem)
    {
    case 1: // América do Norte
        taxa_importacao = 0.2;
        break;
    case 2: // Europa
        taxa_importacao = 0.2;
        break;
    case 3: // Outras regiões
        taxa_importacao = 0.15;
        break;
    default:
        taxa_importacao = 0.0;
        break;
    }
    return livro_importado.valor_compra_dolar * (1 + taxa_importacao) * taxa_dolar;
}

void lerLivrosNacionais(Livro livros_nacionais[], int *total_livros_nacionais) {
    int codigo, num_paginas, tipo_encadernacao;
    float valor_pagina;

    printf("")
}