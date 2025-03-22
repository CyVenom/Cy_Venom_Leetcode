#You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.
#Return the number of complete connected components of the graph.
#A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.
#A connected component is said to be complete if there exists an edge between every pair of its vertices.

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> adj(n);
        vector<bool> visited(n, false);
        
        
        for (const auto& edge : edges) {
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }
        
        int completeComponents = 0;
        
        
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                unordered_set<int> component;
                dfs(i, adj, visited, component);
                
               
                bool isComplete = true;
                for (int node : component) {
                    if (adj[node].size() != component.size() - 1) {
                        isComplete = false;
                        break;
                    }
                }
                
                if (isComplete) {
                    completeComponents++;
                }
            }
        }
        
        return completeComponents;
    }
    
private:
    void dfs(int node, vector<unordered_set<int>>& adj, vector<bool>& visited, unordered_set<int>& component) {
        visited[node] = true;
        component.insert(node);
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, component);
            }
        }
    }
};


 
