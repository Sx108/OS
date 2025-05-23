#include <stdio.h>

int main() {
    int n, tq, i, t = 0, done;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter time quantum: ");
    scanf("%d", &tq);

    int bt[n], rem[n], at[n], pid[n], wt[n], tat[n], ft[n];
    for (i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
        rem[i] = bt[i];
        wt[i] = 0;
        tat[i] = 0;
        ft[i] = 0;
    }

    int completed = 0;
    int prev = -1;
    while (completed < n) {
        done = 1;
        for (i = 0; i < n; i++) {
            if (rem[i] > 0 && at[i] <= t) {
                done = 0;
                if (rem[i] > tq) {
                    t += tq;
                    rem[i] -= tq;
                } else {
                    t += rem[i];
                    wt[i] = t - bt[i] - at[i];
                    rem[i] = 0;
                    ft[i] = t;
                    tat[i] = ft[i] - at[i];
                    completed++;
                }
            }
        }
        // If no process was executed in this cycle, increment time
        if (done) t++;
    }

    // Output
    printf("\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], wt[i], tat[i]);
    }

    float avg_wt = 0, avg_tat = 0;
    for (i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    avg_wt /= n;
    avg_tat /= n;
    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);

    return 0;
}