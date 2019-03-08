
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Jimmis_Riddles_10058 {
	public static void main (String args[]){
		Jimmis_Riddles_10058 myWork = new Jimmis_Riddles_10058();
        myWork.Begin(); 
    }
    void Begin(){
    	BufferedReader mds = new BufferedReader(new InputStreamReader(System.in));
    	try {
    		String linea;
    		String noun="(tom|jerry|goofy|mickey|jimmy|dog|cat|mouse)";
			String verb ="((hate|love|know|like)[s]?)";
			String article ="(a|the)";
			String actor= "("+noun+"|("+article+" "+noun+"))";
			String active_list_aux="[("+actor+"|("+actor+" and "+actor+"))]+";
			String active_list="("+actor+"|("+active_list_aux+" and "+actor+"))";
			String action = "("+active_list+" "+verb+" "+active_list+")";
			String statement_aux="["+action+"|("+action+" , "+action+")]+";
			String statement = action+"|("+statement_aux+" , "+action+")"; 
    		while((linea= mds.readLine())!=null && !linea.isEmpty()) {
    			if(linea.matches(statement)) {
    				System.out.println("YES I WILL");
    			}else {
    				System.out.println("NO I WON'T");
    			}
    		}
    	}catch(Exception x) {;}
    }
}
