#include <stdio.h>

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
    Carta cartas[4];
    char estados[] = "ABCDEFGH"; // Lista de estados (A até H)

    // Exibir os dados cadastrados
    printf("=== Cadastro das Cartas ===\n");

    for (int i = 0; i < 4; i++) {
        // Gerar o código automaticamente
        char estado = estados[i / 4];  // Pega a letra do estado
        int numero = (i % 4) + 1;       // Garante números de 1 a 4

        sprintf(cartas[i].codigo, "%c%02d", estado, numero); // Formata o código (ex: A01)

        printf("\nCarta %d (Código %s):\n", i + 1, cartas[i].codigo);

        printf("Digite o nome da cidade: ");
        scanf(" %[^\n]", cartas[i].nome); 

        printf("Digite a população da cidade: ");
        scanf("%d", &cartas[i].populacao);

        printf("Digite a área da cidade (em km²): ");
        scanf("%f", &cartas[i].area);

        printf("Digite o PIB da cidade (em bilhões): ");
        scanf("%lf", &cartas[i].pib);

        printf("Digite o número de pontos turísticos da cidade: ");
        scanf("%d", &cartas[i].pontos_turisticos);

        // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    
    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.
    }

    // Exibir os dados cadastrados
    printf("\n=== Cartas Cadastradas ===\n");
    for (int i = 0; i < 4; i++) {
        printf("\nCódigo: %s\n", cartas[i].codigo);
        printf("Cidade: %s\n", cartas[i].nome);
        printf("População: %d habitantes\n", cartas[i].populacao);
        printf("Área: %.2f km²\n", cartas[i].area);
        printf("PIB: %.2lf bilhões\n", cartas[i].pib);
        printf("Pontos turísticos: %d\n", cartas[i].pontos_turisticos);
    }

    return 0;
}