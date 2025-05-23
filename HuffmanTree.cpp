// Write your code here

#include "HuffmanTree.h"


HuffmanTree::HuffmanTree(std::map<char, int> counts){
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;
    for(auto kv : counts){
        pq.push(new HuffmanNode(kv.first, kv.second));
    }
    while(!pq.empty()){
        cout << "test" << endl;
        cout << pq.top()->getC() << " " << pq.top()->getAmount() << endl;
        pq.pop();
    }
}
HuffmanTree::HuffmanTree(std::istream* in){
    cout << "working 2" << endl;
}
std::map<char, std::string> HuffmanTree::createEncodings(){
    return coded;
}
void HuffmanTree::compress(ifstream* input, OBitStream* output){

}

void HuffmanTree::decompress(IBitStream* input, OBitStream* output){

}
