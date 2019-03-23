package Matematicas;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Basically_Speaking_389 {

    public static void main (String args[]){
    	Basically_Speaking_389  myWork = new Basically_Speaking_389 ();
        myWork.Begin(); 
    }
    void Begin(){
    	BufferedReader mds = new BufferedReader(new InputStreamReader(System.in));
    	try {
    		String linea;
    		while((linea = mds.readLine())!=null && !linea.isEmpty()) {
    			StringTokenizer tk = new StringTokenizer(linea," ");
    			String convertFrom = tk.nextToken().toString();
    			int base = Integer.parseInt(tk.nextToken().toString());
    			int baseTo = Integer.parseInt(tk.nextToken().toString());
    			String result = Integer.toString(Integer.parseInt(convertFrom, base), baseTo).toUpperCase();
    			StringBuilder sb = new StringBuilder("       ");
    			int start = 7-result.length();
    			if(result.length()>7) {
    				System.out.println("  ERROR");
    			}else if(start>0) {
    				sb =sb.replace(start, sb.length(), result);
    				System.out.println(sb.toString());
    			}else {
    				System.out.println(result);
    			}
    		}
    	}catch(Exception x) {}
    }
}
