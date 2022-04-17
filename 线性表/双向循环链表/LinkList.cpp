#include <bits/stdc++.h>
#include "LinkList.h"

LinkList::LinkList() {
    head = p = new Node{0};
    head->prior = head->next = head;
    q = nullptr;
    data = 0;
}

void LinkList::print(bool next) {
    q = next ? head : head->prior;
    do {
        printf("%d%s%s\n", q->data, q == head ? " <- head" : "", q == p ? " <- p" : "");
        q = next ? q->next : q->prior;
    } while (q != (next ? head : head->prior));
}

void LinkList::clear() {
    p = head->next;
    while (p != head) {
        p = p->next;
        delete p->prior;
    }
    head->data = 0;
    head->prior = head->next = head;
}

void LinkList::move(int index, bool h) {
    index = index < (data = -head->data - h) ? data : (index > (data = head->data - !h) ? data : index);
    if (index >= 0) {
        p = head->next;
        while (index--)
            p = p->next;
    } else {
        p = head->prior;
        while (++index)
            p = p->prior;
    }
}

void LinkList::move_prior() {
    p = p->prior;
}

void LinkList::move_next() {
    p = p->next;
}

void LinkList::push(int num) {
    p = p->prior = p->prior->next = new Node{num, p->prior, p};
    ++head->data;
}

void LinkList::push(int index, int num) {
    move(index, true);
    if (index < 0)
        p = p->next;
    push(num);
}

void LinkList::push_front(int num) {
    push(0, num);
}

void LinkList::push_back(int num) {
    push(-1, num);
}

int LinkList::pop() {
    if (!head->data)
        return 0;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    data = p->data;
    delete p;
    p = head;
    --head->data;
    return data;
}

int LinkList::pop(int index) {
    move(index);
    return pop();
}

int LinkList::pop_front() {
    return pop(0);
}

int LinkList::pop_back() {
    return pop(-1);
}

void LinkList::alter(int num) {
    p->data = num;
}

void LinkList::alter(int index, int num) {
    move(index);
    alter(num);
}

int LinkList::select(int index) {
    move(index);
    return p->data;
}

int LinkList::select_front() {
    return select(0);
}

int LinkList::select_back() {
    return select(-1);
}
