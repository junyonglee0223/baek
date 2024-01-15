
#include <string>
#include <vector>

#include <bits/stdc++.h>
using namespace std;

void calculateSums(const vector<vector<int>>& dice, int index, int currentSum, vector<int>& sums) {
    if (index == dice.size()) {
        sums.push_back(currentSum);
        return;
    }
    for (int num : dice[index]) {
        calculateSums(dice, index + 1, currentSum + num, sums);
    }
}

vector<int> getAllPossibleSums(const vector<vector<int>>& dice) {
    vector<int> sums;
    calculateSums(dice, 0, 0, sums);
    return sums;
}

int binocountAWins(vector<int>& diceA, vector<int>& diceB) {
    sort(diceB.begin(), diceB.end());
    int wins = 0;
    for (int sumA : diceA) {
        auto it = upper_bound(diceB.begin(), diceB.end(), sumA);
        wins += distance(it, diceB.end());
    }
    return wins;
}

vector<int> solution(vector<vector<int>> dice) {
    int n = dice.size();
    int maxWins = 0;
    vector<int> answer;

    for (int i = 0; i < (1 << n); ++i) {
        if (__builtin_popcount(i) == n / 2) {
            vector<vector<int>> diceA, diceB;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) diceA.push_back(dice[j]);
                else diceB.push_back(dice[j]);
            }

            vector<int> sumsA = getAllPossibleSums(diceA);
            vector<int> sumsB = getAllPossibleSums(diceB);

            int wins = binocountAWins(sumsA, sumsB);
            if (wins > maxWins) {
                maxWins = wins;
                answer.clear();
                for (int j = 0; j < n; ++j) {
                    if ((i & (1 << j)) == 0) answer.push_back(j + 1);
                }
            }
        }
    }

    return answer;
}



/*
1, 2, 3, 2, 3
1
2 1
3 2 1
4 3 2 


*/