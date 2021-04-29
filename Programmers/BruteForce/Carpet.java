package programmers.BruteForce;

public class Carpet {
    public int[] solution(int brown, int yellow) {
        // brown + yellow = garo*sero;
    	int garo = brown/2+2 - 3;
    	int sero = 3; // �ּҰ��� 3
    	int sum = brown+yellow;
    	
    	// ������ �ִ�
    	while(garo >= sero) {
    		if(garo*sero == sum) break;
    		garo++;
    		sero++;
    	}
        
        int[] answer = {garo, sero};
        return answer;
    }
}
