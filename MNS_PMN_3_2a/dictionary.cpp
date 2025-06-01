// Dictionary class: where we read words from the dictionary and store them in a vector
// The purpose of this function is to translate from file (.txt format) to vector and order the 
// words alphabetically to facilitate in search


#include "Dictionary.h"
#include <fstream>
#include <ostream>

Dictionary::Dictionary(const string& filename) {
    // open file for reading dictionary, must be within folder if only name was specified

    ifstream in(filename);

    string receivedWord;
    while (in >> receivedWord) {
        // according to the word serach guidelines, words must be at least 5 characters long
        // if abiding, append to vector

        if (receivedWord.length() >= 5)
            unorderedWords.push_back(receivedWord);

    }

    // end receiving form input file. vector has now been completely filled with every valid word 
    // from dictionary. only unsorted vector is available so far

    in.close();
}

void Dictionary::selectionSort() {
    // sort as shown in class, so that algorithm has worst time case = O^2
    // in such a manner that a where the index value of the character is lower than that of the next word, 
    // they get swapped until whole vector is ordered


    int wordCount = unorderedWords.size();

    // copying unorderedVector into a new orderedVector for receiving sorting
    // unnecessary step but leaves vector untouched for debugging

    for (int i = 0; i < wordCount; i++) {
        orderedWords.push_back(unorderedWords[i]);
    }


    for (int i = 0; i < wordCount - 1; i++) {
        int min = i;
       
        for (int j = i + 1; j < wordCount; j++) {
            
            if (orderedWords[j] < orderedWords[min])
                min = j;
        }
        
        // for each word in unorderedWords, it founds the minimum word (e.g.: aaaaa) and swaps it for whatever 
        // the first index holds, so that the next loop of this outter for loop will look for the second to minimum word
        swap(orderedWords[i], orderedWords[min]);


    }

    for (int i = 0; i < words.size(); i++) {
        cout << orderedWords[i] << "\n";
    }


}

int Dictionary::binarySearch(const string& wordCompare) const {
    // this function allows us to run a binary search to compare a word given closing into the words from the dictionary that
    // have been ordered in such a manner that if the word is found, its index within the ordered list will be returned, but a 
    // negative index will be returned otherwise


    int left = 0;
    int right = orderedWords.size() - 1;
    int mid = 0;

    while (left <= right) {
        mid = (left + right) / 2;
        
        if (orderedWords[mid] == wordCompare) {

            // in this case, the word seeked for has been found in dictionary, so its index is returned
            return mid;

        }

        // continues if word not found, this means word might still be on the left or right side from index checked.
        // The next if/else case decides which side the word could still be at, and shifts right or left bound accordingly
        
        if (orderedWords[mid] < wordCompare) {

            left = mid + 1;

        }

        else {

            right = mid - 1;
        }

    }

    // if the while loop is over, that means we have closed into the word from both sides and not found any matches on the dictionary
    // which means the search is over and there was no compatibility

    return -1;
}

ostream& operator<<(ostream& ostr, const Dictionary& dict) {
    ostr << "beginning...\n";
    for (int i = 0; i < dict.orderedWords.size(); i++) {

        ostr << dict.orderedWords[i] << "\n";

    }
    return ostr;
    
}



const vector<string>& Dictionary::getWords() const {
    return words;
}



//#include "dictionary.h"
//#include <vector>
//#include <iostream>
//using namespace std;
//
//Dictionary::Dictionary() {
//
//    return;
//
//}
//
//
//Dictionary::Dictionary(const string& filename) {
//    ifstream file(filename);
//    string line;
//    while (getline(file, line)) {
//        wordsUnordered.push_back(line);
//    }
//
//    sizeDictionary = wordsUnordered.size();
//    wordsOrdered.resize(sizeDictionary);
//
//}
//
//
//void Dictionary::initializeFile(const Dictionary& dictionaryObject) {
//
//
//}
//
//
//ostream& operator<<(ostream& ostr, const Dictionary& dict) {
//
//
//}
//
//
//void Dictionary::selectionSort() {
//
//}
//
//
//void Dictionary::binarySearch(const string& beginning) {
//
//}
