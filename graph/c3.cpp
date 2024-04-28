#include <iostream>
#include <unordered_map>
#include <list>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class graph
{
public:
    unordered_map<int, list<int>> adjlist;

    void addEdge(int u, int v, bool direction)
    {
        if (direction == 1)
        {
            adjlist[u].push_back(v);
        }
        else
        {
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
    }

    void printad()
    {
        for (auto &&i : adjlist)
        {
            cout << i.first << ": {";
            for (auto &&j : i.second)
            {
                cout << j << ",";
            }
            cout << "}" << endl;
        }
    }

    void toposortDfs(int src, map<int, bool> &vis, stack<int> &st)
    {
        vis[src] = true;

        for (auto nbr : adjlist[src])
        {
            if (!vis[nbr])
            {
                toposortDfs(nbr, vis, st);
            }
        }
        st.push(src);
    }

    void topSortBfs(int n, vector<int> &topoOrd)
    {
        queue<int> q;
        map<int, int> indegree;

        // initialize indegree sbki
        for (auto &&i : adjlist)
        {
            for (auto &&nbr : i.second)
            {
                indegree[nbr]++;
            }
        }
        // for (auto &&i : indegree)
        // {
        //     cout<<i.first<<"->"<<i.second<<endl;
        // }

        // push all zero indegree wali node  into queue

        // push all zero indegree node in queue
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // bfs chalate hai
        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            // cout<<frontNode<<", ";
            topoOrd.push_back(frontNode);

            for (auto &&nbr : adjlist[frontNode])
            {
                indegree[nbr]--;

                // check for zero indegree
                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
    }

  	void shortestPathBfs(int src, int dest) {
		queue<int> q;
		map<int,bool> visited;
		map<int,int> parent;

		//initial state
		q.push(src);
		visited[src] = true;
		parent[src] = -1;

		while(!q.empty()) {
			int frontNode = q.front();
			q.pop();

			for(auto nbr: adjlist[frontNode]) {
				if(!visited[nbr]) {
					q.push(nbr);
					parent[nbr] = frontNode;
					visited[nbr] = true;
				}
			}
		}

		//parent array tyaar hoga 
		vector<int> ans;
		while(dest != -1) {
			ans.push_back(dest);
			dest = parent[dest];
		}

		reverse(ans.begin(), ans.end());
		//printig the shortest path
		for(auto i: ans) {
			cout << i <<" ";
		}
		
	}
};
int main()
{
    graph g;
g.addEdge(0, 5, 0);
	g.addEdge(5, 4, 0);
	g.addEdge(4, 3, 0);
	g.addEdge(0, 6, 0);
	g.addEdge(6, 3, 0);
	g.addEdge(0, 1, 0);
	g.addEdge(1, 2, 0);
	g.addEdge(2, 3, 0);


    // int n = 7; 
    int src = 0;
    int dest = 3;

    g.shortestPathBfs(src,dest);

    // g.printad();
    // vector<int> topoOrd;
    // int n = 8;
    // g.topSortBfs(n, topoOrd);
    // for (int i = 0; i < topoOrd.size(); i++)
    // {
    //     cout << topoOrd[i] << " ";
    // }

    // map<int,bool> vis;
    // stack<int>st;

    // for (int i = 0; i < n; i++)
    // {
    //     if(!vis[i]){
    //         g.toposortDfs(i,vis,st);
    //     }
    // }

    // cout<<"prinitng stack"<<endl;
    // while (!st.empty())
    // {
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }

    return 0;
}