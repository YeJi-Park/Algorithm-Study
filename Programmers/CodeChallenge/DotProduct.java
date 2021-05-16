package programmers.codechallenge;

import java.util.Arrays;
import java.util.stream.StreamSupport;

public class DotProduct {
	
    public int solution(int[] a, int[] b) {
        int ans = 0, len = a.length;
        
        for(int i=0; i<len; i++) {
        	ans += (a[i]*b[i]);
        }
        
        return ans;
    }

}
