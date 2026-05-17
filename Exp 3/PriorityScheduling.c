#include <stdio.h>

int main() {
    int n, i, time = 0, completed = 0, highest;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], pr[n];
    int ct[n], tat[n], wt[n], visited[n];

    float avgTAT = 0, avgWT = 0;

    // Input
    for(i = 0; i < n; i++) {
        printf("\nEnter AT, BT and Priority for P%d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        visited[i] = 0;
    }

    // Priority Scheduling
    while(completed < n) {
        highest = -1;

        // Find highest priority process among arrived processes
        for(i = 0; i < n; i++) {
            if(at[i] <= time && visited[i] == 0) {

                if(highest == -1 || pr[i] < pr[highest]) {
                    highest = i;
                }
            }
        }

        // If no process has arrived
        if(highest == -1) {
            time++;
        }
        else {
            time += bt[highest];

            ct[highest] = time;
            tat[highest] = ct[highest] - at[highest];
            wt[highest] = tat[highest] - bt[highest];

            avgTAT += tat[highest];
            avgWT += wt[highest];

            visited[highest] = 1;
            completed++;
        }
    }

    // Average calculations
    avgTAT /= n;
    avgWT /= n;

    // Output
    printf("\n\nAverage Turnaround Time = %.2f\n", avgTAT);
    printf("Average Waiting Time = %.2f\n", avgWT);

    return 0;
}