import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class QHEAP1 {

	public static void main (String args[]) {
		QHEAP1 madophs = new QHEAP1();
		madophs.justGetStarted();
	}

	void justGetStarted(){
		BufferedReader mds = new BufferedReader(new InputStreamReader(System.in));
		
		try{
			int q = Integer.parseInt(mds.readLine());
			int op,val;
			MinHeap heap = new MinHeap();
			while(q-->0){
				String line = mds.readLine();
				StringTokenizer tk = new StringTokenizer(line," ");
				op = Integer.parseInt(tk.nextToken().toString());
				switch(op){
					case 1:
						val = Integer.parseInt(tk.nextToken().toString());
						heap.insert(val);
						break;
					case 2:
						val = Integer.parseInt(tk.nextToken().toString());
						heap.removeNode(val);
						break;
					case 3:
						System.out.println(heap.getMin());
						break;
				}
			}
		}catch(Exception e){
			System.out.println(e.getMessage());
		};
	}
}

class MinHeap{
	private ArrayList<Integer> nodes = new ArrayList<>();

	public int getMin(){
		return nodes.get(0);
	}
	public void insert(int val){
		nodes.add(val);
		int index = nodes.size()-1;
		while(nodes.get(parent(index)) > nodes.get(index)){
			swap(parent(index), index);
			index = parent(index);
		}
	}
	public void removeNode(int val){
		int index = 0;
		for(; index<nodes.size(); index++){
			if(nodes.get(index)==val)break;
		}
		swap(index,nodes.size()-1);
		nodes.remove(nodes.size()-1);
		if(nodes.size()>1){
			heapify(index);
		}
	}
	private void heapify(int index){
		int lc = left(index), rc = right(index),smallest = index;
		if(lc < nodes.size() && nodes.get(lc)<nodes.get(smallest)){
			smallest = lc;
		}
		if(rc < nodes.size() && nodes.get(rc)<nodes.get(smallest)){
			smallest = rc;
		}
		if(smallest!=index){
			swap(smallest, index);
			heapify(smallest);
		}
	}
	private void swap(int a, int b){
		int aux = nodes.get(a);
		nodes.set(a,nodes.get(b));
		nodes.set(b,aux);
	}
	private int parent(int index){
		return (index-1)/2;
	}

	private int left(int index){
		return (index*2)+1;
	}

	private int right(int index){
		return (index*2)+2;
	}
}