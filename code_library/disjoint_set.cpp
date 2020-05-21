#include <stdio.h>
#include <bits/stdtr1c++.h>

using namespace std;

struct DSU{
    int n;
    vector <int> counter, parent;

    DSU(int n): n(n){
        parent.resize(n + 1);
        counter.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int find_root(int i){
        while (i != parent[i]){
            parent[i] = parent[parent[i]];
            i = parent[i];
        }
        return parent[i];
    }

    void connect(int a, int b){
        int c = find_root(a), d = find_root(b);
        if (c != d){
            parent[c] = d;
            counter[d] += counter[c], counter[c] = 0;
        }
    }

    bool is_connected(int a, int b){
        return find_root(a) == find_root(b);
    }

    int component_size(int i){
        int p = find_root(i);
        return counter[p];
    }
};

int main(){
    auto dsu = DSU(8);
    dsu.connect(1, 2);
    dsu.connect(1, 3);
    dsu.connect(4, 5);
    dsu.connect(5, 6);
    dsu.connect(6, 7);

    printf("%d\n", dsu.component_size(3));  /// 3
    printf("%d\n", dsu.component_size(5));  /// 4
    printf("%d\n", dsu.is_connected(3, 5)); /// 0

    dsu.connect(2, 5);

    printf("%d\n", dsu.component_size(2));  /// 7
    printf("%d\n", dsu.component_size(6));  /// 7
    printf("%d\n", dsu.is_connected(3, 5)); /// 1

    return 0;
}
