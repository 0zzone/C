#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void creationMot(char *mot){
    char provisoire[20] = {0};
    printf("Quel mot souhaitez-vous faire deviner ? ");
    scanf("%s", provisoire);
    strcpy(mot, provisoire);
}

void devinette(char *mot){
    int valide = 0;
    char lettre[15] = {0};
    int essais = 0;

    int *tab = NULL;
    tab = (int *) malloc( (strlen(mot) + 1) * sizeof(int*) );

    for(int x=0; x<strlen(mot); x++){
        tab[x] = 0;
    }

    while(valide == 0){
        int i = 0;
        i = 0;
        printf("Le mot à deviner -> ");
        while(mot[i] != '\0'){
            if(tab[i] == 1){
                printf(" %c ", mot[i]);
            }
            else{
                printf(" * ");
            }
            i++;
        }
        printf("\n");
        printf("\n\n Votre proposition: ");
        scanf("%s", lettre);

        int comp =0;
        while(mot[comp] != '\0'){
            if(mot[comp] == lettre[0]){
                tab[comp] = 1;
            }
            comp++;
        }

        i = 0;
        int y = 0;   
        for(int z=0; z<strlen(mot); z++){
            if(tab[z] == 1){
                y++;
            }
        }
        if(y == strlen(mot)){
            valide = 1;
        }
        if(essais == 10){
            valide = 2;
        }
        essais++;
        system("clear");


    }

    if(valide == 1){
        printf("Vous avez trouvé le mot en %d essais ! \n\n", essais);
    }
    else if(valide == 2){
        printf("Vous avez dépassé le nombre d'essais possibles, dommage ;( \n\n");
    }


}



int main(void){
    char mot[20] = {0};
    char *pt_mot = mot;
    int a;
    creationMot(pt_mot);
    devinette(mot);

    return 0;
}