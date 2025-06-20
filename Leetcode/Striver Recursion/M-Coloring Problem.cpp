class Solution {
public:
	bool pos(int node, vector<int>& color, vector<vector<int>>& adj, int col, int v) {
		for (auto neighbor : adj[node]) {
			if (color[neighbor] == col) {
				return false;
			}
		}
		return true;
	}
	bool f(int node, vector<int>& color, int m, int v, vector<vector<int>>& adj) {
		if (node == v) {
			return true;
		}
		for (int i = 1; i <= m; i++) {
			if (pos(node, color, adj, i, v)) {
				color[node] = i;
				if (f(node + 1, color, m, v, adj)) {
					return true;
				} else {
					color[node] = 0;
				}
			}
		}
		return false;
	}
	bool graphColoring(int v, vector<vector<int>>& edges, int m) {
		// code here
		vector<vector<int>> adj(v);
		for (auto it : edges) {
			adj[it[0]].push_back(it[1]);
			adj[it[1]].push_back(it[0]);
		}
		vector<int> color(v, 0);
		return (f(0, color, m, v, adj));

	}
};