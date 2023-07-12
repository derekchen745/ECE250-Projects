#include <iostream>
#include <string>

class TrieNode {
    private:
        TrieNode *children[26];
        //TrieNode **children;
        bool terminal;
        //bool hasChildren;
        //std::string str;

    public:
        TrieNode();

        ~TrieNode();

        bool getTerminal();

        bool getHasChildren();

        bool insert(std::string word, int depth); //done

		bool search(std::string word, int depth); //done

        bool erase(std::string word, int depth, TrieNode *ptr);

		void clear();

        //void print(int depth);

        std::string spellcheckSearch(std::string word, char str[], int depth);

        friend class Trie;
};