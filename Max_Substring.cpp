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

bool check(string& s, vector<int>& p, vector<bool>& use, int j){
	char t = -1;
	rep(i,p.size()){
		if(p[i] + j >= s.size()) continue;
		if(t == -1){
			t = s[ p[i] + j ];
			if(not use[t - 'a']) return false;
		}else{
			if(s[ p[i] + j ] != t) return false;
		}
	}
	return true;
}

int main(){
	string s;
	cin >> s;

	map<char,int> m;
	for(auto i : s) m[i]++;

	int maxi = 0;
	for(auto i : m) maxi = max(maxi, i.second);

	vector<bool> use(26, 0);
	for(auto i : m) if(i.second == maxi) use[i.first - 'a'] = true;

	vector<vector<int>> alp(26);
	rep(i,s.size()) alp[s[i] - 'a'].emplace_back(i);

	string ans;
	rep(i,26){
		string t;
		if(not use[i]) continue;

		int j = 0;
		while(alp[i].back() + j < s.size()){
			if(check(s, alp[i], use, j)){
				t += s[ alp[i].front() + j ];
				j++;
			}else{
				if(ans.size() < t.size()) ans = t;
				else if(ans.size() == t.size() and ans.size() > t.size()) ans = t;
				break;
			}
		}
		if(ans.size() < t.size()) ans = t;
		else if(ans.size() == t.size() and ans.size() > t.size()) ans = t;
	}
	cout << ans << endl;
}
