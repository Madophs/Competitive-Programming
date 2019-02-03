import java.io.*;
import java.util.Stack;

public class Balanced_Brackets {

	public static void main (String args[]) {
		Balanced_Brackets madophs = new Balanced_Brackets();
		madophs.justGetStarted();
	}

	void justGetStarted(){
		BufferedReader mds = new BufferedReader(new InputStreamReader(System.in));
		
		try{
			int t = Integer.parseInt(mds.readLine());
			while(t-->0){
				String brackets = mds.readLine();
				Stack<Character> pila = new Stack<>();
				boolean ans = true;
				for(int x=0; x<brackets.length() && ans; x++){
					if(brackets.charAt(x)=='{' || brackets.charAt(x)=='(' || brackets.charAt(x)=='['){
						pila.push(brackets.charAt(x));
					}else{
						if(pila.isEmpty()){
							ans = false;
						}else{
							if(theyMatch(pila.peek(), brackets.charAt(x))){
								pila.pop();
							}else{
								ans = false;
							}
						}
					}
				}
				if(!pila.isEmpty())ans=false;
				System.out.println((ans?"YES":"NO"));
			}
		}catch(Exception e){};
	}

	boolean theyMatch(char a, char b){
		if(a=='(' && b==')')return true;
		if(a=='{' && b=='}')return true;
		if(a=='[' && b==']')return true;
		return false;
	}
}