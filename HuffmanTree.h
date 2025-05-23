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
    std::map<char, std::string> coded;
    std::map<char, std::string> createEncodingsHelper(HuffmanNode* root);
    public:
    HuffmanTree(std::map<char, int> counts);
    HuffmanTree(std::istream* in);
    std::map<char, std::string> createEncodings();
    void compress(ifstream* input, OBitStream* output);
    void decompress(IBitStream* input, OBitStream* output);

};


#endif
