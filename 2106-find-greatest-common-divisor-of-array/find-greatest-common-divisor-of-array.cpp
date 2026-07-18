class Solution {
public:
    int findGCD(vector<int>& nums) {
     int smallestNumber = *min_element(nums.begin(),nums.end());
     int largestNumber = *max_element(nums.begin(),nums.end());
     return __gcd(smallestNumber,largestNumber);   
    }
};