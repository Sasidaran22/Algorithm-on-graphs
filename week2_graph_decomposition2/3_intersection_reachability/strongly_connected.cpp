#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int> > reverseEdges(vector<vector<int> > &adj){
	vector<vector<int> > adj1(adj.size(), vector<int>());
    for(int i = 0; i < adj.size(); i++){
	  for(int j = 0; j < adj[i].size(); j++){
		adj1[adj[i][j]].push_back(i);
	  }
	}
	return adj1;
}

void dfs(vector<vector<int> > &adj, int x, vector<int> &used, stack<int> &order) {
	used[x] = 1;
	
	for (int i = 0; i < adj[x].size(); i++) {
      if(!used[adj[x][i]]){
        used[adj[x][i]] = 1;
		dfs(adj, adj[x][i], used, order);
	  }	
	}
	
	order.push(x);
}

int number_of_strongly_connected_components(vector<vector<int> > adj) {
  int result = 0;
  stack<int> order;
  
  vector<int> used(adj.size(), 0);
  for (int i = 0; i < adj.size(); i++) {
	if(!used[i]){
	  dfs(adj, i, used, order);
	}
  }
	
  // get the reversed adj list
  vector<vector<int> > adj1 = reverseEdges(adj);
	
  for(int i = 0; i < adj.size(); i++) {
	used[i] = 0;
  }
	
  while (! order.empty()) {
   int x = order.top();
    order.pop();
 
    if (!used[x]) {
	  stack<int> componentStack;
	  dfs(adj1, x, used, componentStack);
	  result++;
	}
  }
  return result;
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
  std::cout << number_of_strongly_connected_components(adj);
}


