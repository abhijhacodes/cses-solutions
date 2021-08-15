#include <bits/stdc++.h>
using namespace std;

#ifdef CLASSIC
int N, Q;
vector<int> arr;
vector<int> tree;

void build(int p, int l, int r) {
    if (l == r) {tree[p] = arr[l]; return;}

    int mid = (l + r)/2;
    build(2*p, l, mid);
    build(2*p + 1, mid + 1, r);

    tree[p] = min(tree[2*p], tree[2*p + 1]);
}

void update(int p, int l, int r, int x, int y) {
    // turn arr[x] into y
    if (l == r) { tree[p] = y; return; }

    int mid = (l + r)/2;
    if (x <= mid) {
        update(2*p, l, mid, x, y);
    }
    else {
        update(2*p + 1, mid + 1, r, x, y);
    }

    tree[p] = min(tree[2*p], tree[2*p + 1]);
}

int query(int p, int l, int r, int x, int y) {
    if (l == r) { return tree[p]; }

    int mid = (l + r)/2;
    int ans = INT_MAX;
    if (x <= mid) {
        ans = min(ans, query(2 * p, l, mid, x, y));
    }
    if (y >= mid + 1) {
        ans = min(ans, query(2 * p + 1, mid + 1, r, x, y));
    }

    return ans;
}


int main() {
    cin >> N >> Q;

    arr.resize(N + 1);
    tree.resize(4*N);
    for (int i = 1; i < N + 1; i++) {
        cin >> arr[i];
        update(1, 1, N, i, arr[i]);
    }

    // build(1, 1, N);

    for (int i = 0; i < Q; i++) {
        int what, x, y;
        cin >> what >> x >> y;
        if (what == 1) {
            // update
            update(1, 1, N, x, y);
        }
        else {
            int a = query(1, 1, N, x, y);
            cout << a << endl;
        }
    }
}


#else
template<class T> struct Seg { // comb(ID,b) = b
    const T ID = 1e18; T comb(T a, T b) { return min(a,b); }
    int n; vector<T> seg;
    void init(int _n) { n = _n; seg.assign(2*n,ID); }
    void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
    void upd(int p, T val) { // set val at position p
        seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
    T query(int l, int r) { // min on interval [l, r]
        T ra = ID, rb = ID;
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l&1) ra = comb(ra,seg[l++]);
            if (r&1) rb = comb(seg[--r],rb);
        }
        return comb(ra,rb);
    }
};

Seg<int> st;

int N, Q;

int main() {
    cin >> N >> Q;

    st.init(N + 1);

    for (int i = 1; i < N + 1; i++) {
        int x;
        cin >> x;
        st.upd(i, x);
    }

    for (int i = 0; i < Q; i++) {
        int what, x, y;
        cin >> what >> x >> y;
        if (what == 1) {
            // update
            st.upd(x, y);
        }
        else {
            int a = st.query(x, y-1);
            cout << a << endl;
        }
    }
}
#endif