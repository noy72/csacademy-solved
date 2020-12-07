#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

template <typename X, typename T>
auto vectors(X x, T a) {
	return vector<T>(x, a);
}

template <typename X, typename Y, typename Z, typename... Zs>
auto vectors(X x, Y y, Z z, Zs... zs) {
	auto cont = vectors(y, z, zs...);
	return vector<decltype(cont)>(x, cont);
}

template<typename T>
ostream& operator << (ostream& os, vector<T>& v){
	rep(i,v.size()){ os << v[i] << (i == v.size() - 1 ? "" : " "); } return os;
}
template<typename T>
istream& operator >> (istream& is, vector<T>& v){
	for(T& x: v){ is >> x; } return is;
}

class LCA{
	private:
		vector<vector<int>> g, parent;
		int n, root, log_n;
		bool inited;
		vector<int> depth;
		void dfs(int v, int p, int d){
			parent[0][v] = p;
			depth[v] = d;
			rep(i,g[v].size()){
				if(g[v][i] != p) dfs(g[v][i], v, d + 1);
			}
		}
		void init(){
			inited = true;
			dfs(root, -1, 0);
			rep(k,log_n - 1){
				rep(i,n){
					if(parent[k][i] < 0) parent[k + 1][i] = -1;
					else parent[k + 1][i] = parent[k][ parent[k][i] ];
				}
			}
		}
		void dfs(int pos){
			for(auto to : g[pos]){
				if(dis[to] != -1) continue;
				dis[to] = dis[pos] + 1;
				dfs(to);
			}
		}
	public:
		vector<int> dis;
		LCA(int n, int root = 0) : g(n), parent(log2(n) + 1, vector<int>(n)), n(n), root(root), log_n(log2(n) + 1), inited(false), depth(n), dis(n, -1) { }
		void addEdge(int u, int v){
			g[u].emplace_back(v);
			g[v].emplace_back(u);
		}
		void dfs(){
			dis[0] = 0;
			dfs(0);
		}
		int dist(int u, int v){
			return dis[u] + dis[v] - 2 * dis[get(u,v)];
		}
		int get(int u, int v){
			if(not inited) init();
			if(depth[u] > depth[v]) swap(u, v);
			rep(k,log_n){
				if( (depth[v] - depth[u]) >> k & 1){
					v = parent[k][v];
				}
			}
			if(u == v) return u;
			for(int k = log_n - 1; k >= 0; k--){
				if(parent[k][u] != parent[k][v]){
					u = parent[k][u];
					v = parent[k][v];
				}
			}
			return parent[0][u];
		}
};

pair<int,int> solve(LCA& lca, int a, int b, int c){
	int u = lca.get(b,c);
	return make_pair(lca.dist(a,u) + lca.dist(b,u) + lca.dist(c,u), u);
}

int main(){
	int n, q;
	cin >> n >> q;

	LCA lca(n);
	rep(i,n - 1){
		int a, b;
		cin >> a >> b;
		a--; b--;
		lca.addEdge(a,b);
	}
	lca.dfs();

	rep(i,q){
		pair<int,int> ans(INT_MAX,0);
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--; c--;
		ans = min(ans, solve(lca, a, b, c));
		ans = min(ans, solve(lca, b, a, c));
		ans = min(ans, solve(lca, c, b, a));
		cout << ans.second + 1 << ' ' << ans.first  << endl;
	}
}
