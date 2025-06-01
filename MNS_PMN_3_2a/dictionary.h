#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Dictionary {
public:
    Dictionary(const string& filename);
    
    void selectionSort();

    int binarySearch(const string& word) const;
    
    friend ostream& operator<<(ostream& ostr, const Dictionary& dict);
    
    const vector<string>& getWords() const;

private:
    vector<string> words;
    vector<string> unorderedWords, orderedWords;

};

#endif



//#ifndef DICTIONARY_H
//#define DICTIONARY_H
//
//#include <vector>
//#include <fstream>
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Dictionary
//{
//public:
//
//
//	Dictionary();
//
//	
//	Dictionary(const string& filename);
//
//
//	void initializeFile(const Dictionary& dictionaryObject);
//
//
//	friend ostream& operator<<(ostream& ostr, const Dictionary& dict);
//
//
//	void selectionSort();
//
//
//	void binarySearch(const string& beginning);
//
//
//
//	vector<string> wordsUnordered;
//	vector<string> wordsOrdered;
//
//	int sizeDictionary;
//
//
//private:
//
//
//}; // end Code class
//
//#endif