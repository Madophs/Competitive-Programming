import java.io.BufferedReader;
import java.io.InputStreamReader;

public class SumaDigitos {

	public static void main(String[] args) {
		BufferedReader mds = new BufferedReader(new InputStreamReader(System.in));
	
		try{
			String cadena="";
			while((cadena=mds.readLine())!="-1"){
				int suma=0;
				for(int x=0; x<cadena.length(); x++){
					suma+=Integer.parseInt(cadena.charAt(x)+"");
					System.out.print(cadena.charAt(x)+((x+1)==cadena.length()?" = "+suma+"\n":" + "));
				}
			}
		}catch(Exception x){;}
	}
}