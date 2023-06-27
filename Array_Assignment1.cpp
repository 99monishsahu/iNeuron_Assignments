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

/*
Question 2.
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

- Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
- Return k.

Example :
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_*,_*]

Explanation: Your function should return k = 2, with the first two elements of nums being 2. It does not matter what you leave beyond the returned k (hence they are underscores)
*/

#include <iostream>
using namespace std;

int main() 
{
    int val,size_of_array,i=0,count=0;
    
    cout<<"Enter size of array(nums): "<<endl;
    cin>>size_of_array;
    
    int j = size_of_array-1;
    
    cout<<"Enter value: "<<endl;
    cin>>val;
    
    int nums[size_of_array];
    cout<<"Enter values in array(nums): "<<endl;
    for(i=0; i<size_of_array; i++){
      cin>>nums[i];
    }
    
    //Main Code
    for(i=0; i<size_of_array; i++){
      if(nums[i]!=val) count++;
    }
    cout<<"The number of elements in nums which are not equal to val are: "<<count<<endl;
    
    i=0;
    while(count){
      if(nums[i]==val){
        for(j=size_of_array-1; j>0; j--){
          if(nums[i]!=nums[j]){
            int temp = nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
            break;
          }
        }
      }
      i++;
      count--;
    }
    
    for(i=0; i<size_of_array; i++){
      cout<<nums[i]<<",";
    }
}
