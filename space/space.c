#include <stdio.h>

int main() {

  double weight;
  int fightPlanet;
 
  printf("Please enter your current earth weight: ");
  scanf("%lf", &weight);

  printf("=================================\n");
  printf("Please choose your fight planet:\n");
  printf("Enter 1 for: Mercury\n");
  printf("Enter 2 for: Venus\n");
  printf("Enter 3 for: Mars\n");
  printf("Enter 4 for: Jupiter\n");
  printf("Enter 5 for: Saturn\n");
  printf("Enter 6 for: Uranus\n");
  printf("Enter 7 for: Neptune\n");
  printf("Enter 8 for: Earth\n");
  printf("=================================\n");
  scanf("%d", &fightPlanet);

//   printf("Your official weight on Earth is %.0f kg\n", weight);
//   printf("Your fight planet of choice is %d\n", fightPlanet);

// 1	Mercury	0.38
// 2	Venus	0.91
// 3	Mars	0.38
// 4	Jupiter	2.34
// 5	Saturn	1.06
// 6	Uranus	0.92
// 7	Neptune	1.19

  switch(fightPlanet) {
      case 1:
        printf("You have chosen Mercury as your fight planet\n");
        weight *= 0.38;
        break;
      case 2:
        printf("You have chosen Venus as your fight planet\n");
        weight *= 0.91;
        break;
      case 3:
        printf("You have chosen Mars as your fight planet\n");
        weight *= 0.38;
        break;
      case 4:
        printf("You have chosen Jupiter as your fight planet\n");
        weight *= 2.34;
        break;
      case 5:
        printf("You have chosen Saturn as your fight planet\n");
        weight *= 1.06;
        break;
      case 6:
        printf("You have chosen Uranus as your fight planet\n");
        weight *= 0.92;
        break;
      case 7:
        printf("You have chosen Neptune as your fight planet\n");
        weight *= 1.19;
        break;
      case 8:
        printf("You have chosen Earth as your fight planet\n");
        break;
      default:
        printf("You do not have chose a correct planet...\n");
  }

 printf("Your weight on the destination planet is %.2f kg\n", weight);

}