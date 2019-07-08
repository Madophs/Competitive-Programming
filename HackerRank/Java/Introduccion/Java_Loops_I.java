import java.io.*;

class Java_Loops_I {

	public static void main (String args[]) {
		Java_Loops_I Madophs = new Java_Loops_I();
		Madophs.justGetStarted();
	}

	void justGetStarted(){
		BufferedReader mds = new BufferedReader(new InputStreamReader(System.in));
		int value;
		try{
			value = Integer.parseInt(mds.readLine());
			for(int i = 1; i < 11; ++i){
				System.out.println(value+" x "+i+" = "+(i*value));
			}
		}catch(Exception e){
			System.out.println("Error: "+e.getMessage());
		};

	}
}
