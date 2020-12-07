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


const int kN = 200005;
void primeNumber(bool prime[kN]){
	rep(i,kN) prime[i] = 1;
	prime[0] = prime[1] = 0;
	rep(i,kN){
		if(prime[i]){
			for(int j = i + i; j < kN; j+=i){
				prime[j] = 0;
			}
		}
	}
}

const int INF = 1e8;
const int MAX_V = 10005;

class Edge{
	public:
		int to, cap, rev;
		Edge(int to, int cap, int rev) : to(to), cap(cap), rev(rev) {}
};

class Flow{
	private:
		vector<Edge> G[MAX_V];
		bool used[MAX_V];
		int level[MAX_V]; //sからの距離
		int iter[MAX_V]; //どこまで調べ終わったか

		/* fordFulkerson */
		int dfs(int v, int t, int f){
			if(v == t) return f;
			used[v] = true;
			rep(i,G[v].size()){
				Edge &e = G[v][i];
				if(not used[e.to] && e.cap > 0){
					int d = dfs(e.to, t, min(f, e.cap));
					if(d > 0){
						e.cap -= d;
						G[e.to][e.rev].cap += d;
						return d;
					}
				}
			}
			return 0;
		}

		/* dinic */
		int dfs_(int v, int t, int f){
			if(v == t) return f;
			for(int &i = iter[v]; i < G[v].size(); i++){
				Edge &e = G[v][i];
				if(e.cap > 0 && level[v] < level[e.to]){
					int d = dfs_(e.to, t, min(f, e.cap));
					if(d > 0){
						e.cap -= d;
						G[e.to][e.rev].cap += d;
						return d;
					}
				}
			}
			return 0;
		}
		void bfs(int s){
			memset(level, -1, sizeof(level));
			queue<int> que;
			level[s] = 0;
			que.push(s);
			while(not que.empty()){
				int v = que.front(); que.pop();
				rep(i,G[v].size()){
					Edge &e = G[v][i];
					if(e.cap > 0 && level[e.to] < 0){
						level[e.to] = level[v] + 1;
						que.push(e.to);
					}
				}
			}
		}

		/* minimumVertexCover */
		void dfs(int v, vector<bool>& used){
			used[v] = true;
			for(auto e : G[v]){
				if(e.cap == 0 or used[e.to]) continue;
				dfs(e.to, used);
			}
		}
	public:
		void addEdge(int from, int to, int cap){
			G[from].push_back(Edge(to, cap, static_cast<int>(G[to].size())));
			G[to].push_back(Edge(from, 0, static_cast<int>(G[from].size() - 1)));
		}
		int fordFulkerson(int s, int t){
			int flow = 0;
			while(true){
				memset(used, 0, sizeof(used));
				int f = dfs(s, t, INF);
				if(f == 0) return flow;
				flow += f;
			}
		}
		int dinic(int s, int t){
			int flow = 0;
			while(true){
				bfs(s);
				if(level[t] < 0) return flow;
				memset(iter, 0, sizeof(iter));
				int f;
				while( (f = dfs_(s, t, INF)) > 0){
					flow += f;
				}
			}
		}

		// 二部グラフ G = (U + V, E) の最大マッチング後の残余グラフから、最小点カバーを求める。
		// n := 頂点数
		// s, t := ソース、シンク
		// u := |s から辺が張られている頂点集合|
		vector<int> minimumVertexCover(int n, int s, int t, int u){
			fordFulkerson(s,t);

			vector<bool> used(n,0);
			dfs(s, used);

			vector<int> res;
			rep(i,u){
				if(not used[i]) res.emplace_back(i);
			}
			range(i,u,n - 2){
				if(used[i]) res.emplace_back(i);
			}
			return res;
		}
};

int main(){
	bool p[kN];
	primeNumber(p);

	int n;
	cin >> n;

	vector<int> a(n);
	cin >> a;

	vector<int> even, odd;
	for(auto i : a) (i % 2 == 1 ? odd : even).emplace_back(i);

	Flow flow;
	int s = n, t = s + 1;
	rep(i,even.size()){
		flow.addEdge(s,i,1);
	}

	rep(i,even.size()){
		rep(j,odd.size()){
			if(p[even[i] + odd[j]]) {
				flow.addEdge(i,j + even.size(),1);
			}
		}
	}

	rep(i,odd.size()){
		flow.addEdge(i + even.size(),t,1);
	}

	vector<int> ans = flow.minimumVertexCover(t + 1, s, t, even.size());
	cout << ans.size() << endl;
	rep(i,ans.size()){
		if(i) cout << ' ';
		cout << (ans[i] < even.size() ? even[ans[i]] : odd[ans[i] - even.size()]);
	}
	cout << endl;
}
