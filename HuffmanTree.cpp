// Write your code here

#include "HuffmanTree.h"
#include <set>


HuffmanTree::HuffmanTree(std::map<char, int> counts){
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, HuffmanNode::Compare> pq;
    set<char> characters;
    for(auto kv : counts){
        pq.push(new HuffmanNode(kv.first, kv.second));
        characters.insert(kv.first);
    }
    for(char c : characters){
        chars += c;
    }
    while(pq.size() > 1){
        HuffmanNode* leftNode = pq.top();
        pq.pop();
        HuffmanNode* rightNode = pq.top();
        pq.pop();
        HuffmanNode* root = new HuffmanNode('/', leftNode->getAmount() + rightNode->getAmount());
        root->changeLeft(leftNode);
        root->changeRight(rightNode);
        pq.push(root);
    }
}
HuffmanTree::HuffmanTree(std::istream* in){
    std::string line;
    while (getline(*in, line)) {
        std::cout << line << std::endl;
    }
}
std::map<char, std::string> HuffmanTree::createEncodingsHelper(HuffmanNode* root, std::string path, int i){
    if(i == chars.size() - 1){
        return paths;
    } else if(root == nullptr){
        cout << "null" << endl;
        return paths;
    }
    if(chars[i] == root->getC()){
        paths[chars[i]] = path;
    }else{
        createEncodingsHelper(root->getLeft(), path + '0', i);
        createEncodingsHelper(root->getRight(), path + '1', i);
    }
    return paths;
}
std::map<char, std::string> HuffmanTree::createEncodings(){
    paths = createEncodingsHelper(root, "", 0);
    for(const auto& kv : paths){
        std::cout << kv.second << endl;
    }
    return paths;
}
void HuffmanTree::compress(ifstream* input, OBitStream* output){

}

void HuffmanTree::decompress(IBitStream* input, OBitStream* output){

}
