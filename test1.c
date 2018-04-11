//Eric Glover && Paul Stumpe
//Adventure Management Simulator PROTOTYPE
// 1/12/17

//TM T-Swift

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "test1.h"

//use enums for game state tracking
enum state {MAIN, SIMULATOR};
enum state gameState = MAIN;

//Status : helper functions working, initial heroes, monsters and rooms hard coded
        //GAME AI logic : undone
        //UI : undone


/*
char german[20][100];
char russian[20][100];
char french[20][100];
*/
char ***dictionary;


int main(void){
  printf("%d is gameState\n", gameState);
  srand(time(NULL));
  FILE *output;
  char string[100];
  //char ***dictionary;
  char **german;
  char **russian;
  char **french;




  //heroes
  Hero *rogue = malloc(sizeof(Hero));
  rogue->name = "Dagger";
  rogue->h_class = "Rogue";
  for(size_t i = 0; i < STAT_NUM; i++){
    rogue->stats[i] = 10;
  }
  for(size_t i = 0; i < DES_NUM; i++){
    rogue->desires[i] = 20;
  }
  printHero(rogue);
  Hero *knight = createHero("Fred", "Knight", 100, 2, 12, 3, 42, 2, 60, 70);
  printHero(knight);
  //Hero *cleric = malloc(sizeof(Hero));

  //knight, cleric, wizard

  //create monsters
  //populateNameDictionary(german, russian, french);
  dictionary = populateNameDictionary();
  german = dictionary[0];
  russian = dictionary[1];
  french = dictionary[2];
  Monster *slug1 = createMonster(dictionary, "slug", 10, 0, 5, 0, 5);
  Monster *slug2 = createMonster(dictionary, "slug", 10, 0, 5, 0, 5);
  Monster *slug3 = createMonster(dictionary, "slug", 10, 0, 5, 0, 5);
  Monster *golem1 = createMonster(dictionary, "Golem", 45, 2, 3, 0, 5);
  Monster *tinyHydra = createMonster(dictionary, "Mini Hydra", 30, 0, 12, 0, 2);

  //create items


  //create rooms
  Room *room1 = malloc(sizeof(Room));
  room1->monsters[0] = slug1;
  room1->monsters[1] = slug2;
  room1->monsters[2] = slug3;
  room1->monsters[3] = golem1;
  room1->monsters[4] = tinyHydra;
  printMonster(room1->monsters[0]);

  room1->heroes[0] = knight;
  room1->heroes[1] = rogue;
  printHero(room1->heroes[0]);

  //printRoom(room1); //is this sort of function necessary?


  output = fopen("temp.txt", "r+");
  fprintf(output, "dank\n");
  fclose(output);

  //create a few heroes (JSON, txt file or hard code?)
    //later add generation


  //create dungeon asset
  //game loop
    //select heroes
    //run dungeon with heroes
    //print out results every turn

  printf("<----------WELCOME TO THE FABULOUS PROTOTYPE---------->\n");
  //do setup shit
  //game loop : while ( getInput && runGame() )
  while( runGame(getInput()) ){
    //do nothing?
  }
  printf("GAME OVER\n");

  /*----------*/
  //Game AI
  //design, character
    //should chars and monsters have the same abstract class?
  //character desires
    //greed, survival, party members survival, urge to kill (?)
  //stats
    //stats : health armor attack crit% intelligence

  //desire check then planning algorithms then actions



  return 0;
}

char * getInput(){
  char *input;
  char c;
  int i;
  i = 0;
  input = malloc(sizeof(char) * 100);
  //printf("What you do? : \n");
  gets(input);
  //printf("your input is : %s\n", input);
  return input;
}

int runGame(char *input){
  printf("Your input : %s\n", input);

  //switch statement for game modes
  switch (gameState) {
    case MAIN:
      printf("run Game says gameState is MAIN\n");
      //mainMenu(input);
      return mainMenu(input);
      break;
    case SIMULATOR :
      puts("running simulator in runGame");
      return simulator(input);
      break;
    default :
      //nothing
      puts("Default error");
  }
  //later program in a command array and a switch system like in simple.c
    //for now just use some if elses
    /*
  if (!strcmp(input, "quit")){
    return 0;
  }else if (!strcmp(input, "print all")){
    printf("Printing out all Objs\n");
    //code here
  }else if (!strcmp(input, "run dungeon1")){
    printf("Running first dungeon\n");
    //select heroes
    //run first room
    //run second room
  }else{
    return 1;
  }
  */
  return 0;
}

int simulator(char *input){

  if (!strcmp(input, "quit")){
    return 0;
  }else if (!strcmp(input,"print heroes")){
    //print heroes
  }else if (!strcmp(input,"print monsters")){
    //print monsters
  }else if (!strcmp(input,"")){
    //run sim
    runSim();
  }else if (!strcmp(input, "run")){
    //run sim
    runSim();
  }
  return 1;
}

void runSim(){
  //run game ai logics
  //execute a turn
  //update any necessary files 
}

int mainMenu(char *input){
  //later program in a command array and a switch system like in simple.c
    //for now just use some if elses
  if (!strcmp(input, "quit")){
    return 0;
  }else if (!strcmp(input, "print all")){
    printf("Printing out all Objs\n");
    //code here
    return 1;
  }else if (!strcmp(input, "run dungeon1")){
    printf("Running first dungeon\n");
    //select heroes
    gameState = SIMULATOR;
    return 1;
  }else{
    return 1;
  }
  return 0;
}

void printHero(Hero *hero){
  printf("%s is a %s\n", hero->name, hero->h_class);
  printf("%s stats : health %d; armor %d; attack %d; crit %% %d; intelligence %d\n", hero->name, hero->stats[0], hero->stats[1], hero->stats[2], hero->stats[3], hero->stats[4]);
  printf("%s desires : survival %d; greed %d; party survival %d\n", hero->name, hero->desires[0], hero->desires[1], hero->desires[2]);
}

Hero * createHero(char *name, char *class, int health, int armor, int attack, int crit, int intel, int greed, int survival, int partyLove){
  Hero *hero = malloc(sizeof(Hero));
  hero->name = name; // does this work?
  hero->h_class = class;

  hero->stats[0] = health;
  hero->stats[1] = armor;
  hero->stats[2] = attack;
  hero->stats[3] = crit;
  hero->stats[4] = intel;

  hero->desires[0] = greed;
  hero->desires[1] = survival;
  hero->desires[2] = partyLove;
  return hero;
}

Monster * createMonster(char ***dictionary, char *class, int health, int armor, int attack, int crit, int intel){
  Monster *monster = malloc(sizeof(Monster));

  monster->name = dictionary[ (rand() % 3)][ (rand() % 20)];
  monster->h_class = class;

  monster->stats[0] = health;
  monster->stats[1] = armor;
  monster->stats[2] = attack;
  monster->stats[3] = crit;
  monster->stats[4] = intel;

  return monster;
}

void printMonster(Monster *monster){
  printf("%s is a %s\n", monster->name, monster->h_class);
  printf("%s stats : health %d, armor %d, attack %d, crit %% %d, intelligence %d\n", monster->name, monster->stats[0], monster->stats[1], monster->stats[2], monster->stats[3], monster->stats[4]);
}

char *** populateNameDictionary(void){
  FILE *dictionaryText;
  dictionaryText = fopen("NameDictionary.txt", "r");
  char **german;
  char **russian;
  char **french;
  char ***dictionary;
  char c;
  char empty[100];
  int z, i;
  i = z = 0;

  dictionary = malloc(sizeof(char**) * 3);
  german = malloc(sizeof(char*) * 20);
  dictionary[0] = german;
  russian = malloc(sizeof(char*) * 20);
  dictionary[1] = russian;
  french = malloc(sizeof(char*) * 20);
  dictionary[2] = french;
  for (i = 0; i < 3; i++){
    while( (c = fgetc(dictionaryText) ) != '\n' ){
      //skip first line
    }
    for (size_t j = 0; j < 20; j++){
        dictionary[i][j] = malloc( sizeof(char) * 40);
        while( (c = fgetc(dictionaryText) ) != '\n' ){
          //printf("%c", c);
          dictionary[i][j][z] = c;
          //printf("%c", dictionary[i][j][z]);
          z++;
      }
      z = 0;
      //puts("");
      //printf("german[j] = %s\n", dictionary[i][j]);
    }
  }
  //printf("size of dictionary is %lu\n", sizeof(dictionary));

  return dictionary;
}

/*SCRAP CODE
//fscanf(dictionaryText, "%s", empty); //skip first part
/*while( (c = fgetc(dictionaryText) ) != '\n' ){
  //skip first line
}
for (size_t j = 0; j < 20; j++){
    german[j] = malloc( sizeof(char) * 40);
    while( (c = fgetc(dictionaryText) ) != '\n' ){
      //printf("%c", c);
      german[j][z] = c;
      printf("%c", german[j][z]);
      z++;
  }
  z = 0;
  puts("");
  printf("german[j] = %s\n", german[j]);
}
//german[0] = strtok(dictinoary, d);
//strcpy(german[0], strtok(dictionary, d));
//first line is <--German--->
/*
fgets(line, sizeof(line) , dictionary);

for(size_t i = 0; i < 20; i++){
  /*strcpy( line, strtok(NULL, d) );
  fscanf(dictionary, "%s\n", german[i]);
  */
  /*
  fscanf(dictionary, "%s\n", line);
  strcpy()
  */

  //fgets(line, sizeof(line) , dictionary);
  //german[i] = strtok(line, d);
  //printf("size of char %lu size of line %lu\n", sizeof(char), sizeof(line));
  /*line = strtok(line, d);
  printf("%s\n", line);
  strcpy(german[i], line);
  printf("%s\n", german[i] );
*/
  //german[i] = strtok(NULL, d);
  //strcpy(german[i], strtok(NULL, d));
//*/
/*//lets try it like this, line* malloc 500


//char line[500];
//char *line;
//line = malloc(sizeof(char) * 500);
//char *line;
//line = malloc(sizeof(char)*500);
*/
