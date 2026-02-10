package g34853;

import java.io.*;
import java.util.*;

public class Main {
    
    static int lowerBoundCustom(int[] arr, int val){
        int left = 0;
        int right = arr.length - 1;

        if(val > arr[right])return -1;

        while(left < right){
            int mid = ((left + right) >> 1);
            if(arr[mid] < val){
                left = mid + 1;
            }
            else if(arr[mid] >= val){
                right = mid;
            }
        }
        return left;
    }

    static int countLowerEle(int[] arr1, int[] arr2, int[] arr3, int val){
        int larr1 = lowerBoundCustom(arr1, val);
        int larr2 = lowerBoundCustom(arr2, val);
        int larr3 = lowerBoundCustom(arr3, val);

        larr1 = (larr1 == -1 ? arr1.length : larr1);
        larr2 = (larr2 == -1 ? arr2.length : larr2);
        larr3 = (larr3 == -1 ? arr3.length : larr3);

        return larr1 + larr2 + larr3;
    }

    static int findValue(int[] arr1, int[] arr2, int[] arr3, int target){
        int minVal = Math.min(arr1[0], Math.min(arr2[0], arr3[0]));
        int maxVal = Math.max(arr1[arr1.length-1], Math.max(arr2[arr2.length-1], arr3[arr3.length-1]));
        int saveMaxVal = maxVal;

        while(minVal < maxVal){
            int midVal = (minVal + maxVal) / 2;

            int curCount = countLowerEle(arr1, arr2, arr3, midVal);

            if(curCount < target){
                minVal = midVal + 1;
            }else{
                maxVal = midVal;
            }
            //System.out.println("counting " + curCount + "/" + midVal);
        }

        //현재 같거나 큰 값을 반환하는 중
        int checkCount = countLowerEle(arr1, arr2, arr3, minVal);
        if(checkCount > target){
            minVal -= 1;
        }


        int idx1 = lowerBoundCustom(arr1, minVal);
        int idx2 = lowerBoundCustom(arr2, minVal);
        int idx3 = lowerBoundCustom(arr3, minVal);


        int ret = saveMaxVal;
        if(idx1 != -1){
            ret = Math.min(ret, arr1[idx1]);
        }
        if(idx2 != -1){
            ret = Math.min(ret, arr2[idx2]);
        }
        if(idx3 != -1){
            ret = Math.min(ret, arr3[idx3]);
        }
        return ret;
    }


    static void solutionThreeArrayAscending(int n, int q, List<int[]> listGroup, List<int[]> querys){

        for(int[] query : querys){
            int a = query[0]-1;
            int b = query[1]-1;
            int c = query[2]-1;
            int idx = query[3]-1;

            System.out.println(findValue(listGroup.get(a), listGroup.get(b), listGroup.get(c), idx));
        }
    }

    static void monoMain(BufferedReader br) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());

        List<int[]> listGroup = new ArrayList<int[]>();
        for(int i = 0; i<n; i++){
            st = new StringTokenizer(br.readLine());

            int eleSize = Integer.parseInt(st.nextToken());

            int[] eleList = new int[eleSize];

            for(int j = 0; j<eleSize; j++){
                eleList[j] = Integer.parseInt(st.nextToken());
            }

            //사전 입력 시 모든 배열 정렬
            Arrays.sort(eleList);
            listGroup.add(eleList);
        }

        List<int[]> querys = new ArrayList<int[]>();
        for(int i = 0; i<q; i++){
            st = new StringTokenizer(br.readLine());

            int[] curQuery = new int[4];
            for(int j = 0; j<4; j++){
                curQuery[j] = Integer.parseInt(st.nextToken());
            }
            querys.add(curQuery);
        }

        
        solutionThreeArrayAscending(n, q, listGroup, querys);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        monoMain(br);
        // int T = Integer.parseInt(br.readLine());

        // while(T-- > 0){
        //     System.out.println("------------");
        //     monoMain(br);
        // }
    }
}

/*
3
3 3
3 1 3 5
2 2 4
4 2 7 1 6
1 2 3 1
1 2 3 5
3 2 1 9
4 4
5 5 1 4 2 3
4 2 6 7 2
3 9 8 5
2 1 100
1 2 3 4
2 3 4 1
4 1 2 9
1 3 4 10
3 2
3 1 1 2
3 1 1 2
4 1 2 2 2
1 2 3 3
1 2 3 9
*/

/*
1
3
7

2
1
6
100

1
2
*/
/*
1
4 4
5 5 1 4 2 3
4 2 6 7 2
3 9 8 5
2 1 100
1 2 3 4
2 3 4 1
4 1 2 9
1 3 4 10

3
1
100
100
이런 결과가 나옴

1 2 3 4 5
2 2 6 7
5 8 9
1 2 100

---
1 2 3 4 5
2 2 6 7
5 8 9
(3index 원소) -> 2가 나와야 함
5 -> 6
3 -> 4
2 -> 1

---
1 2 3 4 5
2 2 6 7
1 2 100

(8 index)
50 -> 11
25 -> 11
13 -> 11
7 -> 10
4 -> 7
6 -> 9
5 -> 8






*/


    /*
    배열 3개 주어진 상황
    1 배열 자체를 돌면서

    하나의 기준점을 잡고 이진탐색으로 
    해당 위치를 알아내야 시초를 막을 수 있음

    전체 배열 3개를 합하고 산술하는 과정
    O(10^5 * log(10^5)) * (10^5)(전체 쿼리 개수)
    비효율

    j번째 배열의 값을 구하는 것임
    같은 원소가 존재할 수 있기 때문에
    작은 걸 기준으로 찾는다

    현재 값보다 작은 것의 개수를 찾는다
    작은 것의 개수가 j보다 작은 것중 가장 큰 값이 필요하다.

    해당 값을 찾고
    마지막 이진탐색 lower_bound 세번 사용해서 가장 가까운 값을
    찾아내면 된다.

    각각의 최대 최소의 value를 기준으로 이진탐색
    3 * O(log(10^9) * log(4 * 10^5))

    1 3 5
    2 4
    1 2 6 7
    예시가 이렇게 있다 가정하고
    0, 4, 8(나보다 작은 개수)를 찾아본다.

    최소 1, 최대 7 -> 4으로 시작
    1 + 1 + 2 -> 4 충분
    더 줄이기 2
    1 + 0 + 1 -> 2 부족 늘리기

    마지막 조건이 걸리는 부분이 있음
    같거나 크면 줄이고 작으면 늘리고

    마지막은 해당 값보다 큰 가장 작은 값을 배열에서 찾으면 됨

    (4) -> 5
    (3) -> 4
    (2) -> 2
    (1) -> 0 

    부족한 쪽으로 결과를 내야 함

    결론은 작은 쪽으로 가야함
    해당 값이 존재하지 않는 값일 수 있음
    */