package g29737;

import java.io.*;
import java.util.*;

public class Main {
    static int N, W;
    static int H = 7;
    static class NODE implements Comparable<NODE>{
        int len, fCnt, start;
        NODE(){}
        NODE(int len, int fCnt, int start){
            this.len = len;
            this.fCnt = fCnt;
            this.start = start;
        }
        @Override
        public int compareTo(NODE other){
            if(this.len == other.len){
                if(this.fCnt == other.fCnt)return this.start - other.start;
                return this.fCnt - other.fCnt;
            }
            return other.len - this.len;
        }
    }
    static class PERNODE implements Comparable<PERNODE>{
        String name;
        int len, fCnt, start;
        int failCnt;
        PERNODE(String name, int len, int fCnt, int start, int failCnt){
            this.name = name;
            this.len = len;
            this.fCnt = fCnt;
            this.start = start;
            this.failCnt = failCnt;
        }
        @Override
        public int compareTo(PERNODE other){
            if(this.len == other.len){
                if(this.fCnt == other.fCnt){
                    if(this.start == other.start){
                        //if(this.failCnt == other.failCnt)return this.name.compareTo(other.name);
                        return this.failCnt - other.failCnt;
                    }
                    return this.start - other.start;
                }
                return this.fCnt - other.fCnt;
            }
            return other.len - this.len;
        }
    }


    static PERNODE calcPerson(String name, String[] data){
        List<NODE>nodeList = new ArrayList<>();
        //idx = 7*i+j;
        int failCnt = 0;
        int start = 0;
        int cnt = 0;

        for(int i = 0 ;i<W; i++){
            for(int j = 0; j<H; j++){
                int curIdx = H*i+j;
                if(data[j].substring(i, i+1).equals("X")){
                    start = curIdx + 1;
                    failCnt++;
                    cnt = 0;
                }
                else if(data[j].substring(i, i+1).equals("F")){
                    if(start == curIdx){start++; cnt = 0;}
                    else cnt++;
                }
                else{
                    nodeList.add(new NODE(curIdx - start-cnt+1, cnt, start));
                }
            }
        }
        // int lastIdx = W*H;
        // if(start < lastIdx){
        //     nodeList.add(new NODE(lastIdx-start-cnt, cnt, start));
        // }
        Collections.sort(nodeList);

        // System.out.println("!!!!!!!!!!!!!!!!!!!!!"+name);
        // for(NODE n : nodeList){
        //         System.out.println("len="+n.len+" fcount="+n.fCnt+" start="+n.start);
        //     }
        // System.out.println("!!!!!!!!!!!!!!!!!!!!!"+name);
        
        if(nodeList.isEmpty()){
            return new PERNODE(name, 0, 0, H * W, failCnt);
        }

        NODE ret = nodeList.get(0);
        return new PERNODE(name, ret.len, ret.fCnt, ret.start, failCnt);
    }
    
    static void solutionBsilLovesGrass(BufferedReader br) throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        W = Integer.parseInt(st.nextToken());
        
        List<PERNODE>personList = new ArrayList<>();
        for(int i = 0; i<N; i++){
            String curName = br.readLine();
            String[] curData = new String[H];
            for(int j = 0; j<H; j++){
                curData[j] = br.readLine();
            }
            PERNODE curPerson = calcPerson(curName, curData);
            personList.add(curPerson);
        }
        Collections.sort(personList, new Comparator<PERNODE>() {
            @Override
            public int compare(PERNODE a, PERNODE b){
                if(a.compareTo(b) == 0){
                    return a.name.compareTo(b.name);
                }
                return a.compareTo(b);
            }
        });
        // System.out.println("!!!!!!!!!!!!!!!!!!!!!");
        // for(int i = 0; i<N; i++){
        //     PERNODE n = personList.get(i);
        //     System.out.println("name = "+n.name+" len="+n.len+" fcount="+n.fCnt+" start="+n.start);

        // }
        // System.out.println("!!!!!!!!!!!!!!!!!!!!!");
        int[] personLevel = new int[N];
        personLevel[0] = 1;
        for(int i = 1; i<N; i++){
            PERNODE person = personList.get(i);

            if(i > 0){
                PERNODE prePerson = personList.get(i-1);
                if(prePerson.compareTo(person) == 0){
                    personLevel[i] = personLevel[i-1];
                    continue;
                }
            }
            personLevel[i] = personLevel[i-1] + 1;
            //System.out.println((i+1)+". "+person.name);
        }

        for(int i = 0; i<N; i++){
            PERNODE person = personList.get(i);
            System.out.println(personLevel[i]+". "+person.name);
        }

    }
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        solutionBsilLovesGrass(br);

        // int T = Integer.parseInt(br.readLine());
        // while(T-- > 0){
        //     System.out.println("answer =");
        //     solutionBsilLovesGrass(br);
        // }
        
    }
}
/*
정보의 첫 번째 줄에는 브실이 친구의 아이디 
$S$가 주어지며, 두 번째 줄부터 친구의 스트릭이 가로 
$W$줄 세로 
$7$줄 
$7 \times W$ 형태로 주어진다. 
$i$행 
$j$열은 
$7j + i + 1$번째 날을 나타낸다.


가장 긴 최장 스트릭을 가진 친구
최장 스트릭 내의 더 적은 개수의 스트릭 프리즈를 사용한 친구
최장 스트릭을 시작한 날짜가 더 이른 친구
스트릭 프리즈 사용한 날짜를 제외하고 스트릭 달성에 실패한 날짜 수가 적은 친구

N, W가 100 이하임 (스트릭 길이, 프리즈 개수, 시작 위치), 실패 개수 
위 3가지 원소가 하나의 클래스로 작동되고 실패 개수는 개인의 변수로 설정
노드 정렬로 최대 찾고 해당 노드와 실패 개수로 추가 노드를 설정해서 순서 구현

처음 주어진 문자열 가지고 최대 노드와 실패 카운팅한 객체를 return 하는 메서드 필요


 */
/*
2
2 4
baekjoon
OOOF
XOOO
OOFO
OOOO
OOOF
OFOO
XOOO
shiftpsh
XOOO
OOOO
OOFO
OOOO
OOOO
OOOO
XOOO

3 9
nonickname
OOOOOFOOO
XOOFOOFOO
OOOFOOXOO
OOFOOOOOO
OOOOOOOOO
OOOOOOOOO
OOOOOOOOO
baekjoon
OOOOOOOOO
OOOOFOOOO
OXOOOOOXO
OOOOOFOOO
OOFOOFOOO
OOFOOOOOO
OOOOOOOOO
shiftpsh
OOOOOOOOO
OOOOFOOOO
OOFOOOOOO
OOOOFOOOO
OFOOOOOOO
XOOOFOXOO
OOOOOOOOO
 */
/*
1. shiftpsh
2. baekjoon
 */
/*
1. nonickname
2. shiftpsh
3. baekjoon
 */