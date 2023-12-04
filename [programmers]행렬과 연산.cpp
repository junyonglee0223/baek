#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> matrix, vector<string> operations) {
    int numRows = matrix.size(); 
    int numCols = matrix[0].size();
    deque<int> firstColumn, lastColumn; 
    deque<deque<int>*> rowPointers; 
    deque<int> deques[numRows];

    for (int i = 0; i < numRows; i++) {
        firstColumn.push_back(matrix[i][0]);
        lastColumn.push_back(matrix[i][numCols - 1]);
        copy(matrix[i].begin() + 1, matrix[i].begin() + numCols - 1, inserter(deques[i], deques[i].end()));
        rowPointers.push_back(&deques[i]);
    }

    for (auto& op : operations) {
        if (op == "Rotate") {
            rowPointers.front()->push_front(firstColumn.front());
            firstColumn.pop_front();
            lastColumn.push_front(rowPointers.front()->back());
            rowPointers.front()->pop_back();
            rowPointers.back()->push_back(lastColumn.back());
            lastColumn.pop_back();
            firstColumn.push_back(rowPointers.back()->front());
            rowPointers.back()->pop_front();
        }
        else {
            firstColumn.push_front(firstColumn.back());
            firstColumn.pop_back();
            rowPointers.push_front(rowPointers.back());
            rowPointers.pop_back();
            lastColumn.push_front(lastColumn.back());
            lastColumn.pop_back();
        }
    }

    vector<vector<int>> result; 
    vector<int> newRow;

    for (int i = 0; i < numRows; i++) {
        newRow.push_back(firstColumn[i]);
        for (int elem : *rowPointers.front()) {
            newRow.push_back(elem);
        }
        rowPointers.pop_front();
        newRow.push_back(lastColumn[i]);
        result.push_back(newRow);
        newRow.clear();
    }

    return result;
}
