
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.BitSet;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.StringTokenizer;


public class Bicoloring_10004 {
	public static void main (String args[]){
		Bicoloring_10004 myWork = new Bicoloring_10004();
        myWork.Begin(); 
    }
    void Begin(){
    	BufferedReader mds = new BufferedReader(new InputStreamReader(System.in));
    	try {
    		int n,e,a,b;
    		n=e=a=b=0;
    		while(true) {
    			n = Integer.parseInt(mds.readLine());
    			if(n==0)break;
    			Graph g = new Graph(n);
    			e = Integer.parseInt(mds.readLine());
    			while(e-->0) {
    				String linea = mds .readLine();
    				StringTokenizer tk = new StringTokenizer(linea," ");
    				a = Integer.parseInt(tk.nextToken().toString());
    				b = Integer.parseInt(tk.nextToken().toString());
    				g.insertEdges(a, b);
    			}
    			System.out.println((g.isBicolorable()?"BICOLORABLE.":"NOT BICOLORABLE."));
    		}
    	}catch(Exception x) {
    		System.err.print("Error "+x.getMessage());
    	}
    }
    
}
enum Color{
	azul,rojo,blanco
}
class Vertex{
	ArrayList<Vertex> adj;
	int nom;
	Color color;
	Vertex(int nom){
		this.color=Color.blanco;
		this.adj = new ArrayList<Vertex>();
		this.nom=nom;
	}
}

class Graph{
	int tam;
	Map<Integer,Vertex> mapa;
	BitSet set;
	Graph(int tam){
		this.tam=tam;
		this.set = new BitSet(tam+10);
		this.mapa = new HashMap<>();
		for(int x=0; x<tam; x++) {
			mapa.put(x, new Vertex(x));
		}
	}
	void insertEdges(int a, int b) {
		mapa.get(a).adj.add(mapa.get(b));
		mapa.get(b).adj.add(mapa.get(a));
	}
	Boolean isBicolorable() {
		set.clear();
		Queue<Integer> q = new LinkedList<>();
		q.offer(0);
		set.set(0, true);
		mapa.get(0).color=Color.azul;
		while(!q.isEmpty()) {
			int u =q.poll();
			for(int x=0; x<mapa.get(u).adj.size(); x++) {
				Vertex aux =mapa.get(u).adj.get(x);
				if(mapa.get(u).color==aux.color)return false;
				if(!set.get(aux.nom)) {
					set.set(aux.nom,true);
					q.offer(aux.nom);
					if(mapa.get(u).color==Color.azul) {
						aux.color=Color.rojo;
					}else{
						aux.color=Color.azul;
					}
				}
			}
		}
		return true;
	}
}
