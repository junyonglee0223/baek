#include <string>
#include <vector>

#include <iostream>
using namespace std;

//return t1 < t2 -> true
bool compare(pair<int,int>t1, pair<int,int>t2){
    if(t1.first < t2.first)return true;
    if(t1.first == t2.first)return t1.second < t2.second ? true : false;
    return false;
}

pair<int,int>totime(string t){
    string hour = t.substr(0, 2);
    string minute = t.substr(3, 2);
    return {stoi(hour), stoi(minute)};
}
string toStrTime(pair<int,int>t){
    string ret;
    int hour = t.first;
    int minute = t.second;
    if(hour>=0 && hour<10)
        ret += "0";
    ret += to_string(hour);
    ret += ":";
    if(minute>=0 && minute<10)
        ret += "0";
    ret += to_string(minute);
    return ret;
}
pair<int,int>calcTime(pair<int,int> now, int t){
    pair<int,int> ret = now;
    ret.second += t;
    if(ret.second > 60){
        ret.first += 1;
        ret.second -= 60;
    }
    if(ret.second < 0){
        ret.first -=1;
        ret.second += 60;
    }
    return ret;
}

string solution(string video_len, string pos, string op_start, 
string op_end, vector<string> commands) {
    string answer = "";
    pair<int,int>start = {0, 0};
    pair<int,int>finish = totime(video_len);
    pair<int,int>op_start_time = totime(op_start);
    pair<int,int>op_end_time = totime(op_end);
    pair<int,int> now = totime(pos);

    for(auto cmd : commands){
        /**************************************** */
        //cout<<now.first<<" "<<now.second<<endl;//test
        /**************************************** */
        if(compare(calcTime(op_start_time, -1), now) 
        && compare(now, op_end_time)){
            now = op_end_time;
        }
        if(cmd == "next"){
            now = calcTime(now, 10);
            if(compare(finish, now)){
                now = finish;
            }
        }
        else if(cmd == "prev"){
            now = calcTime(now, -10);
            if(compare(now, start)){
                now = start;
            }
        }
        if(compare(calcTime(op_start_time, -1), now) 
        && compare(now, op_end_time)){
            now = op_end_time;
        }
    }
    answer = toStrTime(now);
    return answer;
}

// int main(){

// }