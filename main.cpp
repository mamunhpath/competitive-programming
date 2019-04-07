#include <iostream>
#include <string>
#include <utility>
#include <sstream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <unordered_set>
#include <ctime>
#include <list>

using namespace std;

template<class T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define F0R1(i, a) for (int i=1; i<=(a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define F0Rd1(i, a) for (int i=a; i>0; i--)
#define SORT(vec) sort(vec.begin(), vec.end())
#define MIN(a, b) a = min(a, b)
#define MAX(a, b) a = max(a, b)

#define INF 1000000010
#define LL_INF 4500000000000000000
#define LSOne(S) (S & (-S))
#define EPS 1e-9
#define pA first
#define pB second
#define mp make_pair
#define pb push_back
#define PI acos(-1.0)
#define ll long long
#define MOD (int)(2e+9+11)
#define SET(vec, val, size) for (int i = 0; i < size; i++) vec[i] = val;
#define SET2D(arr, val, dim1, dim2) F0R(i, dim1) F0R(j, dim2) arr[i][j] = val;
#define SET3D(arr, val, dim1, dim2, dim3) F0R(i, dim1) F0R(j, dim2) F0R(k, dim3) arr[i][j][k] = val;
#define SET4D(arr, val, dim1, dim2, dim3, dim4) F0R(i, dim1) F0R(j, dim2) F0R(k, dim3) F0R(l, dim4) arr[i][j][k][l] = val;
#define READGRID(arr, dim) F0R(i, dim) F0R(j, dim) cin >> arr[i][j];
#define all(x) (x).begin(), (x).end()

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vl;

void setupIO(const string &PROB) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream infile(PROB + ".in");
    if (infile.good()) {
        freopen((PROB + ".in").c_str(), "r", stdin);
        freopen((PROB + ".out").c_str(), "w", stdout);
    }
}

/* ============================ */

vi stuff;

void parse(string s) {
    int lhs = 0, rhs = 0;
    for (char c : s) {
        if (c == '0') lhs++;
        else rhs++;
    }
    stuff.pb(lhs);
    stuff.pb(rhs);
}

string gen(int n, int depth) {
    if (depth == 0) {
        string ask;
        F0R(i, n) {
            if (i < n / 2) ask += "0";
            else ask += "1";
        }
        return ask;
    }
    return gen(n/2, depth-1) + gen(n-n/2, depth-1);
}

int main() {
    int t; cin >> t;
    F0R1(caseNum, t) {
        int n, b, f; cin >> n >> b >> f;
        stuff.clear();

        int nextBigN = 1;
        while (nextBigN < n) nextBigN*=2;

        int idx = 0;
        stuff.pb(n);
        FOR(i, 0, ceil(log2(n))) {
            string ask = gen(nextBigN, i);
            cout << ask.substr(0, n) << endl;
            string resp;
            cin >> resp;
            F0R(j, nextBigN - n) resp += ask[n+j];

            int x = stuff.size();
            int loc = 0;
            FOR(j, idx, x) {
                int len = stuff[j];

                string s = resp.substr(loc, len);
                parse(s);

                loc += len;
            }
            idx = x;
        }

        int loc = 0;
        vi ans;
        FOR(j, idx, stuff.size()) {
            if (stuff[j] == 0 && j - idx <= n) {
                ans.pb(j - idx);
            }
            loc += stuff[j];
        }
        cout << ans[0];
        FOR(j, 1, ans.size()) cout << " " << ans[j];
        cout << endl;
        int blah; cin >> blah;
    }

    return 0;
}
