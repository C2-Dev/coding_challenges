/*
Problem #3
Diffculty: MEDIUM

Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, and deserialize(s), which deserializes the string back into the tree.

For example, given the following Node class

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
The following test should pass:

node = Node('root', Node('left', Node('left.left')), Node('right'))
assert deserialize(serialize(node)).left.left.val == 'left.left'

*/

#include <iostream>
#include <string>

class  Node 
{
public:
  std::string val_;
  Node* lchild_;
  Node* rchild_;
  Node(std::string, Node* = NULL, Node* = NULL);
  static std::string Serialize(Node*);
};


int main() 
{
  Node* ll = new Node("left.left");
  Node* l = new Node("left", ll);
  Node* r = new Node("right");
  Node* root = new Node("root",  l, r);

  std::cout << "Node l.l.val: " << (*root).lchild_->lchild_->val_ << '\n';
  std::cout << "Serialize: " << Node::Serialize(root);
  std::cout << '\n';
  return 0;
}

Node::Node(std::string val, Node* lchild, Node* rchild) : 
  val_(val), lchild_(lchild), rchild_(rchild)
{
  // parameterized constructors
}

std::string Node::Serialize(Node* n)
{
  std::string str;
  
  if (n == NULL)
  {
    return str;
  }
  
  str.append(n->val_ + ',');
  str.append(Serialize(n->lchild_));
  str.append(Serialize(n->rchild_));
  return str;
}
