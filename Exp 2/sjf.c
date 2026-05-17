#include <stdio.h>

int main() {
    int n, i, j, completed = 0, time = 0, shortest;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n], visited[n];

    float avgTAT = 0, avgWT = 0;

    // Input Arrival Time and Burst Time
    for(i = 0; i < n; i++) {
        printf("\nEnter Arrival Time and Burst Time for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        visited[i] = 0;
    }

    // SJF Scheduling
    while(completed < n) {
        shortest = -1;

        // Find process with minimum burst time among arrived processes
        for(i = 0; i < n; i++) {
            if(at[i] <= time && visited[i] == 0) {
                if(shortest == -1 || bt[i] < bt[shortest]) {
                    shortest = i;
                }
            }
        }

        // If no process has arrived yet
        if(shortest == -1) {
            time++;
        }
        else {
            time += bt[shortest];
            ct[shortest] = time;

            tat[shortest] = ct[shortest] - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];

            avgTAT += tat[shortest];
            avgWT += wt[shortest];

            visited[shortest] = 1;
            completed++;
        }
    }

    // Calculate averages
    avgTAT /= n;
    avgWT /= n;

    // Display results
    printf("\n\nAverage Turnaround Time = %.2f", avgTAT);
    printf("\nAverage Waiting Time = %.2f\n", avgWT);

    return 0;
}