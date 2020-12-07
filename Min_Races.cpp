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

template < typename pile_type >
struct pile_less : std::binary_function<pile_type, pile_type, bool> {
	bool operator()(const pile_type& x, const pile_type& y) const {
		return x.back() < y.back();
	}
};

template < typename pile_type >
struct pile_more : std::binary_function<pile_type, pile_type, bool> {
	bool operator()(const pile_type& x, const pile_type& y) const {
		return x.back() > y.back();
	}
};

template < typename PileType, typename TableType, typename InputIterator >
void patience_sort(TableType& table, InputIterator first, InputIterator last) {
	typedef PileType pile_type;
	//typedef typename PileType::value_type card_type;
	typedef TableType table_type;
	typedef typename table_type::iterator iterator;

	while (first != last) {
		pile_type new_pile{*first};

		// upper_bound	:	i < j -> a_i < a_j
		// lower_bound	:	i < j -> a_i <= a_j
		// pile_more	:	単調増加
		// pile_less	:	単調減少
		iterator pile_p = std::upper_bound(
				table.begin(), table.end(), new_pile,
				pile_more<pile_type>() );
		if (pile_p != table.end()) {
			pile_p->push_back(new_pile.back());
		} else {
			table.push_back(new_pile);
		}
		first++;
	}
}

vector<vector<int>> psort(vector<int>& a){
	vector<vector<int>> table;
	patience_sort<vector<int>, vector<vector<int>>, vector<int>::const_iterator>(table, a.begin(), a.end());
	return table;
}

int main(){
	int n, k;
	cin >> n >> k;

	vector<pair<int,int>> a(n); // rank, class
	rep(i,n){
		cin >> a[i].second >> a[i].first;
	}
	sort(all(a));

	vector<int> s(n);
	rep(i,n){
		s[i] = a[i].second;
	}

	vector<vector<int>> table = psort(s);
	cout << table.size() << endl;
}
