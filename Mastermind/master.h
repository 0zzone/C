#ifndef HEADER_FILE
#define HEADER_FILE

// Constant
const int SIZE = 5;

// Prototypes
void display_combinaison(int *comb);
int read_comb(int *comb);
void random_comb(int *comb);
int well_placed(int *comb, int *propos);
int wrong_placed(int *comb, int *propos);
void result(int x, int y);
int *copyComb(int *comb);


#endif
