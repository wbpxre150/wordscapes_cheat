#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char buffer [256];
  // load words files
  FILE* words;
  FILE* new_words;
  words = fopen("all_words", "r");
  new_words = fopen("words", "w");

  // loop over words one at a time.
  while (fgets(buffer, 256, words) != NULL) {
    // words between length 3 and 7 letters long inclusive.
    if ( strlen(buffer) > 9 || strlen(buffer) < 5 ) {
      continue;
    } else {
      // convert uppercase to lower case.
      for(int i=0;i<=strlen(buffer);i++){
         if(buffer[i]>=65&&buffer[i]<=90)
            buffer[i]=buffer[i]+32;
      }
      // write word to words file.
      fputs(buffer, new_words);
    }
  }
  return 0;
}
