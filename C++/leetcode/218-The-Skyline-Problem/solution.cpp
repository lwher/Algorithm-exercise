struct Event{
    int x, h, belong;
    bool ty; // 0: Insert, 1: Delete
    Event(int _x = 0, int _h = 0, bool _ty = 0, int _belong = -1) : x(_x), h(_h), ty(_ty), belong(_belong) {}
    bool operator <(const Event &other) const{
        return x < other.x;
    }
};

struct HeapNode{
    int h, belong;
    HeapNode(int _h = 0, int _belong = -1) : h(_h), belong(_belong) {}
    bool operator <(const HeapNode &other) const{
        return h < other.h;
    }
};

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size(), l, r, h, top = 0;
        Event *P = new Event[2 * (n + 1)];
        bool *exist = new bool[n + 1];
        vector<pair<int, int> > result;
        for(int i = 0; i < n; ++i){
            l = buildings[i][0];
            r = buildings[i][1];
            h = buildings[i][2];
            P[++top] = Event(l, h, 0, i + 1);
            P[++top] = Event(r, h, 1, i + 1);
        }
        sort(P + 1, P + 1 + top);
        std::priority_queue<HeapNode> Q; 
        Q.push(HeapNode(0, 0));
        exist[0] = 1;
        int now = 1, lasth = -1;
        while(now <= top){
            int x = P[now].x;
            while(now <= top && P[now].x == x){
                if(P[now].ty){ // Delete
                    exist[P[now].belong] = 0;
                }
                else{ // Insert
                    Q.push(HeapNode(P[now].h, P[now].belong));
                    exist[P[now].belong] = 1;
                }
                ++now;
            }
            while(!exist[Q.top().belong]) Q.pop();
            HeapNode q = Q.top();
            if(q.h == lasth) continue;
            else{
                lasth = q.h;
                result.push_back(make_pair(x, q.h));
            }
        }
        return result;
    }
};