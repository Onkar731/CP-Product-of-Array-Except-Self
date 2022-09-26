/*
    2. Product of Array Except Self

    Problem Statement :
    Given an integer array nums , return an array answer such that answer[i] is equal to the
    product of all the elements of nums except nums[i] .
    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
    You must write an algorithm that runs in O(n) time and without using the division
    operation

    Example 1:

    Input: nums = [1,2,3,4]
    Output: [24,12,8,6]

    Example 2:

    Input: nums = [-1,1,0,-3,3]
    Output: [0,0,9,0,0]
*/

#include<iostream>
using namespace std;

long productArrayExceptSelf(int[], int, int);

int main()
{
    int n;

    printf("Enter a number : ");
    scanf("%d", &n);

    int array[n];
    printf("Enter %d values : ", n);

    for(int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    
    int answer[n];

    // logic start
    
    int product = 1, j;

    for(j = 0; j < n; j++)
        if(array[j] == 0)
            break;

    if(j != n) {
        for(int i = 0; i < n; i++)
            if(array[i] == 0)
                answer[i] = productArrayExceptSelf(array, n);
            else
                answer[i] = 0;
    }
    else {
        for(int i = 0; i < n; i++)
            product *= array[i];
        for(int i =0; i < n; i++)
            answer[i] = product/array[i];
    }
    
    // logic ends
    
    
    printf("\nProduct of Array Elements Except Self : ");
    for(int i = 0; i < n; i++)
        printf("%d ", answer[i]);

    return 0;
}

long productArrayExceptSelf(int array[], int n)
{
    long prd = 1;
    for(int i = 0; i < n; i++)
        if(array[i] != 0){
            prd *= array[i];
        }

    return prd;
}
