package programmers.Hash;

import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class PhoneNumberList {
	
    public static boolean solution(String[] phone_book) {
        boolean answer = true;
        
        Set<String> m = new HashSet<String>(Arrays.asList(phone_book));
        
        for(String n : phone_book) {
        	for(int i=1; i<n.length(); i++) {
        		if(m.contains(n.substring(0, i))) return false;
        	}
        }
        
        return answer;
    }

}
