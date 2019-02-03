import java.io.*;
import java.math.BigInteger;

public class Extra_Long_Factorials {

	public static void main (String args[]) {
		Extra_Long_Factorials madophs = new Extra_Long_Factorials();
		madophs.justGetStarted();
	}

	void justGetStarted(){
		BufferedReader mds = new BufferedReader(new InputStreamReader(System.in));		
		try{
			int num = Integer.parseInt(mds.readLine());
			BigInteger factorial = BigInteger.ONE;
			for(int x=2; x<=num; x++){
				factorial = factorial.multiply(BigInteger.valueOf((long)x));
			}
			System.out.println(factorial.toString());
		}catch(Exception e){};
	}
}
