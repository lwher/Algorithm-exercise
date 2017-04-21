class TrieNode{
public:
    TrieNode* trans[26];
    int belong;
    TrieNode(){
        belong = 0;
        for(int i = 0; i < 26; ++i)
            trans[i] = NULL;
    }
};

class Solution{
public:
    TrieNode *root;
    bool mark[51][51], exist[50010];
    int res[50010], n, m;
    char My_board[51][51];

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    void TrieInsert(int index, const string &s){
        int len = s.size();
        TrieNode *now = root;
        for(int i = 0; i < len; ++i){
            int k = s[i] - 'a';
            if(now -> trans[k] == NULL){
               now -> trans[k] = new TrieNode();
            }
            now = now -> trans[k];
        }
        now -> belong = index;
    }

    void dfs(int x, int y, TrieNode *now){
        mark[x][y] = true;
        if(now -> belong){
            if(!exist[now -> belong]){
                exist[now -> belong] = true;
                res[++res[0]] = now -> belong;
            }
        }
        for(int k = 0; k < 4; ++k){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m || mark[nx][ny]) continue;
            int ch = My_board[nx][ny] - 'a';
            if(now -> trans[ch]){
                dfs(nx, ny, now -> trans[ch]);
            }
        }
        mark[x][y] = false;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        for(int i = 0; i < words.size(); ++i){
            TrieInsert(i + 1, words[i]);
        }
        n = board.size(), m = 0, res[0] = 0;
        if(n > 0) m = board[0].size();
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[i].size(); ++j){
                My_board[i][j] = board[i][j];
            }
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(root -> trans[My_board[i][j] - 'a'])
                    dfs(i, j, root -> trans[My_board[i][j] - 'a']);
            }
        }
        vector<string> answer;
        for(int i = 1; i <= res[0]; ++i){
            answer.push_back(words[res[i] - 1]);
        }
        return answer;
    }
};