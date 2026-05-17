#include <stdio.h>

int main() {
    int n, i;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n];
    float avgTAT = 0, avgWT = 0;

    // Input Arrival Time and Burst Time
    for(i = 0; i < n; i++) {
        printf("\nEnter Arrival Time and Burst Time for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    // Calculate Completion Time
    for(i = 0; i < n; i++) {
        if(i == 0) {
            ct[i] = at[i] + bt[i];
        } else {
            if(ct[i - 1] < at[i]) {
                ct[i] = at[i] + bt[i];
            } else {
                ct[i] = ct[i - 1] + bt[i];
            }
        }

        // Calculate TAT and WT
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avgTAT += tat[i];
        avgWT += wt[i];
    }

    // Calculate averages
    avgTAT /= n;
    avgWT /= n;

    // Display results
    printf("\n\nAverage Turnaround Time: %.2f\n", avgTAT);
    printf("\nAverage Waiting Time: %.2f\n", avgWT);

    return 0;
}