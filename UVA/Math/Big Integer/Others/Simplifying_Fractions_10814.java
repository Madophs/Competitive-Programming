package Matematicas;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

class Simplifying_Fractions_10814 {
	public static void main (String args[]){
		Simplifying_Fractions_10814 myWork = new Simplifying_Fractions_10814();
        myWork.Begin(); 
    }
    void Begin(){
    	BufferedReader mds = new BufferedReader(new InputStreamReader(System.in));
    	try {
    		int casos = Integer.parseInt(mds.readLine());
    		while(casos-- >0) {
    			String linea = mds.readLine();
    			StringTokenizer tk = new StringTokenizer(linea," ");
    			BigInteger p = new BigInteger(tk.nextToken().toString());
    			tk.nextToken();
    			BigInteger q = new BigInteger(tk.nextToken().toString());
    			BigInteger gcd = p.gcd(q);
    			System.out.println(p.divide(gcd).toString()+" / "+q.divide(gcd).toString());
    		}
    	}catch(Exception x) {}
    }
}
