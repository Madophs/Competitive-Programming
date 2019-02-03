package Cadenas;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class IdentifyingPascal_350 {

	public static void main(String args[]) {
		IdentifyingPascal_350 myWork = new IdentifyingPascal_350();
		myWork.Begin();
	}

	void Begin() {
		BufferedReader mds = new BufferedReader(new InputStreamReader(System.in));
		try {
			String linea;
			while ((linea = mds.readLine()) != null && !linea.equals("*")) {
				if (linea.matches("\\s*[-+]?\\d+(\\.\\d+([eE][-+]?\\d+)?|[eE][-+]?\\d+)\\s*")) {
					linea = linea.replaceAll("^\\s+|\\s+$", "");
					System.out.println(linea + " is legal.");
				} else {
					linea = linea.replaceAll("^\\s+|\\s+$", "");
					System.out.println(linea + " is illegal.");
				}
			}
		} catch (Exception x) {
		}
	}

}
