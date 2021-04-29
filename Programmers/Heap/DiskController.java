package programmers.Heap;

import java.util.Arrays;
import java.util.PriorityQueue;

public class DiskController {
	
    public int solution(int[][] jobs) {
        int answer = 0;
        
        // ���� �ð� ������ ����
        Arrays.sort(jobs, (o1, o2)->{
        	return Integer.compare(o1[0], o2[0]);
        });
        
        // q�� takes�� ª�� ������ ������
        PriorityQueue<int[]> pq = new PriorityQueue<>((i1, i2)-> {
        	return Integer.compare(i1[1], i2[1]);
        });
        
        int time = 0; // ���� �ð�
        int i = 0;
        while(i<jobs.length || !pq.isEmpty()) {
        	while(i<jobs.length && time>=jobs[i][0]) pq.add(jobs[i++]);
        	
        	if(pq.isEmpty() ) // ���� ������ task�� ������ �ð� ������ task �� ���
        	{ 
        		time = jobs[i][0]; 
        	}else {
        		int[] t = pq.poll();
        		answer += (time-t[0])+t[1];
        		time += t[1];
        	}
        }
        return answer/jobs.length;
    }
}
