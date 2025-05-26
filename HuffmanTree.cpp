// Write your code here

#include "HuffmanTree.h"
#include <set>


HuffmanTree::HuffmanTree(std::map<char, int> counts){
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, HuffmanNode::Compare> pq;
    pq.push(new HuffmanNode('@', 1));
    for(auto kv : counts){
        pq.push(new HuffmanNode(kv.first, kv.second));
    }
    while(pq.size() > 1){
        HuffmanNode* leftNode = pq.top();
        pq.pop();
        HuffmanNode* rightNode = pq.top();
        pq.pop();
        root = new HuffmanNode('/', leftNode->getAmount() + rightNode->getAmount());
        root->changeLeft(leftNode);
        root->changeRight(rightNode);
        pq.push(root);
    }
}
HuffmanTree::HuffmanTree(std::istream* in){
    std::string line;
    int x = 0;
    char c;
    root = new HuffmanNode('/', 0);
    HuffmanNode* curr = root;
    while(getline(*in, line)){
        if(x % 2 == 0){
            c = static_cast<char>(std::stoi(line));
        }
        else{
            curr = root;
            for(int i = 0; i < line.size(); i++){
                if(line[i] == '1'){
                    if(curr->getRight() == nullptr){
                        curr->changeRight(new HuffmanNode(c, 0));
                    }
                    curr = curr->getRight();
                }else{
                    if(curr->getLeft() == nullptr){
                        curr->changeLeft(new HuffmanNode(c, 0));
                    }
                    curr = curr->getLeft();
                }
            }
            curr->changeC(c);
        }
        x++;
    }
}
std::map<char, std::string> HuffmanTree::createEncodingsHelper(HuffmanNode* root, std::string path, int i){
    if(root == nullptr){
        return paths;
    }
    if(root->isLeaf()){
        paths[root->getC()] = path;
        std::cout << root->getC() << " " << path << endl;
    } else{
        createEncodingsHelper(root->getLeft(), path + "0", i);
        createEncodingsHelper(root->getRight(), path + "1", i);
    }
    return paths;
}
std::map<char, std::string> HuffmanTree::createEncodings(){
    createEncodingsHelper(root, "", 0);
    return paths;
}
void HuffmanTree::compress(ifstream* input, OBitStream* output){
    char c;
    std::string pathOfC;
    while(input->get(c)){
        pathOfC = paths[c];
        output->writeBits(pathOfC);
    }
    pathOfC = paths['@'];
    output->writeBits(pathOfC);
    output->close();
}

void HuffmanTree::decompress(IBitStream* input, OBitStream* output){
    HuffmanNode* current = root;
    int bit;
    while((bit = input->readBit()) != -1){
         if(bit == 0){
            cout << "left" << endl;
            current = current->getLeft();
        }else if (bit == 1){
            cout << "right" << endl;
            current = current->getRight();
        }

        if(current->isLeaf()){
            cout << current->getC() << endl;
            output->write(current->getC());
            current = root;
        }
    }
}
