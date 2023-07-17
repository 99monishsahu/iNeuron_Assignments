/*Question 1
Given three integer arrays arr1, arr2 and arr3 **sorted** in **strictly increasing** order, return a sorted array of **only** the integers that appeared in **all** 
three arrays.
Example 1:
Input: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]
Output: [1,5]
*/

class Solution {
public:
    vector<int> arraysIntersection(vector<int>& A, vector<int>& B, vector<int>& C) {
        int i = 0, j = 0, k = 0, R = A.size(), S = B.size(), T = C.size();
        vector<int> ans;
        while (i < R && j < S && k < T) {
            int a = A[i], b = B[j], c = C[k];
            if (a == b && b == c) {
                ans.push_back(a);
                ++i, ++j, ++k;
            } else {
                int mx = max({ a, b, c });
                if (a < mx) ++i;
                if (b < mx) ++j;
                if (c < mx) ++k;
            }
        }
        return ans;
    }
};

/*
Question 2

Given two **0-indexed** integer arrays nums1 and nums2, return *a list* answer *of size* 2*where:

- answer[0] *is a list of all **distinct** integers in* nums1 *which are **not** present in* nums2*.*
- answer[1] *is a list of all **distinct** integers in* nums2 *which are **not** present in* nums1.

**Note** that the integers in the lists may be returned in **any** order.
**Example 1:**
**Input:** nums1 = [1,2,3], nums2 = [2,4,6]
**Output:** [[1,3],[4,6]]
*/
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(),n2 = nums2.size();
        set<int> ans1, ans2;
        int i = 0 ,j = 0;
        vector<int>v1,v2;
        
        unordered_map<int, int> m;
        unordered_map<int, int> m1;
        
         while(i < n1 || j < n2) {
            if( i < n1 ) m[nums1[i++]]++;    
            if( j < n2 ) m1[nums2[j++]]++;
        }

        i  = 0 ,j = 0;
         while(i < n1 || j < n2) {
            if( i < n2  && m[nums2[i]] == 0) ans2.insert (nums2[i]);    
            if( j < n1 && m1[nums1[j]] == 0) ans1.insert(nums1[j]);
            i++;
            j++;
        }


        for(auto i : ans1) v1.push_back(i);
        for(auto i : ans2) v2.push_back(i);

        return {v1, v2};

    }
};


/*
Question 3
Given a 2D integer array matrix, return *the **transpose** of* matrix.
The **transpose** of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.
Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]
*/
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> v(matrix[0].size(), vector<int>(matrix.size()));
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                v[j][i]=matrix[i][j];
            }
        }
        return v;
    }
};

/*
Question 4
Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is 
**maximized**. Return *the maximized sum*.
**Example 1:**
Input: nums = [1,4,3,2]
Output: 4
*/
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n= nums.size(), ans=0;
        for(int i=0; i<n; i+=2){
            ans+= nums[i];
        }
        return ans;
    }
};

/*
Question 5
You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the 
staircase **may be** incomplete.
Given the integer n, return *the number of **complete rows** of the staircase you will build*.
*/
class Solution {
public:
    int arrangeCoins(int n) {
        int num = n;
        int count = 0;
        for(int i = 1,j; num > 0; i++){
            for(j = 0; j < i && num > 0; j++)
                num--;
            

            if(j == i)
                count++;
        }
    return count;
    }
};
/*
Question 6
Given an integer array nums sorted in **non-decreasing** order, return *an array of **the squares of each number** sorted in non-decreasing order*.
**Example 1:**
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        for(auto x: nums) ans.push_back(x * x);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

/*
Question 7
You are given an m x n matrix M initialized with all 0's and an array of operations ops, where ops[i] = [ai, bi] means M[x][y] should be incremented by one 
for all 0 <= x < ai and 0 <= y < bi.
Count and return *the number of maximum integers in the matrix after performing all the operations*
*/
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int a = m;
        int b = n;
        for (auto i: ops){
            if (i[0] < a){
                a = i[0];
            }
            if (i[1] < b){
                b = i[1];
            } 
        }
        return (a * b);
        
        
    }
};

/*
Question 8
Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].
*Return the array in the form* [x1,y1,x2,y2,...,xn,yn].
**Example 1:**
**Input:** nums = [2,5,1,3,4,7], n = 3
**Output:** [2,3,5,4,1,7]
*/
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        int i,j=n;
        for(i=0; i<n; i++){
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            j++;
        }
        return ans;
    }
};
