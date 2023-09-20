class Solution {
public:
     vector<int>nextSmallerElement(int* arr, int n)
    {
        stack<int>s;
        s.push(-1);
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--)
        {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()]>= curr)
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int>prevSmallerElement(int* arr, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int>ans(n);
        
        for(int i=0;i<n;i++)
        {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    int largestRectangleArea(int* heights, int n) {
        // int n = heights.size();
        
        vector<int>next(n);
        next = nextSmallerElement(heights, n);
        
        vector<int>prev(n);
        prev = prevSmallerElement(heights, n);
        
        int area = INT_MIN;
        for(int i=0;i<n;i++)
        {
            int l = heights[i];
            if(next[i]==-1)
            {
                next[i] = n;
            }
            int b = next[i]-prev[i]-1;
            int newArea = l*b;
            area = max(area,newArea);
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& m) {
        int r =m.size();
        int c =m[0].size();
        
        int arr[r][c];
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(m[i][j]=='1')
                    arr[i][j] = 1;
                else
                    arr[i][j] = 0;
            }
        }
        int area = largestRectangleArea(arr[0],c);
        
        for(int i=1;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(arr[i][j] != 0)
                {
                   arr[i][j] = arr[i][j] + arr[i-1][j];
                }
                else{
                   arr[i][j] = 0;     
                }
            }
            area = max(area, largestRectangleArea(arr[i],c));
        }
        return area;
    }
};