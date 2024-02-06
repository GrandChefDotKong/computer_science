#pragma once
#include <deque>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>

////////////////////////////////////////////////////
/** SOME OFF THE LEETCODE.COM PROBLEMS I SOLVED ***/
////////////////////////////////////////////////////



/***************************/
/** 20. VALID PARENTHESES **/
/***************************/
/*
  Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
  determine if the input string is valid.
  An input string is valid if:
    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.
*/

bool is_in_map(const std::map<char, char>& m, const char c) {
  for(auto& it : m) {
    if(it.second == c) {
      return true;
    }
  }

  return false;
}

bool valid_parenthese(std::string s) {
  std::map<char, char> check = {{'}', '{'}, {')', '('}, {']','['}}; 
  std::vector<char> stack;

  for(int i = 0; i < s.size(); ++i) {
    if(is_in_map(check, s[i])) {
      stack.push_back(s[i]);
      continue;
    }

    if(stack.size() == 0) {
      return false;
    }

    if(check[s[i]] != stack[stack.size() -1]) {
      return false;
    }
    
    stack.pop_back();
  }

  return stack.size() == 0;
}

/*******************************/
/** 14. LONGEST COMMON PREFIX **/
/*******************************/
/* 
  Function to find the longest common prefix string amongst an array of strings.
  If there is no common prefix, return an empty string "".
*/

std::string longestCommonPrefix(std::vector<std::string>& strs) {
  std::string output = "";

// SOLUTION 1
/*
  int index = 0;
  while(index < strs[0].length()) {
    int letter = strs[0][index];

    for(short int i = 0; i < strs.size(); ++i) {
      if(letter != strs[i][index] || index >= strs[i].length()) {
        return output;
      }
    }

    output += letter;
    index++;
  }
*/
// SOLUTION 2
  int size = strs.size();
  sort(strs.begin(), strs.end());

  for(short int i = 0; i < strs[0].length() || i < strs[size-1].length(); ++i) {
    if(strs[0][i] != strs[size-1][i]) {
      return output;
    }
    
    output += strs[0][i];
  }

  return output;
}


/**************************/
/** 13. ROMAN TO INTEGER **/
/**************************/
/*
  Convert roman number to integer
*/
int romanToInt(std::string s) {
  std::map<char, int> m = 
    {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
  int number = 0;
  int length = s.length();

  for(short int i = 0; i < length-1; ++i) {
    if(m[s[i]] < m[s[i+1]]) {
      number -= m[s[i]];
      continue;
    }

    number += m[s[i]];

  }

  return number + m[s[length-1]];
}

/**************************/
/** 9. PALINDROME NUMBER **/
/**************************/
/*
  Given an integer x, return true if x is a palindrome, and false otherwise.
*/
bool isPalindrome(int x) {
  if(x < 0) {
    return false;
  }

  long int temp = x;
  long int reverse = 0;
  int digit;

  do {
    digit = x % 10;
    reverse = (reverse * 10) + digit;
    x = x / 10;
  } while( x > 0);
  
  return reverse == temp;
}

/****************/
/** 1. TWO SUM **/
/****************/
/*
  Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
  You may assume that each input would have exactly one solution, and you may not use the same element twice.
  You can return the answer in any order.
*/
std::vector<int> twoSum(std::vector<int>& nums, int target) {
  std::unordered_map<int, int> map;
  std::unordered_map<int,int>::iterator it;
  int diff;

  for(short int i = 0; i < nums.size(); ++i) {
    diff = target - nums[i];
    it = map.find(diff);
    if(it != map.end() && it->second != i) {
        return std::vector<int>{i, it->second};
    }

    map[nums[i]] = i;
  }

  return {};
}




