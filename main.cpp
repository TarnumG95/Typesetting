/*
	This is a C++ implement of the beautiful typesetting problem. 
	Copyright @ Mr. Geng Tianyi
	Contact: gty12[at]mails[dot]tsinghua[dot]edu[dot]cn. 
*/

#include <iostream>
#include <vector>
using namespace std;

class Typesetting {
public: 
	unsigned long int num = 0; // Num of words
    int max_len = 0; // Maximum length of a line
    vector<int> word;
    vector<int> optiValuePre;
    vector<int> optiValuePost;
    vector<int> cut_point; // Index of beginning words in all lines.

    Typesetting();
    ~Typesetting();

    bool FindPostValue(); // Implement the optiValuePost array. 
    bool FindPreValue(); // Implement the optiValuePre array. 
    bool FindSolution();
};

bool Typesetting::FindPreValue() {
	if (!optiValuePre.length() == word.length()) { // Sanity check
		return false;
	}

	// Search from backward to forward 
	int curr_word = 0; // Index of current word
    int curr_len = 0; // Length of current line

    // If all words can be put in a single line
    while (curr_len + word[curr_word - 1] + 1 <= max_len) {
    	curr_word--;
    	curr_len += word[curr_word] + 1; 
    	optiValuePost[curr_word] = 0; 
    	cut_point[curr_word] = num - 1;
    }

    // Dynamic begins
    for (int i = curr_word - 1; i >= 0; --i) {
    	int temp_cut_pos = i;
    	curr_len = word[i];

    	// New words can be added to line begin with word[i]
    	while (curr_len + word[temp_cut_pos + 1] + 1 <= max_len) {
    		temp_cut_pos++;
    		curr_len += word[temp_cut_pos] + 1; 
			int temp_P_val = (max_len - curr_len)^2 + optiValuePost[temp_cut_pos + 1];
			// If the current cut position is better
    		if (temp_P_val < optiValuePost[i]) {
    			optiValuePost[i] = temp_P_val;
    			cut_point[i] = temp_cut_pos;
    		} //!!!!
    	}

    }

    bool Typesetting::FindPostValue() {
	if (!optiValuePost.length() == word.length()) { // Sanity check
		return false;
	}

	// Search from backward to forward 
	int curr_word = num; // Index of current word
    int curr_len = 0; // Length of current line

    // If all words can be put in a single line
    while (curr_len + word[curr_word - 1] + 1 <= max_len) {
    	curr_word--;
    	curr_len += word[curr_word] + 1; 
    	optiValuePost[curr_word] = 0; 
    	cut_point[curr_word] = num - 1;
    }

    // Dynamic begins
    for (int i = curr_word - 1; i >= 0; --i) {
    	int temp_cut_pos = i;
    	curr_len = word[i];

    	// New words can be added to line begin with word[i]
    	while (curr_len + word[temp_cut_pos + 1] + 1 <= max_len) {
    		temp_cut_pos++;
    		curr_len += word[temp_cut_pos] + 1; 
			int temp_P_val = (max_len - curr_len)^2 + optiValuePost[temp_cut_pos + 1];
			// If the current cut position is better
    		if (temp_P_val < optiValuePost[i]) {
    			optiValuePost[i] = temp_P_val;
    			cut_point[i] = temp_cut_pos;
    		} //!!!!
    	}

    }

	return true;
}








int main() {
    

    cin >> num >> max_len;

     

    for (int i = 0; i < num; ++i) {
    	cin >> word[i];
    }



    return 0;
}