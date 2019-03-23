package Matematicas;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;

class Simply_Emirp_10235 {

	public static void main (String args[]){
		Simply_Emirp_10235 myWork = new Simply_Emirp_10235();
        myWork.Begin(); 
    }
    void Begin(){
    	BufferedReader mds = new BufferedReader(new InputStreamReader(System.in));
    	String linea="";
    	try {
    		while((linea=mds.readLine())!=null && !linea.isEmpty()) {
        		int num = Integer.parseInt(linea);
        		BigInteger number = BigInteger.valueOf(num);
        		StringBuilder sb = new StringBuilder(number.toString());
        		int reverse = Integer.parseInt(sb.reverse().toString());
        		BigInteger numReverse = BigInteger.valueOf(reverse);
        		if(!number.isProbablePrime(10)) {
        			System.out.println(number.toString()+" is not prime.");
        		}else if(num!=reverse && numReverse.isProbablePrime(10)) {
        			System.out.println(number.toString()+" is emirp.");
        		}else {
        			System.out.println(num+" is prime.");
        		}
        	}
    	}catch(Exception x) {}
    }

}
