#include <stdio.h>
main(){
  int num;
  printf("Question 1 part c)\nEnter an integer number in Fahrenheit and I will convert it to Celcius: ");
  scanf("%d", &num);
  float toCel = 5*(num-32)/9;
  printf("%d degrees Fahrenheit is about %.2f degrees Celcius.\n\n", num,toCel);
  return 0;
}
