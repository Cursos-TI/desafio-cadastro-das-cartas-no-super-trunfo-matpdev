#include <stdio.h>

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
start:
  int selected_item;

  printf("==========================\n");
  printf("MENU DO SUPER TRUNFO\n");
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

int main()
{
  struct Card cards[5] = {};
  int finishedCount = 0;

  int selected = menu();

  printf("ITEM SELECTED = %d", selected);

  if (selected == -1)
  {
    return 1;
  }

  // printf("Olá, vamos iniciar o super trunfo de países?\n");
  // if (finishedCount < 2)
  // {
  //   printf("Antes de iniciarmos, precisamos criar nossas cartas\n");
  //   printf("Precisamos de no mínimo 2 cartas");
  // }

  //  float area, pib;
  //    int touristSpot, population;

  //
  //    printf("Vamos criar a primeira.\n");
  //
  //    printf("Diga me a área do país, modelo: 10.0\n");
  //    scanf("%f", &area);
  //
  //    printf("Agora preciso da população, modelo: 1000\n");
  //    scanf("%d", &population);
  //
  //    printf("Agora, preciso do PIB deste país\n");
  //    scanf("%f", &pib);
  //
  //    printf("E por ultimo, preciso da quantidade de pontos turísticos\n");
  //    scanf("%d", &touristSpot);
  //
  //    printf("\n\n============== PRIMEIRA CARTA CADASTRADA
  //    ============\n\n\n");
  //
  //    printf("Quantidade de pontos turísticos: %d\n", touristSpot);
  //    printf("População total de %d\n\n", population);
  //
  //    printf("Área total do país será de %.2f\n", area);
  //    printf("PIB desta país é será de %.2f\n", pib);

  return 0;
}
