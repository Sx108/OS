#include <stdio.h>
#include <limits.h>

int main() {
    int n, i, t = 0, completed = 0, min_pr, curr = -1;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], rem[n], pr[n], at[n], pid[n];
    int wt[n], tat[n], ft[n];

    // Input
    for (i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
        printf("Enter priority for process %d (lower number = higher priority): ", i + 1);
        scanf("%d", &pr[i]);
        rem[i] = bt[i];
        ft[i] = 0;
    }

    // Preemptive Priority Scheduling
    while (completed < n) {
        min_pr = INT_MAX;
        curr = -1;
        for (i = 0; i < n; i++) {
            if (at[i] <= t && rem[i] > 0 && pr[i] < min_pr) {
                min_pr = pr[i];
                curr = i;
            }
        }
        if (curr != -1) {
            rem[curr]--;
            if (rem[curr] == 0) {
                completed++;
                ft[curr] = t + 1;
                tat[curr] = ft[curr] - at[curr];
                wt[curr] = tat[curr] - bt[curr];
            }
        }
        t++;
    }

    // Output
    printf("\nProcess\tArrival\tBurst\tPriority\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n", pid[i], at[i], bt[i], pr[i], wt[i], tat[i]);
    }

    // Average times
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