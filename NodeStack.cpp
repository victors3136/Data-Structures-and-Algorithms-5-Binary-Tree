//
// Created by victor on 31/05/2023.
//

#include <stdexcept>
#include "NodeStack.h"

node *NodeStack::top() const  {
    if (head == nullptr)
        throw std::runtime_error("Empty stack");
    return head->treeNode;
}

void NodeStack::push(node *value) {
    auto newTop = new StackNode(value);
    newTop->next = head;
    head = newTop;
}

node *NodeStack::pop() {
    if (head == nullptr)
        throw std::runtime_error("Empty stack");
    auto tempNode = head->treeNode;
    auto tempNext = head->next;
    delete head;
    head = tempNext;
    return tempNode;
}

bool NodeStack::empty() const {
    return head == nullptr;
}

void NodeStack::clear()  {
    auto current = head;
    while (current != nullptr) {
        auto next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}
