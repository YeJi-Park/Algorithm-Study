package programmers.codechallenge;

public class TernaryReverse {
	private int getReversedTernary(int n) {
		StringBuilder ternary = new StringBuilder();
		
		while(n>0) {
			ternary.append(n%3);
			n /= 3;
		}
		
		return Integer.parseInt(ternary.toString(), 3);
	}

	private int getReversedTernaryUsingPublicAPI(int n) {
	  	StringBuilder ternary = new StringBuilder(Integer.toString(n, 3));
    	return Integer.parseInt(ternary.reverse().toString(), 3);
	}
	
    public int solution(int n) {
    	return getReversedTernary(n);
//    	return getReversedTernaryUsingPublicAPI(n);
    }

}
