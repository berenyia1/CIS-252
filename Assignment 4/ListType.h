//
//  ListType.h
//
//  Created by Ariel Katz on 2/7/23.
//

#ifndef ListType_h
#define ListType_h

template <class Type>
struct NodeType {
    Type data;
    NodeType<Type> *next;
    NodeType<Type> *prev;
};

template <class Type>
class ListType {
public:
    const ListType<Type>& operator=
                         (const ListType<Type>&);
      //Overload the assignment operator.
    
    bool  operator==(const ListType<Type>&) const;
    //Overload the equality operator.
    //Precondition: The Type must have valid == operator
    //Postcondition: Returns true if they have the same data
    // in the same order. Two empty lists will always be equal.

    void initializeList();
      //Initialize the list to an empty state.
      //Postcondition: head = NULL, tail = NULL, count = 0;

    bool isEmptyList() const;
      //Function to determine whether the list is empty.
      //Postcondition: Returns true if the list is empty,
      //               otherwise it returns false.

    void print() const;
      //Function to output the data contained in each node.
      //Postcondition: none
    
    virtual void print(bool) const = 0 ;
      //Function to output the data contained in each node.
      //Enable reverse print for testing of doubly linked list

    int length() const;
      //Function to return the number of nodes in the list.
      //Postcondition: The value of count is returned.

    void destroyList();
      //Function to delete all the nodes from the list.

    Type front() const;
      //Function to return the head element of the list.
      //Precondition: The list must exist and must not be
      //              empty.
      //Postcondition: If the list is empty, the program
      //               terminates; otherwise, the head
      //               element of the list is returned.

    Type back() const;
      //Function to return the tail element of the list.
      //Precondition: The list must exist and must not be
      //              empty.
      //Postcondition: If the list is empty, the program
      //               terminates; otherwise, the tail
      //               element of the list is returned.

    virtual bool search(const Type& searchItem) const = 0;
      //Function to determine whether searchItem is in the list.
      // Returns true if searchItem is in the

    virtual void insertFirst(const Type& newItem) = 0;
      //Function to insert newItem at the beginning of the list.
      //newItem becomes head and count is incremented by 1.

    virtual void insertLast(const Type& newItem) = 0;
      //Function to insert newItem at the end of the list.
      //newItem becomes tail and count is incremented by 1.
    
    virtual void insertNode(const Type& newItem, int index) = 0;
      //Function to insert newItem at index.
      

    virtual void deleteNode(const Type& deleteItem) = 0;
      //Function to delete deleteItem from the list.
      //Postcondition: If found, the node containing
      //               deleteItem is deleted from the list
      //               and count is decremented by 1.

    //TODO: Add list iterator
    // linkedListIterator<Type> begin();
      //Function to return an iterator at the begining of the
      //linked list.

    ListType();
      //default constructor
      //Initializes the list to an empty state.
      //head and tail = NULL, count = 0;

    ListType(const ListType<Type>& otherList);
      //copy constructor

    ~ListType();
      //destructor - Deletes all the nodes from the list.

protected:
    int count;   //variable to store the number of
                 //elements in the list
    NodeType<Type> *head; //pointer to the head node of the list
    NodeType<Type> *tail;  //pointer to the tail node of the list

private:
    void copyList(const ListType<Type>& otherList);
      //Function to make a copy of otherList.
      //Internal helper method for copy constructor and
      //Assignment operator override
};


template <class Type>
bool ListType<Type>::isEmptyList() const
{
    return(head == NULL);
}

template <class Type>
ListType<Type>::ListType() //default constructor
{
    head = NULL;
    tail = NULL;
    count = 0;
}

template <class Type>
void ListType<Type>::destroyList()
{
    NodeType<Type> *temp;   //pointer to deallocate the memory
                            //occupied by the node
    while (head != NULL)   //while there are nodes in the list
    {
        temp = head;        //set temp to the current node
        head = head->next; //advance head to the next node
        //temp->next = NULL;
        delete temp;   //deallocate the memory occupied by temp
    }
    tail = NULL; //initialize tail to NULL; head has already
                 //been set to NULL by the while loop
    count = 0;
}

template <class Type>
void ListType<Type>::initializeList()
{
    destroyList();
}

template <class Type>
void ListType<Type>::print() const
{
    NodeType<Type> *current; //pointer to traverse the list

    current = head;    //start traversal from the head node
    while (current != NULL) //while more data to print
    {
        std::cout << current->data << " ";
        current = current->next;
    }
}

template <class Type>
int ListType<Type>::length() const
{
    return count; //return the data of the head node
}

template <class Type>
Type ListType<Type>::front() const
{
    assert(head != NULL);//confirm head exists

    return head->data; //return the data of the head node
}

template <class Type>
Type ListType<Type>::back() const
{
    assert(tail != NULL); //confirm tail exists

    return tail->data; //return the data of the tail node
}


template <class Type>
void ListType<Type>::copyList
                   (const ListType<Type>& otherList)
{
    NodeType<Type> *newNode; //pointer to create a node
    NodeType<Type> *current; //pointer to traverse the list

    if (head != NULL) //if the list is nonempty, make it empty
       destroyList();

    if (otherList.head == NULL) //otherList is empty
    {
        head = NULL;
        tail = NULL;
        count = 0;
    }
    else
    {
        current = otherList.head; //current points to the
                                   //list to be copied
        count = otherList.count;

            //copy the head node
        head = new NodeType<Type>;  //create the node

        head->data = current->data; //copy the data
        head->next = NULL;        //set the link field of
                                   //the node to NULL
        tail = head;              //make tail point to the
                                   //head node
        current = current->next;     //make current point to
                                     //the next node

           //copy the remaining list
        while (current != NULL)
        {
            newNode = new NodeType<Type>;  //create a node
            newNode->data = current->data; //copy the data
            newNode->next = NULL;       //set the link of
                                        //newNode to NULL
            tail->next = newNode;  //attach newNode after tail
            tail = newNode;        //make tail point to
                                   //the actual tail node
            current = current->next;   //make current point
                                       //to the next node
        }//end while
    }//end else
}//end copyList

template <class Type>
ListType<Type>::~ListType() //destructor
{
   destroyList();
}

//copy constructor
template <class Type>
ListType<Type>::ListType
                      (const ListType<Type>& otherList)
{
    head = NULL;
    copyList(otherList);
}

//overload the assignment operator
template <class Type>
const ListType<Type>& ListType<Type>::operator=
                      (const ListType<Type>& otherList)
{
    if (this != &otherList) //avoid self-copy
    {
        copyList(otherList);
    }//end else

     return *this;
}

//overload the equality operator
template <class Type>
bool ListType<Type>::operator==
                      (const ListType<Type>& otherList) const
{
    if (this->count != otherList.count) return false;
    if (isEmptyList() && otherList.isEmptyList()) return false;
    
    NodeType<Type> *currPtr, *otherPtr;
    currPtr = head;
    otherPtr = otherList.head;
    while(currPtr != NULL && otherPtr != NULL){
        // precondition is that == must work for Type
        if( !(currPtr->data == otherPtr->data))
            return false;
        
        currPtr = currPtr->next;
        otherPtr = otherPtr->next;
    }
    
    return true;
}

#endif /* ListType_h */
