#include <iostream>

class SinglyLinkedList {
private:
    struct Node {
        int data;
        Node *next;
    } *head, *tail, *p, *q;

public:
    SinglyLinkedList() {
        head = tail = new Node{0, p = q = nullptr};
    }

    void print() {
        p = head;
        while (p != nullptr) {
            printf("%d\n", p->data);
            p = p->next;
        }
    }

    void clear() {
        head->data = 0;
        tail = head;
        p = head->next;
        while (p != nullptr) {
            head->next = p->next;
            delete p;
            p = head->next;
        }
    }

    // 头插法，有头结点，时间复杂度O(1)
    void headInsert(int data) {
        head->next = new Node{data, head->next};
        if (tail == head)
            tail = head->next;
        ++head->data;
    }

    // 头插法，无头结点，时间复杂度O(1)，演示代码，没事别调用
    void headInsert2(int data) {
        head = new Node{data, head};
    }

    // 尾插法，有尾指针，时间复杂度O(1)
    void tailInsert(int data) {
        tail = tail->next = new Node{data, nullptr};
        ++head->data;
    }

    // 尾插法，无尾指针，时间复杂度O(n)
    void tailInsert2(int data) {
        p = head;
        while (p->next != nullptr)
            p = p->next;
        tail = p->next = new Node{data, nullptr};
        ++head->data;
    }

    // 插入结点，时间复杂度O(n)
    void push(int i, int data) {
        if (i < 0 || i > head->data)
            return;
        p = head;
        while (i--)
            p = p->next;
        p->next = new Node{data, p->next};
        if (tail == head)
            tail = head->next;
        ++head->data;
    }

    // 删除结点，时间复杂度O(n)
    void pop(int i) {
        if (i < 0 || i >= head->data)
            return;
        p = head;
        while (i--)
            p = p->next;
        q = p->next;
        p->next = q->next;
        if (q == tail)
            tail = p;
        delete q;
        --head->data;
    }

    // 按索引查找值，时间复杂度O(n)
    int get(int i) {
        if (i < 0 || i >= head->data)
            return -1;
        p = head->next;
        while (i--)
            p = p->next;
        return p->data;
    }

    // 按值查找索引，时间复杂度O(n)
    int index(int data) {
        int i = 0;
        p = head->next;
        while (p != nullptr && p->data != data) {
            p = p->next;
            ++i;
        }
        return i == head->data ? -1 : i;
    }
};