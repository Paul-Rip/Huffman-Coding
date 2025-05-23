// Write your code here


#ifndef HUFFMANNODE_H_
#define HUFFMANNODE_H_

class HuffmanNode{
    private:
    char c;
    int amount;
    HuffmanNode* left;
    HuffmanNode* right;
    public:
    HuffmanNode(char c, int amount);
    bool isLeaf();
    char getC();
    int getAmount();
    HuffmanNode* getLeft();
    HuffmanNode* getRight();
    struct Compare{
        bool operator()(HuffmanNode* a, HuffmanNode* b){
            return a->amount > b->amount;
        }
    };
    void changeLeft(HuffmanNode* left);
    void changeRight(HuffmanNode* right);
    void changeC(char c);
    void changeAmount(int amount);
};

/*struct HuffmanNode{
    std::string data;
    HuffmanNode* left;
    HuffmanNode* right;
    HuffmanNode(std::string data);
    bool isLeaf();
};*/

#endif
