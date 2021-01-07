#Uses python3

import sys
import queue


def distance(adj, cost, s, t):
    dist=[-1*len(adj)]
    prev=[0*len(adj)]
    for i in adj[t]:
        dist[i]=0
    h=queue.Queue()
    h.put(t)
    while not h.empty():
        u=min(h)
        for i in adj:
            if(dist[t]>dist[u]+cost[u][t]):
                dist[t]=dist[u]+cost[u][t]
                prev[t]=u
                h.get(t)
        
    return dist[t]


if __name__ == '__main__':
    data = input()
    data=data.split()
    n=int(data[0])
    m=int(data[1])
    for i in range(m):
        data.append(input().split())
    for i in data:
        for j in i:
            data = list(map(int,j))
    edges = list(zip(zip(data[0:(3 * m):3], data[1:(3 * m):3]), data[2:(3 * m):3]))
    data = data[3 * m:]
    adj = [[] for _ in range(n)]
    cost = [[] for _ in range(n)]
    for ((a, b), w) in edges:
        adj[a - 1].append(b - 1)
        cost[a - 1].append(w)
    s, t = data[0] - 1, data[1] - 1
    print(distance(adj, cost, s, t))
