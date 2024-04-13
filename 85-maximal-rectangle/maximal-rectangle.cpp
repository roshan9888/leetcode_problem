class Solution {

     vector<int>previoussmaller(vector<int>&input){
        stack<int>s;
        s.push(-1);
        vector<int>ans(input.size());
        for(int i=0;i<input.size();i++){
            int curr=input[i];
            while(s.top()!=-1 && input[s.top()]>=curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int>nextsmaller(vector<int>&input){
        stack<int>s;
        s.push(-1);
        vector<int>ans(input.size());
        for(int i=input.size()-1;i>=0;i--){
            int curr=input[i];
            while(s.top()!=-1 && input[s.top()]>=curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int>prev=previoussmaller(heights);

        vector<int>next=nextsmaller(heights);
        int size=heights.size();
        int maxrect=INT_MIN;
        for(int i=0;i<heights.size();i++){
            int length=heights[i];

            if(next[i]==-1){
                next[i]=size;
            }
            int width=next[i]-prev[i]-1;
            int area=length*width;
            maxrect=max(maxrect,area);
        }  
        return maxrect;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>>v;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            vector<int>t;
            for(int j=0;j<m;j++){
               t.push_back(matrix[i][j]-'0');
            }
            v.push_back(t);
        }
        int area = largestRectangleArea(v[0]);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]){
                    v[i][j]+=v[i-1][j];
                }
                else{
                    v[i][j]=0;
                }
            }
            area=max(area,largestRectangleArea(v[i]));
        }
        return area;
    }
};