class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int last = 0;
            int m_index, m = nums1.size(), n = nums2.size();
            if((m + n) % 2 == 0) 
                m_index = (m + n) / 2;
            else 
                m_index = (m + n) / 2;
            int i = 0, j = 0;
            while(i < m || j < n) {
                if(m_index == 0)
                    break;
                m_index--;
                if(i == m) {
                    last = nums2[j];
                    j++;
                    continue;
                }
                if(j == n) {
                    last = nums1[i];
                    i++;
                    continue;
                }
                if(nums1[i] < nums2[j]) {
                    last = nums1[i];
                    i++;
                }
                else {
                    last = nums2[j];
                    j++;
                }
            }
            if(i == m && j == n)
                return 0.0;
            if((m + n) % 2 == 0) {
                if(i == m)
                    return (last + nums2[j]) / 2.0;
                if(j == n)
                    return (last + nums1[i]) / 2.0;
                if(nums1[i] < nums2[j])
                    return (last + nums1[i]) / 2.0;
                else
                    return (last + nums2[j]) / 2.0;
            }
            else {
                if(i == m)
                    return nums2[j];
                if(j == n)
                    return nums1[i];
                if(nums1[i] < nums2[j])
                    return nums1[i];
                else
                    return nums2[j];
            }

        }
};
