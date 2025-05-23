#include <stdio.h>

void calculateTimes(int n, int pid[], int at[], int bt[], int ct[], int tat[], int wt[]) {
    int completed = 0, currTime = 0, minIdx;
    int isComp[n];
    for (int i = 0; i < n; i++) isComp[i] = 0;

    while (completed != n) {
        minIdx = -1;
        for (int i = 0; i < n; i++) {
            if (!isComp[i] && at[i] <= currTime) {
                if (minIdx == -1 || bt[i] < bt[minIdx]) {
                    minIdx = i;
                }
            }
        }

        if (minIdx == -1) {
            currTime++;
        } else {
            currTime += bt[minIdx];
            ct[minIdx] = currTime;
            tat[minIdx] = ct[minIdx] - at[minIdx];
            wt[minIdx] = tat[minIdx] - bt[minIdx];
            isComp[minIdx] = 1;
            completed++;
        }
    }
}

void printProcesses(int n, int pid[], int at[], int bt[], int ct[], int tat[], int wt[]) {
    printf("PID\tAT\tBT\tCT\t\tTAT\t\tWT\n");
    int total_tat = 0, total_wt = 0;
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
        total_tat += tat[i];
        total_wt += wt[i];
    }
    float avg_tat = (float)total_tat / n;
    float avg_wt = (float)total_wt / n;
    printf("Average Turnaround Time: %.2f\n", avg_tat);
    printf("Average Waiting Time: %.2f\n", avg_wt);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], ct[n], tat[n], wt[n];

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Burst time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    calculateTimes(n, pid, at, bt, ct, tat, wt);
    printProcesses(n, pid, at, bt, ct, tat, wt);

    return 0;
}