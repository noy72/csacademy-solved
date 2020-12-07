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
	int n, m;
	cin >> n >> m;

	vector<int> a(n);
	cin >> a;

	int cnt = 0;
	rep(i,m){
		int com;
		cin >> com;
		if(com == 1){
			int p;
			cin >> p;
			a[p - 1]--;
			if(a[p - 1] < 0){
				cout << p << endl;
				cnt--;
			}
		}else{
			cnt++;
		}
	}
	while(cnt--){
		cout << 1 << endl;
	}
}
