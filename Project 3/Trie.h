#include <iostream>
#include <string>
#include "TrieNode.h"

class Trie{
    private:
        TrieNode *rootNode;
        int trieSize;

    public:
        Trie();
        ~Trie();

        TrieNode* getRoot();

        int insert(std::string word); //done

        int search(std::string word); //done

        int erase(std::string word);

        int print(TrieNode *ptr, char str[], int depth);

        //void spellcheck(std::string word, TrieNode *rootNode, std::string prefix, std::string suffix); //, TrieNode* rootNode, std::string prefix, std::string suffix

        int printSP(TrieNode* rootNode, char word[], int depth, std::string prefix);

        //void printSpellcheck(TrieNode *currentNode, std::string prefix, std::string suffix);

        void getSpellcheckNode(TrieNode* rootNode, const std::string prefix);

        void empty();

		void clear();

        void size();


};