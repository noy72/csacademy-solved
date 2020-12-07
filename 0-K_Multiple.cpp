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
	int n, k;
	cin >> n >> k;

	queue<int> q;
	q.emplace(k % n);

	vector<int> path(n, -1);
	vector<char> c(n);

	path[k % n] = 0;
	c[k % n] = k + '0';
	while(path[0] == -1){
		int pos = q.front(); q.pop();
		for(auto i : {0, k}){
			int nxt = (pos * 10 + i) % n;
			if(path[nxt] == -1){
				path[nxt] = pos;
				c[nxt] = i + '0';
				q.emplace(nxt);
			}
		}
	}

	int pos = 0;
	string s;
	do{
		s += c[pos];
		pos = path[pos];
	}while(pos != 0);
	reverse(all(s));
	cout << s << endl;
}
