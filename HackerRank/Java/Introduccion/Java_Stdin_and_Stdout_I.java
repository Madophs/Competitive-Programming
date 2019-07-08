import java.io.*;
import java.util.Scanner;

class Java_Stdin_and_Stdout_I {

	public static void main (String args[]) {
		Java_Stdin_and_Stdout_I Madophs = new Java_Stdin_and_Stdout_I();
		Madophs.justGetStarted();
	}

	void justGetStarted(){
		Scanner mds = new Scanner(System.in);
		int value[] = new int[3];
		for(int i = 0; i < 3; i++) value[i] = mds.nextInt();
		for(int i = 0; i < 3; i++) System.out.println(value[i]);
	}
}
