import java.io.*;
import java.util.Scanner;

class Java_Stdin_and_Stdout_II {

	public static void main (String args[]) {
		Java_Stdin_and_Stdout_II Madophs = new Java_Stdin_and_Stdout_II();
		Madophs.justGetStarted();
	}

	void justGetStarted(){
		Scanner mds = new Scanner(System.in);
		int number = mds.nextInt();
		double doubleNumber = mds.nextDouble();
		mds.nextLine();
		String stringValue = mds.nextLine();
		System.out.println("String: "+stringValue);
		System.out.println("Double: "+doubleNumber);
		System.out.println("Int: "+number);
		mds.close();
	}
}
