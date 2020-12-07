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

int l, m, r;

bool C(){
	printf("Q %d %d\n", l + 1, m);
	int f, b;
	cin >> f;

	printf("Q %d %d\n", m + 1, r);
	cin >> b;

	if(f == 2 or (f == 1 and b != 2)) return true;
	else return false;
}

int c(int a[9], int l, int r){
	int mini = 10, p;
	range(i,l,r + 1){
		if(mini > a[i]){
			mini = a[i];
			p = i;
		}
	}
	return p;
}

int get(int n, int pass){
	int p = pass == 0 ? 1 : 0;
	rep(i,n){
		if(pass == i or i == p) continue;
		
		cout << "Q " << p + 1 << ' ' << i + 1 << endl;
		cin >> p;
		p--;
	}
	return p;
}

int main(){
	int n;
	cin >> n;

	cout << "A " << get(n, get(n, -1)) + 1 << endl;
	return 0;


	r = n;
	l = 0;
	rep(i,100){
		m = (r + l) / 2;
		if(C()) r = m;
		else l = m;
	}
	cout << r + 1 << endl;
}
