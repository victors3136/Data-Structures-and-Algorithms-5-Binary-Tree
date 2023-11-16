#pragma once
//DO NOT INCLUDE SETITERATOR

//DO NOT CHANGE THIS PART
typedef int TElem;
typedef TElem TComp;
typedef bool(*Relation)(TComp, TComp);
#define NULL_TELEM (-11111)
struct node {
    TComp data;
    node * left;
    node * right;
    explicit node(TComp value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
class SortedSetIterator;


class SortedSet {
	friend class SortedSetIterator;
private:
	node* root;
    Relation rel;
    int count;
	node * actuallyRemove(node * current, TComp elem, bool * changed);
    /// \Space: Theta(log(size))
    /// \Time: Theta(log(size))
    /// \Params: current -> BST node to act like a root for searching;
    /// \Params: elem -> value of the node to be removed
    /// \Params: changed -> ptr to bool to be used after the return of the function
    /// \Return: either current if elem was not found or the replacement for current if elem was found
    /// \Errors: throws no custom error
    void actuallyDelete(node * current);
    /// \Space: Theta(size)
    /// \Time: Theta(size)
    /// \Params: current -> BST node to act like a root for deletion;
    /// \Errors: throws no custom error
public:

	//constructor
	explicit SortedSet(Relation r);
    /// \Space: Theta(1)
    /// \Time: Theta(1)
    /// \Params: r -> relation serving as the base for the BST;
    /// \Errors: throws no custom error

	//adds an element to the sorted set
	//if the element was added, the operation returns true, otherwise (if the element was already in the set)
	//it returns false
	bool add(TComp e);
    /// \Space: Theta(1)
    /// \Time: Theta(log(size))
    /// \Params: e -> element to be added in the set;
    /// \Return: true if e was successfully added, false if it was already part of the set
    /// \Errors: throws no custom error
	//removes an element from the sorted set
	//if the element was removed, it returns true, otherwise false
	bool remove(TComp e);
    /// \Space: Theta(log(size))
    /// \Time: Theta(log(size))
    /// \Params: e -> value of the node to be removed
    /// \Return: true if e was successfully removed, false if it could not be found
    /// \Errors: throws no custom error

	//checks if an element is in the sorted set
	[[nodiscard]] bool search(TElem elem) const;
    /// \Space: Theta(1)
    /// \Time: Theta(log(size))
    /// \Params: elem -> value of the node to be searched
    /// \Return: true if elem is part of the set, false otherwise
    /// \Errors: throws no custom error


	//returns the number of elements from the sorted set
	[[nodiscard]] int size() const;
    /// \Space: Theta(1)
    /// \Time: Theta(1)
    /// \Return: number of elements in the set
    /// \Errors: throws no custom error

	//checks if the sorted set is empty
	[[nodiscard]] bool isEmpty() const;
    /// \Space: Theta(1)
    /// \Time: Theta(1)
    /// \Return: true if number of elements in the set is 0, false otherwise
    /// \Errors: throws no custom error

	//returns an iterator for the sorted set
	[[nodiscard]] SortedSetIterator iterator() const;
    /// \Space: O(size)
    /// \Time: O(size)
    /// \Errors: throws no custom error

	// destructor
	~SortedSet();
    /// \Space: Theta(size)
    /// \Time: Theta(size)
    /// \Errors: throws no custom error

    int diff(const SortedSet& s);
    /// \Space: Theta(log(size) * #of_elements_matching)
    /// \Time: O(s.size * log(size))
    /// \Param: s Sorted Set ordered by the same relation as *this
    /// \Return: number of elements matching between the two
    /// \Errors: Throws no custom errors

    int difference(const SortedSet& s);
    /// \Space: Theta(size + s.size())
    /// \Time: O(size + s.size())
    /// \Param: s Sorted Set ordered by the same relation as *this
    /// \Return: number of elements matching between the two
    /// \Errors: Throws no custom errors
};
