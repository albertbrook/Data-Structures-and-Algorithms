#ifndef LINKLIST_H
#define LINKLIST_H


class LinkList {
private:
    struct Node {
        int data;
        Node *prior;
        Node *next;
    } *head, *p, *q;

    int data;

public:
    LinkList();
    void print(bool next);
    void clear();

    void move(int index, bool h = false);
    void move_prior();
    void move_next();

    void push(int num);
    void push(int index, int num);
    void push_front(int num);
    void push_back(int num);

    int pop();
    int pop(int index);
    int pop_front();
    int pop_back();

    void alter(int num);
    void alter(int index, int num);

    int select(int index);
    int select_front();
    int select_back();
};


#endif
