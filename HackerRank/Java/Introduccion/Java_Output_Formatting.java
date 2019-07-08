import java.io.*;
import java.util.StringTokenizer;

class Java_Output_Formatting {

	public static void main (String args[]) {
		Java_Output_Formatting Madophs = new Java_Output_Formatting();
		Madophs.justGetStarted();
	}

	void justGetStarted(){
		BufferedReader mds = new BufferedReader(new InputStreamReader(System.in));
		int value;
		String programmingLanguage, line;
		try{
			System.out.println("================================");
			for(int i = 0; i < 3; i++){
				line = mds.readLine();
				StringTokenizer tk = new StringTokenizer(line," ");
				programmingLanguage = tk.nextToken().toString();
				value = Integer.parseInt(tk.nextToken().toString());
				System.out.printf("%-14s %03d%n", programmingLanguage, value);
			}	
			System.out.println("================================");
		}catch(Exception e){
			System.out.println("Error: "+e.getMessage());
		};

	}
}
