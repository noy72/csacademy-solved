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

struct RMQ{
	using T = long long;
	T operator()(const T &a, const T &b) { return max(a,b); };
	static constexpr T identity() { return 0; }
	static constexpr T init() { return 0; }
};

template<class Monoid>
class rangeAddQuery{
	private:
		using T = typename Monoid::T;
		Monoid op;
		const int n;
		vector<T> dat, lazy;
		T query(int a, int b, int k, int l, int r){
			eval(k);
			if(b <= l || r <= a) return op.identity();
			else if(a <= l && r <= b) return dat[k];
			else{
				T left = query(a, b, k * 2, l, (l + r) / 2);
				T right = query(a, b, k * 2 + 1, (l + r) / 2, r);
				propTo(k);
				return op(left, right);
			}
		}
		void add(int a, int b, int k, int l, int r, T x){
			eval(k);
			if(a <= l && r <= b){
				lazy[k] += x;
				eval(k);
			}else if(l < b && a < r){
				add(a, b, k * 2, l, (l + r) / 2, x);
				add(a, b, k * 2 + 1, (l + r) / 2, r, x);
				propTo(k);
			}
		}
		inline void eval(int k){
			if(lazy[k] == op.init()) return;
			dat[k] += lazy[k];
			if(k < n){
				lazy[k * 2] += lazy[k];
				lazy[k * 2 + 1] += lazy[k];
			}
			lazy[k] = op.init();
		}
		inline void propTo(int k){
			dat[k] = op(dat[k * 2], dat[k * 2 + 1]);
		}
		int power(int n){
			int res = 1;
			while(n >= res) res*=2;
			return res;
		}
	public:
		rangeAddQuery(int n) : n(power(n)), dat(4 * n, op.identity()), lazy(4 * n, op.init()) {}
		rangeAddQuery(const vector<T> &v) : n(power(v.size())), dat(4 * n), lazy(4 * n, op.init()){
			copy(begin(v), end(v), begin(dat) + n);
			for(int i = n - 1; i > 0; i--) propTo(i);
		}
		T query(int a, int b){ return query(a,b,1,0,n); }
		void add(int s, int t, T x){ add(s, t, 1, 0, n, x); }
		T get(int a){ return query(a, a + 1); };
		void out(){
			rep(i,n * 2){ cout << dat[i + 1] << ' '; } cout << endl;
		}
};

int main(){
	int n, q;
	cin >> n >> q;
	
	vector<tuple<int,int,long long>> t(q);
	rangeAddQuery<RMQ> seg(n);
	rep(i,q){
		int a, b;
		long long c;
		cin >> a >> b >> c;
		t[i] = make_tuple(a,b,c);
		seg.add(a - 1, b, c);
	}

	long long ans = 1e9 + 1;
	rep(i,q){
		int a, b;
		long long c;
		tie(a,b,c) = t[i];
		seg.add(a - 1, b, -c);
		ans = min(ans, seg.query(0, n));
		seg.add(a - 1, b, c);
	}
	cout << ans << endl;
}
