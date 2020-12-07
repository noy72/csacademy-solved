#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

template<typename T>
ostream& operator << (ostream& os, vector<T>& v){
	rep(i,v.size()){ os << v[i] << (i == v.size() - 1 ? "" : " "); } return os;
}
template<typename T>
istream& operator >> (istream& is, vector<T>& v){
	for(T& x: v){ is >> x; } return is;
}

struct Edge {
	int to;
	bool remove;
};

int dfs(int pos, vector<vector<Edge>>& g, vector<bool>& used){
	used[pos] = true;

	int res = 1;
	for (auto& e : g[pos]) {
		if(used[e.to]) continue;
		res += dfs(e.to, g, used);
	}
	return res;
}

vector<int> bfs(int n, vector<vector<Edge>>& g){
	vector<bool> used(n, 0);

	queue<int> q;
	q.emplace(0);

	while(not q.empty()){
		int pos = q.front(); q.pop();
		used[pos] = true;
		for(auto e : g[pos]){
			if(not e.remove and not used[e.to]){
				q.emplace(e.to);
			}
		}
	}

	vector<int> res;
	rep(i,n) if(used[i]) res.emplace_back(i);
	return res;
}

int main(){
	int n, k;
	cin >> n >> k;

	vector<vector<Edge>> g(n);
	rep(i,n - 1){
		int a, b;
		bool c;
		cin >> a >> b >> c;
		a--; b--;
		g[a].emplace_back(Edge{b,c});
		g[b].emplace_back(Edge{a,c});
	}

	vector<int> s = bfs(n, g);
	vector<int> c;
	vector<bool> used(n, 0);
	rep(i,s.size()) used[s[i]] = true;
	rep(i,s.size()){
		for(auto e : g[ s[i] ]){
			if(e.remove == 1){
				c.emplace_back(dfs(e.to, g, used));
			}
		}
	}

	int cnt = 0;
	int sum = n;
	sort(all(c), greater<int>());
	rep(i,c.size()){
		if(sum <= k) break;
		sum -= c[i];
		cnt++;
	}
	if(sum > k) cout << -1 << endl;
	else cout << cnt << endl;
}
