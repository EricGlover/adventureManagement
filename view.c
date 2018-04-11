#include <stdio.h>
#include <time.h>

#include <unistd.h>

#define REFRESH_RATE 2

void clearScreen(); //no idea how but it works bby

int main(void){
    FILE *input;
    input = fopen("temp.txt","r");
    char line[100];
    while (1) {
        fscanf(input,"%s\n", line);
        //clear screen
        clearScreen();
        printf("%s\n", line);
        fclose(input);
        sleep(REFRESH_RATE);
        input = fopen("temp.txt", "r");
    }
    return 0;

}

void clearScreen(){
  const char* CLEAR_SCREE_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO,CLEAR_SCREE_ANSI,12);
}
