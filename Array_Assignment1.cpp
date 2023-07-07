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


/*Q2. Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the 
number of elements in nums which are not equal to val.
Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:
- Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not 
  important as well as the size of nums.
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


/*3. Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if 
it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [1,3,5,6], target = 5

Output: 2
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

/*Q4. You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. 
The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
Increment the large integer by one and return the resulting array of digits.

Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]

Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
*/
#include <iostream>
using namespace std;

int main() 
{
    int size_of_array,i,carry=0;
    
    cout<<"Enter size of array: "<<endl;
    cin>>size_of_array;
    
    int digits[size_of_array];
    cout<<"Enter digits of Integer: "<<endl;
    for(i=0; i<size_of_array; i++){
      cin>>digits[i];
    }
    
    //Main Code
    for(i=size_of_array-1; i>=0; i--){
      if(digits[i]<9){
        digits[i]++;
        carry=0;
        break;
      }
      else{
        digits[i]=0;
        carry=1;
      }
    }
    
    if(carry){
      cout<<"1,";
    }
    for(i=0; i<size_of_array; i++){
      cout<<digits[i];
      if(i<size_of_array-1) cout<<",";
    }
}


/*Q5.You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 
and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of 
m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

Example 1:
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]

Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1
*/

#include <iostream>
using namespace std;

void merge(int a[], int beg, int mid, int end)    
{    
    int i, j, k;  
    int n1 = mid - beg + 1;    
    int n2 = end - mid;    
      
    int LeftArray[n1], RightArray[n2]; 
      
    for (int i = 0; i < n1; i++)    
    LeftArray[i] = a[beg + i];    
    for (int j = 0; j < n2; j++)    
    RightArray[j] = a[mid + 1 + j];    
      
    i = 0; 
    j = 0; 
    k = beg; 
      
    while (i < n1 && j < n2)    
    {    
        if(LeftArray[i] <= RightArray[j])    
        {    
            a[k] = LeftArray[i];    
            i++;    
        }    
        else    
        {    
            a[k] = RightArray[j];    
            j++;    
        }    
        k++;    
    }    
    while (i<n1)    
    {    
        a[k] = LeftArray[i];    
        i++;    
        k++;    
    }    
      
    while (j<n2)    
    {    
        a[k] = RightArray[j];    
        j++;    
        k++;    
    }    
}    
  
void mergeSort(int a[], int beg, int end)  
{  
    if (beg < end)   
    {  
        int mid = (beg + end) / 2;  
        mergeSort(a, beg, mid);  
        mergeSort(a, mid + 1, end);  
        merge(a, beg, mid, end);  
    }  
}


int main() 
{
    int m,n,i;
    
    cout<<"Enter size of array 1: "<<endl;
    cin>>m;
    cout<<"Enter size of array 2: "<<endl;
    cin>>n;
    
    int nums1[m+n],nums2[n];
    cout<<"Enter Integer values in nums1 : "<<endl;
    for(i=0; i<m; i++){
      cin>>nums1[i];
    }
    cout<<"Enter Integer values in nums2 : "<<endl;
    for(i=0; i<n; i++){
      cin>>nums2[i];
    }
    
    //Main Code
    int j=0;
    for(i=m; i<m+n; i++){
      nums1[i]=nums2[j];
      j++;
    }
    
    mergeSort(nums1,0,m+n-1);
    
    for(i=0; i<m+n; i++){
      cout<<nums1[i];
      if(i<size_of_array-1) cout<<",";
    }
}


/*Q6. Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
Example 1:
Input: nums = [1,2,3,1]
Output: true
*/

#include <bits/stdc++.h>
using namespace std;


int main() 
{
    int m,i,flag=0;
    
    cout<<"Enter size of array: "<<endl;
    cin>>m;
    
    int nums[m], arr[1000000]={0};
    cout<<"Enter Integer values in nums : "<<endl;
    for(i=0; i<m; i++){
      cin>>nums[i];
    }
    
    //Main Code
    for(i=0; i<m; i++){
      arr[nums[i]]++;
    }
    
    for(i=0; i<m; i++){
      if(arr[nums[i]]>1){
        cout<<"True"<<endl;
        flag=1;
        break;
      }
    }
    if(flag==0) cout<<"False"<<endl;
}

/*Q7. Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the nonzero elements.
Note that you must do this in-place without making a copy of the array.

Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
*/

#include <bits/stdc++.h>
using namespace std;


int main() 
{
    int m,i,j,flag=0;
    
    cout<<"Enter size of array: "<<endl;
    cin>>m;
    
    int nums[m];
    cout<<"Enter Integer values in nums : "<<endl;
    for(i=0; i<m; i++){
      cin>>nums[i];
    }
    
    //Main Code
    
    for(i=0; i<m; i++){
      if(nums[i]!=0){
        for(j=0; j<m; j++){
          if(nums[j]==0){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
          }
        }
      }
    }
    
    for(i=0; i<m; i++){
      cout<<nums[i];
      if(i<m-1) cout<<",";
    }
}

/*Q8. You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got 
duplicated to another number in the set, which results in repetition of one number and loss of another number.
You are given an integer array nums representing the data status of this set after the error.
Find the number that occurs twice and the number that is missing and return them in the form of an array.

Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]
*/
