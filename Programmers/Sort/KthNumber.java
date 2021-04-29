package programmers.Sort;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class KthNumber {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        
        List<Integer> list = new ArrayList<>();
        
        int idx = 0;
        for(int[] cmd : commands) {
        	list.clear();
        	for(int i=cmd[0]-1; i<cmd[1]; i++)
        		list.add(array[i]);
        	Collections.sort(list);
        	answer[idx++] = list.get(cmd[2]-1);
        }
        return answer;
    }
}
