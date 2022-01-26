// Imports
#include <stdio.h>

// Main code
int main(){

	int tab[] = {3,8,2,0, 9,34,21,90};
	int taille = sizeof(tab)/sizeof(int);

	for(int k=0; k<taille-1; k++){
		for(int i=0; i<taille-1; i++){
			if(tab[i] > tab[i+1]){
				int temp = tab[i];
				tab[i] = tab[i+1];
				tab[i+1] = temp;
			}
		}
	}

	for(int l=0; l<taille; l++){
		printf("%d ", tab[l]);
	}

	return 0;
}