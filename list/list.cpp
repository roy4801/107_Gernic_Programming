#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <initializer_list>
#include <string>

using namespace std;

template <typename T>
struct listNode {
    T data;
    struct listNode<T> *nextPtr;
    typedef input_iterator_tag iterator_category;
};

template<typename T>
using ListNode = listNode<T>;
template<typename T>
using ListNodePtr = listNode<T>*;

// ListNode<T> a'
template <class T>
struct node_wrap : public iterator<input_iterator_tag, T>
{
	// typedef input_iterator_tag iterator_category;
	T* ptr;
	node_wrap(T* p = nullptr) : ptr(p) { }
	decltype(ptr->data) operator*() const { return ptr->data; }
	T* operator->() const { return ptr; }
	node_wrap& operator++() { ptr = ptr->nextPtr; return *this; }

	bool operator==(const node_wrap& i) const { return ptr == i.ptr; }
	bool operator!=(const node_wrap& i) const { return ptr != i.ptr; }
};

template<typename T>
using ListIter = node_wrap< ListNode<T> >;

// insert a new value into the list in sorted order
template <typename T>
void insert(ListNodePtr<T> *sPtr, T value)
{
    ListNodePtr<T> newPtr = (ListNodePtr<T>)malloc(sizeof(ListNode<T>)); // create node

    if (newPtr != NULL) { // is space available
        newPtr->data = value; // place value in node
        newPtr->nextPtr = NULL; // node does not link to another node

        ListNodePtr<T> previousPtr = NULL;
        ListNodePtr<T> currentPtr = *sPtr;

        // loop to find the correct location in the list
        while (currentPtr != NULL) {
            previousPtr = currentPtr; // walk to ...
            currentPtr = currentPtr->nextPtr; // ... next node
        }

        // insert new node at beginning of list
        if (previousPtr == NULL) {
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        }
        else { // insert new node between previousPtr and currentPtr
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    }
    else {
        cout << value << " not inserted. No memory available." << '\n';
        // printf("%c not inserted. No memory available.\n", value);
    }
}

template <typename T>
T del(ListNodePtr<T> *sPtr, T value)
{
    if (value == (*sPtr)->data) {
        ListNodePtr<T> tempPtr = *sPtr; // hold onto node being removed
        *sPtr = (*sPtr)->nextPtr; // de-thread the node
        free(tempPtr); // free the de-threaded node
        return value;
    }
    else {
        ListNodePtr<T> previousPtr = *sPtr;
        ListNodePtr<T> currentPtr = (*sPtr)->nextPtr;

        // loop to find the correct location in the list
        while (currentPtr != NULL && currentPtr->data != value) {
            previousPtr = currentPtr; // walk to ...
            currentPtr = currentPtr->nextPtr; // ... next node
        }

        // delete node at currentPtr
        if (currentPtr != NULL) {
            ListNodePtr<T> tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free(tempPtr);
            return value;
        }
    }

    return '\0';
}

template<typename T>
void deleteList(ListNodePtr<T> sPtr)
{
    auto head = sPtr;
    while(head && head->nextPtr)
    {
        auto tmp = head->nextPtr;
        delete head;
        head = tmp;
    }
    delete head;
}

template <typename T>
bool isEmpty(ListNodePtr<T> sPtr)
{
    return sPtr == NULL;
}

// print the list
template <typename T>
void printList(ListNodePtr<T> currentPtr)
{
    // if list is empty
    if (isEmpty(currentPtr)) {
        puts("List is empty.\n");
    }
    else {
        puts("The list is:");

        // while not the end of the list
        while (currentPtr != NULL) {
            cout << currentPtr->data << "---> ";
            currentPtr = currentPtr->nextPtr;
        }

        puts("NULL\n");
    }
}

// helper func for getting a vector (little syntatic sugar)
template <typename T>
vector<T> GET_vec(initializer_list<T> l)
{
    vector<T> v;
    for(auto i = l.begin(); i != l.end(); i++)
        v.push_back(*i);
    return v;
}

// C++14 feature
template <typename T>
void TEST_insert(vector<T> list)
{
    ListNodePtr<T> startPtr = nullptr;
    for (auto &i : list)
        insert(&startPtr, i);
    printList(startPtr);
    deleteList(startPtr);
}

int main(void)
{
    TEST_insert(GET_vec({'a', 'b', 'c', 'd'}));
    TEST_insert(GET_vec({"Hello", "There", "I'm roy4801", "My teammate is william31212"}));
    TEST_insert(GET_vec({1, 2, 3, 4}));
    return 0;
}

