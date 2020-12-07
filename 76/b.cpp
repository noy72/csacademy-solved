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
	int h, w, x, y;
	cin >> h >> w >> x >> y;

	vector<vector<int>> m(h + x, vector<int>(w + y));
	rep(i,h + x) rep(j,w + y) cin >> m[i][j];

	vector<vector<int>> a(h, vector<int>(w));
	rep(i,h){
		rep(j,w){
			if(i - x < 0 or j - y < 0){
				a[i][j] = m[i][j];
			}else{
				a[i][j] = m[i][j] - a[i - x][j - y];
			}
		}
	}

	rep(i,h){
		rep(j,w){
			if(j) cout << ' ';
			cout << a[i][j];
		}
		cout << endl;
	}
}
