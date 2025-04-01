#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

// Declaração das funções utilizadas
void gerarCartas(Carta cartas[]);
void compararCartas(Carta c1, Carta c2, int atributo);
void menuComparacao(Carta cartas[]);
void removerNovaLinha(char *str);

int main() {
    // Inicializa a semente dos números aleatórios
    srand(time(NULL));
    Carta cartas[TOTAL_CARTAS];
    
    // Gera automaticamente as cartas com dados aleatórios
    gerarCartas(cartas);
    
    // Exibe as cartas geradas com seus atributos
    printf("\n=== Cartas Geradas ===\n");
    for (int i = 0; i < TOTAL_CARTAS; i++) {
        printf("\nCódigo: %s\n", cartas[i].codigo);
        printf("Cidade: %s, Estado: %s, País: %s\n", cartas[i].nome, cartas[i].estado, cartas[i].pais);
        printf("População: %d\nÁrea: %.2f km²\nPIB: %.2lf bilhões\nPontos turísticos: %d\n",
               cartas[i].populacao, cartas[i].area, cartas[i].pib, cartas[i].pontos_turisticos);
    }
    
    // Inicia o menu interativo de comparação de cartas
    menuComparacao(cartas);
    return 0;
}

// Função que gera 32 cartas automaticamente com dados aleatórios
void gerarCartas(Carta cartas[]) {
    const char estados[] = "ABCDEFGH";
    const char *nomesCidades[] = {"Cidade1", "Cidade2", "Cidade3", "Cidade4"};
    const char *nomePais = "PaísX";
    int index = 0;
    
    for (int e = 0; e < TOTAL_ESTADOS; e++) {
        char nomeEstado[50];
        sprintf(nomeEstado, "Estado %c", estados[e]);
        
        for (int c = 0; c < CIDADES_POR_ESTADO; c++) {
            sprintf(cartas[index].codigo, "%c%02d", estados[e], c + 1);
            strcpy(cartas[index].nome, nomesCidades[c]);
            strcpy(cartas[index].estado, nomeEstado);
            strcpy(cartas[index].pais, nomePais);
            
            cartas[index].populacao = rand() % 1000000 + 50000;
            cartas[index].area = (rand() % 9000 + 1000) / 10.0;
            cartas[index].pib = (rand() % 100 + 10) / 10.0;
            cartas[index].pontos_turisticos = rand() % 10 + 1;
            
            cartas[index].densidade = cartas[index].populacao / cartas[index].area;
            cartas[index].pib_per_capita = (cartas[index].pib * 1e9) / cartas[index].populacao;
            index++;
        }
    }
}

// Função que compara duas cartas com base no atributo escolhido
void compararCartas(Carta c1, Carta c2, int atributo) {
    float valor1, valor2;
    char nomeAtributo[50];
    int inverter = 0;  // Flag que indica se a lógica deve ser invertida (usada para densidade)
    
    // Seleciona o atributo a ser comparado com base na escolha do usuário
    switch (atributo) {
        case 1: // Comparação de População
            valor1 = c1.populacao;
            valor2 = c2.populacao;
            strcpy(nomeAtributo, "População");
            break;
        case 2: // Comparação de Área
            valor1 = c1.area;
            valor2 = c2.area;
            strcpy(nomeAtributo, "Área");
            break;
        case 3: // Comparação de Densidade Populacional (menor vence)
            valor1 = c1.densidade;
            valor2 = c2.densidade;
            strcpy(nomeAtributo, "Densidade Pop.");
            inverter = 1;  // Inverte a lógica: a carta com MENOR valor vence
            break;
        case 4: // Comparação de PIB
            valor1 = c1.pib;
            valor2 = c2.pib;
            strcpy(nomeAtributo, "PIB");
            break;
        case 5: // Comparação de PIB per Capita
            valor1 = c1.pib_per_capita;
            valor2 = c2.pib_per_capita;
            strcpy(nomeAtributo, "PIB per Capita");
            break;
        case 6: // Comparação de Pontos Turísticos
            valor1 = c1.pontos_turisticos;
            valor2 = c2.pontos_turisticos;
            strcpy(nomeAtributo, "Pontos Turísticos");
            break;
        default:
            printf("Atributo inválido!\n");
            return;
    }
    
    // Exibe os valores dos atributos escolhidos
    printf("\nComparação: %s\n", nomeAtributo);
    printf("%s: %.2f VS %s: %.2f\n", c1.nome, valor1, c2.nome, valor2);
    
    // Determina e exibe o vencedor com base na regra de comparação
    if (valor1 == valor2) {
        printf("Empate!\n");
    } else {
        if (inverter) {
            printf("Vencedor: %s\n", (valor1 < valor2) ? c1.nome : c2.nome);
        } else {
            printf("Vencedor: %s\n", (valor1 > valor2) ? c1.nome : c2.nome);
        }
    }
}

// Função que exibe um menu interativo e instruções claras para comparar as cartas
void menuComparacao(Carta cartas[]) {
    while (1) {
        int c1, c2, atributo;
        
        // Instruções detalhadas para o usuário
        printf("\n===================================================\n");
        printf("Para comparar duas cartas, digite os índices das cartas separados por um espaço.\n");
        printf("Exemplo: Para comparar a carta 0 com a carta 15, digite: 0 15\n");
        printf("Os índices válidos são de 0 a %d.\n", TOTAL_CARTAS - 1);
        printf("Para sair, digite -1 em qualquer posição.\n");
        printf("===================================================\n");
        
        // Lê os índices das cartas para comparar
        scanf("%d %d", &c1, &c2);
        if (c1 == -1 || c2 == -1)
            break;
        if (c1 < 0 || c1 >= TOTAL_CARTAS || c2 < 0 || c2 >= TOTAL_CARTAS) {
            printf("Índices inválidos! Tente novamente.\n");
            continue;
        }
        
        // Menu para seleção do atributo
        printf("\nEscolha o atributo para comparação:\n");
        printf("Digite 1 para População\n");
        printf("Digite 2 para Área\n");
        printf("Digite 3 para Densidade Populacional (a carta com MENOR densidade vence)\n");
        printf("Digite 4 para PIB\n");
        printf("Digite 5 para PIB per Capita\n");
        printf("Digite 6 para Pontos Turísticos\n");
        printf("Sua opção: ");
        scanf("%d", &atributo);
        
        // Compara as cartas com base no atributo escolhido
        compararCartas(cartas[c1], cartas[c2], atributo);
    }
}

// Função utilitária que remove o caractere de nova linha ('\\n') do final de uma string, se presente
void removerNovaLinha(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}
