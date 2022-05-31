#include <stdio.h>

int main(void) {
  int month, day, year;

  // Standard date form
  printf("Enter date (mm/dd/yyyy): ");
  // Split the user input into 3 variables for the date
  // Don't worry about the `scanf()` below, you'll learn more about these later!
  scanf("%d /%d /%d", &month, &day, &year);

//   printf("The chosen month is %d", month);

// st
// nd
// rd
// th

  // Print the month
  switch(month) {
      case 1:
        printf("January");
        break;
      case 2:
        printf("February");
        break;
      case 3:
        printf("March");
        break;
      case 4:
        printf("April");
        break;
      case 5:
        printf("May");
        break;
      case 6:
        printf("June");
        break;
      case 7:
        printf("July");
        break;
      case 8:
        printf("August");
        break;
      case 9:
        printf("September");
        break;
      case 10:
        printf("October");
        break;
      case 11:
        printf("November");
        break;
      case 12:
        printf("December");
        break;
  }

  // Print the day
    printf(" %d", day);

  // Print the suffix for a given day
  switch(day) {
      case 1: case 21: case 31:
       printf("st,");
       break;
      case 2: case 22:
       printf("nd,");
       break;
      case 3: case 23:
       printf("rd,");
       break;
    //   case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19: case 20: case 24: case 25: case 26: case 27: case 28: case 29: case 30:
    //    printf("th,");
    //    break;
      default:
       printf("th,");

  }

  // Print the year
  printf(" %d\n", year);
  
  return 0;
}