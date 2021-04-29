package programmers.Heap;

import java.util.Arrays;
import java.util.PriorityQueue;

public class Spicier {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        Arrays.stream(scoville).boxed().forEach(sc -> pq.add(sc));
        
        while(pq.size()>=2) {
        	Integer least = pq.poll();
        	if(least >= K) return answer;

        	Integer less = pq.poll();
        	
        	pq.add(least+less*2);
            answer++;
        }
        
        if(pq.peek() >= K) return answer;
        else return -1;
    }
}
