import java.io.*;
import java.math.BigInteger;
import java.util.Scanner;

class Leap_Year_Or_Not_Leap_Year_And_10070 {

	public static void main (String args[]) {
		Leap_Year_Or_Not_Leap_Year_And_10070 Madophs = new Leap_Year_Or_Not_Leap_Year_And_10070();
		Madophs.justGetStarted();
	}

	void justGetStarted(){
		Scanner mds = new Scanner(System.in);
		try{
			BigInteger year;
			int blackLine = 0;
			while((year = mds.nextBigInteger())!=null){
				if(blackLine++>0) System.out.println();
				boolean leap = isLeapYear(year);
				boolean huluculu = isHuluculu(year);
				if(!leap && !huluculu){
					System.out.println("This is an ordinary year.");
				}else{
					if(leap) System.out.println("This is leap year.");
					if(huluculu) System.out.println("This is huluculu festival year.");
					if(leap && year.mod(BigInteger.valueOf(55)) == BigInteger.ZERO)
						System.out.println("This is bulukulu festival year.");
				}
			}
		}catch(Exception e){};
	}
	boolean isHuluculu(BigInteger year){
		return year.mod(BigInteger.valueOf(15)) == BigInteger.ZERO;
	}
	boolean isLeapYear(BigInteger year){
		if((year.mod(BigInteger.valueOf(4)) == BigInteger.ZERO && year.mod(BigInteger.valueOf(100)) != BigInteger.ZERO)) return true;
		return year.mod(BigInteger.valueOf(400)) == BigInteger.ZERO;
	}
}
