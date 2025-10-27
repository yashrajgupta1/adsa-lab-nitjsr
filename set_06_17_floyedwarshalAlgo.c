#include <stdio.h>


int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve 0/1 Knapsack using DP (bottom-up)
int knapsack(int W, int wt[], int val[], int n) {
    int dp[n+1][W+1];

    // Build table dp[][] in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;  // Base case: no items or capacity = 0
            }
            else if (wt[i-1] <= w) {
                dp[i][w] = max(val[i-1] + dp[i-1][w - wt[i-1]], dp[i-1][w]);
            }
            else {
                dp[i][w] = dp[i-1][w];  // Item too heavy, skip it
            }
        }
    }

    return dp[n][W]; 
}

int main() {
    int val[] = {60, 100, 120};   
    int wt[] = {10, 20, 30};      
    int W = 50;                 
    int n = sizeof(val) / sizeof(val[0]);

    printf("Maximum value in Knapsack = %d\n", knapsack(W, wt, val, n));

    return 0;
}
