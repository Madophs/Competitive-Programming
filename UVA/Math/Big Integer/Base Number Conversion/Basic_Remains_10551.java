package Matematicas;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Basic_Remains_10551 {

	public static void main(String[] args) {
		BufferedReader mds = new BufferedReader(new InputStreamReader(System.in));
		int b,p,m;
		String linea;
		try {
			while(true) {
				linea= mds.readLine();
				if(linea.charAt(0)=='0')break;
				StringTokenizer tk = new StringTokenizer(linea," ");
				int base = Integer.parseInt(tk.nextToken().toString());
				BigInteger param = new BigInteger(tk.nextToken().toString(),base);
				BigInteger modulo = new BigInteger(tk.nextToken().toString(),base);
				param = param.mod(modulo);
				System.out.println(param.toString(base));
			}
		}catch(Exception x) {}

	}
}
