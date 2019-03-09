#include <bits/stdc++h>
using namespace std;

struct Vertex {
    map<int, Vertex*> to;
    Vertex *link = 0;
    int len = 0;
};

int main () {

    int n;
    cin >> n;

    Vertex *root = new Vertex, *cur = root;

    vector< stack<Vertex*> > length_ordered;

    while (n--) {
        int c;
        cin >> c;
        Vertex *v = cur;
        cur = new Vertex;
        cur->len = v->len+1;
        length_ordered[cur->len].push_back(cur);
        while (v && !v->to[c])
            v->to[c] = cur, v = v->link;
        if (!v)
            cur->link = root;
        else if (v->to[c]->len == v->len+1)
            cur->link = v->to[c];
        else {
            Vertex *u = v->to[c];
            Vertex *clone = new Vertex;
            clone->to = u->to;
            clone->link = u->link;
            clone->len = v->len+1;
            length_ordered[clone->len].push_back(clone);
            while (v && v->to[c] == u)
                v->to[c] = clone, v = v->link;
            cur->link = u->link = clone;
        }
    }

    add_string(s);

    long long ans = 0;
    
    for (int i = n; i >= 1; i--) {
        ans = max(ans, 1ll * v->cnt * v->len);
        if (v->link)
            v->link->cnt += v->cnt;
    }

    cout << ans;


    return 0;
}
