package Matematicas;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.util.StringTokenizer;

public class Exponentiation_748 {

	public static void main(String args[]) {
		Exponentiation_748 myWork = new Exponentiation_748();
		myWork.Begin();
	}

	void Begin() {
		BufferedReader mds = new BufferedReader(new InputStreamReader(System.in));
		try {
			String linea;
			while ((linea = mds.readLine()) != null && !linea.isEmpty()) {
				StringTokenizer tk = new StringTokenizer(linea, " ");
				BigDecimal num = new BigDecimal(tk.nextToken().toString());
				int exp = Integer.parseInt(tk.nextToken().toString());
				StringBuilder sb = new StringBuilder(num.pow(exp).toPlainString());
				if (sb.charAt(sb.length() - 1) == '0') {
					int start = 0;
					for (int x = sb.length() - 1; x >= 0; x--) {
						if (sb.charAt(x) != '0') {
							start = x + 1;
							break;
						}
					}
					sb.delete(start, sb.length());
					if (sb.charAt(0) == '0') {
						sb.delete(0, 1);
					}
					System.out.println(sb);
				} else {
					if (sb.charAt(0) == '0') {
						sb.delete(0, 1);
					}
					System.out.println(sb);
				}

			}
		} catch (Exception x) {
		}
	}
}
