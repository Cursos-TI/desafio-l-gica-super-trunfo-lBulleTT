#include <stdio.h> // Para funções de entrada/saída como printf e scanf

// Estrutura para representar uma carta de cidade
// Agrupa todas as informações de uma cidade em uma unica entidade.
typedef struct {
    char estado[4];
    char codigo[4];
    char nome_cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} CartaCidade;

// Função para limpar o buffer de entrada
// Essencial para evitar problemas com scanf e entradas de string.
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para cadastrar os dados de uma carta
// Recebe um ponteiro para uma CartaCidade para preencher seus dados.
void cadastrarCarta(CartaCidade *carta) {
    limparBufferEntrada(); // Limpa o buffer antes de cada cadastro para garantir entradas limpas

    printf("Estado (A-H): ");
    scanf(" %c", &carta->estado); // O espaço antes de %c consome qualquer caractere de nova linha pendente
    limparBufferEntrada(); // Limpa o buffer após o scanf de %c

    printf("Código da Carta (ex: A01): ");
    scanf("%s", carta->codigo);
    limparBufferEntrada(); // Limpa o buffer após o scanf de %s

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta->nome_cidade); // Lê a linha inteira até a quebra de linha
    limparBufferEntrada(); // Limpa o buffer após o scanf de %[^\n]

    printf("População: ");
    scanf("%d", &carta->populacao);
    // Não precisa limpar o buffer aqui se o próximo scanf for um número ou float

    printf("Área (km²): ");
    scanf("%f", &carta->area);

    printf("PIB (bilhões): ");
    scanf("%f", &carta->pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
}

// Função para exibir os dados de uma carta
// Recebe uma CartaCidade (passada por valor, pois não será modificada) e imprime seus atributos.
void exibirCarta(const CartaCidade carta) {
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nome_cidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontos_turisticos);
}

// Função para comparar duas cartas com base na população
// Retorna 1 se carta1 vence, 2 se carta2 vence, ou 0 em caso de empate.
// Regra: Maior população vence.
int compararPorPopulacao(const CartaCidade carta1, const CartaCidade carta2) {
    if (carta1.populacao > carta2.populacao) {
        return 1; // Carta 1 vence
    } else if (carta2.populacao > carta1.populacao) {
        return 2; // Carta 2 vence
    } else {
        return 0; // Empate
    }
}

int main() {
    CartaCidade carta1; // Declaração da primeira carta
    CartaCidade carta2; // Declaração da segunda carta

    printf("\n--- CADASTRO CARTA 1 ---\n");
    cadastrarCarta(&carta1); // Chama a função para cadastrar a carta 1

    printf("\n--- CADASTRO CARTA 2 ---\n");
    cadastrarCarta(&carta2); // Chama a função para cadastrar a carta 2

    // Exibição dos Dados das Cartas:
    printf("\n--- DADOS DA CARTA 1 ---\n");
    exibirCarta(carta1); // Exibe os dados da carta 1

    printf("\n--- DADOS DA CARTA 2 ---\n");
    exibirCarta(carta2); // Exibe os dados da carta 2

    // Comparação das Cartas (Nível Novato - Comparação por População)
    printf("\n--- RESULTADO DA COMPARACAO (POR POPULACAO) ---\n");
    int resultado = compararPorPopulacao(carta1, carta2);

    if (resultado == 1) {
        printf("A carta vencedora é: %s (Carta 1) com %d de População!\n", carta1.nome_cidade, carta1.populacao);
    } else if (resultado == 2) {
        printf("A carta vencedora é: %s (Carta 2) com %d de População!\n", carta2.nome_cidade, carta2.populacao);
    } else {
        printf("As cartas empataram em População!\n");
    }

    
    return 0; // Indica que o programa terminou com sucesso
}
