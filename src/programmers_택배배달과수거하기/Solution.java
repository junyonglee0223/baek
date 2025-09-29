package programmers_택배배달과수거하기;

class Solution {

    static void visit_far(int last_idx, int[] arr, int cap){
        int rest = cap;
        int idx = last_idx;
        while(idx >= 0){
            int nxt_rest = rest - arr[idx];
            if(nxt_rest <= 0){
                arr[idx] -= rest;
                break;
            }
            rest = nxt_rest;
            arr[idx] = 0;
            idx--;
        }
    }

    static int update_last_idx(int last_idx, int[] de, int[] pi){
        int ret = last_idx;
        while(ret >= 0 && de[ret] == 0 && pi[ret] == 0){
            ret--;
        }
        return ret;
    }

    public long solution(int cap, int n, int[] deliveries, int[] pickups) {
        //last idx 설정
        //총 이동거리 저장변수
        int last_idx = n-1;
        last_idx = update_last_idx(last_idx, deliveries, pickups);
        long del_cnt = 0;

        //last_idx가 음수일때까지 모든게 0일 때까지 반복한다.
        while(true){
            if(last_idx < 0)break;
        //0 -> last 배달 가능한 개수 설정
            del_cnt += (last_idx + 1) * 2;

            //idx까지만 check하면 됨
            //현재 원소가 cap을 초과하면 현재에 반영
            //cap에 딱 맞다면 그거도 반영
            //마지막 원소의 idx와 차이만 필요함

            visit_far(last_idx, deliveries, cap);
            visit_far(last_idx, pickups, cap);


            last_idx = update_last_idx(last_idx, deliveries, pickups);
        }
        return del_cnt;
    }
}
/*
그리디 하게 접근하는 문제라고 생각한다.
최소 거리를 찾는 문제기 때문에 거리가 먼 집을 한번에 여러 태스크를 처리하는게
최적이다.
n이 10 ^ 5이기 때문에 계속 탐색하는 방법은 비효율적이다.
lastidx까지 가면서 수거하는 방식도 필요없다.
0 -> last : 배달
last -> 0 : 수거

 */