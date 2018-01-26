/*
Software Systems Exercise 1

Card Counting - Prompts user for card values to keep track of card count and
displays the current card count.

Camille Xue
January 2018
*/

#include <stdio.h>
#include <stdlib.h>
void get_card_name(char *prompt, char *card_name);
int get_card_value(char *card_name);
int update_count(int val, int count);


int main() {
  char card_name[3];
  int count = 0;
  int value;
  do {
    get_card_name("Enter your card name.\n", card_name);
    if(card_name[0] == 'X'){
      continue;
    }
    value = get_card_value(card_name);
    count = update_count(value, count);
    printf("Current count: %i\n", count);
  } while (card_name[0] != 'X');

  return 0;
}

/* Prompts the user for input and puts the reply in the given buffer.

   User input is truncated to the first two characters.

   prompt: string prompt to display
   card_name: buffer where result is stored
*/
void get_card_name(char *prompt, char *card_name) {
  printf("%s", prompt);
  scanf("%2s", card_name);
}

/* Figures out and returns value of given card_name.

   card_value: number value 1-10 of card_name
*/
int get_card_value(char *card_name) {
  int card_value;
  switch(card_name[0]) {
    case 'K':
    case 'Q':
    case 'J':
      card_value = 10;
      break;
    case 'A':
      card_value = 11;
      break;
    default:
      card_value = atoi(card_name);
      if ((card_value < 1) || (card_value > 10)) {
        puts("I don't understand that value!");
      }
  }
  return card_value;
}

/* Returns updated card count based on given new card_value and current count.

  Adds 1 if between 2 and 7, decreases 1 if 10.

  card_value: new card value 1-10 used to calculate count
  count: current card count
*/
int update_count(int val, int count) {
  if ((val > 2) && (val < 7)) {
    count++;
  } else if (val == 10) {
    count--;
  }
  return count;
}
