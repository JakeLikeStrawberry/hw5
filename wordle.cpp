// For debugging
#include <iostream>
// For std::remove
#include <algorithm> 
#include <map>
#include <set>
#include "wordle.h"
#include "dict-eng.h"
using namespace std;


// Add prototypes of helper functions here
void wordHelper(int i, int k, std::set<std::string> &all, 
std::string in, std::string floating, const std::set<std::string> &dict);

// Definition of primary wordle function
std::set<std::string> wordle(
    const std::string& in,
    const std::string& floating,
    const std::set<std::string>& dict)
{
    // Add your code here
        std::set<std::string> answers;
        std::string in_ = in;
        std::string floating_ = floating + '-';

        wordHelper(0, floating_.size()-1, answers, in_, floating_, dict);
        return answers;
        

}


// Define any helper functions here

void wordHelper(int i, int k, std::set<std::string> &all, 
std::string in, std::string floating, const std::set<std::string> &dict){

    if (i>= (int)in.size()){
        std::set<std::string>::iterator it = dict.find(in);
        if ((floating.empty() || floating[0] =='-' ) &&
            it != dict.end()){
            all.insert(in);
    }
        if (!floating.empty() && floating[0]=='-') {
            floating.clear();
            wordHelper(0, floating.size()-1+('z'-'a')+1, all, in, floating, dict);
    }
        return;
    }
        if (in[i] != '-') {
            wordHelper(i+1, k, all, in, floating, dict);
            return;
    }
            if (k <0){
                return;
    }
        wordHelper(i, k-1, all, in, floating, dict);

        if (k >= (int)floating.size()) {
            in[i] = 'a'+(k-floating.size());
            wordHelper(i, floating.size()-1+('z'-'a')+1, all, in, floating, dict);
        }
        else{
            in[i] = floating[k];
            if (floating[k]!='-') floating.erase(k, 1);
            wordHelper(i+1, floating.size()-1, all, in, floating, dict);
    }
    }

