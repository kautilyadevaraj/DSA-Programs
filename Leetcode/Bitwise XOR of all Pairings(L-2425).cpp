class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int XOR = 0;

        if(size1 % 2 == 0 && size2 % 2 == 0) return 0;

        if(size1 % 2 == 0)
            for(int i = 0 ; i < size1 ; i++) XOR ^= nums1[i];
        
        if(size2 % 2 == 0)
            for(int i = 0 ; i < size2 ; i++) XOR ^= nums2[i];
        
        if(size1 % 2 != 0 && size2 % 2 != 0)
        {
            for(int i = 0 ; i < size1 ; i++) XOR ^= nums1[i];
            for(int i = 0 ; i < size2 ; i++) XOR ^= nums2[i];
        }
        return XOR;
        
    }
};