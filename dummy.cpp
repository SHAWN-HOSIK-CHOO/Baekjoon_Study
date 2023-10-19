#include <iostream>
#include <vector>
using namespace std;
bool ans = false;

void dfs(int k,int cur, vector<vector<int>> &v,vector<bool> &vis) {
	if (k == 4) {
		ans = true;
		return;
	}
	for (int j = 0; j < v[cur].size(); j++) {
		int nxt = v[cur][j];
		if (vis[nxt]) continue;
		vis[nxt] = 1;
		dfs(k + 1, nxt, v, vis);
		vis[nxt] = 0;
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		vector<bool> vis(n);
		vis[i] = 1;
		dfs(0, i, v, vis);
		if (ans) break;
	}
	cout << ans;

	return 0;
}