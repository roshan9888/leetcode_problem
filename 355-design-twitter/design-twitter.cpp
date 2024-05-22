class Twitter {
private:
    struct Tweet{
        int tweetId;
        int timestamp;
        Tweet(int id,int time):tweetId(id),timestamp(time){}
    };

    unordered_map<int,list<Tweet>>userTweets;
    unordered_map<int,unordered_set<int>>followers;
    int timestamp;

    struct TweetComparator {
        bool operator()(const pair<int, list<Tweet>::iterator>& a, const pair<int, list<Tweet>::iterator>& b) {
            return a.first < b.first; // This creates a max heap based on the timestamp
        }
    };
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        userTweets[userId].emplace_front(tweetId,timestamp++);
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, list<Tweet>::iterator>, vector<pair<int, list<Tweet>::iterator>>, TweetComparator> minHeap;
        
         // Add user's own tweets to the heap
        if (userTweets.find(userId) != userTweets.end()) {
            for (auto it = userTweets[userId].begin(); it != userTweets[userId].end() && distance(userTweets[userId].begin(), it) < 10; ++it) {
                minHeap.emplace(it->timestamp, it);
            }
        }
        
        // Add tweets from followed users to the heap
        if (followers.find(userId) != followers.end()) {
            for (int followeeId : followers[userId]) {
                if (userTweets.find(followeeId) != userTweets.end()) {
                    for (auto it = userTweets[followeeId].begin(); it != userTweets[followeeId].end() && distance(userTweets[followeeId].begin(), it) < 10; ++it) {
                        minHeap.emplace(it->timestamp, it);
                    }
                }
            }
        }

        // Retrieve the 10 most recent tweets
        vector<int> newsFeed;
        while (!minHeap.empty() && newsFeed.size() < 10) {
            newsFeed.push_back(minHeap.top().second->tweetId);
            minHeap.pop();
        }
        
        return newsFeed;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followers[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followers[followerId].find(followeeId) != followers[followerId].end()) {
            followers[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */