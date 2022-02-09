#include <stdio.h>

int main()
{

    int tab[100], val, index, found = 1, i=0, n;
    printf("Taille du tableau : ");
    scanf("%d", &n);

    for(int p=0; p<n; p++){
        printf("Valeur : ");
        scanf("%d", &tab[p]);
    }

    printf("Valeur à insérer : ");
    scanf("%d", &val);

    while(i<n && found == 1){
        if(val <= tab[i]){
            index = i;
            found = 0;
        }
        i++;
    }


    if(found == 1){
        index = n;
    }

    tab[n] = 0;

    for(int l=5;l>index; l--){
        tab[l] = tab[l-1];
    }
    tab[index] = val;


    for(int t=0; t<6; t++){
        printf("%d ", tab[t]);
    }


    return 0;
}
