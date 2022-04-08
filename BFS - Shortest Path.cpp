// https://hack.codingblocks.com/app/contests/2675/34/problem

#include<iostream>
#include<map>
#include<list>
#include<unordered_set>
#include<queue>
#include<vector>
using namespace std;

int ver;

template <typename T>
class graph{
	map<T, list<T>> neighbourMap;
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
			cout<< vertex.first<< " : ";
			for(T neighbour : vertex.second)
				cout<<neighbour<<" ";
			cout<<endl;
		}
		cout<<endl;
	}

	void bfs(T s){
		unordered_set<T> visited;
		queue<T> q;
		map<T, int> distanceMap;
		map<T, T> parentMap;

		visited.insert(s);
		q.push(s);
		distanceMap[s] = 0;
		parentMap[s] = s;

		while(!q.empty()){
			T front = q.front();
			q.pop();

			for(T neighbour : neighbourMap[front]){
				if(visited.find(neighbour) == visited.end()){
					visited.insert(neighbour);
					q.push(neighbour);
					distanceMap[neighbour] = 1 + distanceMap[front];
					parentMap[neighbour] = front;
				}
			}
		}
		vector<int> arr(ver,-1);
		for(pair<T, int> dist : distanceMap){
			arr[dist.first-1] = dist.second * 6;
		}

		for(int x : arr){
			if(x ==0)
				continue;
			cout<<x<<" ";
		}
	}
};

int main() {
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		ver=n;
		graph<int> g;
		while(m--){
			int x,y;
			cin>>x>>y;
			g.addEdge(x,y);
		}
		int src;
		cin>>src;
		g.bfs(src);
		cout<<endl;
	}
	return 0;
}