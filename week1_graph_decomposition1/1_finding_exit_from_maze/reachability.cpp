  
#include <iostream>
#include <vector>

using namespace std;

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


int reach(vector<vector<int> > &adj, int x, int y) {
  vector<int> v(adj.size());
  return exp(adj, x-1, y-1, v);
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x, y);
}
