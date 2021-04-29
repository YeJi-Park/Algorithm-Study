package programmers.Stack;

import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.stream.Collectors;

public class Printer {
	class Print{
		private int prio;
		private int loc;
		
		public Print(int prio, int loc) { this.prio = prio; this.loc = loc; }
	}
	
    public int solution(int[] priorities, int location) {    	
    	Queue<Print> q = new LinkedList<>();
    	
    	int i=0;
    	for(int p : priorities) {
    		q.add(new Print(p, i++));
    	}
    	
    	List<Integer> list = Arrays.stream(priorities)
    							.boxed()
    							.sorted(Comparator.reverseOrder())
    							.collect(Collectors.toList());
    	
    	for(i=0; i<list.size(); i++) {
    		while(q.peek().prio != list.get(i)) q.add(q.poll());
    		
    		if(q.peek().loc == location)
    			break;
    		q.poll();
    	}
    	
    	return i+1;
    }
}
