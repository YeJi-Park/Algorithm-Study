package programmers.Sort;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class BiggestNumber {
    public String solution(int[] numbers) {
        String answer =   
        		Arrays.stream(numbers)
        		.mapToObj(n->Integer.toString(n))
        		.sorted((s1, s2)->{
        			return Integer.compare(Integer.parseInt(s2+s1),Integer.parseInt(s1+s2));
        		})
        		.collect(Collectors.joining());
        if(answer.charAt(0) == '0')  return "0";
        else return answer;
    }
}
