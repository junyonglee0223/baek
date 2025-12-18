package g30037;

import java.io.*;
import java.util.*;

public class Main {

    static Set<Character> punctuationMarks;

    static boolean canConvertStr(String str) {
        for (int i = 0; i < str.length(); i++) {
            char ele = str.charAt(i);
            if (punctuationMarks.contains(ele)) return false;
        }
        return true;
    }

    static boolean isPuncToken(String tok) {
        return tok.length() == 1 && punctuationMarks.contains(tok.charAt(0));
    }

    static List<String> convertStrAsToken(String inputStr) {
        List<String> strList = new ArrayList<>();
        StringTokenizer st = new StringTokenizer(inputStr);

        while (st.hasMoreTokens()) {
            String ele = st.nextToken();
            char eleLast = ele.charAt(ele.length() - 1);
            if (punctuationMarks.contains(eleLast)) {
                String word = ele.substring(0, ele.length() - 1);
                String punc = ele.substring(ele.length() - 1);
                strList.add(word);
                strList.add(punc);
                continue;
            }
            strList.add(ele);
        }
        return strList;
    }

    static String changeSmall2Large(String str) {
        String firstStr = str.substring(0, 1);
        String restStr = str.substring(1);
        StringBuilder sb = new StringBuilder();
        sb.append(firstStr.toUpperCase()).append(restStr);
        return sb.toString();
    }

    static String changeLarge2Small(String str) {
        String firstStr = str.substring(0, 1);
        String restStr = str.substring(1);
        StringBuilder sb = new StringBuilder();
        sb.append(firstStr.toLowerCase()).append(restStr);
        return sb.toString();
    }

    static List<String> convertStrAsRule1(List<String> strList) {
        for (int i = strList.size() - 2; i >= 0; i--) {
            String cur = strList.get(i);
            String next = strList.get(i + 1);

            if (!cur.equals("Korea")) continue;
            if (!canConvertStr(next)) continue;

            String newWord = "K-" + changeSmall2Large(next);
            strList.set(i, newWord);
            strList.remove(i + 1);
        }
        return strList;
    }

    static List<String> convertStrAsRule2(List<String> strList) {
        List<String> ret = new ArrayList<>();
        int lastIdxRet = -1;

        for (int i = 0; i < strList.size(); i++) {
            String curEle = strList.get(i);

            if (curEle.equals("of")) {

                if (i + 1 < strList.size() && isPuncToken(strList.get(i + 1))) {
                    ret.add(curEle);
                    lastIdxRet++;
                    continue;
                }

                if (lastIdxRet == -1 || i == strList.size() - 1) {
                    ret.add(curEle);
                    lastIdxRet++;
                    continue;
                }

                String prevStr = ret.get(lastIdxRet);
                if (!canConvertStr(prevStr)) {
                    ret.add(curEle);
                    lastIdxRet++;
                    continue;
                }

                String nxtStr = strList.get(i + 1);
                if (!nxtStr.equals("Korea")) {
                    ret.add(curEle);
                    lastIdxRet++;
                    continue;
                }

                boolean hasPuncAfterKorea = (i + 2 < strList.size()) && isPuncToken(strList.get(i + 2));
                String punc = hasPuncAfterKorea ? strList.get(i + 2) : null;

                ret.remove(lastIdxRet);
                String createNewStr = "K-" + changeSmall2Large(prevStr);
                ret.add(createNewStr);
                lastIdxRet = ret.size() - 1;

                if (punc != null) {
                    ret.add(punc);
                    lastIdxRet = ret.size() - 1;
                    i += 2;
                    continue;
                }

                i += 1;
                continue;
            }

            ret.add(curEle);
            lastIdxRet++;
        }
        return ret;
    }

    static String convertStr(String inputStr) {
        List<String> strList = convertStrAsToken(inputStr);

        if (strList.contains("of")) {
            strList = convertStrAsRule2(strList);
        }

        if (strList.contains("Korea")) {
            strList = convertStrAsRule1(strList);
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < strList.size(); i++) {
            String tok = strList.get(i);
            boolean isPunc = isPuncToken(tok);

            if (sb.length() > 0 && !isPunc) sb.append(" ");
            sb.append(tok);
        }
        return sb.toString();
    }

    static List<String> solutionKWords(BufferedReader br) throws Exception {
        int n = Integer.parseInt(br.readLine());
        List<String> result = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            String line = br.readLine();
            result.add(convertStr(line));
        }
        return result;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        punctuationMarks = new HashSet<>();
        punctuationMarks.add('.');
        punctuationMarks.add(',');
        punctuationMarks.add('?');
        punctuationMarks.add('!');

        List<String> ret = solutionKWords(br);
        for (String str : ret) {
            System.out.println(str);
        }
    }
}


/*
7
Artichoke in Korea Army uses Aheui.
Aheui, the best language of Korea.
Korea is our country.
of Korea? Korea Korea Aheui of Korea.
Language of, Korea Korea.
Aheui has shown the greatness of Korea of Korea.
korea Korea! koRea Of Korea of Korea oF kORea.
*/
/*
Artichoke in K-Army uses Aheui.
Aheui, the best K-Language.
K-Is our country.
of Korea? K-K-K-Aheui.
Language of, K-Korea.
Aheui has shown the K-K-Greatness.
korea Korea! koRea Of K-Korea oF kORea.
*/