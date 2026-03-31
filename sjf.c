#include <stdio.h>
#include <limits.h>
int main() {
    int n;
    int at[20], bt[20], ct[20], tat[20], wt[20];
    int completed[20] = {0};
    int time = 0, count = 0;
    float atat = 0, awt = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time of P%d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter Burst Time of P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    while (count < n) {
        int idx = -1;
        int min_bt = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && completed[i] == 0 && bt[i] < min_bt) {
                min_bt = bt[i];
                idx = i;
            }
        }
        if (idx == -1) {
            time++;   // CPU idle
        } 

else {
            time += bt[idx];
            ct[idx] = time;
            completed[idx] = 1;
            count++;
        }
    }
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        atat += tat[i];
        awt += wt[i];
    }
    printf("\n------------------------------------------------------\n");
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    printf("------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    

printf("------------------------------------------------------\n");
    printf("Average Turnaround Time = %.2f\n", atat / n);
    printf("Average Waiting Time    = %.2f\n", awt / n);
    return 0;
}
