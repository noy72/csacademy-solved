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

template<typename T>
class CumulativeSum {
	vector<T> a;
	int n;
	public:
	CumulativeSum(vector<T>& x) : a(x.size() + 1,0) , n(x.size() / 3) {
		rep(i,x.size()){
			a[i + 1] = a[i] + x[i];
		}
	}
	T get(int l, int r){ // [l, r]の区間の合計を求める
		if(l > r) swap(l,r);
		return min(a[r + n] - a[l + n], a[l + n] - a[r]);
	}
	T operator [] (const int i) const {
		return a[i];
	}
};

int n;
inline int next(int s){
	return (s + 1) % n;
}
inline int prev(int s){
	return (s - 1 + n) % n;
}

int main(){
	int s;
	cin >> n >> s;
	s--;

	vector<int> a(n * 3);
	rep(i,n){
		int in;
		cin >> in;
		a[i] = a[i + n] = a[i + n + n] = in;
	}

	CumulativeSum<int> sum(a);
	//rep(i,n * 3){ cout << sum[i] << ' ' ; } cout << endl;

	int nxt = next(s), pre = prev(s);
	int ans = 0;
	rep(_,n - 1){
		int x = sum.get(s, nxt);
		int y = sum.get(s, pre);
		if(x < y or(x == y and nxt < pre)){
			ans += x;
			s = nxt;
			nxt = next(s);
		}else{
			ans += y;
			s = pre;
			pre = prev(s);
		}
	}
	cout << ans << endl;
}
