class Solution {
public:
    string replaceDigits(string s) {
        int n = s.length();
        for (int i = 1; i < n; i+=2){
            int shift = s[i] - '0';
            s[i] = s[i-1] + shift;
        }
        return s;
        
    }
};