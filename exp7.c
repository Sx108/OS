#include <stdio.h>

int main() {
    int n, i, j;
    printf("No. of procs: ");
    scanf("%d", &n);

    int bt[n], pr[n], pid[n];
    int wt[n], tat[n];

    // Input bt & pr
    for (i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("BT for P%d: ", i + 1);
        scanf("%d", &bt[i]);
        printf("PR for P%d (low val = high pr): ", i + 1);
        scanf("%d", &pr[i]);
    }

    // Sort by pr
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (pr[i] > pr[j]) {
                int temp = pr[i]; pr[i] = pr[j]; pr[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = pid[i]; pid[i] = pid[j]; pid[j] = temp;
            }
        }
    }

    // Calc wt & tat
    wt[0] = 0;
    tat[0] = bt[0];
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
    }

    // Output
    printf("\nPID\tBT\tPR\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", pid[i], bt[i], pr[i], wt[i], tat[i]);
    }

    float avg_wt = 0, avg_tat = 0;
    for (i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    avg_wt /= n;
    avg_tat /= n;
    printf("\nAvg WT: %.2f\n", avg_wt);
    printf("Avg TAT: %.2f\n", avg_tat);

    return 0;
}