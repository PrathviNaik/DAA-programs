#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function to build bad character table
vector<int> badCharHeuristic(string pattern) {
    vector<int> badChar(256, -1);

    for (int i = 0; i < pattern.length(); i++) {
        badChar[(int)pattern[i]] = i;
    }
    return badChar;
}

// Boyer-Moore search function
void boyerMoore(string text, string pattern) {
    int m = pattern.length();
    int n = text.length();

    vector<int> badChar = badCharHeuristic(pattern);

    int shift = 0; // shift of pattern

    while (shift <= (n - m)) {
        int j = m - 1;

        // Keep reducing index j while characters match
        while (j >= 0 && pattern[j] == text[shift + j]) {
            j--;
        }

        // If pattern found
        if (j < 0) {
            cout << "Pattern found at index " << shift << endl;

            shift += (shift + m < n) ? m - badChar[text[shift + m]] : 1;
        }
        else {
            shift += max(1, j - badChar[text[shift + j]]);
        }
    }
}

// Main function
int main() {
    string text = "ABAAABCD";
    string pattern = "ABC";

    boyerMoore(text, pattern);

    return 0;
}