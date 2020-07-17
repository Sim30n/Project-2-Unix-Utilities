// Petteri Särkkä 17.7.2020
// Project 2: Unix Utilities
// Lähteet:
// C ohjelmoinnin perusteet kurssi
// Linux getline() man page
// https://stackoverflow.com/questions/15098936/simple-way-to-check-if-a-string-contains-another-string-in-c

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 80

// lue tiedosto funktio
void lue(char *haku, char *tiedostonimi) {
  FILE* tiedosto;
  char * line = NULL;
  size_t len = 0;
  ssize_t read;
  tiedosto = fopen(tiedostonimi, "r");
  if (tiedosto == NULL){
    fprintf(stderr,"my-grep: cannot open file\n");
    exit(1);
  }
  while ((read = getline(&line, &len, tiedosto)) != -1) {
      if(strstr(line, haku) != NULL){
        printf("%s\n", line);
      }
  }
  fclose(tiedosto);
  if (line){
    free(line);
  }
}

// lue käyttäjän syöttämästä lauseesta
void lue_stdin(char *haku) {
  char sana[LEN];
  scanf("%s", sana);
  if(strstr(sana, haku) != NULL){
    printf("%s\n", sana);
  }
}

// pääohjelma
int main(int argc, char *argv[]){
 int i;
 if(argc == 2){
   lue_stdin(argv[1]);
 } else if(argc == 1){
   printf("my-grep: searchterm [file ...]\n");
   exit(1);
 }
 for(i=2;i<argc;i++){
   lue(argv[1], argv[i]);
 }
 return (0);
}
