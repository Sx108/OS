#include <stdio.h>
#include <limits.h> // Include for INT_MAX

#define N 100 // N is the maximum number of processes supported by the program

int main() {
    int n, t = 0, done = 0;
    int pid[N], at[N], bt[N], rt[N], ct[N], wt[N], tat[N];

    printf("No. of procs: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("AT & BT for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    while (done < n) {
        int min = INT_MAX, idx = -1; // Use INT_MAX instead of 1e9
        for (int i = 0; i < n; i++) {
            if (at[i] <= t && rt[i] > 0 && rt[i] < min) {
                min = rt[i];
                idx = i;
            }
        }
        if (idx == -1) {
            t++;
            continue;
        }
        rt[idx]--;
        t++;
        if (rt[idx] == 0) {
            done++;
            ct[idx] = t;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
        }
    }

    printf("\nPID\tAT\tBT\tCT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], wt[i], tat[i]);
    }

    float avg_wt = 0, avg_tat = 0;
    for (int i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    printf("\nAvg WT: %.2f\n", avg_wt / n);
    printf("Avg TAT: %.2f\n", avg_tat / n);

    return 0;
}