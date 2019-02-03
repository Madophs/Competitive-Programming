
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Graph_Connectivity_459 {
	
	public static void main (String args[]){
		Graph_Connectivity_459 myWork = new Graph_Connectivity_459();
        myWork.Begin(); 
    }
    void Begin(){
    	BufferedReader mds = new BufferedReader(new InputStreamReader(System.in));
    	try {
    		int t = Integer.parseInt(mds.readLine());
    		boolean salto=false;
    		while(t-->0) {
    			if(!salto)
    				mds.read();
    			if(salto)System.out.println();
    			salto=true;
    			char c = (mds.readLine()).charAt(0);
    			Graph g = new Graph(c);
    			String chars;
    			while((chars=mds.readLine())!=null && !chars.isEmpty()) {
    				g.addEdges(chars.charAt(0), chars.charAt(1));
    			}
    			System.out.println(g.maxConnectedSubgraphs());
    		}
    	}catch(Exception x) {
    		System.err.print("Error "+x.getMessage());
    	}
    }   
}

class Vertex{
	ArrayList<Vertex> adj;
	char nom;
	Vertex(char nom){
		this.nom=nom;
		this.adj= new ArrayList<Vertex>();
	}
}
enum State{
	visited,unvisited
}
class Graph{
	char maxChar;
	ArrayList<State> connectivity;
	Map<Character,Vertex> mapa;
	Graph(char maxNode){
		this.mapa = new HashMap<>();
		this.connectivity = new ArrayList<>();
		this.maxChar=maxNode;
		for(char x ='A'; x<=maxNode; x++) {
			mapa.put(x, new Vertex(x));
			connectivity.add(State.unvisited);
		}
	}
	
	void addEdges(char from, char to) {
		mapa.get(from).adj.add(mapa.get(to));
		mapa.get(to).adj.add(mapa.get(from));
	}
	int maxConnectedSubgraphs() {
		int res=0;
		for(char x='A'; x<=maxChar; x++) {
			if(connectivity.get(x-'A')==State.unvisited) {
				maxConnectedSubgraphs(x);
				++res;
			}
		}
		return res;
	}
	void maxConnectedSubgraphs(char vertex) {
		connectivity.set(vertex-'A', State.visited);
		for(int x=0; x<mapa.get(vertex).adj.size(); x++) {
			if(connectivity.get(mapa.get(vertex).adj.get(x).nom-'A')==State.unvisited) {
				maxConnectedSubgraphs(mapa.get(vertex).adj.get(x).nom);
			}
		}
	}
}