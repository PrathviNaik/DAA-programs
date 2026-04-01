#include <iostream>
using namespace std;

bool subsetSum(int arr[], int n, int sum) {
    if (sum == 0) return true;
    if (n == 0) return false;

    if (arr[n - 1] > sum)
        return subsetSum(arr, n - 1, sum);

    return subsetSum(arr, n - 1, sum) ||
           subsetSum(arr, n - 1, sum - arr[n - 1]);
}

int main() {
    int arr[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = 6;

    if (subsetSum(arr, n, sum))
        cout << "Subset exists";
    else
        cout << "No subset";

    return 0;
}