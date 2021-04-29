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
        
        // 제일 큰 숫자가 0이라면 소수x
        if(chars[size-1] == 0) return 0;
        
        int max = 0;
        for(int i=size-1; i>=0; i--) {
        	max *= 10;
        	max += chars[i] - '0';
        }
        
        // 제일 큰 숫자까지의 prime 구하기
        boolean[] prime = new boolean[max+1];
        Arrays.fill(prime, true);
        
        isPrime(prime, max);
        
        // set에 넣어
        makePermutation("", numbers);
        
        for(Integer i : s) {
        	if(prime[i]) answer++;
        }
        
        return answer;
        
    }
    
    private void isPrime(boolean[] prime, int num) {
    	prime[0] = prime[1] = false; //소수 아님
    	double sqrt = Math.sqrt(num);
    	
    	for(int i=2; i<=sqrt; i++) {
    		if(prime[i]) // 소수면
    			for(int j=i*2; j<=num; j+=i)
    				prime[j] = false; // 배수는 소수아님
    	}
    }
    
    private void makePermutation(String prefix, String str) {
    	int n = str.length();
    	
    	if(!prefix.equals("")) s.add(Integer.valueOf(prefix));
    	
    	for(int i=0; i<n; i++)
    		makePermutation(prefix+str.charAt(i), str.substring(0, i)+str.substring(i+1,n));
    }
}
