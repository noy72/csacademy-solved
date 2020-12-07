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


int main(){
	int n, k, m, s;
	cin >> n >> k >> m >> s;

	vector<bool> no(n, false);
	rep(i,m){
		int a;
		cin >> a;
		no[a - 1] = true;
	}

	vector<int> dis(n, 1e9);
	dis[s - 1] = 0;
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.emplace(0, s - 1);
	while(not q.empty()){
		int cost, pos;
		tie(cost, pos) = q.top(); q.pop();

		for (int len = k % 2 ? 2 : 1; len <= k; len+=2) {
			if(pos - (k - 1 - len) / 2 < 0) continue;
			  
		}
	}
	
	rep(i,n){
		if(i) cout << ' ';
		cout << (dis[i] == 1e9 ? -1 : dis[i]);
	}
	cout << endl;
}
