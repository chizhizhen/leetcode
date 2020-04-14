N张扑克牌 5张同花顺

花色：S H C D
点数：A 2 3 4 5 6 7 8 9 10 J Q K

方片K："DK"
黑桃10："S10"

A 2 3 4 5
2 3 4 5 6
... ...
9 10 J Q K
10 J Q K A

unodered_map<string, int> str_val = {{"A",1},{"2",2},{"3",3},{"4",4},{"5",5},{"6",6},{"7",7},{"8",8},{"9",9},{"10",10},{"J",11},{"Q",12},{"K",13}};

bool f(const vector<string>& cards) {
    unordered_map<char, int> dict;
    unordered_map<char, int>::iterator iter;
    for (const auto& c:cards) {
        dict[c[0]]++;
    }
    vector<char> firstStrs;
    for (iter = dict.begin(); iter != dict.end(); iter++) {
        if (iter->second >= 5) {
            firstStrs.push_back(iter->first);
        }
    }
    if (firstStrs.size() == 0) return false;
    for (auto &firstS :firstStrs) {
        vector<string> cards_f;
        for (const auto& c:cards) {
            if (c[0] == firstS) cards_f.push_back(c);
        }
        vector<int> cards_i;
        for (auto& c:cards_f) {
            string sub = c.substr(1, c.size());
            int val = str_val[sub];
            cards_i.push_back(val);
        }
        if isT(cards_i) return true; 
    }
    return false;
}
bool isT(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    if (nums[0] == 1 && nums[n-1] == 13 && nums[n-2] == 12 && nums[n-3] == 11 && nums[n-4] == 10) return true;
    for (int i = 0; i < n - 4; i++) {
        int tmp = nums[i];
        if (nums[i+1]-tmp ==1 && nums[i+2]-tmp == 2 && nums[i+3]-tmp == 3 && nums[i+4]-tmp == 4) {
            return true;
        }
    }
    return false;
}
