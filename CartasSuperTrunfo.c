#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

struct Card
{
    float area;
    float pib;
    int tourist_spots;
    int population;

    float population_density; // Calculed by the code
    float pib_head;           // Calculed by the code
};

int menu()
{
    int selected_item = 0;
start:

    printf("\n\n==========================\n");
    printf("   MENU DO SUPER TRUNFO\n");
    printf("==========================\n");

    printf("\n");
    printf("\n");
    printf("O QUE DESEJA FAZER?\n");
    printf("\n");
    printf("\n");
    printf("[1] - Jogar | [2] - Cadastrar cartas | [3] - Sair\n");
    printf("\n");
    printf("\n");

    scanf("%d", &selected_item);

    switch (selected_item)
    {
    case 1:
        return selected_item;
    case 2:
        return selected_item;
    case 3:
        return -1;

    default:
        goto start;
    }
}

int create_cards(struct Card *cards[5], int start_at)
{
    int index_start = start_at;
    char need_continue;

    if (index_start <= 0)
    {
        index_start = 0;
    }
    else if (index_start > 0)
    {
        index_start--;
    }

    printf("Vamos criar as carta.\n");
    for (int i = index_start; i < 5; i++)
    {
        if (i == 2 && need_continue != 'S')
        {
            printf("Você criou o mínimo de 2 cartas, deseja continuar criando?\n");
            printf("S para sim e N para não\n");
            scanf(" %c", &need_continue);

            if (need_continue == 'N')
            {
                return index_start;
            }
        }

        printf("%d° carta \n", i + 1);

        printf("Digite a área da cidade, modelo: 10.0 -> ");
        if (scanf("%f", &cards[i]->area) != 1)
        {
            printf("Erro ao ler a área da cidade %d!\n", i + 1);
            return 1; // Return error code if scanf fails
        }
        printf("Área da cidade: %.2f\n", cards[i]->area);

        printf("Digite a população da cidade, ex: 1000 -> ");
        if (scanf("%d", &cards[i]->population) != 1)
        {
            printf("Erro ao ler a população da cidade %d!\n", i + 1);
            return 1; // Return error code if scanf fails
        }
        printf("População da cidade: %d\n", cards[i]->population);

        printf("Digite o PIB da cidade, ex: 1000.10 -> ");
        if (scanf("%f", &cards[i]->pib) != 1)
        {
            printf("Erro ao ler a PIB da cidade %d!\n", i + 1);
            return 1; // Return error code if scanf fails
        }
        printf("PIB da cidade: %.2f\n", cards[i]->pib);

        printf("Por ultimo, a quantidade de pontos turisticos da cidade, ex: 1000 -> ");
        if (scanf("%d", &cards[i]->tourist_spots) != 1)
        {
            printf("Erro ao ler a PIB da cidade %d!\n", i + 1);
            return 1; // Return error code if scanf fails
        }
        printf("Quantidade de pontos turisticos da cidade: %d\n", cards[i]->tourist_spots);

        index_start = i + 1;

        if (cards[i]->area != 0)
        {
            cards[i]->population_density = cards[i]->area / (float)cards[i]->population;
        }
        else
        {
            cards[i]->population_density = 0;
        }

        if (cards[i]->pib != 0)
        {
            cards[i]->pib_head = cards[i]->pib / (float)cards[i]->population;
        }
        else
        {
            cards[i]->pib_head = 0;
        }
    }

    printf("INDEX START %d", index_start);

    return index_start + 1;
}

void clear_terminal()
{
#ifdef _WIN32
    system("cls"); // For Windows
#else
    system("clear"); // For Linux/macOS
#endif
}

void delay(int milliseconds)
{
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds * CLOCKS_PER_SEC / 1000)
        ;
}

int compare_cards(struct Card *cards[5], int total_cards_added)
{
    int first_card;
    int second_card;

    int first_card_total = 0;
    int second_card_total = 0;

    clear_terminal();

    printf("\n\nAgora vamos iniciar nosso Super Truco\n");
    printf("---------------------------------------\n\n");
    printf("Você criou algumas cartas, qual delas quer comparar primeiro?\n\n");
    printf("Irei lhe mostrar os dados de todas que criou\n\n");
    delay(1000);

    for (int i = 0; i < total_cards_added; i++)
    {
        // cards[i]
        printf("\nCarta Número %d\n----------------\n", i + 1);
        printf("Área da cidade: %.2f\n", cards[i]->area);
        printf("População da cidade: %d\n", cards[i]->population);
        printf("PIB da cidade: %.2f\n", cards[i]->pib);
        printf("Quantidade de pontos turisticos da cidade: %d\n", cards[i]->tourist_spots);

        printf("PIB per capita da carta: %.2f\n", cards[i]->pib_head);
        printf("Densidade Populacional da carta: %.2f\n\n", cards[i]->population_density);
        delay(2000);
    }

    for (int i = 0; i < total_cards_added; i++)
    {
        printf("Carta [%d]", i + 1);
        if (i < total_cards_added - 1)
        {
            printf(" | ");
        }
    }

    printf("\n");

    printf("Escolha qual das cartas deseja ser sua carta: ");
    scanf("%d", &first_card);
    printf("Escolha qual das cartas será do seu adversário: ");
    scanf("%d", &second_card);

    printf("\n");

    printf("============ E que comecem os jogos! ============\n");

    printf("Primeiro vamos comparar a área das cidades\n");

    printf("Cidade 1: %.2f e Cidade 2: %.2f\n\n", cards[first_card - 1]->area, cards[second_card - 1]->area);
    delay(1000);
    if (cards[first_card - 1]->area > cards[second_card - 1]->area)
    {
        first_card_total++;
        printf("A sua carta venceu!\n");
    }
    else if (cards[second_card - 1]->area > cards[first_card - 1]->area)
    {
        second_card_total++;
        printf("A carta do seu adversário venceu!\n");
    }
    else
    {
        printf("Essa deu empate, nenhum ponto para as duas cartas\n");
    }

    printf("Agora vamos comparar a população das cidades\n");

    printf("Cidade 1: %d e Cidade 2: %d\n\n", cards[first_card - 1]->population, cards[second_card - 1]->population);
    delay(1000);
    if (cards[first_card - 1]->population > cards[second_card - 1]->population)
    {
        first_card_total++;
        printf("A sua carta venceu!\n");
    }
    else if (cards[second_card - 1]->population > cards[first_card - 1]->population)
    {
        second_card_total++;
        printf("A carta do seu adversário venceu!\n");
    }
    else
    {
        printf("Essa deu empate, nenhum ponto para as duas cartas\n");
    }

    printf("Agora vamos comparar o PIB das cidades\n");

    printf("Cidade 1: %.2f e Cidade 2: %.2f\n\n", cards[first_card - 1]->pib, cards[second_card - 1]->pib);
    delay(1000);
    if (cards[first_card - 1]->pib > cards[second_card - 1]->pib)
    {
        first_card_total++;
        printf("A sua carta venceu!\n");
    }
    else if (cards[second_card - 1]->pib > cards[first_card - 1]->pib)
    {
        second_card_total++;
        printf("A carta do seu adversário venceu!\n");
    }
    else
    {
        printf("Essa deu empate, nenhum ponto para as duas cartas\n");
    }

    printf("Agora vamos comparar a quantidade de pontos turisticos das cidades\n");

    printf("Cidade 1: %d e Cidade 2: %d\n\n", cards[first_card - 1]->tourist_spots, cards[second_card - 1]->tourist_spots);
    delay(1000);
    if (cards[first_card - 1]->tourist_spots > cards[second_card - 1]->tourist_spots)
    {
        first_card_total++;
        printf("A sua carta venceu!\n");
    }
    else if (cards[second_card - 1]->tourist_spots > cards[first_card - 1]->tourist_spots)
    {
        second_card_total++;
        printf("A carta do seu adversário venceu!\n");
    }
    else
    {
        printf("Essa deu empate, nenhum ponto para as duas cartas\n");
    }

    printf("Agora vamos comparar a densidade populacional das cidades\n");

    printf("Cidade 1: %.2f e Cidade 2: %.2f\n\n", cards[first_card - 1]->population_density, cards[second_card - 1]->population_density);
    delay(1000);
    if (cards[first_card - 1]->population_density > cards[second_card - 1]->population_density)
    {
        first_card_total++;
        printf("A sua carta venceu!\n");
    }
    else if (cards[second_card - 1]->population_density > cards[first_card - 1]->population_density)
    {
        second_card_total++;
        printf("A carta do seu adversário venceu!\n");
    }
    else
    {
        printf("Essa deu empate, nenhum ponto para as duas cartas\n");
    }

    printf("Agora vamos comparar o PIB per capita das cidades\n");

    printf("Cidade 1: %.2f e Cidade 2: %.2f\n\n", cards[first_card - 1]->pib_head, cards[second_card - 1]->pib_head);
    delay(1000);
    if (cards[first_card - 1]->pib_head > cards[second_card - 1]->pib_head)
    {
        first_card_total++;
        printf("A sua carta venceu!\n");
    }
    else if (cards[second_card - 1]->pib_head > cards[first_card - 1]->pib_head)
    {
        second_card_total++;
        printf("A carta do seu adversário venceu!\n");
    }
    else
    {
        printf("Essa deu empate, nenhum ponto para as duas cartas\n");
    }

    printf("============ Saindo os resultados dos jogos! ============\n\n");

    if (first_card_total > second_card_total)
    {
        printf("Você venceu! Parabéns!\n");
        return 0;
    }
    else
    {
        printf("Você perdeu! Mais sorte na próxima\n");
        return 0;
    }
}

int main()
{
    struct Card *cards[5] = {NULL};
    int finishedCount = 0;

    for (int i = 0; i < 5; i++)
    {
        cards[i] = (struct Card *)malloc(sizeof(struct Card));
        if (cards[i] == NULL)
        {
            printf("Ocorreu um erro ao alocar dados na memoria %d\n", i);
            return 1;
        }
    }

    while (1)
    {
        // back_to_menu:
        int selected = menu();
        if (selected == -1)
        {
            return 0; // Exit the program
        }

        if (finishedCount < 2)
        {
            printf("Antes de iniciarmos, precisamos criar nossas cartas\n");
            printf("Precisamos de no mínimo 2 cartas\n");

            finishedCount = create_cards(cards, finishedCount);
        }

        if (finishedCount >= 2)
        {
            compare_cards(cards, finishedCount);
        }
    }

    for (int i = 0; i < 5; i++)
    {
        free(cards[i]);
    }

    return 0;
}
