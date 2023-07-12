#include <iostream>
#include <fstream>
#include <string>
#include "Trie.h"

int main(){
    Trie myTrie;

    std::string cmd;
    std::string addWord;
    while(std::cin >> cmd){
        if(cmd == "load"){
            std::ifstream fin("corpus.txt");

            while(fin >> addWord){
                //std::cout<<addWord<<std::endl;
                myTrie.insert(addWord);
                
            }
            std::cout<<"success"<<std::endl;
        }
        
        else if(cmd == "i"){
            std::cin >> addWord;
            int count = myTrie.insert(addWord);
            if(count == 0){
                std::cout<<"success"<<std::endl;
            }else if(count == 1){
                std::cout<<"failure"<<std::endl;
            }
        }
        
        else if(cmd == "s"){
            std::cin >> addWord;
            int count = myTrie.search(addWord);
            if(count == 0){
                std::cout<<"found "<<addWord<<std::endl;
            }else if(count == 1){
                std::cout<<"not found"<<std::endl;
            }
        }
        
        else if(cmd == "e"){
            //std::cout<<"erase"<<std::endl;
            std::cin >> addWord;
            
            int count = myTrie.erase(addWord);
            if(count == 0){
                std::cout<<"success"<<std::endl;
            }else if(count == 1){
                std::cout<<"failure"<<std::endl;
            }


        }
        
        else if(cmd == "p"){
            // char str[20];
            char string[26];

            //std::cout<<"print1"<<std::endl;
            int count = myTrie.print(myTrie.getRoot(), string, 0);
            if(count != 1){
                std::cout<<std::endl;
            }
        }
        
        else if(cmd == "spellcheck"){
            //std::cout<<"spellcheck"<<std::endl;
            std::cin >> addWord;
            //std::cout<<addWord<<std::endl;

            //myTrie.printPrefix(myTrie.getRoot(),addWord);

            char string[26];
            for(int i = 0; i<26; i++){
                string[i] = '\0';
            }
            std::string prefix = ""; 
            if(myTrie.getRoot() != nullptr){
                prefix = myTrie.getRoot()->spellcheckSearch(addWord, string, 0);
                if(myTrie.search(addWord) == 0){
                    std::cout<<"correct"<<std::endl;

                }else if(prefix == ""){ 
                    std::cout<<std::endl;
                }else{
                    myTrie.getSpellcheckNode(myTrie.getRoot(), prefix);
                    std::cout<<std::endl;

                }
            }else if(myTrie.getRoot() == nullptr){
                 std::cout<<std::endl;
                 //std::cout<<std::endl;
            }


            //}else if(count == 0){
                

                // if(prefix == ""){
                //     std::cout<<std::endl;

                // }else{
                //myTrie.spellcheck(addWord, myTrie.getRoot(), prefix, "");
                
                //}
            //}
            
            
            //myTrie.spellcheck(myTrie.getRoot(), prefix, "");
            //std::cout<<myTrie.getRoot()<<std::endl;
            //std::cout<<myTrie.getRoot()->spellcheckSearch(addWord, string, 0)<<std::endl;
            //std::cout<<"spellcheck"<<std::endl;
        }
        
        else if(cmd == "empty"){
            myTrie.empty();
        }
        
        else if(cmd == "clear"){
            myTrie.clear();
            std::cout<<"success"<<std::endl;
        }
        
        else if(cmd == "size"){
            myTrie.size();
        }
        
        else if(cmd == "exit"){
            myTrie.clear();
            return 0;
        }
    }
}

