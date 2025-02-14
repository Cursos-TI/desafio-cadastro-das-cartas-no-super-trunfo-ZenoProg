#include <stdio.h>

#define TOTAL_ESTADOS 8
#define CIDADES_POR_ESTADO 4
#define TOTAL_CARTAS (TOTAL_ESTADOS * CIDADES_POR_ESTADO)

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

typedef struct {
    char codigo[4];       // Código da cidade (ex: A01, B02)
    char nome[50];        // Nome da cidade
    int populacao;        // População total
    float area;           // Área total em km²
    double pib;           // PIB em bilhões
    int pontos_turisticos;// Número de pontos turísticos
} Carta;

int main() {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    Carta cartas[TOTAL_CARTAS];
    char estados[] = "ABCDEFGH"; // Lista de estados (A até H)

    // Exibir os dados cadastrados
    printf("=== Cadastro das Cartas ===\n");

    int index = 0;
    for (int e = 0; e < TOTAL_ESTADOS; e++) {
        for (int c = 0; c < CIDADES_POR_ESTADO; c++) {
            // Gerar código automaticamente (ex: A01, B02, C03)
            sprintf(cartas[index].codigo, "%c%02d", estados[e], c + 1);

            printf("\nCarta %d (Código %s):\n", index + 1, cartas[index].codigo);

            printf("Digite o nome da cidade: ");
            scanf(" %[^\n]", cartas[index].nome);

            printf("Digite a população da cidade: ");
            scanf("%*c"); //descarta o '\n' que sobra no buffer
            

            printf("Digite a área da cidade (em km²): ");
            scanf("%f", &cartas[index].area);
            scanf("%*c");

            printf("Digite o PIB da cidade (em bilhões): ");
            scanf("%lf", &cartas[index].pib);

            printf("Digite o número de pontos turísticos da cidade: ");
            scanf("%d", &cartas[index].pontos_turisticos);

            index++;
        }


        // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    
    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.
    }

    // Exibir os dados cadastrados
    printf("\n=== Cartas Cadastradas ===\n");
    for (int i = 0; i < TOTAL_CARTAS; i++) {
        printf("\nCódigo: %s\n", cartas[i].codigo);
        printf("Cidade: %s\n", cartas[i].nome);
        printf("População: %d habitantes\n", cartas[i].populacao);
        printf("Área: %.2f km²\n", cartas[i].area);
        printf("PIB: %.2lf bilhões\n", cartas[i].pib);
        printf("Pontos turísticos: %d\n", cartas[i].pontos_turisticos);
    }

    return 0;
}
