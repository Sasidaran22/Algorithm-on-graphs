  
#include <iostream>
#include <vector>

using namespace std;

void exp(vector<vector<int> > &adj, int x, vector<int> &v) {
	v[x] = 1;
	for (int i = 0; i < adj[x].size(); i++) {
		if (!v[adj[x][i]])
			{
				exp(adj, adj[x][i], v);
			}
	}
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
	int res=0;
	vector<int> v(adj.size());
  for (int i = 0; i < adj.size(); i++)
  {
    if (!v[i])
    {
      exp(adj, i, v);
      res++;
    }
  }
  cout<<res;
}
