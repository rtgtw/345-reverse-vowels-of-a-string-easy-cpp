/*

345. Reverse vowls of a string


Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.


Steps to this solution.

1. Create a string that holds all vowels
2. Create a string that holds the values of s (possibly optional)
3.The goal is to achieve this solution by assigning two pointers which are
at the first and last position and check for vowels, and while both pointers are sitting
inside of a vowel then swap them, else just keep advancing 
we want to stop when the two pointers cross each other and return the string array


The key method used in this solution is the std::string method .find()

.find() scans thru a substring and looks for the first occurence of the char and returns the 
index location

.find() is all we need to solve this solution 

*/

#include <iostream>
#include <string>




class Solution {

private:
	//We can create a member variable to represent the string array that holds 
	//all the vowels (upper and lowercase) that we will check with .find
	//member variables should be private
	std::string vowels = { "aeiouAEIOU" };
	


public:
	
	std::string reverseVowels(std::string &s);
	
};


std::string Solution::reverseVowels(std::string &s) {

	//We will be using the vowel string to check for occurences and index location within string s

	//We want to create a while loop that continously cycles thru the string swapping the vowels
	//We use a while loop rather than a for loop because we do not know how many iterations is
	//needed for completion 
	//we know the operation is complete when the first pointer and the last pointer cross
	//so that will be the basis of our while loop
	//We have to initialize first and last 
	//first is going to be the first location, last is going to be the last location within stirng s
	//we can find the last location within string s by using the string method .length() - 1, 
	//We use - 1 since indexes start a 0
	int first = 0;
	int last = s.length() - 1;
	char temp;
	
	

	while (first < last) {

		//While inside of the while loop, we want to check each element that first and last are on
		//to see if they are vowels, if they are not vowels then move forward,
		//However if they are vowels, then we want to wait there until the other pointer has landed on a vowel as well
		//we want to use a while loop because we want this to be continous until the two pointers cross
		//So while first is less than last and after doing vowel.find() receiving no hits within (-1) we can
		//safely enter the while loop advancing the pointer
		//We need two while loops, one for the first pointer and one for the second pointer
		//NPOS = -1
		while (first < last && vowels.find(s[first]) == std::string::npos) {
			first++;
		}
		while (first < last && vowels.find(s[last]) == std::string::npos) {
			last--;
		}

		//At this point within this method, first and last are both on a vowel,
		//This is true because they kept advancing every occurence that was not within 
		//Our string vowel
		//Now we have to swap the values of first and last within the string
		//going to make a temp variable to swap

		temp = s[first];
		s[first] = s[last];
		s[last] = temp;

		//Now we have to increment first and decrement last to continue forward after the operation
		first++;
		last--;


	}

	//After the while loop is done, the vowels will be reversed return the string

	return s;

}


int main() {

	Solution solution;

	std::string sS = "hEllo";
	std::string s = "AEIOUaeiou";

	std::cout << solution.reverseVowels(sS);


	//Time Complexity O(n)
	//Spacae Complexity O(n)

	return 0;
}