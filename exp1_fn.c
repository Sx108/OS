#include <stdio.h>

// Function to calculate waiting times
void calc_wt(int n, int bt[], int wt[]) {
    wt[0] = 0; // Waiting time for the first process is 0
    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}

// Function to calculate turnaround times
void calc_tt(int n, int bt[], int wt[], int tt[]) {
    for (int i = 0; i < n; i++) {
        tt[i] = bt[i] + wt[i];
    }
}

// Function to display results and calculate averages
void show_res(int n, int bt[], int wt[], int tt[]) {
    float avg_wt = 0, avg_tt = 0;

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tt[i]);
        avg_wt += wt[i];
        avg_tt += tt[i];
    }

    avg_wt /= n;
    avg_tt /= n;

    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tt);
}

// Main function
void main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tt[n];

    printf("Enter the burst time of each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    calc_wt(n, bt, wt);
    calc_tt(n, bt, wt, tt);
    show_res(n, bt, wt, tt);
}
