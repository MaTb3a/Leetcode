class Solution {
public:
    int numTeams(vector<int>& rating) {
        int mx = *max_element(rating.begin(),rating.end());
        int n = rating.size();
        vector<int>pre1(mx+1),pre2(mx+1);

        // pre processing
        for(int j = 0 ; j < n ; j++){
            for(int k = j+1 ; k < n ; k++){
                if(rating[k] > rating[j])
                    pre1[rating[j]]++;
                if(rating[k] < rating[j])
                    pre2[rating[j]]++;
            }
        }

        int cnt = 0;
        for(int i = 0 ; i < n ;i++){
            for(int j = i+1 ; j < n ;j++){

                if(rating[i] < rating[j])
                    cnt+=pre1[rating[j]];
                if(rating[i] > rating[j])
                    cnt+=pre2[rating[j]];

            }
        }
        return cnt;


    }
};