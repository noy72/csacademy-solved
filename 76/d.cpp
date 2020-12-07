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

struct D{
	long long r, c;
	bool operator < ( const D &right ) const {
		return c < right.c;
	}
};


struct T{
	long long cnt;
	int idx;
	T(long long cnt, int idx) : cnt(cnt), idx(idx) {}
};

bool containB(D a, D b){
	if(a.r <= b.r) return false;

	long long dif = a.r - b.r;
	if(a.c - dif <= b.c and a.c + dif >= b.c){
		return true;
	}
	return false;
}

bool connect(D a, D b){
	long long right = a.c + a.r - 1;
	long long left = b.c - b.r + 1;
	return left <= right;
}

inline long long get(D a){
	return a.r * a.r;
}

long long get(D a, D b){
	if(a.r < b.r) swap(a,b);
	long long rdif = a.r - b.r;
	long long cdif = abs(a.c - b.c) - rdif;

	if(cdif % 2){
		long long h = b.r - (cdif + 1) / 2;
		return (1 + h) * h;
	}else{
		long long h = b.r - cdif / 2;
		return h * h;
	}
}


signed main(){
	long long n;
	cin >> n;

	vector<D> v(n);
	rep(i,n){
		long long r, c;
		cin >> r >> c;
		v[i] = D{r,c};
	}
	sort(all(v));

	vector<T> s;

	int i = 0;
	//for(auto i : v){ cout << i.first << ' ' << i.second << endl; }
	while(i < n){
		if(s.empty() or not connect(v[s.back().idx], v[i])){
			s.emplace_back(get(v[i]), i);
			i++;
		}else if(containB(v[s.back().idx], v[i])){
			i++;
		}else if(containB(v[i], v[s.back().idx])){
			s.pop_back();
		}else{
			s.emplace_back(get(v[i]) - get(v[i], v[s.back().idx]), i);
			i++;
		}
		//cout << "S " ;
		//for(auto i : s) cout << i.cnt << ' ';
		//cout << endl;
	}

	long long ans = 0;
	for(auto i : s) ans += i.cnt;
	cout << ans << endl;
}
