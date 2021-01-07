
import sys
import queue

def bipartite(adj):
    

    q = queue.Queue()    #to process from one point and outerwards from that point
    #initialize all vertices to zero (undiscovered)
    tag = len(adj) * [0]
    #initialize first vertex with tag 1 and add to Queue
    tag[0] = 1
    q.put(0)
    while not q.empty():
        u = q.get()
        for i in adj[u]:    #process all immediate neighbors
            #check if tag is the same as u, if it is, the graph is not bipartite
            if tag[i] == tag[u]:
                return 0  #tag is not bipartite since tag(u) = tag(i)
            elif tag[i] == 0:
                q.put(i)  #if undiscovered, add to queue for processing and give it a tag of alternating number
                if tag[u] == 1:
                    tag[i] = 2
                else:
                    tag[i] = 1

    return 1

if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n, m = data[0:2]
    data = data[2:]
    edges = list(zip(data[0:(2 * m):2], data[1:(2 * m):2]))
    adj = [[] for _ in range(n)]
    for (a, b) in edges:
        adj[a - 1].append(b - 1)
        adj[b - 1].append(a - 1)
    print(bipartite(adj))