//
//  DoublyLinkedList.h
//
//  Blank version of file for assignment
//
//  Created by Katz, Ariel on 2/14/23.
//

#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

#include "ListType.h"

using namespace std;

template <class Type>
class DoublyLinkedList: public ListType<Type> {
public:
    
    void print(bool forward) const ;
      //Function to output the data contained in each node.
      //If argument is true list prints forward
    // If forward is false list prints in reverse
    
    bool search(const Type& searchItem) const;
      //Function to determine whether searchItem is in the list.
      // Returns true if searchItem is in the

    void insertFirst(const Type& newItem);
      //Function to insert newItem at the beginning of the list.
      //newItem becomes head and count is incremented by 1.

    void insertLast(const Type& newItem);
      //Function to insert newItem at the end of the list.
      //newItem becomes tail and count is incremented by 1.
    
    void insertNode(const Type& newItem, int index);
      //Function to insert newItem at the given index.
    // If index is out of range print error
      //newItem becomes element at index and all other elements are shifted.
    // count is incremented by one.

    void deleteNode(const Type& deleteItem);
      //Function to delete deleteItem from the list.
      //Postcondition: If found, the node containing
      //               deleteItem is deleted from the list
      //               and count is decremented by 1.
    
};

template <class Type>
void DoublyLinkedList<Type>::print(bool forward) const
{
    NodeType<Type> *current; //pointer to traverse the list
    if (forward){
        current = this->head;    //start traversal from the head node
        while (current != NULL) //while more data to print
        {
            cout << current->data << " ";
            current = current->next;
        }
    } else {
        current = this->tail;    //start traversal from the tail node
        while (current != NULL) //while more data to print
        {
            cout << current->data << " ";
            current = current->prev;
        }
    }
    
}

template <class Type>
bool DoublyLinkedList<Type>::
                   search(const Type& searchItem) const
{
    NodeType<Type> *current; //pointer to traverse the list
    current = this->head; //start search at the beginning

    //as long as there is more to search
    //and the node hasn't been found - keep searching
    while (current != NULL )
        if (current->data == searchItem)
            return true;
        else{
            current = current->next; //step forward
        }
            
    return NULL;
}//end search

template <class Type>
void DoublyLinkedList<Type>::insertFirst(const Type& newItem){
    
    //TODO: COMPLETE THIS FUNCTION!
}

template <class Type>
void DoublyLinkedList<Type>::insertLast(const Type& newItem){
    //TODO: COMPLETE THIS FUNCTION!

}

template <class Type>
void DoublyLinkedList<Type>::insertNode(const Type& newItem, int index){
    //TODO: COMPLETE THIS FUNCTION!

}

template <class Type>
void DoublyLinkedList<Type>::deleteNode(const Type& deleteItem){
    //TODO: COMPLETE THIS FUNCTION!

}

#endif /* DoublyLinkedList_h */
