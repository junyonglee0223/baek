#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int N;
bool isPoswin(long long maxHp, long long curHp, long long atk, vector<vector<long long>>dungeons){
    int n = dungeons.size();
    for(int i = 0; i<n; i++){
        long long type = dungeons[i][0];
        //cout<<dungeons[i][0]<<" "<<dungeons[i][1]<<" "<<dungeons[i][2]<<endl;//test
        
        if(type == 1LL){
            long long a = dungeons[i][1];
            long long h = dungeons[i][2];

            // while(true){
            //     //cout<<h<<" "<<curHp<<endl;//test
            //     h -= atk;
            //     if(h <= 0LL)break;
            //     curHp -= a;
            //     if(curHp <= 0LL)return false;
            // }
            long long pCnt = (h % atk == 0) ? h/atk : (h/atk)+1;
            //long long mCnt = (curHp % a == 0) ? curHp/a : (curHp/a)+1;
            if(curHp - (pCnt-1)*a <= 0)return false;
            curHp -= (pCnt-1) * a;
        }
        else if(type == 2LL){
            long long a = dungeons[i][1];
            long long h = dungeons[i][2];

            atk += a;
            curHp = (curHp + h) >= maxHp ? maxHp : curHp + h;
        }
        else{
        }
        //cout<<"finish first\t"<<curHp<<endl;//test
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long hatk;
    cin>>N>>hatk;

    vector<vector<long long>>dungeons;
    for(int i = 0; i<N; i++){
        //1, 공격력, 생명력
        //2, 공격력(up), 생명력(up)
        long long a, b, c; cin>>a>>b>>c;
        vector<long long>tmp;
        tmp.push_back(a);
        tmp.push_back(b);
        tmp.push_back(c);
        dungeons.push_back(tmp);
    }


    //cout<<"{final result}\n"<<isPoswin(49, 49, hatk, dungeons)<<endl;//test
    long long left = 0;
    long long right = LLONG_MAX;
    while(left < right){
        long long mid = (left + right)/2;
        if(isPoswin(mid, mid, hatk, dungeons)){
            right = mid;
        }
        else{
            left = mid + 1LL;
        }
    }
    cout<<right<<endl;
}