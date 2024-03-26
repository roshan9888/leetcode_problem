class Solution {
public:
    string largestGoodInteger(string num) {
        // vector<string>v;
        // v.push_back("999");
        // v.push_back("888");
        // v.push_back("777");
        // v.push_back("666");
        // v.push_back("555");
        // v.push_back("444");
        // v.push_back("333");
        // v.push_back("222");
        // v.push_back("111");
        // v.push_back("000");
        // for(auto it :v){
        //     size_t found = num.find(it);
        //     if (found != string::npos)
        //         return it;
        // }
        // return "";

        //optimal solution
        int count=0;
        char prev='X', maxd=' ';
        for(char c: num){
            if (c==prev) count++;
            else count=1;
            if (count==3)
                maxd=max(maxd, c);
            prev=move(c);
        }
        return (maxd==' ')?"":string(3, maxd);
    }
};