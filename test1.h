//1/12/17
//game #1

//TM T-Swift

//test1.h
//maybe use enums for this?
#define STAT_NUM 5
#define DES_NUM 3

struct hero {
  //to use ptrs or array declar here ? oh the questions..
  char *name;
  char *h_class;

  //stats : health armor attack crit% intelligence
  int stats[STAT_NUM];
  //desires : greed, survival, party members survival
  int desires[DES_NUM];
};

struct item {
  //nothing for now
};

struct monster {
  char *name;
  char *h_class;

  //stats : health armor attack crit% intelligence
  int stats[STAT_NUM];
};

struct room {
  struct monster *monsters[10];
  struct hero *heroes[10];

};

typedef struct hero Hero;
typedef struct monster Monster;
typedef struct item Item;
typedef struct room Room;

Hero * createHero(char *name, char *class, int health, int armor, int attack, int crit, int intel, int greed, int survival, int partyLove);
void printHero(Hero*);

Monster * createMonster(char ***dictionary, char *class, int health, int armor, int attack, int crit, int intel);
void printMonster(Monster*);

//void populateNameDictionary(char[20][100], char[20][100], char[20][100]);
char *** populateNameDictionary(void);

int main(void);
int mainMenu(char *);
int simulator(char *);

void runSim(void);

char * getInput(void);
int runGame(char input[]);
