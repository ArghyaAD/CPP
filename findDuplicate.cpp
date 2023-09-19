/*--------------------------------------------LEETCODE 287------------------------------------*/
/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3

Input: nums = [2,2,2,2,2]
Output: 2
*/
/*
The approach you're taking is based on the property of XOR where x ^ x = 0 and x ^ 0 = x. But this approach will only work if there are exactly two copies of one number and one copy of every other number. That's not the case in this problem. In this problem, one number might appear more than twice, and your approach won't handle that correctly.

A classic way to solve this problem without modifying the original array and with constant space is by using Floyd's Cycle Detection Algorithm, also known as the "Tortoise and the Hare" approach.
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tortoise=0, hare=0;
        do{
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        }while(tortoise!=hare);
        hare = 0;
        while(tortoise!=hare){
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        return tortoise;
    }
};
