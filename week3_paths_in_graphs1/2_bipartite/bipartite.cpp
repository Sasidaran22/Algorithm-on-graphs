#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int distance(vector<vector<int> > &adj) 
{	
	vector<int> distance(adj.size(),-1);
	queue<int> q;
	distance[0]=0;
	q.push(0);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<adj[u].size();i++)
		{
			if(distance[adj[u][i]]==-1)
			{
				q.push(adj[u][i]);
				if(distance[u]==1)
				{
					distance[adj[u][i]]=2;
				}
				else
				distance[adj[u][i]]=1;
				
			}
			else if(distance[adj[u][i]]==distance[u])
			{
				return 0;
			}
		}
	}
  return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  
  std::cout << distance(adj);
}
