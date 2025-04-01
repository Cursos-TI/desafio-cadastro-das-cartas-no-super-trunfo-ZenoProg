/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    float densidade;
    float pib_per_capita;
} Carta;

void removerNovaLinha(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void compararCartas(Carta c1, Carta c2) {
    printf("\n========================================================\n");
    printf("               Comparação de Cartas\n");
    printf("========================================================\n");
    printf("%-25s | %-15s | %-15s | Vencedor\n", "Propriedade", c1.nome, c2.nome);
    printf("--------------------------------------------------------\n");

    printf("%-25s | %-15d | %-15d | %-15s\n", "População", c1.populacao, c2.populacao, 
           (c1.populacao > c2.populacao) ? c1.nome : c2.nome);

    printf("%-25s | %-15.2f | %-15.2f | %-15s\n", "Área (km²)", c1.area, c2.area, 
           (c1.area > c2.area) ? c1.nome : c2.nome);

    printf("%-25s | %-15.2f | %-15.2f | %-15s\n", "Densidade Pop.", c1.densidade, c2.densidade, 
           (c1.densidade < c2.densidade) ? c1.nome : c2.nome);

    printf("%-25s | %-15.2lf | %-15.2lf | %-15s\n", "PIB (bilhões)", c1.pib, c2.pib, 
           (c1.pib > c2.pib) ? c1.nome : c2.nome);

    printf("%-25s | %-15.2f | %-15.2f | %-15s\n", "PIB per Capita", c1.pib_per_capita, c2.pib_per_capita, 
           (c1.pib_per_capita > c2.pib_per_capita) ? c1.nome : c2.nome);

    printf("%-25s | %-15d | %-15d | %-15s\n", "Pontos Turísticos", c1.pontos_turisticos, c2.pontos_turisticos, 
           (c1.pontos_turisticos > c2.pontos_turisticos) ? c1.nome : c2.nome);

    float superPoder1 = c1.populacao + c1.area + c1.pib + c1.pib_per_capita + c1.pontos_turisticos - c1.densidade;
    float superPoder2 = c2.populacao + c2.area + c2.pib + c2.pib_per_capita + c2.pontos_turisticos - c2.densidade;

    printf("--------------------------------------------------------\n");
    printf("%-25s | %-15.2f | %-15.2f | %-15s\n", "Super Poder", superPoder1, superPoder2, 
           (superPoder1 > superPoder2) ? c1.nome : c2.nome);
    printf("========================================================\n");
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

            if (cartas[index].area > 0) {
                cartas[index].densidade = cartas[index].populacao / cartas[index].area;
            }

            if (cartas[index].populacao > 0) {
                cartas[index].pib_per_capita = (cartas[index].pib * 1e9) / cartas[index].populacao;
            }
            index++;
        }
    }

    // Exibição das cartas no formato desejado
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

    // Laço para permitir várias comparações
    char comando[10];
    while (1) {
        printf("\nDigite os índices das duas cartas para comparar (0-%d) ou 'exit' para sair:\n", TOTAL_CARTAS - 1);
        printf("Exemplo: Para comparar as cartas 0 e 3, digite '0 3'.\n");
        
        printf("Comando: ");
        fgets(comando, sizeof(comando), stdin);
        removerNovaLinha(comando);

        // Verifica se o usuário digitou "exit"
        if (strcmp(comando, "exit") == 0) {
            printf("Saindo do programa...\n");
            break;
        }

        int c1, c2;
        int valid_input = 0;

        // Verifica se os índices fornecidos são válidos
        if (sscanf(comando, "%d %d", &c1, &c2) == 2) {
            if (c1 >= 0 && c1 < TOTAL_CARTAS && c2 >= 0 && c2 < TOTAL_CARTAS) {
                compararCartas(cartas[c1], cartas[c2]);
                valid_input = 1;
            }
        }

        if (!valid_input) {
            printf("Índices inválidos ou comando incorreto! Tente novamente.\n");
        }
    }

    return 0;
}
