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
