import java.io.*;
import java.util.StringTokenizer;

class Java_Loops_II {

	public static void main (String args[]) {
		Java_Loops_II Madophs = new Java_Loops_II();
		Madophs.justGetStarted();
	}

	void justGetStarted(){
		BufferedReader mds = new BufferedReader(new InputStreamReader(System.in));
		int a, b, n, q;
		String line;
		try{
			q = Integer.parseInt(mds.readLine());
			while(q-- > 0){
				line = mds.readLine();
				StringTokenizer tk = new StringTokenizer(line," ");
				a = Integer.parseInt(tk.nextToken().toString());
				b = Integer.parseInt(tk.nextToken().toString());
				n = Integer.parseInt(tk.nextToken().toString());
				long serie = 0;
				for(int i = 0; i < n; ++i){
					if(i > 0) System.out.print(" ");
					serie = a + 1 * b;
					for(int j = 1; j < i+1; ++j){
						serie += Math.pow(2,j) * b;
					}
					System.out.print(serie);
				}
				System.out.println();
			}
		}catch(Exception e){
			System.out.println("Error: "+e.getMessage());
		};

	}
}
