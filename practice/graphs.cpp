#include<iostream>
#include<vector>
#include<queue>

using namespace std;
using pii = pair<int,int>;


vector<int> dijkstra(vector<vector<pair<int,int>>> &al, int src) {
    int n = al.size();
    vector<int> dist(n, -1);
    dist[src] = 0;
    auto cmp = [](auto &a, auto &b) -> bool {
        return a.second > b.second;
    };
    priority_queue<pii,vector<pii>, decltype(cmp) > pq(cmp);

    pq.push({src, 0});

    while(pq.size() > 0) {
        auto top = pq.top();
        pq.pop();
        auto node = top.first;
        auto wt = top.second;
        if(dist[node] < wt) {
            continue;
        }
        for(auto &ne: al[node]) {
            int next = ne.first;
            int ewt = ne.second;
            if(dist[next] == -1 || wt + ewt < dist[next]) {
                dist[next] = wt + ewt;
                pq.push({next, wt + ewt});
            }
        }
    }
    return dist;
}


vector<int> kahns(vector<vector<int>> &al) {
    int n = al.size();
    vector<int> indeg(n, 0);
    vector<int> order;

    for(int i=0;i<n;i++) {
        for(int ne: al[i]) {
            indeg[ne] += 1;
        }
    }
    queue<int> q;
    for(int i=0;i<n;i++) {
        if(indeg[i] == 0) {
            q.push(i);
        }
    }

    while(q.size() > 0) {
        auto top = q.front();
        q.pop();
        order.push_back(top);
        for(int ne: al[top]) {
            indeg[ne] -= 1;
            if(indeg[ne] == 0) {
                q.push(ne);
            }
        }
    }
    if(order.size() < n) {
        return {};
    }
    return order;
}


class UnionFind {
    vector<int> parent, size;
    public:
    UnionFind(int n) {
        parent.assign(n, 0);
        size.assign(n, 1);
        for(int i=0;i<n;i++) {
            parent[i] = i;
        }
    }
    int find(int a) {
        if(parent[a] != a) {
            parent[a] = find(parent[a]);
        }
        return parent[a];
    }
    void merge(int x, int y) {
        int a = find(x);
        int b = find(y);
        if(a == b) {
            return;
        }
        if(size[a] > size[b]) {
            parent[b] = a;
            size[a] += size[b];
        }else {
            parent[a] = b;
            size[b] += size[a];
        }
    }
    bool can_merge(int x, int y) {
        int a = find(x);
        int b = find(y);
        return a != b;
    }
};

void merge(vector<int> &arr, int left, int mid, int right) {
    if(left > right) {
        return;
    }

    int n = right - left + 1;
    vector<int> temp(n, 0);
    int i = left, j = mid + 1, k = 0;

    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i += 1;
            k += 1;
        }else {
            temp[k] = arr[j];
            j += 1;
            k += 1;
        }
    }

    while(i <= mid) {
        temp[k] = arr[i];
        i += 1;
        k += 1;
    }
    while(j <= right) {
        temp[k] = arr[j];
        j += 1;
        k += 1;
    }
    k = 0;
    for(int it=left;it<=right;it++) {
        arr[it] = temp[k];
        k+=1;
    }
}

void mergeSort(vector<int> &arr, int left, int right) {
    if(left >= right) {
        return;
    }
    if(left + 1 == right) {
        if(arr[left] > arr[right]) {
            swap(arr[left], arr[right]);
        }
        return;
    }
    int n = right - left + 1;
    int mid = left + (right - left)/2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}


vector<int> kmp(string &s) {
    int n = s.size();
    vector<int> arr(n, 0);
    arr[0] = 1;
    for(int i=1;i<n;i++) {
        int j = arr[i - 1];
        while(s[i] != s[j]) {
            j = arr[j] - 1;
        }
        if(s[i] == s[j]) {
            j += 1;
        }
        arr[i] = j;
    }
    return arr;
}

int main() {
    vector<int> arr{10, 0, 2, 1000, -100, -28, 8};
    mergeSort(arr, 0, arr.size() - 1);
    for(int i=0;i<arr.size();i++) {
        cout<<arr[i] << " ";
    }
    cout<<endl;
    return 0;
}