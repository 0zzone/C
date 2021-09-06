#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Change tous les 'a' en '*' dans une chaîne de caractères

int main(void){
    int i=0;
    char s[50];
    printf("Enter a string here: ");
    scanf("%s", s);
    
    while(s[i] != '\0'){
        if(s[i] == 'a'){
            strcpy(&s[i], "*");
        }
        i++;
    }

    printf("%s", s);

    return 0;
}