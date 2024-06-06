class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        multiset<int>mst;
        for (auto it : hand)mst.insert(it);
        while(mst.size()){
            int x = *mst.begin();
            for(int i = x ; i < x+groupSize;i++){
                auto it = mst.find(i);
                if(it == mst.end())return false;
                mst.erase(it);
            }
        }
        return true;
    }
};