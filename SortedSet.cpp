#include "SortedSet.h"
#include "SortedSetIterator.h"

SortedSet::SortedSet(Relation r): rel(r), root(nullptr){
    count = 0;
}


bool SortedSet::add(TComp elem) {

    if (root == nullptr) {
        root = new node(elem);
        count ++;
        return true;
    }
    node * prev = nullptr;
    node * current = root;
    while (current != nullptr && current->data != elem) {
        if (rel(elem,current->data)) {
            prev = current;
            current = current->left;
        }
        else if (rel(current->data, elem)) {
            prev = current;
            current = current->right;
        }
    }
    if(current != nullptr)
        return false;
    if (rel(elem, prev->data))
        prev->left = new node(elem);
    else
        prev->right = new node(elem);
    count++;
    return true;
}
node* SortedSet::actuallyRemove(node* current, TComp elem, bool* changed) {
    if (current == nullptr)
        return nullptr;

    if (current->data == elem) {
        *changed = true;

        if (current->left == nullptr) {
            auto rightChild = current->right;
            delete current;
            return rightChild;
        }
        if (current->right == nullptr) {
            auto leftChild = current->left;
            delete current;
            return leftChild;
        }

        auto next = current;
        auto replacement = current->right;
        while (replacement->left != nullptr) {
            next = replacement;
            replacement = replacement->left;
        }

        current->data = replacement->data;

        if (next == current) {
            next->right = replacement->right;
        } else {
            next->left = replacement->right;
        }

        delete replacement;
        return current;
    }

    if (rel(elem, current->data)) {
        current->left = actuallyRemove(current->left, elem, changed);
    } else {
        current->right = actuallyRemove(current->right, elem, changed);
    }

    return current;
}

bool SortedSet::remove(TComp elem) {
    bool changed = false;
    root = actuallyRemove(root, elem, &changed);
    if (changed) {
        count--;
    }
    return changed;
}


bool SortedSet::search(TComp elem) const {
	auto current = root;
    while(current!= nullptr) {
        if (current->data == elem){
            return true;

        }else if(rel(elem, current->data)){
            current = current->left;
        }else{
            current = current->right;
        }
    }
	return false;
}


int SortedSet::size() const {
	return count;
}



bool SortedSet::isEmpty() const {
	return count == 0;
}

SortedSetIterator SortedSet::iterator() const {
	return SortedSetIterator(*this);
}


SortedSet::~SortedSet() {
	if(root == nullptr)
        return;
    actuallyDelete(root);
}

void SortedSet::actuallyDelete(node * current) {
    if(current->left!= nullptr)
        actuallyDelete(current->left);
    if(current->right!= nullptr)
        actuallyDelete(current->right);
    delete current;
}

int SortedSet::diff(const SortedSet &s) {
    auto it = s.iterator();
    int removed_count = 0;
    while(it.valid()){
        if(search(it.getCurrent())){
            remove(it.getCurrent());
            removed_count++;
        }
        it.next();
    }
    return removed_count;
}

int SortedSet::difference(const SortedSet &s){
    auto this_iterator = iterator();
    auto other_iterator = s.iterator();
    int removed_count = 0;
    while(other_iterator.valid() && this_iterator.valid()){
        while(rel(other_iterator.getCurrent(), this_iterator.getCurrent()) && this_iterator.getCurrent() != other_iterator.getCurrent() && other_iterator.valid()){
            other_iterator.next();
        }
        if(!other_iterator.valid()) break;
        if(other_iterator.getCurrent() == this_iterator.getCurrent()){
            remove(other_iterator.getCurrent());
            removed_count++;
            other_iterator.next();
        }else{
            this_iterator.next();
        }
    }
    return removed_count;
}


