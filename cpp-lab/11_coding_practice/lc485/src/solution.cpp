#include "solution.hpp"

/** 
int findMaxConsecutiveOnes(const std::vector<int>& nums)
{
    int ans = 0;
    int count = 0;
    int size = nums.size();
    if(nums.size()==0){
        return 0;
    }

    for (int i = 0; i<size; ++i){
        if(nums[i]==1){
            count++;
            if(count>ans){
                ans = count;
            }
        }
        else{
            count = 0;
        }

    }
    return ans;
}
*/

int findMaxConsecutiveOnes(const std::vector<int>& nums)
{
  int best = 0;
  int run = 0;

  for (int n:nums){
    run = (n==1)? run+1:0;
    best = std::max(best,run);
  }
  
  return best;
}