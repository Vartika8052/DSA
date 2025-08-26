class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int freq[2001] = {0};
        int offset = 1000;

        for(int x : arr){
            freq[x+offset] ++;

        }
        int seen[1001] = {0};
        for(int i = 0; i < 2001; i++){
            if(freq[i] > 0){
                if(seen [freq[i]]) return false;
                seen [freq[i]] = 1;

            }
        }
        return true;

       

    }
};