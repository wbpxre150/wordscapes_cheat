#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char buffer [256], buffer2[256];
  int skip=0;
  // load words files
  FILE* words;
  FILE* new_words;
  words = fopen("all_words", "r");

  // loop over words one at a time.
  while (fgets(buffer, 256, words) != NULL) {
    // convert uppercase to lower case.
    for(int i=0;i<=strlen(buffer);i++){
       if(buffer[i]>=65&&buffer[i]<=90)
          buffer[i]=buffer[i]+32;
    }
    
    // loop over new_words file 
    //printf("%s", buffer);
    new_words = fopen("words", "r");
    while (fgets(buffer2, 256, new_words) != NULL) { 
      // if the word is already there skip it
      if (strcmp(buffer, buffer2) == 0) {
        skip = 1;
        break;
      }
    }
    fclose(new_words);
    if ( skip == 0 ) {
      // write word to words file.
      new_words = fopen("words", "a");
      fputs(buffer, new_words);
      fclose(new_words);
    }
    skip = 0;
  }
  return 0;
}
