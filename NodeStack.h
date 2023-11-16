//
// Created by victor on 31/05/2023.
//

#ifndef L05_NODESTACK_H
#define L05_NODESTACK_H

#include "StackNode.h"

class NodeStack {
private:
    StackNode* head;

public:
    NodeStack() : head(nullptr) {}
    ~NodeStack() {
        clear();
    }

    [[nodiscard]] node* top() const;
    /// \Time: Theta(1)
    /// \Space: Theta(1)
    /// \Return: BST Node Ptr without removing it from the stack
    /// \Errors: throws no custom errors

    void push(node* value);
    /// \Time: Theta(1)
    /// \Space: Theta(1)
    /// \Param: value - BST Node Ptr
    /// \Errors: throws no custom errors
    node* pop();
    /// \Time: Theta(1)
    /// \Space: Theta(1)
    /// \Return: BST Node Ptr, also removed from the stack
    /// \Errors: throws no custom errors
    [[nodiscard]] bool empty() const;
    /// \Time: Theta(1)
    /// \Space: Theta(1)
    /// \Return: true if the stack is empty
    /// \Errors: throws no custom errors

    void clear();
    /// \Time: Theta(length)
    /// \Space: Theta(1)
    /// \Errors: throws no custom errors
};


#endif //L05_NODESTACK_H
