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

struct RAQ{
	using T = long long;
	T operator()(const T &a, const T &b) { return max(0LL,a) + max(0LL,b); };
	static constexpr T identity() { return 0; }
};

template<class Monoid>
class rangeAddQuery{
	private:
		using T = typename Monoid::T;
		Monoid op;
		const int n;
		vector<T> dat, lazy;
		T query(int a, int b, int k, int l, int r){
			if(b <= l || r <= a) return op.identity();
			else if(a <= l && r <= b) return dat[k] * (r - l) + lazy[k];
			else{
				T res = (min(b,r) - max(a,l)) * dat[k];
				res += query(a, b, k * 2, l, (l + r) / 2);
				res += query(a, b, k * 2 + 1, (l + r) / 2, r);
				return res;
			}
		}
		void add(int a, int b, int k, int l, int r, T x){
			if(a <= l && r <= b){
				dat[k] += x;
			}else if(l < b && a < r){
				lazy[k] += (min(b,r) - max(a,l)) * x;
				add(a, b, k * 2, l, (l + r) / 2, x);
				add(a, b, k * 2 + 1, (l + r) / 2, r, x);

			}
		}
		int power(int n){
			int res = 1;
			while(n >= res) res*=2;
			return res;
		}
	public:
		rangeAddQuery(int n) : n(power(n)), dat(4 * n, op.identity()), lazy(4 * n, op.identity()) {}
		rangeAddQuery(const vector<T> &v) : n(power(v.size())), dat(4 * n), lazy(4 * n, op.identity()){
			copy(begin(v), end(v), begin(dat) + n);
			for(int i = n - 1; i > 0; i--) dat[i] = op(dat[2 * i], dat[2 * i + 1]);
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

	vector<long long> x(n + 1);
	x[0] = 0;
	rep(i,n) cin >> x[i + 1];

	vector<pair<long long, int>> l(q);
	rep(i,q) {
		cin >> l[i].first;
		l[i].second = i;
	}
	sort(all(l));

	// 与えられら座標の差を取る。
	vector<long long> diff(n); //diff[i] >= 0 -> , diff[i] < 0 <-
	range(i,1,n + 1){
		diff[i - 1] = x[i] - x[i - 1];
	}

	// 座標の差を圧縮する。同じ方向に進む場合は加算する
	vector<long long> a;
	rep(i,n){
		if(a.empty() or a.back() * diff[i] < 0){
			a.emplace_back(diff[i]);
		}else{
			a.back() += diff[i];
		}
	}

	// 区間が増えると最大どれだけ特をするのかを計算する。ここが一番大事なところ
	vector<long long> lim(a.size());
	rep(i,lim.size()){
		if(a[i] >= 0){
			if(i > 2 and a[i - 2] > 0 and a[i - 1] < 0 and a[i] > 0 and a[i - 2] >= -a[i - 1]){ // 意味がわからないけどサンプルケースからエスパーした
				lim[i] = min(abs(a[i]), abs(a[i - 1]));
			}else{
				lim[i] = a[i];
			}
		}else{

			 if(i == 0){
				lim[i] = 0;
			}else{
				lim[i] = min(abs(a[i]), abs(a[i - 1]));
			}
		}
	}
	sort(all(lim));
	//cout << a << endl;
	//cout << lim << endl;

	rangeAddQuery<RAQ> seg(lim.size());
	rep(i,n){
		seg.add(i,i + 1,lim[i]);
	}

	long long sum = 0;
	for(auto i : a) sum += abs(i);


	l.insert(l.begin(), make_pair(0, INT_MAX));
	vector<pair<int,long long>> ans(q);

	int index = 0;
	rep(i,q){
		//seg.add(0, lim.size(), -(l[i + 1].first - l[i].first));

		long long s = 0; // どれだけお得になるか
		long long minus = (l[i + 1].first - l[i].first);

		long long temp = seg.get(index);
		while(minus > seg.get(index) and index < lim.size()){ // 引き算してマイナスになってしまう部分は独立に計算
			s += temp;
			seg.add(index, index + 1, temp);
			temp = seg.get(++index);
		}
		if(index < lim.size()){ // range Add して引き算
			s += (lim.size() - index) * minus;
			seg.add(index, lim.size(), -minus);
		}

		ans[i] = make_pair(l[i + 1].second, sum - s);
		//cout << sum << ' ' << s << ' ' << endl;
		sum -= s;

		//rep(i,lim.size()){
		//	cout << seg.get(i) << ' ';
		//}
		//cout << endl;
	}

	sort(all(ans));
	rep(i,q){
		cout << ans[i].second << endl;
	}
}


