/*
Question 1
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to the target.
Return the sum of the three integers. You may assume that each input would have exactly one solution.
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int sum = nums[0] + nums[1] + nums[2];
        
        for(int i=0; i<nums.size()-1; i++){
            int begin = i+1, end = nums.size()-1;
            while(begin<end){
                int currentsum =nums[begin]+nums[end]+nums[i];
                if(abs(currentsum-target)<abs(sum-target)) sum=currentsum;
                if(currentsum<target) begin++;
                else end--;
            }            
        }
        
        return sum;
    }
};

/*
Question 2
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
           ● 0 <= a, b, c, d < n
           ● a, b, c, and d are distinct.
           ● nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        for(int i=0; i<n-3; i++){
            for(int j=i+1; j<n-2; j++){
                long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
                int low = j+1, high = n-1;
                while(low < high){
                    if(nums[low] + nums[high] < newTarget){
                        low++;
                    }
                    else if(nums[low] + nums[high] > newTarget){
                        high--;
                    }
                    else{
                        output.push_back({nums[i], nums[j], nums[low], nums[high]});
                        int tempIndex1 = low, tempIndex2 = high;
                        while(low < high && nums[low] == nums[tempIndex1]) low++;
                        while(low < high && nums[high] == nums[tempIndex2]) high--;
                    }
                }
                while(j+1 < n && nums[j] == nums[j+1]) j++;
            }
            while(i+1 < n && nums[i] == nums[i+1]) i++;
        }
        return output;
    }
};

/*
Question 3. A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
For example, for arr = [1,2,3], the following are all the permutations of arr:
[1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].

The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array 
are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted 
container.
If such an arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

● For example, the next permutation of arr = [1,2,3] is [1,3,2].
● Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
● While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums. The replacement must be in place and use only constant extra memory.
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index=-1;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                index=i-1;
                break;
            }
        }
        //finding the break point 
        // now stored in index

        if(index==-1){
            sort(nums.begin(),nums.end());
            return ;
        }
        // if no break point we sort the array and return
        // else
        for(int i=nums.size()-1;i>index;i--){
            if(nums[i]>nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }
        //swaping the min element which is greater than break point 
        // and now sorting the remaining elements to get the next permutation
        sort(nums.begin()+index+1,nums.end());
    }
};
/*
Question 4
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were 
inserted in order.
You must write an algorithm with O(log n) runtime complexity.
*/
#include <iostream>
using namespace std;

int main() 
{
    int target,size_of_array,i=0;
    
    cout<<"Enter size of array(nums): "<<endl;
    cin>>size_of_array;
    
    int end = size_of_array;
    int mid = (i+end)/2;
    
    cout<<"Enter target value: "<<endl;
    cin>>target;
    
    int nums[size_of_array];
    cout<<"Enter values in array(nums): "<<endl;
    for(i=0; i<size_of_array; i++){
      cin>>nums[i];
    }
    
    //Main Code
    for(i=0; i<end; i=i+0){
      mid = (i+end)/2;
      if(nums[mid]==target){
        cout<<mid;
        break;
      }
      else{
        if(i+1==end){
          if(target<nums[i]){
            cout<<"0";
            break;
          }
          if(target>nums[end]){
            cout<<end+1;
            break;
          }
          cout<<i+1;
          break;
        }
        if(nums[mid]<target) i = mid;
        else end = mid;
      }
    }
}
//RUN HERE:https://www.onlinegdb.com/online_c++_compiler

/*
Question 5
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most 
significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
Increment the large integer by one and return the resulting array of digits.
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i=digits.size()-1;
        if(digits[i]!=9) {
            digits[i]++;
            return digits;
        }
        else{
            for(i=digits.size()-1; i>=0; i--){
                if(digits[i]!=9){
                    digits[i]++;
                    return digits;
                }
                else{
                    if(i==0){
                        digits[i]=1;
                        digits.push_back(0);
                        return digits;
                    }
                    else{
                        digits[i]=0;
                    }
                }
            }
        }

        return digits;
    }
};

/*
Question 6
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto i : mp){
            if(i.second==1){
                return i.first;
            }
        }
        return -1;
    }
};


/*
Question 7
You are given an inclusive range [lower, upper] and a sorted unique integer array nums, where all elements are within the inclusive range.
A number x is considered missing if x is in the range [lower, upper] and x is not in nums.
Return the shortest sorted list of ranges that exactly covers all the missing numbers. That is, no element of nums is included in any of the ranges, and each
missing number is covered by one of the ranges.
*/


/*
Question 8
Given an array of meeting time intervals where intervals[i] = [starti, endi], determine if a person could attend all meetings.
*/
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    vector<vector<int>> nums = {{1,3},{4,2},{2,2},{2,4},{1,1}};
    sort(nums.begin(),nums.end());
    int flag=0;
    for(int i=0; i<nums.size()-1; i++){
      int j = i+1;
      if(nums[i][1]>nums[j][0]){
        cout<<"False";
        flag=1;
      }
    }
    if(!flag) cout<<"True";
}
