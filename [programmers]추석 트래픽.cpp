#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

int timeToMilliseconds(string time) {
    int hh = stoi(time.substr(11, 2));
    int mm = stoi(time.substr(14, 2));
    int ss = stoi(time.substr(17, 2));
    int sss = stoi(time.substr(20, 3));
    return ((hh * 3600 + mm * 60 + ss) * 1000) + sss;
}

int solution(vector<string> lines) {
    vector<pair<int, int>> intervals;

    for (string line : lines) {
        string timeStr = line.substr(0, 23); 
        string durationStr = line.substr(24); 

        int endTime = timeToMilliseconds(timeStr);
        
        durationStr.pop_back(); 
        double duration = stod(durationStr); 
        int durationMs = (int)(duration * 1000);
        
        int startTime = endTime - durationMs + 1;
        intervals.push_back({startTime, endTime});
    }

    int maxCount = 0;

    for (int i = 0; i < intervals.size(); i++) {
        int currentEndTime = intervals[i].second;
        int oneSecondLater = currentEndTime + 1000; 
        
        int count = 0;
        for (int j = 0; j < intervals.size(); j++) {
            if (intervals[j].first < oneSecondLater && intervals[j].second >= currentEndTime) {
                count++;
            }
        }
        
        maxCount = max(maxCount, count); 
    }

    return maxCount;
}
