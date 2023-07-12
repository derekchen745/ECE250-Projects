#include <iostream>
#include <string>
#include "Trie.h"
#include "IllegalException.h"



Trie::Trie(){
    rootNode = nullptr;
    trieSize = 0;
};

Trie::~Trie(){
    //clear();
    delete this->rootNode;
    rootNode = nullptr;
};

TrieNode* Trie::getRoot(){
    return rootNode;
}

int Trie::insert(std::string word){
    for (int i=0; i<word.length(); i++){
		if(word[i] < 96 || word[i] > 123){
            try {
                throw illegal_exception();
            }catch (illegal_exception ie) {
                ie.printExplaination();
                return 2;
            }
		}
	}

    int count = this->search(word);
    if(count == 0){
        // std::cout<<"failure"<<std::endl;
        // return;
        return 1;
    }

	if(rootNode == nullptr){
		rootNode = new TrieNode();
	}
	bool flag = rootNode->insert(word, 0);
	if(flag == true){
        //std::cout<<"success"<<std::endl;
		trieSize++;
        return 0;
	}else{
        // std::cout<<"failure"<<std::endl;
        return 1;
    }
};

int Trie::search(std::string word){
    for (int i=0; i<word.length(); i++){
		if(word[i] < 96 || word[i] > 123){
            try {
                throw illegal_exception();
            }catch (illegal_exception ie) {
                ie.printExplaination();
                return 2;
            }
		}
	}

    if(rootNode == nullptr){
        return 1;
    }
    bool flag = rootNode->search(word, 0);
    if(flag == true){
        // std::cout<<"success"<<std::endl;
        return 0;
	}else{
        // std::cout<<"failure"<<std::endl;
        return 1;
    }
};

int Trie::erase(std::string word){
    for (int i=0; i<word.length(); i++){
		if(word[i] < 96 || word[i] > 123){
            try {
                throw illegal_exception();
            }catch (illegal_exception ie) {
                ie.printExplaination();
                return 2;
            }
		}
	}

    int count = this->search(word);
    if(count == 1){//not in the trie
        //std::cout<<"not found erase"<<std::endl;
        // return;
        return 1;
    }
    if(rootNode == nullptr){
		return 1;
	}
    bool flag = rootNode->erase(word, 0, rootNode);
    if(flag == true){
        //std::cout<<"true"<<std::endl;
		trieSize--;
        return 0;
	}else{
        //std::cout<<"false"<<std::endl;
        return 1;
    }
};

int Trie::print(TrieNode* rootNode, char word[], int depth){
    if (rootNode == nullptr){
        //std::cout<<"rootnode is nullptr"<<std::endl;
        return 1;
    }
    //std::cout<<"HELLOPEE";
    bool flag = rootNode->terminal;
    if(flag == true){
        word[depth] = '\0';
        std::cout<<word<<" ";
    }

    for (int i=0; i<26; i++){
        if(rootNode->children[i] != nullptr){
            word[depth] = i + 97;
            print(rootNode->children[i], word, depth + 1);
        }
    }
    return 0;
};

int Trie::printSP(TrieNode* rootNode, char word[], int depth, std::string prefix){
    if (rootNode == nullptr){
        //std::cout<<"rootnode is nullptr"<<std::endl;
        return 1;
    }
    //std::cout<<"HELLOPEE";
    bool flag = rootNode->terminal;
    if(flag == true){
        word[depth] = '\0';
        std::cout<<prefix + word<<" ";
    }

    for (int i=0; i<26; i++){
        if(rootNode->children[i] != nullptr){
            word[depth] = i + 97;
            printSP(rootNode->children[i], word, depth + 1, prefix);
        }
    }
    return 0;
};

// void Trie::printSpellcheck(TrieNode *currentNode, std::string prefix, std::string suffix){
//     bool flag = false;
//     if (currentNode->terminal){
//         std::cout<<prefix<<" ";
//     }
//     for (int i=0; i<26; i++){
//         std::string suggestion = "";
//         char nextCharacter = 97 + i;
//         if(currentNode->children[i] != nullptr){
//             if(i < prefix.length() && nextCharacter == prefix[i]){
//                 suggestion = prefix + nextCharacter;
//                 printSpellcheck(currentNode->children[i], suggestion, "");
//             }
//         }
//     }
// }

void Trie::getSpellcheckNode(TrieNode* rootNode, const std::string prefix){
    TrieNode *temp = rootNode;
    int strLength = prefix.length();
    int charIndex;

    for(int i=0; i<strLength; i++){
        charIndex = prefix[i] - 97;
        temp = temp->children[charIndex];

    }
    // if (temp->terminal) {
    //     std::cout << prefix << std::endl;
    //     return -1;
    // }
    //printSpellcheck(temp, prefix, "");
    char string[26];
            for(int i = 0; i<26; i++){
                string[i] = '\0';
            }
    printSP(temp, string, 0, prefix);
    //return 1;
}

void Trie::clear(){
    if(rootNode != nullptr){
        rootNode->clear();
        trieSize = 0;
    }
    rootNode = nullptr;
};

void Trie::empty(){
    if(trieSize == 0){
        std::cout<<"empty 1";
    }else{
        std::cout<<"empty 0";
    }
    std::cout<<std::endl;
};

void Trie::size(){
    std::cout<<"number of words is: " <<trieSize<<std::endl;
};



