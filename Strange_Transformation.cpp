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

map<int, int> primeFactor(int n){
	map<int, int> res;
	for(int i = 2; i * i <= n; i++){
		while(n % i == 0){
			++res[i];
			n /= i;
		}
	}
	if(n != 1) res[n] = 1;
	return res;
}

bool isValid(map<int,int>& a, map<int,int>& b){
	for(auto p : a){
		if(p.first == 2 or p.first == 3) continue;
		if(p.second != b[p.first]) return false;
	}
	for(auto p : b){
		if(p.first == 2 or p.first == 3) continue;
		if(p.second != a[p.first]) return false;
	}

	//if(a[2] < b[2] or a[3] > b[3]) return false;
	return true;
}

int main(){
	int n, a, b;
	cin >> n >> a >> b;

	vector<int> p(n);
	rep(i,n) cin >> p[i];

	vector<map<int,int>> m(n + 2);
	m[0] = primeFactor(a);
	rep(i,n){
		m[i + 1] = primeFactor(p[i]);
	}
	m[n + 1] = primeFactor(b);

	rep(i,m.size()){
		if(not isValid(m[0], m[i])){
			cout << -1 << endl;
			return 0;
		}
	}

	vector<pair<int, int>> pr(n);
	rep(i,n){
		pr[i] = make_pair(-m[i + 1][2], m[i + 1][3]);
	}
	sort(all(pr));
	rep(i,n){
		pr[i].first *= -1;
	}

	pr.insert(pr.begin(), make_pair(m[0][2], m[0][3]));
	pr.emplace_back(make_pair(m[n + 1][2], m[n + 1][3]));

	rep(i,pr.size() - 1){
		if(pr[i].first < pr[i + 1].first or pr[i].second > pr[i + 1].second){
			cout << -1 << endl;
			return 0;
		}
	}

	//rep(i,pr.size()){ cout << pr[i].first << ' ' << pr[i].second << endl; }

	vector<int> ans = {a};
	rep(i,pr.size() - 1){
		rep(_, pr[i].first - pr[i + 1].first){
			ans.emplace_back(ans.back() / 2);
		}
		rep(_, pr[i + 1].second - pr[i].second){
			ans.emplace_back(ans.back() * 3);
		}
	}

	rep(i,ans.size()){
		cout << ans[i] << (i + 1 == ans.size() ? '\n' : ' ');
	}
}
