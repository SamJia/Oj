import sys

sys.setrecursionlimit(10100)

class Graph:
    def __init__(self):
        self.V = []

class Vertex:
    def __init__(self, x):
        self.key = x
        self.color = 'white'
        self.d = 10000
        self.f = 10000
        self.pi = None
        self.adj = []

class Solution:
    def Dfs(self, G, flag, result):
        global time
        time = 0
        for u in G.V:
            if u.color == 'white':
                list=[u]
                self.DfsVisit(G, u, list)
                if flag:
                    result += [len(list)]
        for u in G.V:
            u.color = 'white'
            u.pi = None


    def DfsVisit(self, G, u, list):
        global time
        time = time + 1
        u.d = time
        u.color = 'gray'
        for v in u.adj:
            if v.color == 'white':
                list.append(v)
                v.pi = u
                self.DfsVisit(G, v, list)
        u.color = 'black'
        time = time + 1
        u.f = time

    def GraphTransposition(self, G):
        for u in G.V:
            u.adj = (u.adj,[])

        for u in G.V:
            for v in u.adj[0]:
                v.adj[1].append(u)

        for u in G.V:
            u.adj = u.adj[1]

        return G

    def StronglyConnectedComponents(self, G, result):
        self.Dfs(G, 0, result)
        G_Transposition = self.GraphTransposition(G)
        G_Transposition.V.sort(key=lambda v: v.f, reverse=True)
        self.Dfs(G_Transposition, 1, result)






def find_connected(graph):
    result = []

    verList = []
    n = len(graph)
    for i in range(n):
        verList.append(Vertex(i))
    for i in range(n):
        tmpList = []
        for item in graph[i]:
            tmpList.append(verList[item])
        verList[i].adj = tmpList

    G = Graph()
    G.V = verList    


    m = Solution()
    m.StronglyConnectedComponents(G, result)
    result.sort()
    result = result[::-1]

    return result

def main():
    global DFN, Low, stk, graph, visited, result, youyigeset
    nm = raw_input().split(' ')
    n = int(nm[0])
    m = int(nm[1])
    dic = {}
    serial = 0
    graph = [[] for i in range(n)]
    while(1):
        line = raw_input()
        if (line == 'END'):
            break
        name1 = line.split(' ')[0]
        name2 = line.split(' ')[1]
        if (name1 == name2):
            continue
        if not dic.has_key(name1):
            dic[name1] = serial
            serial += 1
        if not dic.has_key(name2):
            dic[name2] = serial
            serial += 1
        flag = False
        for i in graph[dic[name1]]:
            if i == dic[name2]:
                flag = True
                break;
        if not flag:
            graph[dic[name1]].append(dic[name2])

    result = find_connected(graph)
    if len(result) > m:
        for i in range(m):
            print result[i]
    else:
        for item in result:
            print item
        for i in range(m-len(result)):
            print "Does not apply!"

main()