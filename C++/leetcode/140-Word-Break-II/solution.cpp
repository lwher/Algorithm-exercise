class Solution {
public:
    int top = 0, len, counter = 0;
    int SplitPos[200];
    string S;
    vector<string> Res;
    map<string, bool> Dic;
    bool valid[200];
    vector<int> NextPos[200];
    
    void Add_Result(){
        int lastpos = 0;
        string now = "";
        for(int i = 1; i <= top; ++i){
            for(int j = lastpos; j < SplitPos[i]; ++j)
                now += S[j];
            if(i != top)
                now += " ";
            lastpos = SplitPos[i];
        }
        Res.push_back(now);
    }
    
    void Dfs(int pos){
        if(pos == len){
            Add_Result();
            return;
        }
        int NextPosLen = NextPos[pos].size();
        for(int i = 0; i < NextPosLen; ++i){
            if(!valid[NextPos[pos][i]]) continue;
            SplitPos[++top] = NextPos[pos][i];
            Dfs(NextPos[pos][i]);
            --top;
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        S = s;
        len = s.size();
        Dic.clear();
        for(int i = 0; i < wordDict.size(); ++i){
            Dic[wordDict[i]] = true;
        }
        for(int i = 0; i < len; ++i){
            string now = "";
            for(int j = i; j < len; ++j){
                now += S[j];
                if(Dic.count(now)){
                    NextPos[i].push_back(j + 1);
                }
            }
        }
        valid[len] = true;
        for(int i = len - 1; i >= 0; --i){
            valid[i] = false;
            int NextPosLen = NextPos[i].size();
            for(int j = 0; j < NextPosLen; ++j){
                if(valid[NextPos[i][j]]){
                    valid[i] = true;
                }
            }
        }
        Dfs(0);
        return Res;
    }
};