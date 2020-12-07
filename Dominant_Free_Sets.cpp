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

const long long M = 1000000007;

const int MAX_N = 200000;

template <typename T>
class BIT{
	private:
		vector<T> bit; //[1, n]
	public:
		BIT(){
			bit = vector<T>(MAX_N + 1, 0);
		}
		T sum(int i){
			assert(1 <= i and i <= MAX_N and "invalid argument");
			T s = 0;
			while(i > 0){
				s += bit[i];
				i -= i & -i;
			}
			return s;
		}

		void add(int i, T x){
			assert(1 <= i and i <= MAX_N and "invalid argument");
			while(i <= MAX_N){
				bit[i] += x;
				//bit[i] = max(bit[i], x);
				i += i & - i;
			}
		}
};

int main(){
	int n;
	cin >> n;

	vector<pair<int, int>> a(n);
	rep(i,n){
		cin >> a[i].first >> a[i].second;
	}
	sort(all(a));

	BIT<long long> bit;
	for(auto& p : a){
		long long k = (bit.sum(MAX_N) - bit.sum(p.second + 1) + 1) % M;
		bit.add(p.second + 1, k);
	}
	cout << bit.sum(MAX_N) % M << endl;

}
