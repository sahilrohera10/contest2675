// https://hack.codingblocks.com/app/contests/2675/356/problem

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<list>
using namespace std;

template <typename T>
class graph{

	unordered_map<T,list<T>> neighbourMap;
	bool directed;

public:

	graph(bool directed = false){
		this->directed = directed;
	}

	void addEdge(T u, T v){
		neighbourMap[u].push_back(v);
		if(!directed)
			neighbourMap[v].push_back(u);
	}

	void print(){
		for(pair<T, list<T>> vertex : neighbourMap){
			cout << vertex.first << " : ";
			for(T neighbour : vertex.second)
				cout<<neighbour<<" ";
			cout<<endl;	
		}
		cout<<endl;
	}

	bool dfsHelper(T source, unordered_set<T>& visited, T parent){
		visited.insert(source);

		list<T> neighbourList = neighbourMap[source];
		for(T neighbour : neighbourList){
			if(visited.find(neighbour) == visited.end()){
				//neighbour not visited
				if(dfsHelper(neighbour, visited, source))
					return true;
			}else{
				//neighbour is visited
				if(neighbour != parent)
					return true;
			}
		}
		return false;
	}

	bool isCyclePresent(){
		bool flag = false;
		unordered_set<T> visited;
		for(pair<T, list<T>> vertex : neighbourMap){
			T vertexLabel = vertex.first;
			if(visited.find(vertexLabel) == visited.end()){
				if(dfsHelper(vertexLabel, visited, vertexLabel)){
					flag = true;
					break;
				}
			}
		}
		return flag;
	}
};

int main() {
	int t;
	cin>>t;
	while(t--){
		graph<int> g;
		int n,m;
		cin>>n>>m;
		while(m--){
			int x,y;
			cin>>x>>y;
			g.addEdge(x,y);
		}
		g.isCyclePresent() ? cout << "yes" << endl :
	                     	 cout << "no" << endl;
	}
	return 0;
}