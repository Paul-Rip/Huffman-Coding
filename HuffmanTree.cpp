// Write your code here

#include "HuffmanTree.h"
#include <set>


HuffmanTree::HuffmanTree(std::map<char, int> counts){
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, HuffmanNode::Compare> pq;
    pq.push(new HuffmanNode(EOF_marker, 1));
    if(counts.empty()){
        throw "Counts map can not be empty";
    }
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
    if(in == nullptr){
        throw "file is not valid";
    }
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
std::map<char, std::string> HuffmanTree::createEncodingsHelper(HuffmanNode* root, std::string path){
    if(root == nullptr){
        return paths;
    }
    if(root->isLeaf()){
        paths[root->getC()] = path;
    } else{
        createEncodingsHelper(root->getLeft(), path + "0");
        createEncodingsHelper(root->getRight(), path + "1");
    }
    return paths;
}
std::map<char, std::string> HuffmanTree::createEncodings(){
    map<char, std::string> allPaths;
    if(root == nullptr){
        throw "Tree can not be empty";
    }
    createEncodingsHelper(root, "");
    for(auto kv : paths){
        if(kv.first != EOF_marker){
            allPaths[kv.first] = kv.second;
        }else{
            allPaths[(char)EOF_marker] = paths[EOF_marker];
        }
    }
    return allPaths;
}
void HuffmanTree::compress(ifstream* input, OBitStream* output){
    char c;
    std::string pathOfC;
    if(input == nullptr || output == nullptr){
        throw "At least one file is not valid";
    }
    while(input->get(c)){
        pathOfC = paths[c];
        output->writeBits(pathOfC);
    }
    pathOfC = paths[EOF_marker];
    output->writeBits(pathOfC);
    output->close();
}

void HuffmanTree::decompress(IBitStream* input, OBitStream* output){
    HuffmanNode* current = root;
    int bit;
    bool eof = false;
    if(input == nullptr || output == nullptr){
        throw "At least one file is not valid";
    }
    while((bit = input->readBit()) != -1 && !eof){
         if(bit == 0){
            cout << "left" << endl;
            current = current->getLeft();
        }else if (bit == 1){
            cout << "right" << endl;
            current = current->getRight();
        }else if(bit == -1){
            return;
        }

        if(current->isLeaf()){
            if(current->getC() == EOF_marker){
                eof = true;
            }else{
                cout << current->getC() << endl;
                output->write(current->getC());
                current = root;
            }

        }
    }

    output->close();
}
