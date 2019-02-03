package Cadenas;

import java.io.BufferedReader;
import java.io.InputStreamReader;


public class Message_Decoding_213 {
	public static void main (String args[]){
		Message_Decoding_213 myWork = new Message_Decoding_213();
        myWork.Begin(); 
    }
    void Begin(){
    	BufferedReader mds = new BufferedReader(new InputStreamReader(System.in));
    	try {
    		String linea="",msj="",header="",result="";
    		header = mds .readLine();
    		do {
    			result=msj="";
    			while((linea=mds.readLine())!=null && linea.matches("[1|0]+") && !linea.isEmpty()) {
    				msj+=linea;
    			}
    			int length=0,key=0;
    			for(int x=0; x<msj.length(); ) {
    				if(length==0) {
    					length=Integer.parseInt(msj.substring(x, x+3), 2);
    					if(length==0)break;
    					x+=3;
    					key = getKeyPos(length);
    				}else {
    					String subcadena=msj.substring(x, x+length);
    					if(subcadena.matches("[1]+")) {
    						x+=length;
    						length=0;
    						continue;
    					}
    					int pos = Integer.parseInt(subcadena, 2);
						result+=header.charAt(key+pos);
						x+=length;
    				}
    			}
    			System.out.println(result);
    			if(linea.isEmpty())break;
    			header = linea;
    		}while(true);
    	}catch(Exception x) {;}
    	
    }
    
    int getKeyPos(int num) {
    	int res=0;
    	for(int x=1; x<num; x++) {
    		res+=(int)Math.pow(2, x)-1;
    	}
    	return res;
    }
}
