#include <iostream>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    int weight[n], value[n];

    cout << "Enter weights: ";
    for(int i = 0; i < n; i++)
        cin >> weight[i];

    cout << "Enter values: ";
    for(int i = 0; i < n; i++)
        cin >> value[i];

    cout << "Enter capacity of knapsack: ";
    cin >> W;

    int dp[n+1][W+1];

    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            if(i == 0 || w == 0)
                dp[i][w] = 0;
            else if(weight[i-1] <= w)
                dp[i][w] = max(value[i-1] + dp[i-1][w-weight[i-1]],
                               dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    cout << "Maximum Profit: " << dp[n][W];

    return 0;
}
🔹 Time Complexity

O(n × W)

🔹 0/1 Knapsack in Python
n = int(input("Enter number of items: "))
weights = list(map(int, input("Enter weights: ").split()))
values = list(map(int, input("Enter values: ").split()))
W = int(input("Enter capacity: "))

dp = [[0 for _ in range(W+1)] for _ in range(n+1)]

for i in range(1, n+1):
    for w in range(W+1):
        if weights[i-1] <= w:
            dp[i][w] = max(values[i-1] + dp[i-1][w-weights[i-1]],
                           dp[i-1][w])
        else:
            dp[i][w] = dp[i-1][w]

print("Maximum Profit:", dp[n][W])

If you want, I can also give:

✅ Greedy (Fractional Knapsack)

✅ Recursion method

✅ Tabular explanation for exam writing

✅ Difference between 0/1 and Fractional Knapsack