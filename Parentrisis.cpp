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
	public:
	CumulativeSum(vector<T>& x) : a(x.size() + 1,0) {
		rep(i,x.size()){
			a[i + 1] = a[i] + x[i];
		}
	}
	T get(int l, int r){ // [l, r]の区間の合計を求める
		return a[r + 1] - a[l];
	}
	T operator [] (const int i) const {
		return a[i];
	}
};

// 1. カッコの対応が正しいできるだけ長い文字列を作る
// 2. 1で使われなかった文字列を列挙する
// 3. 2で列挙したカッコに対応するカッコを1の文字列の中から探す

int main(){
	int n;
	cin >> n;

	while(n--){
		string s;
		cin >> s;

		vector<int> p(s.size(), 0);
		rep(i,s.size()){
			if(s[i] == '(') p[i]++;
			else p[i]--;
		}

		CumulativeSum<int> sum(p);

		rep(i,p.size()){ cout << sum[i + 1] << ' '; } cout << endl;

		vector<int> a(s.size(), 0);
		int cnt = 0;
		rep(i,p.size()){
			if(sum[i + 1] + cnt < 0){
				a[i]++;
				cnt++;
			}
		}
		cout << a << endl;

		cnt = sum[p.size()] + cnt;
		//show(cnt)
		assert(a.back() >= 0);
		for(int i = s.size() - 1; i >= 0 and cnt != 0; i--){
			if(s[i] == '('){
				cnt--;
				a[i]++;
			}
		}
		cout << a << endl;

		if(cnt < 0){
			cout << "impossible" << endl;
			continue;
		}


		cnt = 0;
		rep(i,s.size()){
			if(a[i] == 1 and s[i] == '('){
				cnt++;
			}
			if(cnt > 0 and a[i] == 0 and s[i] == ')'){
				a[i] = 2;
				cnt--;
			}
		}

		if(cnt != 0){
			cout << "impossible" << endl;
			continue;
		}

		cnt = 0;
		for(int i = s.size() - 1; i >= 0; i--){
			if(a[i] == 1 and s[i] == ')'){
				cnt++;
			}
			if(cnt > 0 and a[i] == 0 and s[i] == '('){
				a[i] = 2;
				cnt--;
			}
		}

		if(cnt != 0){
			cout << "impossible" << endl;
			continue;
		}

		string ans;
		rep(i,a.size()){
			ans+=("RBG"[a[i]]);
		}
		cout << ans << endl;
	}
}
