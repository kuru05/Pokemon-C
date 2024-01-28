#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_POKEDEX_ENTRIES 150 

typedef struct {
  char name[20];
  char description[100];
  int id;
  char type[10];
  int baseHP;
  int baseAttack;
  int baseDefense;
  int baseSpAttack;
  int baseSpDefense;
  int baseSpeed;
} PokedexEntry;

typedef struct {
  PokedexEntry entries[MAX_POKEDEX_ENTRIES];
  int numEntries;
} Pokedex;

void initPokedex(Pokedex* pokedex) {
  pokedex->numEntries = 0;
}

void addPokedexEntry(Pokedex* pokedex, char* name, char* description, int id, char* type, int baseHP, int baseAttack, int baseDefense, int baseSpAttack, int baseSpDefense, int baseSpeed) {
  
  if(pokedex->numEntries < MAX_POKEDEX_ENTRIES) {
    PokedexEntry entry;
    strcpy(entry.name, name);
    strcpy(entry.description, description);
    entry.id = id;
    strcpy(entry.type, type);
    entry.baseHP = baseHP;
    entry.baseAttack = baseAttack;
    entry.baseDefense = baseDefense;
    entry.baseSpAttack = baseSpAttack;
    entry.baseSpDefense = baseSpDefense;
    entry.baseSpeed = baseSpeed;

    pokedex->entries[pokedex->numEntries] = entry;
    pokedex->numEntries++;
  }
}

PokedexEntry getPokedexEntryById(Pokedex* pokedex, int id) {
  for(int i=0; i < pokedex->numEntries; i++) {
    if(pokedex->entries[i].id == id) {
      return pokedex->entries[i];
    }
  }
  
  // Not found
  PokedexEntry emptyEntry;
  return emptyEntry;
}

PokedexEntry getPokedexEntryByName(Pokedex* pokedex, char* name) {
  for(int i=0; i < pokedex->numEntries; i++) {
    if(strcmp(pokedex->entries[i].name, name) == 0) {
      return pokedex->entries[i];
    }
  }

  // Not found
  PokedexEntry emptyEntry;
  return emptyEntry;  
}

void printPokedexEntry(PokedexEntry entry) {
  printf("Name: %s\n", entry.name);
  printf("Description: %s\n", entry.description);
  printf("Type: %s\n", entry.type);
  printf("Stats:\n");
  printf("  HP: %d\n", entry.baseHP);
  printf("  Attack: %d\n", entry.baseAttack);
  printf("  Defense: %d\n", entry.baseDefense);
  printf("  Sp. Atk: %d\n", entry.baseSpAttack);
  printf("  Sp. Def: %d\n", entry.baseSpDefense);
  printf("  Speed: %d\n", entry.baseSpeed);
}

int main() {

  Pokedex pokedex;
  initPokedex(&pokedex);

  addPokedexEntry(&pokedex, "Pikachu", "Pokemon Souris Electrique", 25, "Electrique", 35, 55, 40, 50, 50, 90);

  PokedexEntry pikachu = getPokedexEntryById(&pokedex, 25);
  printPokedexEntry(pikachu);

  PokedexEntry alsoPikachu = getPokedexEntryByName(&pokedex, "Pikachu");


  return 0;
}
