class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
                vector<int> res;
                low_bound(res, nums, target);
                up_bound(res, nums, target);
                if(res.size()==0)
                {
                    res.push_back(-1);
                    res.push_back(-1);
                }
                return  res;
    }
    void low_bound(vector<int>& r, vector<int>& n, int t)
    {
         int l = 0, h = n.size()-1;
         int mid = (l+h)/2;
         while(l <=h)
         {
              if(n[mid]<t)
              l = mid +1;
              else if(n[mid]>t)
              h = mid-1;
              else if(mid==0 || (mid>0 && n[mid-1]!=t && n[mid]==t))
              {
                   r.push_back(mid);
                   return;
              }
              else h=mid-1;
			  mid = l+(h-l)/2;
         }
    }
    void up_bound(vector<int>& r, vector<int>& n, int t)
    {
          int l = 0, h = n.size()-1;
          int mid = (l+h)/2;
          while(l <=h)
          {
              if(n[mid]<t)
              l = mid +1;
              else if(n[mid]>t)
              h = mid-1;
              else if(mid==n.size()-1 || (mid<n.size()-1 && n[mid+1]!=t && n[mid]==t))
              {
                   r.push_back(mid);
                   return;
              }
              else l=mid+1;
			    mid = l+(h-l)/2;
          }
    }
};
