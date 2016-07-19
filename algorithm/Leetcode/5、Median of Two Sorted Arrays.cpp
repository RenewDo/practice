class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
           int len1= nums1.size(), len2 = nums2.size();
           int total = len1+len2;
           if(total&1)
               return findk(nums1.begin(), len1, nums2.begin(), len2, total/2+1);
           else  return (findk(nums1.begin(), len1, nums2.begin(), len2, total/2)+
                        findk(nums1.begin(), len1, nums2.begin(), len2, total/2+1))/2.0;
    }

private:
   static int findk(vector<int>::const_iterator a, int lena, vector<int>::const_iterator b, int lenb, int k)
   {
       if(lena > lenb)
            return findk(b,lenb, a, lena, k);
       if(lena==0)
            return *(b+k-1);
       if(k==1)
            return min(*(a), *(b));
            
       int ka = min(k/2, lena), kb = k - ka;
       if(*(a+ka-1) < *(b+kb-1))
            return findk(a+ka, lena-ka, b, lenb, k-ka);
       else if(*(a+ka-1) > *(b+kb-1))
                 return findk(a, lena, b+kb, lenb-kb, k-kb);
       else    return *(a+ka-1);
   }
};
