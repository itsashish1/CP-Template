#include <bits/stdc++.h>
using namespace std;

// ============ FAST I/O ============
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'

// ============ TYPE DEFINITIONS ============
#define int long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vpii vector<pii>
#define all(x) (x).begin(), (x).end()

// ============ CONSTANTS ============
const int MOD = 1e9 + 7;
const int INF = 1e18;
const int MAXN = 2e5 + 5;

// ============ GCD & LCM ============
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }

// ============ MODULAR ARITHMETIC ============
int power(int base, int exp, int mod = MOD) {
    int res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}
int modInverse(int n, int mod = MOD) { return power(n, mod - 2, mod); }

// ============ PRIME SIEVE ============
vector<bool> isPrime(MAXN, true);
void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < MAXN; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < MAXN; j += i)
                isPrime[j] = false;
        }
    }
}

// ============ DSU (Disjoint Set Union) ============
struct DSU {
    vector<int> parent, rank;
    DSU(int n) { parent.resize(n); iota(parent.begin(), parent.end(), 0); rank.assign(n, 0); }
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
        return true;
    }
};

// ============ SEGMENT TREE ============
struct SegTree {
    int n;
    vector<int> tree;
    SegTree(int n) : n(n) { tree.resize(4 * n, 0); }
    void build(vi& arr, int node, int start, int end) {
        if (start == end) { tree[node] = arr[start]; return; }
        int mid = (start + end) / 2;
        build(arr, 2*node, start, mid);
        build(arr, 2*node+1, mid+1, end);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return query(2*node, start, mid, l, r) + query(2*node+1, mid+1, end, l, r);
    }
};

// ============ BINARY SEARCH ============
bool bs(vi& arr, int target) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target) return true;
        if (arr[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return false;
}

// ============ MAIN TEMPLATE ============
void solve() {
    int n; cin >> n;
    // Write your solution here
}

signed main() {
    fast_io();
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
