#include <stdio.h>
#include <string.h>

int check_word(char word[256], char input[8], char mask[8]) {
  int i = 0 ,j = 0,n = 0,m = 0, z = 0, y = 0, k = 0;
  char internal_input[8];
  strcpy(internal_input, input);
  m = strlen(word)-2;
  //printf("%s      %s", internal_input, word);
  // if word contains more letters than input string we cannot build it from the input letters.
  if (m > strlen(input)) {
    //printf("word: %i input: %i\n", m, strlen(input));
    return 0;
  }
  // only return words with the length of the mask.
  if (m != strlen(mask)) {
    return 0;
  }
  // count the mask, to check how many letters are given.
  for ( i = 0; i < strlen(mask); i++ ) {
    if ( mask[i] != 46 ) {
      //printf("%i : %i\n", i, mask[i]);
      z++;
    }
  }
  // loop each letter of the word
  for (i = 0; i < m; i++) {
    // compare input letters to current letter, if matched remove that letter to prevent dupes.
    for (j = 0; j < strlen(internal_input); j++) {
      if ( word[i] == internal_input[j] ) {
        //printf("%i == %i MATCH\n", word[i], internal_input[j]);
        internal_input[j] = ' ';
        n++;
        break;
      }
    }
    //printf("n = %i  vs.  m = %i\n", n, m);
    // if all letters in the input string match the word check the mask.
    if ( n == m ) {
      for (k = 0; k < strlen(mask); k++) {
        if ( mask[k] != 46 && mask[k] == word[k] ) {
          //printf("%s y = %d z = %d  k = %d\n", word, y, z, k);
          y++;
        }
      }
      //printf("y = %d z = %d\n", y, z);
      if ( y == z ) {
        // the mask matches return the word, print it.
        return 1;
      }
    }
  }
  return 0;
}


int main(int argc, char const *argv[]) {
  // get letters from command line and print them
  char input[8], mask[8], buffer [256];
  if ( argv[1] != NULL && argv[2] != NULL ) {
    strcpy(input, argv[1]);
    strcpy(mask, argv[2]);
  } else {
    printf("Need to enter letters and mask in format:\n ./gw xxxx ....\n");
    return 0;
  }
  printf("Input Letters: %s\n", input);

  // load words file
  FILE* words;
  words = fopen("words", "r");

  // loop over words one at a time.
  while (fgets(buffer, 256, words) != NULL) {
    if (check_word(buffer, input, mask) == 1)
      printf("%s", buffer);
  }

  return 0;
};
