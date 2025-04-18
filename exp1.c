#include <stdio.h>
void main()
{
    int n, i;
    float avg_wt, avg_tt;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int bt[n], wt[n], tt[n];
    printf("Enter the burst time of each process:\n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }
    wt[0] = 0;
    avg_wt = 0;
    avg_tt = 0;
    for (i = 1; i < n; i++)
    {
        wt[i] = bt[i - 1] + wt[i - 1];
        avg_wt += wt[i];
    }
    for (i = 0; i < n; i++)
    {
        tt[i] = bt[i] + wt[i];
        avg_tt += tt[i];
    }
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tt[i]);
    }
    avg_wt = avg_wt / n;
    avg_tt = avg_tt / n;
}
