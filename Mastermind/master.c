#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "master.h"

int main(){
	int *comb = (int*) malloc(sizeof(int) * SIZE);
	random_comb(comb);
	display_combinaison(comb);
	int *propos = (int*) malloc(sizeof(int) * SIZE) , cpt = 0, x, y, valide = 0;
	do{
		while(read_comb(propos) == 0){
			read_comb(propos);
		}

		if(well_placed(comb, propos) == SIZE){
			valide = 1;
		}

		x = wrong_placed(comb, propos);
		y = well_placed(comb, propos);
		result(x,y);
		cpt++;
	} while(well_placed(comb, propos) != SIZE && cpt < 20);

	if(valide == 0){
		printf("Vous avez trop essayé ! La solution était -> ");
		display_combinaison(comb);
	}
	else{
		printf("Vous avez réussi en %d essais ! \n", cpt);
	}

}


void display_combinaison(int *comb){
	for(int i=0; i<SIZE; i++){
		i<SIZE-1 ? printf("%d - ", *(comb+i)) : printf("%d \n", *(comb+i));
	}
}

int read_comb(int *comb){
	int n;
	printf("Saisir une combinaison sans espace : ");
	scanf("%d", &n);
	if(n>9999 && n < 99999){
		for(int i=0; i<SIZE; i++){
			int reste = n%10;
			if(reste < 1 || reste > 8){
				return 0;
			}
			n /= 10;
			*(comb+SIZE-1-i) = reste;
		}
		return 1;
	}
	return 0;
}


void random_comb(int *comb){
	srand(time(NULL));
	int n = rand() % 10000;
	for(int i =0; i<SIZE; i++){
		int reste = n%10;
		while(reste < 1 || reste > 8){
			reste = rand() % 10;
		}
		n/=10;
		*(comb+i) = reste;
	}
}


int well_placed(int *comb, int *propos){
	int c = 0;
	for(int i =0; i<SIZE; i++){
		if(*(comb+i) == *(propos+i)){
			c++;
		}
	}
	return c;
}


int wrong_placed(int *comb, int *propos){
	int c = 0;
	int *new = copyComb(comb);
	for(int i=0; i<SIZE; i++){
		for(int k =0; k<SIZE; k++){
			if(*(propos+i) == *(new+k) && i!= k){
				c++;
				*(new+k) = 0;
			}
		}
	}
	return c;
}


void result(int x, int y){
	x > 1 ? printf("%d présents - ", x) : printf("%d présent - ", x);
	y > 1 ? printf("%d bien placés \n", y) : printf("%d bien placé \n", y);
}


int *copyComb(int *comb){
	int *new = NULL;
	new = (int*) malloc(sizeof(int) * SIZE);
	for(int i=0; i<SIZE; i++){
		*(new+i) = *(comb+i);
	}
	return new;
}









