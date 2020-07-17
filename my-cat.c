// Petteri Särkkä 17.7.2020
// Project 2: Unix Utilities
// Lähteet:
// C ohjelmoinnin perusteet kurssi
#include <stdio.h>
#include <stdlib.h>
#define LEN 80

// lue tiedosto funktio
void lue(char *tiedostonimi) {
  FILE* tiedosto;
  char rivi[LEN];
  if ((tiedosto = fopen(tiedostonimi, "r")) == NULL){
    perror("my-cat: cannot open file\n");
    exit(1);
  }
  while (fgets(rivi, LEN, tiedosto) !=NULL){
    printf("%s", rivi);
  }
  fclose(tiedosto);
}

// pääohjelma
int main(int argc, char *argv[]){
 int i;
 for(i=1;i<argc;i++){
   lue(argv[i]);
 }
 return (0);
}
