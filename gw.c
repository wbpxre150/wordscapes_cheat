#include <stdio.h>
#include <string.h>

#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
#define reset "\e[0m"

int check_word(char word[256], char input[8], char mask[8]) {
  int i = 0 ,j = 0,n = 0,m = 0, z = 0, y = 0, k = 0;
  char internal_input[8];
  strcpy(internal_input, input);
  m = strlen(word)-1;
  // if word contains more letters than input string we cannot build it from the input letters.
  if (m > strlen(input)) 
    return 0;
  // only return words with the length of the mask.
  if (m != strlen(mask)) 
    return 0;
  // count the mask, to check how many letters are given.
  for ( i = 0; i < strlen(mask); i++ ) {
    if ( mask[i] != 46 ) 
      z++;
  }
  // loop each letter of the word
  for (i = 0; i < m; i++) {
    // compare input letters to current letter, if matched remove that letter to prevent dupes.
    for (j = 0; j < strlen(internal_input); j++) {
      if ( word[i] == internal_input[j] ) {
        internal_input[j] = ' ';
        n++;
        break;
      }
    }
    // if all letters in the input string match the word check the mask.
    if ( n == m ) {
      for (k = 0; k < strlen(mask); k++) {
        if ( mask[k] != 46 && mask[k] == word[k] ) 
          y++;
      }
      if ( y == z )
        // the mask matches return the word, print it.
        return 1;
    }
  }
  return 0;
}

void print_word(char word[256], int c) {
  if ( c == 0 ) printf(RED"%s"reset, word);
  if ( c == 1 ) printf(GRN"%s"reset, word);
  if ( c == 2 ) printf(BLU"%s"reset, word);
  if ( c == 3 ) printf(YEL"%s"reset, word);
  if ( c == 4 ) printf(MAG"%s"reset, word);
  if ( c == 5 ) printf(CYN"%s"reset, word);
  if ( c == 6 ) printf(WHT"%s"reset, word);
}

int main(int argc, char const *argv[]) {
  // get letters from command line and print them
  char input[8], mask[8], buffer [256];
  int c = 0;
  if ( argv[1] != NULL && argv[2] != NULL && strlen(argv[1]) < 8 && strlen(argv[2]) < 8 ) {
    strcpy(input, argv[1]);
    strcpy(mask, argv[2]);
  } else {
    printf("Need to enter letters and mask in format:\n ./gw xxxxxxx .......\n");
    return 0;
  }
  printf("Input Letters: %s\n", input);
  // load words file
  FILE* words;
  words = fopen("words", "r");
  while (fgets(buffer, 256, words) != NULL) {
    if (check_word(buffer, input, mask) == 1) {
      if ( c == 7 ) c = 0;
      print_word(buffer,c);
      c++;
    }
  }
  return 0;
};