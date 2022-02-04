#include <stdio.h>
#include <stdlib.h>


int pgcd(int a, int b){


	int *tab_a = NULL, *tab_b = NULL, size_a = 0, size_b = 0;
	tab_a = malloc(sizeof(int) * size_a+1);
	tab_b = malloc(sizeof(int) * size_a+1);


	for(int i = 1; i<=a; i++){
		if(a%i == 0){
			realloc(tab_a, size_a + 1);
			tab_a[size_a] = i;
			size_a++;
		}
	}


	for(int i = 1; i<=b; i++){
		if(b%i == 0){
			realloc(tab_b, size_b + 1);
			tab_b[size_b] = i;
			size_b++;
		}
	}

	int temp = 1;
	for(int i=0; i<size_a; i++){
		for(int k=0; k<size_b; k++){
			if(tab_a[i] == tab_b[k] && tab_a[i] > temp){
				temp = tab_a[i];
			}
		}
	}

	return temp;

}



int main(){

	int *tab = NULL;
	int taille;
	printf("Taille du tableau : ");
	scanf("%d", &taille);

	if(taille % 2 == 1){
		return 0;
	}


	tab = malloc(sizeof(int) * taille);


	for(int i = 0; i<taille; i++){
		printf("Valeur : ");
		scanf("%d", &tab[i]);
	}


	int PGCD, *new = NULL;
	while(taille > 1){
		taille /=2;
		for(int i=0; i<taille; i++){
			PGCD = pgcd(tab[i], tab[(taille*2)-i-1]);
			tab[i] = PGCD;
		}
	}

	printf("Valeur finale : %d \n", tab[0]);



	return 0;
}