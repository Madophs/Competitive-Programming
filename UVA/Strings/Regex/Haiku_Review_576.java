package Cadenas;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Haiku_Review_576 {
	public static void main (String args[]){
		Haiku_Review_576 myWork = new Haiku_Review_576();
        myWork.Begin(); 
    }
    void Begin(){
    	BufferedReader mds = new BufferedReader(new InputStreamReader(System.in));
    	try {
    		String linea, vocals="[a|e|i|o|u|y]+",regex="[^aeiouy]*"+vocals+"[^aeiouy]*";
    		while((linea = mds.readLine())!=null && !linea.equals("e/o/i")) {
    			StringTokenizer slash = new StringTokenizer(linea,"/");
    			int aux=0,c=0,res=0;
    			while(slash.hasMoreTokens()) {
    				String word = slash.nextToken().toString();
    				aux=word.replaceAll(regex,"+").length();
    				if(c==0 || c==2) {
    					if(aux!=5 && res==0) {
    						res=(c==0)?1:3;
    					}
    				}else {
    					if(aux!=7 && res==0) {
    						res=2;
    					}
    				}
    				c++;
    			}
    			if(res==0) {
    				System.out.println("Y");
    			}else {
    				System.out.println(res);
    			}
    		}
    	}catch(Exception x) {
    		System.err.print("Error "+x.getMessage());
    	}
    }
}
