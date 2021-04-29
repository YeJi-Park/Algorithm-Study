package programmers.Hash;

import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Arrays;

public class NotFinishedPlayer {
	
    public static String solution_MINE(String[] participant, String[] completion) {
        List<String> p = Arrays.asList(participant);
        List<String> c = Arrays.asList(completion);

        Collections.sort(p); Collections.sort(c);

        for(int i=0; i<p.size()-1; i++) {
            if(!p.get(i).equals(c.get(i)))
                return p.get(i);
        }

        return p.get(p.size()-1);
    }
    
    public String solution_Others(String[] participant, String[] completion) {
    	String answer = "";
    	
    	Map<String, Integer> m = new HashMap<>();
    	for(String p : participant)
    		m.put(p, m.getOrDefault(p, 0)+1);
    	
    	for(String c : completion)
    		m.put(c, m.getOrDefault(c, 0)-1);
    	
    	for(Entry<String, Integer> e : m.entrySet()) {
    		if(e.getValue() != 0) {
    			answer = e.getKey();
    			break;
    		}
    	}
    	
    	return answer;
    }

}
