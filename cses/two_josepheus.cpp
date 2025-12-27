#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    vector<int> tree;

    SegTree(int n) : n(n) {
        tree.resize(4 * n);
    }

    // Build: initially everyone is alive (1)
    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = 1;
            return;
        }
        int mid = (l + r) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    // Find index of k-th alive person
    int kth(int node, int l, int r, int k) {
        if (l == r) return l;

        int mid = (l + r) / 2;
        if (tree[node * 2] >= k)
            return kth(node * 2, l, mid, k);
        else
            return kth(node * 2 + 1, mid + 1, r, k - tree[node * 2]);
    }

    // Remove a person (set alive = 0)
    void remove(int node, int l, int r, int pos) {
        if (l == r) {
            tree[node] = 0;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            remove(node * 2, l, mid, pos);
        else
            remove(node * 2 + 1, mid + 1, r, pos);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    int alive() {
        return tree[1];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    SegTree st(n);
    st.build(1, 1, n);

    int idx = 0; // 0-based index among alive people

    while (st.alive() > 0) {
        idx = (idx + k) % st.alive();   // circular jump
        int pos = st.kth(1, 1, n, idx + 1); // convert to 1-based
        cout << pos << " ";
        st.remove(1, 1, n, pos);
    }
    cout<<endl;

    return 0;
}
