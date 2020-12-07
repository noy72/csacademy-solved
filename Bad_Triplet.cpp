#include<bits/stdc++.h>
#define range(i,a,b) for(short i = (a); i < (b); i++)
#define rep(i,b) for(short i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

vector<short> ans, visit;
vector<vector<short>> g;
void dfs(short& s, short pos, short k){
	if(k == 0 and s == pos) {
		rep(i,3){
			ans = visit;
		}
		return;
	}
	if(k == 0) return;

	for(auto to : g[pos]){
		if(not visit.empty() and visit.back() == to) continue;

		visit.emplace_back(pos);
		dfs(s, to, k - 1);
		visit.pop_back();
	}
}

int main(){
	short n, m;
	scanf("%d%d", &n, &m);

	g = vector<vector<short>>(n);
	rep(i,m){
		short a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}

	rep(i,n){
		dfs(i, i, 3);
		if(not ans.empty()){
			show("JI")
			rep(j,3){
				printf("%d%c", ans[j] + 1, j == 2 ? '\n' : ' ');
			}
			return 0;
		}
	}


	rep(i,n){
		if(g[i].size() >= 3){
			rep(j,3){
				printf("%d%c", g[i][j] + 1, j == 2 ? '\n' : ' ');
			}
			return 0;
		}
	}

	rep(i,n){
		if(g[i].size() == 1){
			puts("-1");
			return 0;
		}
	}

	if(n % 3 == 0){
		short pos = 0;
		vector<short> v;
		while(v.empty() or pos != 0){
			v.emplace_back(pos + 1);
			pos = g[pos].front();
		}

		short dif = v.size() / 3;
		printf("%d %d %d\n", v[0], v[dif], v[dif + dif]);
	}else{
		puts("-1");
	}
}
