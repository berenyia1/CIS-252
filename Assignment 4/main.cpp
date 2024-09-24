//
//  main.cpp
//  DoublyLinkedList
//
//  Created by Katz, Ariel on 2/14/23.
//  Students: Amber Nguyen, Antal Berenyi

/// Testing doubly linked list
#include <cassert>
#include <iostream>
#include <cstdlib>
#include "DoublyLinkedList.h"
 
using namespace std;

bool testInsertFirst(){
    cout << "Testing insertFirst" << endl;
    DoublyLinkedList<int> exampleList;
    exampleList.insertFirst(100);
    exampleList.insertFirst(90);
    assert(exampleList.length() == 2);
    assert(exampleList.search(100)); //check for specific node
    exampleList.insertLast(110);
    exampleList.insertLast(120);
    assert(exampleList.length() == 4);
    cout << "Forward Print Expected Output: 90 100 110 120" << endl;
    exampleList.print(true);
    cout << "Reverse Print Expected Output: 120 110 100 90" << endl;
    exampleList.print(false);
    exampleList.destroyList();
    return true;
}

bool testInsertLast(){
    cout << "Testing insertLast" << endl;
    DoublyLinkedList<double> exampleList;
    exampleList.insertLast(2.1);
    exampleList.insertLast(2.2);
    exampleList.insertFirst(2.0);
    assert(exampleList.length() == 3);
    exampleList.insertFirst(1.9);
    cout << "Forward Print Expected Output: 1.9 2 2.1 2.2" << endl;
    exampleList.print(true);
    cout << "Reverse Print Expected Output: 2.2 2.1 2 1.9" << endl;
    exampleList.print(false);
    exampleList.destroyList();
    return true;
}

bool testInsertNode(){
    cout << "Testing insertNode" << endl;
    DoublyLinkedList<int> exampleList;
    exampleList.insertNode(320, 0);
    assert(exampleList.length() == 1);
    exampleList.insertNode(310, 0);
    assert(exampleList.length() == 2);
    exampleList.insertNode(330, 2);
    exampleList.insertLast(340);
    exampleList.insertNode(315, 1);
    
    assert(exampleList.search(315)); //check for specific node
    
    exampleList.insertNode(335, 4);
    cout << "Forward Print Expected Output: 310 315 320 330 335 340" << endl;
    exampleList.print(true);
    cout << "Reverse Print Expected Output: 340 335 330 320 315 310" << endl;
    exampleList.print(false);
    exampleList.destroyList();
    return true;
}

bool testDeleteNode(){
    cout << "Testing deleteNode" << endl;
    DoublyLinkedList<int> exampleList;
    exampleList.insertFirst(310);
    exampleList.insertLast(315);
    exampleList.insertLast(320);
    exampleList.insertLast(330);
    exampleList.insertLast(335);
    exampleList.insertLast(340);
    cout << "Starting List: 310 315 320 330 335 340" << endl;
    exampleList.print(true);
    
    
    //test delete from middle
    exampleList.deleteNode(315);
    assert(!exampleList.search(315));
    assert(exampleList.length() == 5);
    exampleList.deleteNode(335);
    cout << "Forward Print Expected Output: 310 320 330 340" << endl;
    exampleList.print(true);
    cout << "Reverse Print Expected Output: 340 330 320 310" << endl;
    exampleList.print(false);
    // test Deleting first and last from list
    exampleList.deleteNode(340);
    assert(!exampleList.search(340));
    assert(exampleList.length() == 3);
    exampleList.deleteNode(310);
    assert(!exampleList.search(310));
    assert(exampleList.length() == 2);
    cout << "Forward Print Expected Output: 320 330" << endl;
    exampleList.print(true);
    cout << "Reverse Print Expected Output: 330 320" << endl;
    exampleList.print(false);
    
    exampleList.destroyList();
    return true;
}

bool testDeleteNodeAtIndex(){
    cout << "Testing deleteNodeAtIndex" << endl;
     DoublyLinkedList<double> exampleList;
    exampleList.insertFirst(4.5);
    exampleList.insertFirst(4.4);
    exampleList.insertFirst(4.3);
    exampleList.insertFirst(4.2);
    exampleList.insertFirst(4.1);
    cout << "Starting List: 4.1 4.2 4.3 4.4 4.5" << endl;
    exampleList.print(true);
    
    exampleList.deleteNodeAtIndex(3);
    exampleList.deleteNodeAtIndex(1);
    exampleList.deleteNodeAtIndex(0);
    cout << "Forward print -- Expected Output: 4.3 4.5" << endl;
    exampleList.print(true);
    cout << "Forward print -- Expected Output: 4.5 4.3" << endl;
    exampleList.print(false);
    cout << "--- Testing error cases --- " << endl;
    exampleList.deleteNodeAtIndex(6);
    exampleList.deleteNodeAtIndex(-1);
    
    exampleList.destroyList();
    return true;
}

bool testErrorMessages(){
    cout << "Testing Error Messages" << endl;
    DoublyLinkedList<int> exampleList;
    exampleList.insertFirst(310);
    exampleList.insertLast(315);
    exampleList.insertLast(320);
    exampleList.insertLast(330);
    exampleList.insertLast(335);
    exampleList.insertLast(340);
    cout << "Starting List: 310 315 320 330 335 340" << endl;
    exampleList.print(true);
    
    cout << "TEST --- Insert node test with index too big" << endl;
    exampleList.insertNode(370, 7);
    cout << "TEST --- Insert node test with index too small" << endl;
    exampleList.insertNode(300, -1);
    cout << "TEST --- Delete node that isn't in list" << endl;
    exampleList.deleteNode(500);
    exampleList.destroyList();
    
    cout << "TEST --- Delete node from empty list" << endl;
    exampleList.deleteNode(500);
    return true;
}

bool testTypeSupport(){
    cout << "Testing Template Type Support" << endl;
    DoublyLinkedList<string> stringList;
    stringList.insertFirst("one");
    stringList.insertLast("three");
    stringList.insertNode("two", 1);
    cout << "Forward Print Expected Output: one two three" << endl;
    stringList.print(true);
    cout << "Reverse Print Expected Output: three two one" << endl;
    stringList.print(false);
    stringList.destroyList();
    return true;
}
int main()
{
    DoublyLinkedList<int> exampleList;
    
    //cout << "--- Beginning Tests of insert functions --- " << endl;
    if(testInsertFirst()){
        cout << "insertFirst tests finished";
        cout << "\n\n";
    }
    
    if(testInsertLast()){
        cout << "insertLast tests finished";
        cout << "\n\n";
    }
    
    if(testInsertNode()){
        cout << "insertNode tests finished";
        cout << "\n\n";
    }
    
    if(testDeleteNode()){
        cout << "deleteNode tests finished";
        cout << "\n\n";
    }
    
    ///// Test delete node by index for pairs
    
     if(testDeleteNodeAtIndex()) {
         cout << "deleteNodeAtIndex tests finished";
         cout << "\n\n";
     }
     
    
    testErrorMessages();
    
    testTypeSupport();
    
    cout << "All tests executed\n";
    
    return 0;
}








