#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
// Teste larissa

int main()
{
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.

    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.

    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.

    float area, pib;
    int touristSpot, population;

    printf("Olá, vamos iniciar o super trunfo de países?\n");
    printf("Antes de iniciarmos, precisamos criar nossas cartas\n");

    printf("Vamos criar a primeira.\n");

    printf("Diga me a área do país, modelo: 10.0\n");
    scanf("%f", &area);

    printf("Agora preciso da população, modelo: 1000\n");
    scanf("%d", &population);

    printf("Agora, preciso do PIB deste país\n");
    scanf("%f", &pib);

    printf("E por ultimo, preciso da quantidade de pontos turísticos\n");
    scanf("%d", &touristSpot);

    printf("\n\n============== PRIMEIRA CARTA CADASTRADA ============\n\n\n");

    printf("Quantidade de pontos turísticos: %d\n", touristSpot);
    printf("População total de %d\n\n", population);

    printf("Área total do país será de %.2f\n", area);
    printf("PIB desta país é será de %.2f\n", pib);

    return 0;
}
