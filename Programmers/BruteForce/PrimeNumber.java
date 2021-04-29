package programmers.BruteForce;

import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.Set;

public class PrimeNumber {
	
	Set<Integer> s = new HashSet<Integer>();
	
    public int solution(String numbers) {
        int answer = 0;
        int size = numbers.length();
        char[] chars = numbers.toCharArray();
        
        Arrays.sort(chars);
        
        // ���� ū ���ڰ� 0�̶�� �Ҽ�x
        if(chars[size-1] == 0) return 0;
        
        int max = 0;
        for(int i=size-1; i>=0; i--) {
        	max *= 10;
        	max += chars[i] - '0';
        }
        
        // ���� ū ���ڱ����� prime ���ϱ�
        boolean[] prime = new boolean[max+1];
        Arrays.fill(prime, true);
        
        isPrime(prime, max);
        
        // set�� �־�
        makePermutation("", numbers);
        
        for(Integer i : s) {
        	if(prime[i]) answer++;
        }
        
        return answer;
        
    }
    
    private void isPrime(boolean[] prime, int num) {
    	prime[0] = prime[1] = false; //�Ҽ� �ƴ�
    	double sqrt = Math.sqrt(num);
    	
    	for(int i=2; i<=sqrt; i++) {
    		if(prime[i]) // �Ҽ���
    			for(int j=i*2; j<=num; j+=i)
    				prime[j] = false; // ����� �Ҽ��ƴ�
    	}
    }
    
    private void makePermutation(String prefix, String str) {
    	int n = str.length();
    	
    	if(!prefix.equals("")) s.add(Integer.valueOf(prefix));
    	
    	for(int i=0; i<n; i++)
    		makePermutation(prefix+str.charAt(i), str.substring(0, i)+str.substring(i+1,n));
    }
}
