/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include "scrabbleAssistant.h"
#include <algorithm>
#include <stdexcept>
#include <vector>

using std::vector;
using namespace std;

ScrabbleAssistant::ScrabbleAssistant(vector<string> words) {
  this->scrabbleTable = new HashTable<string, int>();
  this->sortedScrabbleTable = new HashTable<string, vector<string>>();
  for(int i = 0; i < words.size(); i++){
    this->scrabbleTable->insert(words[i], 0); //value doesn't matter
    string sortedWord = this->sortLetters(words[i]);
    if(this->sortedScrabbleTable->contains(sortedWord)){
      vector<string> anagrams = this->sortedScrabbleTable->get(sortedWord);
      anagrams.push_back(words[i]);
      this->sortedScrabbleTable->update(sortedWord,anagrams);
   }
    else {
      vector<string> anagrams = vector<string>();
      anagrams.push_back(words[i]);
      this->sortedScrabbleTable->insert(sortedWord, anagrams);
   }
  }
}

ScrabbleAssistant::~ScrabbleAssistant() {
    // TODO: implement destructor
    delete this->scrabbleTable;
    delete this->sortedScrabbleTable;
}

bool ScrabbleAssistant::spellCheck(string word) {
  return this->scrabbleTable->contains(word);
}

vector<string> ScrabbleAssistant::anagramsOf(string letters) {
  vector<string> anagramsVector = vector<string>();
  if(this->sortedScrabbleTable->contains(sortLetters(letters))){
    return this->sortedScrabbleTable->get(sortLetters(letters));
  }
  return anagramsVector; //return empty vector
}

vector<string> ScrabbleAssistant::findWords(string letters) {
  //must use for loop to go through all lengths of letters
  //i.e. cat has: cat, tac, act but also at
  vector<string> powerVector = stringPowerSet(letters);
  vector<string> validPowerVector;
  vector<string> temp;
  for(int i = 0; i < powerVector.size(); i++){
    temp = anagramsOf(powerVector[i]);
    validPowerVector.insert(validPowerVector.end(), temp.begin(),temp.end());
  }
  vector<string> final;
  for(int j = 0; j < validPowerVector.size(); j++) {
    final.push_back(validPowerVector[j]);
    for(int k = j + 1; k < validPowerVector.size(); k++) {
      if(validPowerVector[j] == validPowerVector[k]){
        final.pop_back();
        break;
      }
    }
  }
  return final;
}

vector<string> ScrabbleAssistant::stringPowerSet(string letters){
  vector<string> result;
  //base case: return empty set if letters is empty
  if(letters == ""){
    result.push_back("");
    return result;
  }

  char firstChar = letters[0];
  string sub = letters.substr(1);

  //recursive case: find subset of last n-1 elements in set
  vector<string> smallerResult = stringPowerSet(sub);

  for(int i = 0; i < smallerResult.size(); i++){
      result.push_back(smallerResult[i]); // recursive results
      result.push_back(firstChar+smallerResult[i]); // append first element
  }
  return result;
}
// TODO: implement here any other methods that you choose to declare
//thank you for providing this
string sortLetters(string s) {
  sort(s.begin(), s.end());
  return s;
}
