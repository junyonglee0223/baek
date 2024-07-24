#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <set>
using namespace std;
typedef pair<int,int>p;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<p>max_heap;
    priority_queue<p>min_heap;
    set<int>delete_set;

    for(int i = 0; i<operations.size(); i++){
        string oper = operations[i];
        if(oper[0] == 'I'){
            string tmp = oper.substr(2);
            int tmpn = stoi(tmp);
            max_heap.push({tmpn, i});
            min_heap.push({-tmpn, i});
        }
        else if(oper[0] == 'D'){
            string tmp = oper.substr(2);
            int tmpn = stoi(tmp);
            if(tmpn == 1){
                if(!max_heap.empty()){
                    delete_set.insert(max_heap.top().second);
                    max_heap.pop();
                }
            }
            else if(tmpn == -1){
                if(!min_heap.empty()){
                    delete_set.insert(min_heap.top().second);
                    min_heap.pop();
                }
            }
            else{
                continue;
            }
        }
        else{
            continue;
        }

        while(!max_heap.empty()){
            int check_idx = max_heap.top().second;
            if(delete_set.find(check_idx) == delete_set.end()){
                break;
            }
            max_heap.pop();
        }
        while(!min_heap.empty()){
            int check_idx = min_heap.top().second;
            if(delete_set.find(check_idx) == delete_set.end()){
                break;
            }
            min_heap.pop();
        }
    }

    int max_ret = 0;
    int min_ret = 0;
    if(!max_heap.empty()){
        max_ret = max_heap.top().first;
        min_ret = -min_heap.top().first;
    }
    answer.push_back(max_ret);
    answer.push_back(min_ret);
    
    return answer;
}