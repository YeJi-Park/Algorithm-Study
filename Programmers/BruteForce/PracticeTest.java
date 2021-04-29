package programmers.BruteForce;

import java.util.Arrays;

public class PracticeTest {
    public int[] solution(int[] answers) {
        int[] st = {0,0,0};
        int[] st_2 = {2,1,2,3,2,4,2,5};
        int[] st_3 = {3,3,1,1,2,2,4,4,5,5};
        int length = answers.length;
        
        for(int i=0; i<length; i++) {
        	int ans = answers[i];
        	if(ans == (i%5+1)) st[0]++;
        	if(i%2 == 0)
        		if(ans == 2) st[1]++;
        	else {
        		if(ans == st_2[i%8]) st[1]++;
        	}
        	if(ans == st_3[i%10]) st[3]++;
        }
        
        int max = Math.max(Math.max(st[0], st[1]), st[2]);
        int index = 0;
        int[] answer = new int[3];
        for(int i=0; i<3; i++) {
        	if(max == st[i]) answer[index++] = i;
        }
        
        return Arrays.copyOf(answer, index-1);
    }
}
