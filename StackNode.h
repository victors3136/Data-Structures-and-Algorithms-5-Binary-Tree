//
// Created by victor on 31/05/2023.
//

#ifndef L05_STACKNODE_H
#define L05_STACKNODE_H

#include "SortedSet.h"
class StackNode {
public:
    node* treeNode;
    StackNode* next;

    explicit StackNode(node* value) : treeNode(value), next(nullptr) {}
};


#endif //L05_STACKNODE_H
