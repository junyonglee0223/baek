
    //1시간 시침 분침 만나는 횟수 -> 59회
    //1시간 초침 시침 만나는 횟수 -> 60회
    //1시간 분침 시침 만나는 횟수 -> 1회
    //시침 각도 -> (h + m / 60.0 + s / 3600.0)
    //분침 각도 -> (m + s / 60.0)
    //초침 각도 -> 
     // 시침과 초침이 겹치는 횟수: 시간당 60번 (h * 60)
    // 분침과 초침이 겹치는 횟수: 시간당 59번 (h * 59)
    //m분 동안 초침이 시침과 분침과 만나는 횟수 2번
#include <string>
#include <vector>

int cnt_clock(int h, int m, int s){
    if(h==0 && m==0 && s==0)
        return 0;

    if(h>=12)
        return cnt_clock(11, 59, 59) + cnt_clock(h-12, m, s);

    int ret = (h*59 + h*60 + m*2 - 1);
    if(5*(h + m/60.0 + s/3600.0)<s)
        ret++;
    if((m + s/60.0) < s)
        ret++;
    return ret;
}


int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = -1;

    answer = cnt_clock(h2, m2, s2) - cnt_clock(h1, m1, s1);
    if (5 * (h2 % 12 + m2 / 60.0 + s2 / 3600.0) == s2 || m2 + s2 / 60.0 == s2) {
        answer += 1;
    }
    return answer;
}





