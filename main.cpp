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

using namespace std;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define F0R1(i, a) for (int i=1; i<=(a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define F0Rd1(i, a) for (int i=a; i>0; i--)
#define SORT(vec) sort(vec.begin(), vec.end())

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

bool land[30][30];
bool visited[30][30];

int mi, mj;
int m, n;

int floodfill(int i, int j) {
    if (i < 0) return 0;
    if (i >= m) return 0;
    if (j < 0) j = n - 1;
    if (j >= n) j = 0;
    if (i == mi && j == mj) return -100;
    if (visited[i][j]) return 0;
    visited[i][j] = true;
    if (!land[i][j]) return 0;

    return 1 + floodfill(i + 1, j) + floodfill(i, j + 1) + floodfill(i - 1, j) + floodfill(i, j - 1);
}

int main() {
    while (cin >> m >> n) {

        char graph[30][30];
        F0R(i, m) {
            F0R(j, n) {
                cin >> graph[i][j];
            }
        }

        cin >> mi >> mj;
        char landChar = graph[mi][mj];
        F0R(i, m) {
            F0R(j, n) {
                land[i][j] = graph[i][j] == landChar;
            }
        }

        SET2D(visited, false, m, n);
        int best = 0;
        F0R(i, m) {
            F0R(j, n) {
                if (!visited[i][j]) {
                    best = max(best, floodfill(i, j));
                }
            }
        }
        cout << best << endl;
    }

    return 0;
}