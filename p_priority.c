#include <stdio.h>
#include <limits.h>

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int id[n], arrival[n], burst[n], priority[n], remaining[n];
    int completion[n], waiting[n], turnaround[n];
    int isCompleted[n], currentTime = 0, completed = 0;
    float avgWaiting = 0, avgTurnaround = 0;

    for (int i = 0; i < n; i++) {
        printf("Enter details for Process P%d:\n", i + 1);
        id[i] = i + 1;
        printf("Arrival time: ");
        scanf("%d", &arrival[i]);
        printf("Burst time: ");
        scanf("%d", &burst[i]);
        printf("Priority: ");
        scanf("%d", &priority[i]);
        remaining[i] = burst[i];
        isCompleted[i] = 0;
        completion[i] = 0;
        waiting[i] = 0;
        turnaround[i] = 0;
    }

    while (completed < n) {
        int highestPriorityIdx = -1;
        int highestPriority = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!isCompleted[i] && arrival[i] <= currentTime && priority[i] < highestPriority && remaining[i] > 0) {
                highestPriority = priority[i];
                highestPriorityIdx = i;
            }
        }

        if (highestPriorityIdx == -1) {
            currentTime++;
            continue;
        }

        remaining[highestPriorityIdx]--;
        currentTime++;

        if (remaining[highestPriorityIdx] == 0) {
            completed++;
            isCompleted[highestPriorityIdx] = 1;
            completion[highestPriorityIdx] = currentTime;
            turnaround[highestPriorityIdx] = completion[highestPriorityIdx] - arrival[highestPriorityIdx];
            waiting[highestPriorityIdx] = turnaround[highestPriorityIdx] - burst[highestPriorityIdx];
        }
    }

    printf("\nProcess\tArrival\tBurst\tPriority\tCompletion\tWaiting\tTurnaround\n");
    printf("--------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t\t%d\t%d\n",
               id[i], arrival[i], burst[i], priority[i], completion[i], waiting[i], turnaround[i]);
        avgWaiting += waiting[i];
        avgTurnaround += turnaround[i];
    }

    avgWaiting /= n;
    avgTurnaround /= n;

    printf("\nAverage Waiting Time: %.2f\n", avgWaiting);
    printf("Average Turnaround Time: %.2f\n", avgTurnaround);

    return 0;
}