package programmers.Heap;

import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

public class Dequeque {
	public int[] solution(String[] operations) {
        int[] answer = {0, 0};
        
        List<Integer> dq = new LinkedList<>();
        
        for(String str: operations) {
        	switch(str.charAt(0)) {
        	case 'I': dq.add(Integer.parseInt(str.substring(2))); break;
        	case 'D':{
        		if(dq.isEmpty()) continue;
        		if(str.charAt(2) == '-')
        			dq.remove(0);
        		else
        			dq.remove(dq.size()-1);
        	}
        	}
        	Collections.sort(dq);
        }
        
        if(!dq.isEmpty()) {
        	answer[1] = dq.get(0);
        	answer[0] = dq.get(dq.size()-1);
        }
        return answer;
    }
}
