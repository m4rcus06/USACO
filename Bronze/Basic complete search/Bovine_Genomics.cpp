#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define st first
#define nd second

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve() {
	int n, m;
	cin >> n >> m;
	vector <string> spot(m + 1), plain(m + 1);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			char ch; cin >> ch;
			spot[j].push_back(ch);
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			char ch; cin >> ch;
			plain[j].push_back(ch);
		}
	}

	int res = 0;
	for (int i = 1; i <= m; ++i) {
		sort(all(spot[i]));
		sort(all(plain[i]));
		spot[i].erase(unique(all(spot[i])), spot[i].end());
		plain[i].erase(unique(all(plain[i])), plain[i].end());

		bool flag = true;
		int x = 0, y = 0;
		while (x < sz(spot[i]) && y < sz(plain[i])) {
			if (spot[i][x] == plain[i][y]) {
				flag = false;
				break;
			}
			if (spot[i][x] < plain[i][y]) ++x;
			else ++y;
		}
		res += flag;
	}
	cout << res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("cownomics.in", "r", stdin);
	freopen("cownomics.out", "w", stdout);

	int t = 1;
	while (t--) {
		solve();
	}

	return 0;
}
