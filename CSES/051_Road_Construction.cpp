// #include "bits_std_mac.h"
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class DisjointSet{
public:
	unordered_map<T,T> parent;
	unordered_map<T,int> rank;
	unordered_map<T,int> size;

	T find(T node){
		// If node is not in parent map, initialize it
		if (parent.find(node) == parent.end()){
			parent[node] = node;
			rank[node] = 0;
			size[node] = 1;
		}

		// Path compression: recursive find
		if (node != parent[node]){
			parent[node] = find(parent[node]);
		}
		return parent[node];
	}

	void unite(T u, T v, bool by_size = true){
		T root_u = find(u);
		T root_v = find(v);

		if (root_u == root_v)
			return;

		if (by_size){
			// Union by size
			if (size[root_u] < size[root_v]){
				swap(root_u, root_v);
			}
			parent[root_v] = root_u;
			size[root_u] += size[root_v];
		} else {
			// Union by rank
			if (rank[root_u] < rank[root_v]){
				parent[root_u] = root_v;
			} else if (rank[root_u] > rank[root_v]){
				parent[root_v] = root_u;
			} else {
				parent[root_v] = root_u;
				rank[root_u] += 1;
			}
		}
	}

	bool connected(T u, T v) {
        return find(u) == find(v);
    }
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	DisjointSet<int> ds;
	int n,m;
	cin >> n >> m;

	int components = n, max_size = 1;
	for (int i=1;i<=n;i++){
		ds.find(i);
	}	

	int u,v;
	for (int i=0;i<m;i++){
		cin >> u >> v;
		int root_u = ds.find(u);
		int root_v = ds.find(v);
		if (root_u != root_v){
			components--;
			ds.unite(u,v);
			max_size = max(max_size,ds.size[ds.find(u)]);
		}
		cout << components << " " << max_size << "\n";
	}
	return 0;
}