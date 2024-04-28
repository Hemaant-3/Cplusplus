#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjlist;
    void addEdge(int u, int v, bool direction)
    {
        // direction = 1 --> directed edge
        // direction = 0 --> undirected edge

        if (direction == 1)
        {
            // directed edge
            //  u se v ki taraf
            adjlist[u].push_back(v);
        }
        else
        {
            // undirected edge
            // u se v
            adjlist[u].push_back(v);
            // v se u
            adjlist[v].push_back(u);
        }
        cout << endl
             << "printing" << endl;
        print();
        cout << endl
             << "printing" << endl;
    }

    void print()
    {
        for (auto i : adjlist)
        {
            cout << i.first << " -> " << "{ ";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << " }" << endl;
        }
    }

    bool checkcyclic(int src){
        queue<int>q;

        unordered_map<int,bool> visited;
        unordered_map<int,int> parent;

        // initial state
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            for (auto &&nbr : adjlist[frontNode])
            {
                if(nbr == parent[frontNode]){
                    continue;
                }
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = frontNode;
                }
                else if(visited[nbr]==true){
                    //cyclic present
                    return true;
                }
            }
            
        }
        return false;
    }
};
int main()
{
    Graph g;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(2, 4, 0);
    g.addEdge(3, 4, 0); //cyclic line
    g.addEdge(2, 5, 0);

    int src = 0;
    bool cycle = g.checkcyclic(src); 

    if(cycle){
        cout<<"cycle found"<<endl;  
    } else{
        cout<<"cycle not found";
    }
    return 0;
}