#include <stdio.h>

int main() {
    int n, tq, i, time = 0, completed = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\nEnter Time Quantum: ");
    scanf("%d", &tq);

    int at[n], bt[n], rt[n], ct[n], tat[n], wt[n];

    float avgTAT = 0, avgWT = 0;

    // Input Arrival Time and Burst Time
    for(i = 0; i < n; i++) {
        printf("\nEnter AT and BT for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);

        rt[i] = bt[i]; // Remaining Time
    }

    // Round Robin Scheduling
    while(completed < n) {
        int done = 1;

        for(i = 0; i < n; i++) {

            // Process has arrived and still has remaining time
            if(at[i] <= time && rt[i] > 0) {
                done = 0;

                // Execute for Time Quantum or remaining time
                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                }
                else {
                    time += rt[i];
                    rt[i] = 0;

                    ct[i] = time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];

                    avgTAT += tat[i];
                    avgWT += wt[i];

                    completed++;
                }
            }
        }

        // If no process is ready
        if(done)
            time++;
    }

    // Calculate averages
    avgTAT /= n;
    avgWT /= n;

    // Display averages
    printf("\n\nAverage Turnaround Time: %.2f\n", avgTAT);
    printf("Average Waiting Time: %.2f\n", avgWT);

    return 0;
}