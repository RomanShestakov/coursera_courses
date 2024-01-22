#include<iostream>
#include<vector>

enum Node_t {
    SCOPE,
    UNOP,
    BINOP,
};

enum UnOp_t {
    INC,
    DEC
};

enum BinOp_t {
    ADD,
    SUB,
    MULT,
    DIV
};

struct Node {
    Node *parent_;
    Node_t type_;
};

struct UnOp : public Node {
    UnOp_t op_;
    Node *rhl_;
    UnOp( Node* parent, UnOp_t opcode ) : Node(parent, Node_t::UNOP), op_(opcode) {}
};

struct BinOp : public Node {
    BinOp_t op_;
    Node *lhr_;
    Node *rhl_;

    BinOp( Node* parent, BinOp_t opcode ) : Node(parent, Node_t::BINOP), op_(opcode) {}
};

void foo( const Node& pn );

int main() {
    std::vector< Node*> nodes;

    nodes.push_back( new BinOp( nullptr, ADD ) );
    nodes.push_back( new UnOp( nullptr, INC ) );
    // foo( *b );
    // Node *pn = b;
    // b = static_cast< BinOp*>( pn );

    return 0;
}
