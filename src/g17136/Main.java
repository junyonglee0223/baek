package g17136;

/*
 * 색종이 붙이기
 *
 * 문제 요약
 * 크기가 1, 2, 3, 4, 5 정사각형 모양의 색종이를 각각 5장 가지고 있음.
 * 이를 가지고 도화지에 1이 적혀있는 값만을 색종이로 덮을 예정
 * 최소 색종이만 사용해 모두 덮을 때 값 출력, 불가능하면 -1 출력
 *
 * 문제 풀이
 * 왼쪽 상단에서 시작해서
 * 0 - 스킵
 * 1 - 여기에서 시작해서 각 점에서 시작하는 bfs를 돌림
 * 스텝별로 1인 값은 모두 1이여야지 크기가 2인 색종이 사용 가능.
 * 2인값은 모두 1여야지 크기가 3인 색종이 사용 가능..
 * 이렇게 해서 색종이 개수를 카운팅, 부분별로도 따로 카운팅
 * 전에 왔던 방향에 따라 달라짐
 * 0 -> 0, 1 선택
 * 1 -> 선택하지 않음.
 * 2 -> 1 2 선택
 *
 * 위에 대해 반례가 존재함.
 * 만약, 6 * 6에 1이 모두 있다면?
 * 따라서, 단순 bfs를 하고 그리디하게 사각형을 최대한으로 해서 선택하면 답이 틀리게 된다.
 * 가능 여부에 따라 1, 2, 3, 4, 5 각각에 대해 검증하고, 만약에 된다면, 다음 단계로 넘어간다.
 * 만약, 그러다가 모든 색종이를 사용했다면, 다시 리턴한다. 리턴할 때에는, 이전에 방문했던 노드를 저장한
 * queue에서 팝하면서, 복원하자.
 *
 * 사용 알고리즘
 * - dfs - 각 색종이 한장을 사용하는 단계에서 사용. 만약 모두 사용했다면 리턴.
 * - 만약 모든 1을 없앴다면, 전역변수 ans에 업데이트하고, 리턴
 * - dfs 속 bfs - 색종이 칸을 결정하는 bfs. 1이 발견되면, 큐를 이용해서 Point값을 저장하고, 칸을 1씩 늘리면서
 * 색종이 가능 여부를 판단한다. 1, 2, 3, 4, 5 각 단계에서 dfs를 이용해서 보내고, 더이상 커질 수 없을 때(5 혹은 1이 없을 때)
 * + dfs를 모두 탐색했을 때에는 queue에 저장되어 있는 point값을 이용해 복원한다.
 * - bfs의 경우, dfs에 잘 녹여 잇어야 함. 한 스텝별로 탐색만 진행하고, 백트래킹할 때에도 가지고 잇어야 하므로.
 * - 따라서, 구현체는 두가지 방향이 가능함 1. 큐, 방문 리스트를 가지고 있다가 넘겨주는 방식, 2. dfs에 통합처리
 * - 격자그래프에서 삼방탐색(아래, 오른쪽 아래, 오른쪽) - bfs 단계에서 사용
 *
 * 사용 자료구조
 * queue
 */

import java.io.*;
import java.util.*;

public class Main {
    static final int[] dx = {0, 1, 1};
    static final int[] dy = {1, 1, 0};
    static final int border = 10;
    static final int empty = 0;
    static final int one = 1;

    static int[][] arr;
    static int[] cnt = {0, 5, 5, 5, 5, 5}; // 색종이 남은 개수 카운팅
    static int ans = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        arr = new int[border][border];

        for (int i = 0; i < border; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < border; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        System.out.println(solution());
    }

    static class Point {
        int x, y, step;
        Point(int x, int y, int step) {
            this.x = x;
            this.y = y;
            this.step = step;
        }
    }

    static int solution() {
        int[] areaCount = {0, 5, 5, 5, 5, 5};
        dfs(areaCount);
        if (ans == Integer.MAX_VALUE) ans = -1;
        return ans;
    }

    static boolean isInside(int x, int y) {
        return x >= 0 && x < border && y >= 0 && y < border;
    }

    static boolean isArea(int x, int y, int size){
        int e_x = x + size - 1;
        int e_y = y + size - 1;
        if(!isInside(e_x, e_y)) return false;
        for(int i = x; i<=e_x; i++){
            for(int j = y; j <= e_y; j++){
                if(arr[j][i] == empty) return false; // arr[y][x]
            }
        }
        return true;
    }

    static void updateArea(int x, int y, int size){
        int e_x = x + size - 1;
        int e_y = y + size - 1;
        for(int i = x; i<=e_x; i++){
            for(int j = y; j <= e_y; j++){
                arr[j][i] = empty; // 1 -> 0
            }
        }
    }

    static void updateArea_rev(int x, int y, int size){
        int e_x = x + size - 1;
        int e_y = y + size - 1;
        for(int i = x; i<=e_x; i++){
            for(int j = y; j <= e_y; j++){
                arr[j][i] = one; // 0 -> 1
            }
        }
    }

    static void dfs(int[] areaCount) {
        int used = 0;
        for (int s = 1; s <= 5; s++) used += 5 - areaCount[s];
        if (used >= ans) return;

        int fy = -1, fx = -1;
        for (int i = 0; i < border; i++) {
            for (int j = 0; j < border; j++) {
                if (arr[j][i] == 1) {
                    fx = i;
                    fy = j;
                    i = border;
                    break;
                }
            }
        }

        if (fy == -1) {
            ans = Math.min(ans, used);
            return;
        }

        for (int size = 5; size >= 1; size--) {
            if (areaCount[size] == 0) continue;
            if (!isArea(fx, fy, size)) continue;

            updateArea(fx, fy, size);
            areaCount[size]--;
            dfs(areaCount);
            areaCount[size]++;
            updateArea_rev(fx, fy, size);
        }
    }
}

/*
0 0 0 0 0 0 0 0 0 0
0 1 1 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0
0 0 0 0 1 1 0 0 0 0
0 0 0 0 0 1 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
 */
/*
-1
 */
/*
0 0 0 0 0 0 0 0 0 0
0 1 1 0 0 0 0 0 0 0
0 1 1 1 0 0 0 0 0 0
0 0 1 1 1 1 1 0 0 0
0 0 0 1 1 1 1 0 0 0
0 0 0 0 1 1 1 0 0 0
0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
 */
/*
7
 */
