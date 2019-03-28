#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

template <typename T>
struct listNode {
    T data;
    struct listNode *nextPtr;
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

// return 1 if the list is empty, 0 otherwise
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

void menu()
{
    cout << "------- Welcome to use list -------" << '\n';
    cout << "Press '1' insert" << '\n';
    cout << "Press '2' delete" << '\n';
    cout << "Press '3' check_empty" << '\n';
    cout << "Press '4' print_list" << '\n';
    cout << "Press '5' std::find" << '\n' ;
    cout << "Press '6' exit " << '\n';
}

template <typename T>
void setting_Type()
{
    ListIter<T> startPtr;
    ListIter<T> i(startPtr);
    ListIter<T> end(NULL);
    ListIter<T> iter = std::find(i, end, data);
    if (typeid(T) == typeid(int))
    {
        if ()
        {
            /* code */
        }
    }
    if (typeid(T) == typeid(char))
    {
        if ()
        {
            /* code */
        }
    }
    if (typeid(T) == typeid(double))
    {
        if ()
        {
            /* code */
        }
    }
}



int main(void)
{

    bool flag = 0;
    int data;


    while(1)
    {
        if(flag)
            break;


        menu();
        // setting_Type();
        listNodePtr<int> start = NULL;
        // char button;


        // cin >> button;



        insert(&startPtr,1);
        insert(&startPtr,2);
        insert(&startPtr,3);
        del(&startPtr,1);

        ListIter<int> i(startPtr);
        ListIter<int> end(NULL);
        ListIter<int> iter = std::find(i, end, data);

        if (iter == NULL)
            printf("NOT FOUND\n");
        else
            printf("FIND\n");
        }



}

