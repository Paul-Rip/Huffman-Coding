// Write your code here

#ifndef _HUFFMANTREE_H_
#define _HUFFMANTREE_H_

#include "BitStream.h"
#include "HuffmanNode.h"
#include <queue>
#include <map>

class HuffmanTree{
    private:
    HuffmanNode* root;
    std::string chars;
    std::map<char, std::string> paths;
    std::map<char, std::string> createEncodingsHelper(HuffmanNode* root, std::string path, int i);
    void constructorHelper(std::istream* in, HuffmanNode* root);
    public:
    HuffmanTree(std::map<char, int> counts);
    HuffmanTree(std::istream* in);
    std::map<char, std::string> createEncodings();
    void compress(ifstream* input, OBitStream* output);
    void decompress(IBitStream* input, OBitStream* output);
};


#endif
