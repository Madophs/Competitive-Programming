import java.io.*;

class Java_IfElse {

	public static void main (String args[]) {
		Java_IfElse Madophs = new Java_IfElse();
		Madophs.justGetStarted();
	}

	void justGetStarted(){
		BufferedReader mds = new BufferedReader(new InputStreamReader(System.in));
		
		try{
			int number = Integer.parseInt(mds.readLine());
			if(number % 2 != 0){
				System.out.println("Weird");
			}else if(number >= 2 && number <= 5){
				System.out.println("Not Weird");
			}else if(number >= 6 && number <= 20){
				System.out.println("Weird");
			}else{
				System.out.println("Not Weird");
			}
		}catch(Exception e){};
	}
}
