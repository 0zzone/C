#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void change(char *chaine);
int lengthChar(char *chaine);

int main(void)
{
    char chaine[255];
    printf("Entrez un mot: ");
    fgets(chaine, 255, stdin);
    change(chaine);
    printf("%s", chaine);
    return 0;
}

void change(char *chaine){
    // Change the value of each 'a' in a string to '*'
    int i=0;
    while(chaine[i] != '\0'){
        if(chaine[i] == 'a'){
            chaine[i] = '*';
        }
        i++;
    }
}