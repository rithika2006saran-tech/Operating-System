#include <stdio.h>

int main() {
    int n, m, i, j, k;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\nEnter number of resource types: ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], need[n][m];
    int avail[m], finish[n], safeSeq[n];

    // Input Allocation Matrix
    printf("\nEnter Allocation Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    // Input Max Matrix
    printf("Enter Max Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Input Available Resources
    printf("Enter Available Resources: ");
    for(i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
    }

    // Calculate Need Matrix
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Initialize finish array
    for(i = 0; i < n; i++) {
        finish[i] = 0;
    }

    int count = 0;

    // Banker's Algorithm
    while(count < n) {
        int found = 0;

        for(i = 0; i < n; i++) {

            // If process is not finished
            if(finish[i] == 0) {

                // Check if need <= available
                int possible = 1;

                for(j = 0; j < m; j++) {
                    if(need[i][j] > avail[j]) {
                        possible = 0;
                        break;
                    }
                }

                // If resources can be allocated
                if(possible) {

                    // Release allocated resources
                    for(k = 0; k < m; k++) {
                        avail[k] += alloc[i][k];
                    }

                    safeSeq[count] = i;
                    count++;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        // No process could be executed
        if(found == 0) {
            break;
        }
    }

    // Check safe state
    if(count == n) {
        printf("\nSystem is in a SAFE STATE.\n");
        printf("Safe Sequence: ");

        for(i = 0; i < n; i++) {
            printf("P%d ", safeSeq[i]);
        }
    }
    else {
        printf("\nSystem is NOT in a safe state (Deadlock may occur).\n");
    }

    return 0;
}