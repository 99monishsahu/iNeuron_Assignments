/* Question 1
Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2),..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. 
Return the maximized sum.
*/

#include <bits/stdc++.h>
using namespace std;

int main() 
{
    //APPROACH
    
    /*
    1. Sort the given array nums.
    2. Sum the pairs from 1 to 2n like (1,2),(3,4)...(2n-1,2n).
    3. Return Sum. 
    */
    
    //Let the given set of integers is: 
    vector<int> nums = {5,8,7,3,4,9,1,2,10,6};
    int max=0;
    
    //Main Code
    
    //Sort the array
    sort(nums.begin(),nums.end());
    
    //Sum odd indices to get maximized sum.
    for(int i=0; i<nums.size()-1; i++){
      max = max + nums[i];
      i++;
    }
    
    cout<<max<<endl;
    
}

/*
Question 2
Alice has n candies, where the ith candy is of type candyType[i]. Alice noticed that she started to gain weight, so she visited a doctor. 
The doctor advised Alice to only eat n / 2 of the candies she has (n is always even). Alice likes her candies very much, and she wants to eat the maximum n
number of different types of candies while still following the doctor's advice. 
Given the integer array candyType of length n, return the maximum number of different types of candies she can eat if she only eats n / 2 of them.
*/
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    vector<int> candyType = {1,8,2,1,2,2,2,8};
    
    int canEat = candyType.size()/2, maxType=1;
    
    sort(candyType.begin(), candyType.end());
    
    for(int i=0; i<candyType.size(); i++){
      for(int j=i+1; j<candyType.size(); j++){
        if(candyType[j]!=candyType[i]){
          maxType++;
          i=j-1;
          break;
        }
      }
    }
    
    if(canEat<maxType){
      cout<<canEat<<endl;
    }
    else cout<<maxType<<endl;
}

/*
Question 3.
We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.
Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.
A subsequence of an array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.
*/
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    vector<int> nums = {1,3,2,2,5,2,3,7};
    sort(nums.begin(), nums.end());
    
    int left = 0, result = 0, right = 1;
    
    while(right<nums.size()){
      int diff = nums[right] - nums[left];
      if(diff == 1){
        result = max(result, (right - left + 1));
      }
      if(diff<=1){
        right++;
      }else left++;
    }
    
    cout<<result;
    
}

/*
Question 4
You have a long flowerbed in which some of the plots are planted, and some are not.
However, flowers cannot be planted in adjacent plots.
Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be 
planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
*/

#include <bits/stdc++.h>
using namespace std;

int main() 
{
    vector<int> flowerbed = {1,0,0,1,0,0,1,0,0,1,0,1,0,1};
    int flag=0;
    
    for(int i=0; i<flowerbed.size(); i++){
      if(flowerbed[i]==0){
        int j=i+1,k=j+1;
        if(flowerbed[j]==0 && flowerbed[k]==0){
          cout<<"True";
          flag++;
          break;
        }
        if(flowerbed[j]==1) i=j;
        if(flowerbed[k]==1) i=k;
      }
    }
    
    if(flag==0){
      cout<<"False"<<endl;
    }
}


/*
Question 5
Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

Example 1:
Input: nums = [1,2,3]
Output: 6
*/

#include <bits/stdc++.h>
using namespace std;

int main() 
{
    vector<int> nums = {5,8,7,3,4,9,1,2,10,6};
    sort(nums.begin(), nums.end());
    int size = nums.size();
    int maxProduct = nums[size-1]*nums[size-2]*nums[size-3];
    cout<<maxProduct;
}

/*
Question 6
Given an array of integers nums which is sorted in ascending order, and an integer target,
write a function to search target in nums. If target exists, then return its index. Otherwise,
return -1.

You must write an algorithm with O(log n) runtime complexity.

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
*/
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    vector<int> nums = {0,1,3,5,7,9,11};
    int high=nums.size()-1, low = 0, mid,flag=0, target = 8;
    
    while(low<=high){
      mid = (high+low)/2;
      if(nums[mid] == target){cout<<mid; flag = 1; break;}
      else{
        if(nums[mid]<target) low = mid + 1;
        else high = mid-1;
      }
    }
    
    if(flag==0) cout<<"-1";
}

/* Question 7
An array is monotonic if it is either monotone increasing or monotone decreasing.
An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].
Given an integer array nums, return true if the given array is monotonic, or false otherwise.
Example 1:
Input: nums = [1,2,2,3]
Output: true
*/
    
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    vector<int> nums = {0,1,3,3,7,9,11};
    int md=0,mi=0,flag=0;
    if(nums[0]<nums[1]) mi=1;
    else md=1;
    
    if(mi){
      for(int i=0; i<nums.size()-1; i++){
        int j=i+1;
        if(nums[i]>nums[j]){ cout<<"False"; flag=1; break;}
      }
    }
    
    if(md){
      for(int i=0; i<nums.size()-1; i++){
        int j=i+1;
        if(nums[i]<nums[j]){ cout<<"False"; flag=1; break;}
      }
    }
    
    if(!flag) cout<<"True";
    
}
/*
Question 8
You are given an integer array nums and an integer k.
In one operation, you can choose any index i where 0 <= i < nums.length and change nums[i] to nums[i] + x where x is an integer from the range [-k, k]. 
You can apply this operation at most once for each index i.
The score of nums is the difference between the maximum and minimum elements in nums.
Return the minimum score of nums after applying the mentioned operation at most once for each index in it.
*/

#include <bits/stdc++.h>
using namespace std;

int main() 
{
    vector<int> nums = {0,10};
    sort(nums.begin(),nums.end());
    int diff, k=2;
        
    if(nums[nums.size()-1]-k>=nums[0]+k){
      diff=(nums[nums.size()-1]-k)-(nums[0]+k);
    }
    else{
      int fl=nums[nums.size()-1]-nums[0]+k;
      diff=nums[nums.size()-1]-fl-nums[0]+k;
    }
    cout<<diff;
    
}
