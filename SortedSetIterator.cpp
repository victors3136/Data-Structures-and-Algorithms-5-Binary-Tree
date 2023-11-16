#include "SortedSetIterator.h"
#include <stdexcept>

using namespace std;
SortedSetIterator::SortedSetIterator(const SortedSet& m) : set(m){
    pushNodesOnTheLeft(set.root);
}

void SortedSetIterator::first(){
    stack.clear();
    pushNodesOnTheLeft(set.root);
}

void SortedSetIterator::next(){
    auto temp = stack.pop();
    pushNodesOnTheLeft(temp->right);
}

TElem SortedSetIterator::getCurrent(){
    if(stack.empty())
        throw std::runtime_error("Empty stack");
    return stack.top()->data;
}

bool SortedSetIterator::valid() const{
    return !(stack.empty());
}

void SortedSetIterator::pushNodesOnTheLeft(node *current) {
    while(current!= nullptr){
        stack.push(current);
        current= current->left;
    }
}


