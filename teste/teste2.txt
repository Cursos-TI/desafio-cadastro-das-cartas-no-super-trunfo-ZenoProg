#include <stdio.h>
#include <string.h>

#define TOTAL_ESTADOS 8
#define CIDADES_POR_ESTADO 4
#define TOTAL_CARTAS (TOTAL_ESTADOS * CIDADES_POR_ESTADO)

typedef struct {
    char codigo[4];
    char nome[50];
    int populacao;
    float area;
    double pib;
    int pontos_turisticos;
    char estado[50];
    char pais[50];
} Carta;

void removerNovaLinha(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main() {
    Carta cartas[TOTAL_CARTAS];
    const char estados[] = "ABCDEFGH";
    char nome_pais[50];

    printf("Digite o nome do país: ");
    fgets(nome_pais, sizeof(nome_pais), stdin);
    removerNovaLinha(nome_pais);

    int index = 0;
    for (int e = 0; e < TOTAL_ESTADOS; e++) {
        char nome_estado[50];
        printf("\nDigite o nome do estado %c: ", estados[e]);
        fgets(nome_estado, sizeof(nome_estado), stdin);
        removerNovaLinha(nome_estado);

        for (int c = 0; c < CIDADES_POR_ESTADO; c++) {
            sprintf(cartas[index].codigo, "%c%02d", estados[e], c + 1);

            printf("\nCarta %d (Código %s):\n", index + 1, cartas[index].codigo);

            printf("Digite o nome da cidade: ");
            fgets(cartas[index].nome, sizeof(cartas[index].nome), stdin);
            removerNovaLinha(cartas[index].nome);

            printf("Digite a população da cidade: ");
            while (scanf("%d", &cartas[index].populacao) != 1) {
                printf("Entrada inválida. Digite um número inteiro: ");
                while (getchar() != '\n');
            }

            printf("Digite a área da cidade (em km²): ");
            while (scanf("%f", &cartas[index].area) != 1) {
                printf("Entrada inválida. Digite um número decimal: ");
                while (getchar() != '\n');
            }

            printf("Digite o PIB da cidade (em bilhões): ");
            while (scanf("%lf", &cartas[index].pib) != 1) {
                printf("Entrada inválida. Digite um número decimal: ");
                while (getchar() != '\n');
            }

            printf("Digite o número de pontos turísticos da cidade: ");
            while (scanf("%d", &cartas[index].pontos_turisticos) != 1) {
                printf("Entrada inválida. Digite um número inteiro: ");
                while (getchar() != '\n');
            }
            getchar();

            strncpy(cartas[index].pais, nome_pais, sizeof(cartas[index].pais) - 1);
            cartas[index].pais[sizeof(cartas[index].pais) - 1] = '\0';
            strncpy(cartas[index].estado, nome_estado, sizeof(cartas[index].estado) - 1);
            cartas[index].estado[sizeof(cartas[index].estado) - 1] = '\0';

            index++;
        }
    }

    printf("\n=== Cartas Cadastradas ===\n");
    for (int i = 0; i < TOTAL_CARTAS; i++) {
        printf("\nCódigo: %s\n", cartas[i].codigo);
        printf("País: %s\n", cartas[i].pais);
        printf("Estado: %s\n", cartas[i].estado);
        printf("Cidade: %s\n", cartas[i].nome);
        printf("População: %d habitantes\n", cartas[i].populacao);
        printf("Área: %.2f km²\n", cartas[i].area);
        printf("PIB: %.2lf bilhões\n", cartas[i].pib);
        printf("Pontos turísticos: %d\n", cartas[i].pontos_turisticos);
    }

    return 0;
}
