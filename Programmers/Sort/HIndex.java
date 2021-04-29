package programmers.Sort;

import java.util.Arrays;

public class HIndex {
    public int solution(int[] citations) {
    	Arrays.sort(citations);
    	
    	int H = 0; int length = citations.length;
    	for(int i=0; i<length; i++) {
    		if(citations[i] > length - i-1) {
    			 H = length-i;break;
    		}
    	}
        return H;
    }
   
}
