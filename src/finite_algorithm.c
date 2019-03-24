#include <stdio.h>
#include <stdlib.h>

#define n 10

time_t t;
int payoff_p1[n][n], payoff_p2[n][n];
int maxInd_p1[n], maxInd_p2[n];

void assignValues() {
    int i, j;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        { payoff_p1[i][j] = rand()%100; payoff_p2[i][j] = rand()%100; }
    return; }

void findMax_p1() {
    int i, j, max, ind;
    for(i=0; i<n; i++) {
        max = 0, ind = -1;
        for(j=0; j<n; j++)
            if (payoff_p1[i][j] > max)
                { max = payoff_p1[i][j]; ind = j; }
        maxInd_p1[i] = ind; }
    return; }

void findMax_p2() {
    int i, j, max, ind;
    for(i=0; i<n; i++) {
        max = 0; ind = -1;
        for(j=0; j<n; j++)
            if (payoff_p2[j][i] > max)
                { max = payoff_p2[j][i]; ind = j; }
        maxInd_p2[i] = ind; }
    return; }



int main(int argc, const char * argv[]) {
    srand((unsigned) time(&t));
    int count = 0;

    while(count < 100) {
        assignValues();
        findMax_p1();
        findMax_p2();

        int found = 0;
        int i;
        for(i=0; i<n; i++) {
            if (maxInd_p2[maxInd_p1[i]] == i) {
                printf("Equilibrium found in: %d,%d\n", i, maxInd_p1[i]);
                found = 1; } }

    if (!found) printf("There is no pure Nash equilibrium\n");
    printf("----------------------------------\n");

    count++ ;
    }

    system("pause");
    return 0;
}
