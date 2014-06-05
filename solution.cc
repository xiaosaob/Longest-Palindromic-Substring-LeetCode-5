// Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

class Solution {
public:
    string longestPalindrome(string s) {
        string res("");
        for(int i = 0; i < s.size(); ++i) {
            string s1 = expandFrmCenter(s,i,i);
            if(s1.size() > res.size()) res = s1;
            if(i+1 < s.size()) { 
                string s2 = expandFrmCenter(s,i,i+1);
                if(s2.size() > res.size()) res = s2;
            }
        }
        return res;
    }
    
    string expandFrmCenter(string s, int lidx, int ridx) {
        while(lidx >= 0 && ridx < s.size()) {
            if(s[lidx] != s[ridx]) {
                return s.substr(lidx+1, ridx-lidx-1);
            }
            --lidx;
            ++ridx;
        }
        return s.substr(lidx+1, ridx-lidx-1);
    }
};

