package Matematicas;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

class MODEX_1230 {
	public static void main (String args[]){
		MODEX_1230 myWork = new MODEX_1230();
        myWork.Begin(); 
    }
    void Begin(){
    	BufferedReader mds = new BufferedReader(new InputStreamReader(System.in));
    	try {
    		int casos = Integer.parseInt(mds.readLine());
    		while(casos-- >0) {
    			String linea = mds.readLine();
    			StringTokenizer tk = new StringTokenizer(linea," ");
    			BigInteger x = new BigInteger(tk.nextToken().toString());
    			BigInteger y = new BigInteger(tk.nextToken().toString());
    			BigInteger modulo = new BigInteger(tk.nextToken().toString());
    			System.out.println(x.modPow(y, modulo).toString());
    		}
    		mds.read();
    	}catch(Exception x) {}
    }
}
