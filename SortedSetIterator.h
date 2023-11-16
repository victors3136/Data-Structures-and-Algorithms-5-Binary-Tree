#pragma once

#include <stdexcept>
#include "SortedSet.h"
#include "NodeStack.h"
//DO NOT CHANGE THIS PART
class SortedSetIterator
{
	friend class SortedSet;
private:
	const SortedSet& set;
    NodeStack stack;
    void pushNodesOnTheLeft(node* current);
    /// \Space: O(set.size)
    /// \Time: O(set.size)
    /// \Params: current -> BST node to act like a root from which to start looking;
    /// \Errors: throws no custom error
    explicit SortedSetIterator(const SortedSet& m);
    /// \Space: O(m.size)
    /// \Time: O(m.size)
    /// \Params: m->sorted set with a BST representation
    /// \Errors: throws no custom error
public:
	void first();
    /// \Space: Theta(set.size)
    /// \Time: O(set.size)
    /// \Errors: throws no custom error
	void next();
    /// \Space: Theta(1)
    /// \Time: Theta(1)
    /// \Errors: throws runtime error if the stack is empty
	TElem getCurrent();
    /// \Space: Theta(1)
    /// \Time: Theta(1)
    /// \Return: value of the node at the top of the stack
    /// \Errors: throws runtime error if the stack is empty
	[[nodiscard]] bool valid() const;
    /// \Space: Theta(1)
    /// \Time: Theta(1)
    /// \Return: true if the stack is not empty
    /// \Errors: throws no custom error
    ~SortedSetIterator()=default;
};

