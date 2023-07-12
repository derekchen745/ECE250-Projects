#include <iostream>
#include <string>
#include "TrieNode.h"

TrieNode::TrieNode(){
    for(int i=0; i<26; i++){
        children[i] = nullptr;
    }
    //children = nullptr;
    terminal = false;
    //hasChildren = false;
    //str = "";
}

TrieNode::~TrieNode(){};

bool TrieNode::getTerminal(){
    return terminal;
}

bool TrieNode::getHasChildren(){
    for(int i=0; i<26; i++){
        if(children[i] != nullptr){
            return true;
        }
    }
    return false;
}


bool TrieNode::insert(std::string word, int depth){
    //Initializes the node's children if it has not been intialized yet
    // if(children == nullptr){
    //     children = new TrieNode*[26];
    //     for(int i=0; i<26; i++){
    //         children[i] = nullptr;
    //     }
    // }

    if(depth == word.length() && terminal == false){
        terminal = true;
        return true;
    }

    //Takes the letter and converts it to its position in the alphabet  
    char currentChar = word[depth];
    int charIndex = currentChar - 97; 

    //std::cout<<charIndex<<std::endl;
    if(children[charIndex] == nullptr){
        children[charIndex] = new TrieNode();
    }
    
    depth += 1;
    return children[charIndex]->insert(word, depth);
}

bool TrieNode::search(std::string word, int depth){
    //At the end of the word, if the last letter is terminal, then it is in the trie, if not then it is not in the trie
    if(depth == word.length()){
        return terminal;
    }

    char currentChar = word[depth];
	int charIndex = currentChar - 97;

    //std::cout<<charIndex<<std::endl;
    if(children == nullptr || children[charIndex] == nullptr){
		return false;
	}else{
        depth += 1;
		return children[charIndex]-> search(word, depth);
	}
};

bool TrieNode::erase(std::string word, int depth, TrieNode *ptr){
    if(depth == word.length() && terminal == true){
        terminal = !terminal;
        return true;
    }

    char currentChar = word[depth];
	int charIndex = currentChar - 97;

    if(children == nullptr || children[charIndex] == nullptr){
		return false;
	}

    depth += 1;
    bool next = children[charIndex]->erase(word, depth, children[charIndex]);
	if(next == false){
		return false;
	}

	TrieNode *temp = children[charIndex];
    //TrieNode *null = nullptr;
    if(temp->terminal == false){
        //std::cout<<"HELLO1"<<std::endl;
        //std::cout<<temp->children<<std::endl;
        //std::cout<<null<<std::endl;
        if(temp->getHasChildren() == false){
           // std::cout<<"HEHLO2"<<std::endl;
            //std::cout<<charIndex + 97<<std::endl;
            
            delete temp;
            temp = nullptr;
            //delete children[charIndex];
            children[charIndex] = nullptr;
        }
    }

	// 	children[charIndex] = nullptr;
	// }
    //delete temp;
	return true;
};

void TrieNode::clear(){
    if(children != nullptr){
        //std::cout<<"HELLO!@"<<std::endl;
        for(int i=0; i<26; i++){
            if(children[i] != nullptr){
                //std::cout<<"123clearpls"<<std::endl;
                children[i]->clear();
                children[i] = nullptr;
            }
        }
        //delete []children;
    }
    delete this;
};


std::string TrieNode::spellcheckSearch(std::string word, char str[], int depth){
    //std::string str = "";
    char currentChar = word[depth];
 	int charIndex = currentChar - 97;
    int strLength = 0;

    for(int i=0; i<26; i++){
        if(str[i] != '\0'){
            strLength++;
        }
    }

    if(depth == strLength){
        if(terminal == true){
            //std::cout<<"3 "<< str<<std::endl;
            return str;
        }
    // }else if(strLength == 0){
    //     return "";
    }

    if(children == nullptr || children[charIndex] == nullptr){
        //std::cout<<"4"<<str<<std::endl;
        return str;
    }else{
        char add =  charIndex + 97;
        //std::cout<<"add "<<add<<std::endl;
        if(add > 96 || add < 123){
            str[depth] = charIndex + 97;
        }
        //std::cout<<charIndex + 97<<std::endl;
        //std::cout<<"1: "<<str<<std::endl;
        depth += 1;
        children[charIndex]-> spellcheckSearch(word, str, depth);
    }
    //std::cout<<"2: "<<str<<std::endl;
    return str;
};
