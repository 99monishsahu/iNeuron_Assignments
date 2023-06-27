/*
QUESTION 1.
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]

Explanation:** Because nums[0] + nums[1] == 9, we return [0, 1]

*/


#include <iostream>
using namespace std;

int main() 
{
    int target,size_of_array,i,j,flag=0;
    
    cout<<"Enter size of array(nums): "<<endl;
    cin>>size_of_array;
    
    cout<<"Enter target value: "<<endl;
    cin>>target;
    
    int nums[size_of_array];
    cout<<"Enter values in array(nums): "<<endl;
    for(i=0; i<size_of_array; i++){
      cin>>nums[i];
    }
    
    //Main Code
    for(i=0; i<size_of_array-1; i++){
      for(j=i+1; j<size_of_array; j++){
        if(nums[i]+nums[j]==target){
          cout<<i<<","<<j;
          flag=1;
        }
      }
      if(flag) break;
    }
}
