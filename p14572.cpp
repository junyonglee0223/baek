//p14572 스터디 그룹
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    int id;
    int ability;
    vector<int> probs;
};

long long solution_study_group_v1(){
    int N, K, D; cin>>N>>K>>D;
    //vector<int>problems(K+1);
    vector<Student>students;

    for(int i = 0; i<N; i++){
        int p_cnt, ability; 
        cin >> p_cnt >> ability;
        Student s;
        s.ability = ability;

        for(int j = 0; j<p_cnt; j++){
            int p_ele; cin>>p_ele;
            s.probs.push_back(p_ele);
        }
        students.push_back(s);
    }

    sort(students.begin(), students.end(), [&](Student a, Student b){
        return a.ability < b.ability;
    });

    
    //index, left, right 설정
    int left = 0, right = 0;

    //현재 추가 abi보다 left의 abi가 작다면 erase
    /*추가 삭제 구현을 했는데 문제를 처리하는 방식에서 문제 카운팅 방식을 다르게 할 수 있다.
    */
    //cnt -> 각 문제 개수  bucket 현재 개수 인 문제 
    //add problem -> 
    vector<int>cnt(K+1, 0);
    vector<int>bucket(N+1, 0);
    bucket[0] = K;
    
    auto add_problem = [&](int p){
            int c = cnt[p];
            cnt[p] = c+1;
            bucket[c]--;
            bucket[c+1]++;
    };
    auto erase_problem = [&](int p){
        int c = cnt[p];
        bucket[c]--;

        cnt[p] = c-1;
        bucket[c-1]++;
    };
    
    auto add_student = [&] (int idx){
        for(auto p_e : students[idx].probs){
            add_problem(p_e);
        }
    };
    
    auto erase_student = [&](int idx){
        for(auto p_e : students[idx].probs){
            erase_problem(p_e);
        }
    };

    long long ans = 0;

    for(int right = 0; right<N; right++){
        Student cur = students[right];
        // 현재 학생과 가장 실력 차이가 많이 나는 학생을 제거
        while(left <= right && students[right].ability - students[left].ability > D){
            erase_student(left);
            left++;
        }
        // 현재 학생 추가
        add_student(right);

        int w = right - left + 1;
        int at_least = K - bucket[0];
        int at_all = bucket[w];
        ans = max(ans, (long long)(at_least - at_all) * w);
    }

    //right 증가시 Stu 추가 로직 problems 추가

    return ans;
}

int main() {
    cout << solution_study_group_v1() << "\n";
    return 0;
}
