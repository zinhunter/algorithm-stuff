#include <iostream>
#include <string>
#include <boost/range/adaptor/reversed.hpp>
#include <bits/stdc++.h> 

auto strReverser(std::string &strToReverse){ //We send the variable by reference so we avoid copying the whole variable into another location.
  //Time complexity O(n), we iterate through the whole string
  for(int i = strToReverse.length() - 1; i >= 0; i--){
    std::cout << strToReverse[i];
  }
  std::cout << "\n";
}

auto strReverserRbLoop(std::string &strToReverse){
  //Using a reversed range based loop... basically the same as the first one, needs boost.
  //Time complexity O(n), we iterate through the whole string
  for(auto i : boost::adaptors::reverse(strToReverse)){
    std::cout << i;
  }
  std::cout << "\n";
}

int main() {
  std::string myString;
  std::getline(std::cin,myString);
  strReverser(myString);
  strReverserRbLoop(myString);

  //Simplest one, needs bits
  /*Time complexity O(n/2), depending on the number of swaps, so O(n)*/
  reverse(myString.begin(),myString.end());
  std::cout << myString << "\n";
}
