#include <stdio.h>

int main(void) {
  char user_input_char = 'a';
  float value = 1;

  puts("Type your value, please.");
  scanf("%f", &value);

  const float CELSIUS_TO_FARENHEIT = value * 9/5 + 32;
  const float FARENHEIT_TO_CELSIUS = (value - 32.0) * 5/9;

  puts("Type 'c' to convert value to celsius, or type 'f' to convert value to farenheit.");
  scanf(" %c", &user_input_char);
  if (user_input_char == 'c') {
    printf("%.2f degrees celsius", FARENHEIT_TO_CELSIUS);
  }
  else if (user_input_char == 'f') {
    printf("%.2f degrees farenheit", CELSIUS_TO_FARENHEIT);
  }
  else {
    puts("Incorrect input");
  }
  return 0;
}