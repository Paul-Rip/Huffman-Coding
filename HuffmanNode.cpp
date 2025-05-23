// Write your code here
#include "HuffmanNode.h"

HuffmanNode::HuffmanNode(char c, int amount) : c(c), amount(amount), left(nullptr), right(nullptr){}

bool HuffmanNode::isLeaf(){
    return left == nullptr && right == nullptr;
}

char HuffmanNode::getC(){
    return c;
}
int HuffmanNode::getAmount(){
    return amount;
}

HuffmanNode* HuffmanNode::getLeft(){
    return left;
}

HuffmanNode* HuffmanNode::getRight(){
    return right;
}

void HuffmanNode::changeLeft(HuffmanNode* left){
    this->left = left;
}

void HuffmanNode::changeRight(HuffmanNode* right){
    this->right = right;
}

void HuffmanNode::changeC(char c){
    this->c = c;
}

void HuffmanNode::changeAmount(int amount){
    this->amount = amount;
}
