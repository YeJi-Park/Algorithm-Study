package programmers.BruteForce;

public class Carpet {
    public int[] solution(int brown, int yellow) {
        // brown + yellow = garo*sero;
    	int garo = brown/2+2 - 3;
    	int sero = 3; // 최소값이 3
    	int sum = brown+yellow;
    	
    	// 가로의 최댓값
    	while(garo >= sero) {
    		if(garo*sero == sum) break;
    		garo++;
    		sero++;
    	}
        
        int[] answer = {garo, sero};
        return answer;
    }
}
