import java.io.*;
import java.math.BigInteger;

class Welcome_to_Java {

	public static void main (String args[]) {
		Welcome_to_Java Madophs = new Welcome_to_Java();
		Madophs.justGetStarted();
	}

	void justGetStarted(){
		BufferedReader mds = new BufferedReader(new InputStreamReader(System.in));
		
		try{
			System.out.println("Hello, World.\nHello, Java.");
		}catch(Exception e){
			System.out.println("Error: "+e.getMessage());
		};
	}
}
