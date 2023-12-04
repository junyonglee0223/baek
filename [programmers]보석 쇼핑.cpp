#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> result = {1, static_cast<int>(gems.size())};
    int start = 0;
    int end = 0;
    int minDistance = gems.size() - 1;
    map<string, int> gemCount;
    int totalUniqueGems;

    for (string gem : gems) {
        gemCount[gem] += 1;
    }

    totalUniqueGems = gemCount.size();
    gemCount.clear();

    while (true) {
        if (gemCount.size() == totalUniqueGems) {
            if (end - start < minDistance) {
                minDistance = end - start;
                result[0] = start + 1;
                result[1] = end;
            }

            if (gemCount[gems[start]] == 1) {
                gemCount.erase(gems[start]);
                start++;
            } else {
                gemCount[gems[start]]--;
                start++;
            }
        } else if (end == gems.size()) {
            break;
        } else {
            gemCount[gems[end]]++;
            end++;
        }
    }

    return result;
}
