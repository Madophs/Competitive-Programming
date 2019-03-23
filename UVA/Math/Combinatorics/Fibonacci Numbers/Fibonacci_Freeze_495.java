package Matematicas;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;

public class Fibonacci_Freeze_495 {

	public static void main (String args[]){
		Fibonacci_Freeze_495 myWork = new Fibonacci_Freeze_495();
        myWork.Begin(); 
    }
    void Begin(){
    	BufferedReader mds = new BufferedReader(new InputStreamReader(System.in));
    	ArrayList<BigInteger> lista = new ArrayList<BigInteger>();
    	lista.add(BigInteger.ZERO);
    	lista.add(BigInteger.ONE);
    	lista.add(BigInteger.ONE);
    	BigInteger matrix[][] = {
				{BigInteger.ONE,BigInteger.ONE},
				{BigInteger.ONE,BigInteger.ZERO}
		};
    	int ciclo=0,numero=5000;
    	while(ciclo++<numero-1) {
			BigInteger x0y0 = matrix[0][0];
			BigInteger x0y1 = matrix[0][1];
			BigInteger x1y0 = matrix[1][0];
			BigInteger x1y1 = matrix[1][1];
			matrix[0][0]=new BigInteger(x0y0.multiply(BigInteger.ONE).add(x0y1.multiply(BigInteger.ONE)).toString());
			matrix[0][1]=new BigInteger(x0y0.multiply(BigInteger.ONE).add(x0y1.multiply(BigInteger.ZERO)).toString());
			matrix[1][0]=new BigInteger(x1y0.multiply(BigInteger.ONE).add(x1y1.multiply(BigInteger.ONE)).toString());
			matrix[1][1]=new BigInteger(x1y0.multiply(BigInteger.ONE).add(x1y1.multiply(BigInteger.ONE)).toString());
			if(lista.size()<=ciclo+1)lista.add(matrix[0][1]);
		}
    	try {
    		String linea;
    		
    		while((linea=mds.readLine())!=null && !linea.isEmpty()) {
    			int num=Integer.parseInt(linea);
    			System.out.println("The Fibonacci number for "+num+" is "+lista.get(num));
    		}
    	}catch(Exception x) {}
    }
}
