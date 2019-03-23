import java.io.*;
import java.math.BigInteger;

class Count_the_Trees_10007 {
	
	final int limit = 602; 
	BigInteger factorials[] = new BigInteger[limit];
	BigInteger binomials[][] = new BigInteger[limit][limit];

	public static void main (String args[]) {
		Count_the_Trees_10007 madophs = new Count_the_Trees_10007();
		madophs.justGetStarted();
	}

	void justGetStarted(){
		BufferedReader mds = new BufferedReader(new InputStreamReader(System.in));
		generateBinomialCoefficients();
		generateFactorials();
		int num;
		try{
			while(true){
				num = Integer.parseInt(mds.readLine());
				if(num == 0) break;
				System.out.println(getCatalan(num).multiply(factorials[num]).toString());
			}
		}catch(Exception e){
		};
	}

	BigInteger getCatalan(int n){
		return binomials[n<<1][n].divide(BigInteger.valueOf(n+1));
	}

	void generateFactorials(){
		BigInteger fac = BigInteger.ONE;
		factorials[0] = BigInteger.ONE;
		factorials[1] = BigInteger.ONE;
		for(int i = 2; i<limit; i++){
			factorials[i] = factorials[i-1].multiply(BigInteger.valueOf(i));
		}
	}
	void generateBinomialCoefficients(){
		for(int i = 0; i<limit; i++){
			for(int j = 0; j<=i; j++){
				if(i == j || j == 0)
					binomials[i][j] = BigInteger.ONE;
				else
					binomials[i][j] = binomials[i-1][j].add(binomials[i-1][j-1]);
			}
		}
	}
}
