package programmers.Stack;

import java.util.ArrayList;
import java.util.List;

public class FunctionDevelopment {
    public static int[] solution(int[] progresses, int[] speeds) {
        List<Integer> l = new ArrayList<>();
        int[] answer = new int[progresses.length];
        
        int days = 0;
        
        for(int i=0; i<progresses.length; i++) {
        	int p = progresses[i] + days*speeds[i];
        	if(p<100) {
        		while(p>=100) {p+= speeds[i]; days++;}
        		l.add(1);
        	}else {
        		l.set(l.size()-1, l.get(l.size()-1)+1);
        	}
        	
        	answer[i] = days;
        }
        
        return l.stream().mapToInt(i -> i).toArray();
    }
}
