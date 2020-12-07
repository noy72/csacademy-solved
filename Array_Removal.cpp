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

class UnionFind{
	private:
		vector<int> par, depth;
	public:
		vector<int> cnt; // その集合の頂点数
		UnionFind() {}
		UnionFind(int n){
			init(n);
		}
		void init(int n){
			par = vector<int>(n);
			depth = vector<int>(n, 0);
			cnt = vector<int>(n, 1);
			rep(i,n){
				par[i] = i;
			}
		}
		int find(int x){
			if(par[x] == x){
				return x;
			}else {
				return par[x] = find(par[x]);
			}
		}
		void unite(int x, int y){
			x = find(x);
			y = find(y);
			if(x == y) return;

			if(depth[x] < depth[y]){
				par[x] = y;
				cnt[y] += cnt[x];
			}else{
				par[y] = x;
				cnt[x] += cnt[y];
				if(depth[x] == depth[y]) depth[x]++;
			}
		}
		bool same(int x, int y){
			return find(x) == find(y);
		}
};

template<typename T>
class WeightedUnionFind{
	private:
		vector<int> par, depth;
		vector<T> sum; // 集合の重みの総和
	public:
		vector<int> cnt; // その集合の頂点数
		WeightedUnionFind() {}
		WeightedUnionFind(int n, vector<T>& c){
			init(n, c);
		}
		void init(int n, vector<T>& c){
			par = vector<int>(n);
			depth = vector<int>(n, 0);
			cnt = vector<int>(n, 1);
			sum = c;
			rep(i,n){
				par[i] = i;
			}
		}
		int find(int x){
			if(par[x] == x){
				return x;
			}else {
				return par[x] = find(par[x]);
			}
		}
		void unite(int x, int y){
			x = find(x);
			y = find(y);
			if(x == y) return;

			if(depth[x] < depth[y]){
				par[x] = y;
				cnt[y] += cnt[x];
				sum[y] += sum[x];
			}else{
				par[y] = x;
				cnt[x] += cnt[y];
				sum[x] += sum[y];
				if(depth[x] == depth[y]) depth[x]++;
			}
		}
		bool same(int x, int y){
			return find(x) == find(y);
		}
		T weight(int x){
			return sum[find(x)];
		}
};
int main(){
	int n;
	cin >> n;

	vector<long long> a(n);
	vector<int> v(n);
	cin >> a >> v;
	for(auto& i : v) i--;

	WeightedUnionFind<long long> uni(n, a);

	vector<bool> use(n,0);
	long long maxi = 0;
	vector<long long> ans(n);
	for (int i = n - 1; i >= 0; i--) {
		use[ v[i] ] = true;

		if(v[i] - 1 >= 0 and use[ v[i] - 1 ]){
			uni.unite(v[i], v[i] - 1);
		}
		if(v[i] + 1 < n and use[ v[i] + 1 ]){
			uni.unite(v[i], v[i] + 1);
		}
		maxi = max(maxi, uni.weight(v[i]));
		ans[i] = maxi;
	}
	for(auto i : ans) cout << i << endl;
}
