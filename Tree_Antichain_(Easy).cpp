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

bool possible(vector<int>& deg, int n){
	rep(i,n){
		if(deg[i] == n - 1) return false;
	}
	return true;
}

int main(){
	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		vector<int> deg(n);
		set<pair<int, int>> s;
		rep(i,n){
			int a, b;
			cin >> a >> b;
			s.emplace(a,b);
			deg[a]++;
			deg[b]++;
		}

		if(not possible(deg, n)){
			cout << -1 << endl;
		}else{

		}
	}
}
