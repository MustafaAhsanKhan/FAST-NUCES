#include "pch.h"
#include "Header.h"


//***************** Q1 Test cases ********************
TEST(DoublyLinkedListTest, EmptyList) {
    DoublyLinkedList dll;
    EXPECT_TRUE(dll.isEmpty());
}

TEST(DoublyLinkedListTest, InsertToHead) {
    DoublyLinkedList dll;
    dll.insertToHead(10);
    dll.insertToHead(20);
    dll.print();
    int expected[] = { 20, 10 };
    int result[2] = { 0 };

    int i = 0;
    DoublyNode* current = dll.getHead();
    while (current) {
        result[i++] = current->getData();
        current = current->getNext();
    }

    EXPECT_EQ(0, memcmp(expected, result, sizeof(expected)));
}

TEST(DoublyLinkedListTest, InsertToEnd) {
    DoublyLinkedList dll;
    dll.insert(10);
    dll.insert(20);
    dll.print();
    int expected[] = { 10, 20 };
    int result[2] = { 0 };

    int i = 0;
    DoublyNode* current = dll.getHead();
    while (current) {
        result[i++] = current->getData();
        current = current->getNext();
    }

    EXPECT_EQ(0, memcmp(expected, result, sizeof(expected)));
}

TEST(DoublyLinkedListTest, Search) {
    DoublyLinkedList dll;
    dll.insert(10);
    dll.insert(20);
    dll.insert(30);

    dll.print();
    EXPECT_TRUE(dll.search(20));
    EXPECT_FALSE(dll.search(40));
}

TEST(DoublyLinkedListTest, Update) {
    DoublyLinkedList dll;
    dll.insert(10);
    dll.insert(20);
    dll.insert(30);

    dll.update(20, 25);
    dll.print();

    EXPECT_TRUE(dll.search(25));
    EXPECT_FALSE(dll.search(20));
}

TEST(DoublyLinkedListTest, InsertAtIndex) {
    DoublyLinkedList dll;
    dll.insert(10);
    dll.insert(20);
    dll.insert(40);

    dll.insertAtIndex(30, 2);

    dll.print();

    int expected[] = { 10, 20, 30, 40 };
    int result[4] = { 0 };

    int i = 0;
    DoublyNode* current = dll.getHead();
    while (current) {
        result[i++] = current->getData();
        current = current->getNext();
    }

    EXPECT_EQ(0, memcmp(expected, result, sizeof(expected)));
}

TEST(DoublyLinkedListTest, Delete) {
    DoublyLinkedList dll;
    dll.insert(10);
    dll.insert(20);
    dll.insert(30);

    dll.deleteData(20);

    dll.print();

    int expected[] = { 10, 30 };
    int result[2] = { 0 };

    int i = 0;
    DoublyNode* current = dll.getHead();
    while (current) {
        result[i++] = current->getData();
        current = current->getNext();
    }

    EXPECT_EQ(0, memcmp(expected, result, sizeof(expected)));
}



//****************** Q2 Test cases *******************
TEST(CircularLinkedListTest, FindWinner) {
    CircularLinkedList cll;

    cll.insert(1);
    cll.insert(8);
    cll.insert(7);
    cll.insert(2);
    cll.insert(5);
    cll.print();
    
    int winnerSkill = cll.findWinner(3);

    EXPECT_EQ(winnerSkill, 1);
}


TEST(CircularLinkedListTest, FindWinner2) {
   
    CircularLinkedList cll;

    cll.insert(1);
    cll.insert(2);
    cll.insert(3);
    cll.insert(4);
    cll.insert(5);
    cll.print();
   
    int winnerSkill = cll.findWinner(1);

    EXPECT_EQ(winnerSkill, 3);
}
