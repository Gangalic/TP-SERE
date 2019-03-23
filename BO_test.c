#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <string.h>


#define PASSWORD_LENGTH 10 

void random_pass(char * password){
    int i;
    for(i=0; i<PASSWORD_LENGTH; i++){
        password[i]=rand()%43 + 48; 
    }
}

/*
Spoiler : Il faut entrer "0000000000000000000" pour modifier la variable password à que des 0. Puis il faut écrire "000000000" pour valider. 
          Si on veut modifier le nb d'essais il faut écrire 20 caractères et le 21 sera la nouvelle valeur de lifes. 
*/
int main(){
    
    int lifes=3; 
    char password[PASSWORD_LENGTH];
    char input[PASSWORD_LENGTH]; 

    srand(time(0)); 
    random_pass(password);
    printf("Salut jeune inconnu. Aujourd'hui est un grand jour car tu va passer un test ! \n");
    printf("Essaye de deviner mon mot de passe. Bonne chance.\n---------------------------------------------------------\n");

    do{
	printf("Actual mdp: %sx\n", password);
        printf("Entre mon mdp : ");
        scanf("%s", &input); 
	printf("Input: %sx\n", input);
        if(strcmp(input,password)==0){
            printf("Bravo !");
            return 0; 
        }else{
            printf("Mauvais mot de passe ! \nIl te reste %d essais.\n",lifes-1);
            lifes--; 
        }

    }while(lifes>0);
    printf("Malheureux tu n'es pas digne de la force ! "); 
    return -1; 

    
}
