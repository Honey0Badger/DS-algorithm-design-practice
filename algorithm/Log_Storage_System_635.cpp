class LogSystem {
public:
    LogSystem() {
        label["Year"]=0;
        label["Month"]=1;
        label["Day"]=2;
        label["Hour"]=3;
        label["Minute"]=4;
        label["Second"]=5;
    }
    
    void put(int id, string timestamp) {
        logs.insert({flatten(timestamp), id});
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        int pos=0;
        for (int i=0; i<s.length(); ++i) {
            if (!isdigit(s[i])) ++pos;
            else if (label[gra]<pos) {
                s[i]='0';
                e[i]='9';
            }
        }
        auto it = logs.lower_bound({flatten(s),0});
        vector<int> ans;
        while (it != logs.end() && it->first <= flatten(e)) {
            ans.push_back(it->second);
            ++it;
        };
        return ans;
    }
    
private:
    string flatten(string timestamp) {
        int i=0;
        while (i<timestamp.length()) {
            if (!isdigit(timestamp[i])) timestamp.erase(i,1);
            else ++i;
        }
        return timestamp;
    }
    unordered_map<string, int> label;
    set<pair<string,int>> logs;
};
