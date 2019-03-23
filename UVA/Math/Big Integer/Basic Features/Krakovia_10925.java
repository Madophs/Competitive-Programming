package Matematicas;

import java.math.BigInteger;
import java.util.Scanner;

class Krakovia_10925 {

	public static void main(String[] args) {
		Krakovia_10925 clase = new Krakovia_10925();
		clase.begin();
	}
	void begin() {
		Scanner mds = new Scanner(System.in);
		int items,friends,cont=0;
		String linea;
		while(true) {
			items=mds.nextInt();
			friends=mds.nextInt();
			if(items==0 && friends==0)break;
			BigInteger suma = BigInteger.ZERO;
			for(int x=0; x<items; x++) {
				BigInteger valor = mds.nextBigInteger();
				suma=suma.add(valor);
			}
			BigInteger division = suma.divide(BigInteger.valueOf(friends));
			System.out.println("Bill #"+(++cont)+" costs "+suma+": each friend should pay "+division.toString()+"\n");
		}
	}
}
