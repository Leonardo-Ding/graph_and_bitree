#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

class SparseGraph{
public:
    SparseGraph(size_t num_node, bool directed){
        this->num_node_ = num_node;
        this->num_edge_ = 0;
        this->directed = directed;
        for(int i = 0; i < num_node_; ++i)
            adj_table_.push_back(vector<int>());
    }

    ~SparseGraph(){
    }

    size_t V() const {
        return num_node_;
    }
    size_t E() const {
        return num_edge_;
    }
    void addEgde(int v, int w){
        adj_table_[v].push_back(w);
        if(!directed)
            adj_table_[w].push_back(v);
        ++num_edge_;
    }
    bool hasEdge(int v, int w){
        for(int i = 0; i < adj_table_[v].size(); ++i){
            if(adj_table_[v][i] == w)
                return true;
        }
        return false;
    }
    void Print(){
        for(int i = 0; i < adj_table_.size(); ++i){
            cout << "边" << i << ":";
            for(int j = 0; j < adj_table_[i].size(); ++j){
                cout << adj_table_[i][j] << " ";
            }
            cout << endl;
        }
    }

    void dfs(int v){
        vector<bool> visited(num_node_, false);
        stack<int> s;
        s.push(v);
        while(!s.empty()){
            int tmp = s.top();
            if(!visited[tmp])
                cout << tmp << " ";
            visited[tmp] = true;
            s.pop();
            int size = adj_table_[tmp].size();
            for(int i = 0; i < size; ++i){
                int b = adj_table_[tmp][i];
                if(!visited[b])
                    s.push(b);
            }
        }
        cout << endl;
    }
    void bfs(int v){
        vector<bool> visited(num_node_, false);
        queue<int> que;
        que.push(v);
        while(!que.empty()){
            int tmp = que.front();
            if(!visited[tmp])
                cout << tmp << " ";
            visited[tmp] = true;
            que.pop();
            int size = adj_table_[tmp].size();
            for(int i = 0; i < size; ++i){
                int b = adj_table_[tmp][i];
                if(!visited[b])
                    que.push(b);
            }
        }
        cout << endl;
    }
private:
    size_t num_node_;       //n为节点个数，
    size_t num_edge_;       //m为边的条数
    bool directed;          //是否为有向图
    std::vector<std::vector<int> > adj_table_;
};

int main(){
    int vertex, edge;
    cin >> vertex >> edge;
    //创建无向图
    SparseGraph myGraph(vertex, false);
    for(int i = 0; i < edge; ++i){
        int from, to;
        cin >> from >> to;
        myGraph.addEgde(from, to);
    }
    myGraph.Print();
    myGraph.dfs(0);
    myGraph.bfs(0);
    return 0;
}
