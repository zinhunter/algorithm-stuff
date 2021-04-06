/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

https://leetcode.com/problems/two-sum/description/*/


#include <iostream>
#include <unordered_map>

/*The first and obvious way of doing this is by using brute force: nested loops. 
However, this is a rather slow method, with a time complexity of O(n^2). 
Anyway, this would be my implementation:*/
auto twoSum1(int arr[], int target){
  bool found = false;
  for(int i = 0; i < *(&arr + 1) - arr; i++){
    for(int j = 0; j < *(&arr + 1) - arr; j++){
      if(j != i){
        if(arr[i] + arr[j] == target){
          std::cout << i << ", " << j << std::endl; //Or whatever format you need to return.
          found = true;
          break;
        }
      }
    }
    if(found==true){break;}
  }
}

/*Now, we could use hash tables, or unordered maps in C++.
This is a one pass implementation, we iterate through the array only once, 
searching and storing the values in the map inside the same loop.

This solution's time complexity is O(n). The lookups in the map are amortized O(1) each.
*/
auto twoSum2(int arr[], int target){
  std::unordered_map<int, int> map;
  int complement;

  for(int i = 0; i < *(&arr + 1) - arr; i++){
    complement= target - arr[i];
    auto search = map.find(complement);
    
    if(search != map.end()){
      std::cout << search->second << ", " << i << std::endl;
      break;
    }
    map[arr[i]] = i;
  }
}

int main(){
  //Test data
  int nums[] = {2,7,11,15};
  int tgt = 9;

  twoSum1(nums,tgt);
  twoSum2(nums,tgt);
}