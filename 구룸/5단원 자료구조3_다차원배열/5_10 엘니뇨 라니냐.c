#include <stdio.h>
#include <math.h>

int main() {
    float enso[11][2] = {
        {1990, 0.6},
        {1991, 0.2},
        {1992, 1.1},
        {1993, 0.5},
        {1994, 0.1}, // made by wwwxsv19
        {1995, 1.2},
        {1996, -0.3},
        {1997, -0.1},
        {1998, 2.2},
        {1999, -0.7},
        {2000, -1.1}
    };

    int elnino = 0, lanina = 0, n = 11, i;
    float minAbsStrength = fabs(enso[0][1]);

    printf("엘니뇨: ");
    for (i = 0; i < n; i++) {
        if (enso[i][1] > 0) {
            printf("%.f ", enso[i][0]);
            if (enso[i][1] > enso[elnino][1]) {
                elnino = i;
            } // made by wwwxsv19
        }
    }
    printf("\n");
    printf("가장 강한 엘니뇨: %.f\n", enso[elnino][0]);

    printf("라니냐: ");
    for (i = 0; i < n; i++) {
        if (enso[i][1] < 0) {
            printf("%.f ", enso[i][0]);
            if (enso[i][1] < enso[lanina][1]) {
                lanina = i;
            }
        } // made by wwwxsv19
    }
    printf("\n");
    printf("가장 강한 라니냐: %.f\n", enso[lanina][0]);

    printf("가장 정상적인 해: ");
    for (i = 0; i < n; i++) {
        if (i != elnino && i != lanina) {
            if (fabs(enso[i][1]) < minAbsStrength) {
                minAbsStrength = fabs(enso[i][1]);
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (i != elnino && i != lanina) {
            if (fabs(enso[i][1]) == minAbsStrength) {
                printf("%.f ", enso[i][0]);
            }
        } // made by wwwxsv19
    }
    printf("\n");

    return 0;
}
