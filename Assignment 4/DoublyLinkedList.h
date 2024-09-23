//
//  DoublyLinkedList.h
//
//  Students: Amber Nguyen, Antal Berenyi
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

    Type& deleteNodeAtIndex(const int index);
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

/**
 * @brief Insert into first position in list. Make sure to handle inserting into both 
 * empty and non-empty list. When insertign a new node, re-point the head pointer to
 * the new node. The tail will be pointed to the new node if this this was an empty list.
 * @tparam Type data type.
 * @param newItem new data.
 */
template <class Type>
void DoublyLinkedList<Type>::insertFirst(const Type& newItem) {
//TODO: COMPLETE THIS FUNCTION! DONE
    
    // create a new node and initialize data, and next and prev to NULL
    NodeType<Type>* newNode = new NodeType<Type>;
    newNode->data = newItem;
    newNode->next = NULL;
    newNode->prev = NULL;


    // if no nodes exist yet, set the head and tail to the new node.
    if (this->isEmptyList()) {

        this->tail = newNode;

    } else {

        // if nodes exist, make the old head point back to new node
        NodeType<Type>* oldHead = this->head;
        oldHead->prev = newNode;

        // newNode will be the new head, so its next is the current head
        newNode->next = oldHead;

    }

    // re-point head to newNode, common to both cases
    this->head = newNode;

    // increment count
    this->count += 1;

    return;

}

template <class Type>
void DoublyLinkedList<Type>::insertLast(const Type& newItem){
    //TODO: COMPLETE THIS FUNCTION!
    NodeType<Type>* newNode = new NodeType<Type>;
    newNode->data = newItem;

    newNode->next = NULL;
    newNode->prev = NULL;

    if (this->isEmptyList()){

        this->tail = newNode; // if list is empty, set the head and tail to the new node
        this->head = newNode;
    }
    else{ 
        NodeType<Type>* oldTail = this->tail;
        oldTail->next = newNode; // the old tail will point to the next node if there is an existing list
        newNode->prev = oldTail; // the previous node will point to the old tail
        this->tail = newNode; // the tail will update into the new node
    }

    this->count += 1;

    return;
}

template <class Type>
void DoublyLinkedList<Type>::insertNode(const Type& newItem, int index){
    //TODO: COMPLETE THIS FUNCTION!
    NodeType<Type>* newNode = new NodeType<Type>;
    newNode->data = newItem;

    newNode->next = NULL;
    newNode->prev = NULL;

    if (index <= 0){ // if the index is 0 or less it will insert the node in the beginning
        insertFirst(newItem);
        return;
    }
    else if (index >= this->count){ // if the index is the more or the same as the count, it will insert the node at the end
        insertLast(newItem);
        return;
    }
    else{
        NodeType<Type>* current = this->head;
        
        for (int i = 0; i < index - 1 ; i++){
        current = current->next; // traverses the list to point the node at the certain index
        }

        newNode->next = current->next; 
        newNode->prev = current; // the previous node is pointed to the node before the next current node
        current->next->prev = newNode; // the node after the newNode will point its previous to the new node
        current->next = newNode; // current pointer will now point to the new node
}
    this->count+=1;
    return;
}

template <class Type>
void DoublyLinkedList<Type>::deleteNode(const Type& deleteItem){
    //TODO: COMPLETE THIS FUNCTION!
    if (this-> isEmptyList()){
        cout << "List is Empty";
    }

    NodeType<Type>* current = this->head;
    
    while (current != NULL && current->data != deleteItem){
        current = current->next; // traverses the list
    }

    if (current == NULL){
        cout << "Item to delete not found in list";
    }

   // if the head is the item we want to delete:
    if (current == this->head){ 
        this->head = current->next; // moves the head to the next node
        this->head->prev = NULL; // if the new head is a node then it makes the old head into NULL

    // if the tail is the item we want to delete:
    } else if (current == this->tail){
        this->tail = current->prev; // moves the tail to the prev node
        this->tail->next = NULL; // if the new tail is a node then it makes the old tail into NULL

    } else{
        (current->prev)->next = current->next;
        (current->next)->prev = current->prev;
    }

    this->count -= 1;
    return;
}

template <class Type>
Type& DoublyLinkedList<Type>::deleteNodeAtIndex(const int index){
    //TODO: COMPLETE THIS FUNCTION!
    Type deletedNode;
    NodeType<Type>* current = this->head;
    
    if (this-> isEmptyList()){
        cout << "Error: List is Empty\n";
        return deletedNode;
    }

    if (index < 0 || index > (this->count - 1)){
        cout << "Error: Index out of bounds\n";
        return deletedNode;

    } else if (index == 0){ // if the index is 0 at the beginning
        deletedNode = current->data; // will keep the data of the node we want to delete
        this->head = current->next; // moves the head to the next node
        this->head->prev = NULL;

    } else if (index == this->count - 1){
        current = this->tail;
        deletedNode = current->data;
        this->tail = current->prev; // moves the tail to the prev node
        this->tail->next = NULL;

    } else {
        for (int i = 0; i < index; i++){
            current = current->next; // points to the index we want to remove
    }
        deletedNode = current->data;
        (current->prev)->next = current->next;
        (current->next)->prev = current->prev;

    }

    this->count -= 1;
    return deletedNode;
}

#endif /* DoublyLinkedList_h */
