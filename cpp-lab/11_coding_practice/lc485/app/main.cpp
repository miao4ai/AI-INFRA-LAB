#include <cassert>
#include <iostream>
#include <vector>

#include "solution.hpp"

void test(const std::vector<int>& nums, int expected)
{
    int ans = findMaxConsecutiveOnes(nums);

    assert(ans == expected);

    std::cout << "Passed!\n";
}

int main()
{
    test({1,1,0,1,1,1},3);
    test({1,0,1,1,0,1},2);
    test({0},0);
    test({1},1);
    test({},0);

    std::cout << "All tests passed!\n";
}