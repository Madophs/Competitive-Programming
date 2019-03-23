package Matematicas;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Factorial500_623 {
	 public static void main (String args[]){
		 	Factorial500_623 myWork = new Factorial500_623();
	        myWork.Begin(); 
	    }
	    void Begin(){
	    	BufferedReader mds = new BufferedReader(new InputStreamReader(System.in));
	    	BigInteger factoriales[] = new BigInteger[1001];
	    	factoriales[0]=BigInteger.ONE;
	    	factoriales[1]=BigInteger.ONE;
	    	BigInteger aux=BigInteger.ONE;
	    	for(int x = 2; x<=1000; x++) {
	    		BigInteger tmp = BigInteger.valueOf(x);
	    		aux = aux.multiply(tmp);
	    		factoriales[x]=aux;
	    	}
	    	try {
	    		String linea;
	    		while((linea=mds.readLine())!=null && !linea.isEmpty()) {
	    			int fac = Integer.parseInt(linea);
	    			System.out.println(fac+"!\n"+factoriales[fac].toString());
	    		}
	    	}catch(Exception x) {}
	    }
}
