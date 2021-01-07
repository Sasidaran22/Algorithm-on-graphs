#include <iostream>
#include <vector>

using std::vector;
using std::pair;
int exp(vector<vector<int> > &adj, int x, int y, vector<int> &v) {
	if (x == y) {
		return 1;
	}	
	v[x] = 1;
	for(int i = 0; i < adj[x].size(); i++) {
		if (!v[adj[x][i]]) {
			if(exp(adj, adj[x][i], y, v)) {
				return 1;
			}
		}
	}
	return 0;
}
int acyclic(vector<vector<int> > &adj) {
 vector<int> v(adj.size());
 for(int i=0;i<adj.size();i++)
 {
 	for(int j=0;j<adj[i].size();j++)
 	{
 	 if(exp(adj,adj[i][j] ,i , v)==1)
  	{
	  	return 1;
  	}
 }
 }
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
