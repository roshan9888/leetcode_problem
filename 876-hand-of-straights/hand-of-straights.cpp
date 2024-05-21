class Solution {
    class pair {
    public:
        int key; // Key represents the card value
        int data; // Data represents the frequency of the card

        // Constructor to initialize the Pair
        pair(int key, int data) : key(key), data(data) {}

        // Override < operator to compare Pairs based on their keys
        bool operator<(const pair &o) const {
            return this->key > o.key; // We want a min heap, so invert the comparison
        }
    };
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize != 0) return false;
        unordered_map<int,int>mp;
        for(int i=0;i<hand.size();i++){
            mp[hand[i]]++;
        }

        priority_queue<pair> minHeap;

        for(auto it:mp){
            minHeap.push(pair(it.first,it.second));
        }

        while(!minHeap.empty()){
            vector<pair>temp;
            pair min=minHeap.top();
            minHeap.pop();
            min.data--;
            temp.push_back(min);
            int current=min.key;
            for(int i=1;i<groupSize;i++){
                if(!minHeap.empty()){
                    pair freq=minHeap.top();
                    minHeap.pop();
                    if(freq.key!=current+1){
                        return false;
                    }
                    freq.data--;
                    temp.push_back(freq);
                    current++;
                }
                else{
                    return false;
                }
            }

            for(auto it:temp){
                if(it.data>0){
                    minHeap.push(it);
                }
            }
        }
        return true;
    }
};