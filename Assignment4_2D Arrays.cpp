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

/*
Question 3
Given a 2D integer array matrix, return *the **transpose** of* matrix.
The **transpose** of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.
Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]
*/

/*
Question 4
Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is 
**maximized**. Return *the maximized sum*.
**Example 1:**
Input: nums = [1,4,3,2]
Output: 4
*/


/*
Question 5
You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the 
staircase **may be** incomplete.
Given the integer n, return *the number of **complete rows** of the staircase you will build*.
*/

/*
Question 6
Given an integer array nums sorted in **non-decreasing** order, return *an array of **the squares of each number** sorted in non-decreasing order*.
**Example 1:**
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
*/


/*
Question 7
You are given an m x n matrix M initialized with all 0's and an array of operations ops, where ops[i] = [ai, bi] means M[x][y] should be incremented by one 
for all 0 <= x < ai and 0 <= y < bi.
Count and return *the number of maximum integers in the matrix after performing all the operations*
*/


/*
Question 8
Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].
*Return the array in the form* [x1,y1,x2,y2,...,xn,yn].
**Example 1:**
**Input:** nums = [2,5,1,3,4,7], n = 3
**Output:** [2,3,5,4,1,7]
*/
