#include <bits/stdc++.h>
#include "LinkList.h"

using namespace std;

LinkList linkList;
char c;
int i, d;

void start() {
    if (c == '\n')
        printf(">");
    else if (c == 'p') {
        scanf("%c", &c);
        linkList.print(c != 'p');
        if (c != 'p')
            start();
    } else if (c == 'c')
        linkList.clear();
    else if (c == 'm') {
        scanf("%c", &c);
        if (c == 'p')
            linkList.move_prior();
        else if (c == 'n')
            linkList.move_next();
        else if (c == 'm' && scanf("%d", &i))
            linkList.move(i);
    } else if (c == 'i')
        while (scanf("%c", &c) != EOF) {
            if (c == '\n')
                printf("insert>");
            else if (c == 'q')
                break;
            else if (c == 'f' && scanf("%d", &d))
                linkList.push_front(d);
            else if (c == 'b' && scanf("%d", &d))
                linkList.push_back(d);
            else if (c == 'i' && scanf("%d", &i) && scanf("%d", &d))
                linkList.push(i, d);
        }
    else if (c == 'd')
        while (scanf("%c", &c) != EOF) {
            if (c == '\n')
                printf("delete>");
            else if (c == 'q')
                break;
            else if (c == 'f')
                printf("-%d\n", linkList.pop_front());
            else if (c == 'b')
                printf("-%d\n", linkList.pop_back());
            else if (c == 'd' && scanf("%d", &i))
                printf("-%d\n", linkList.pop(i));
        }
    else if (c == 'a') {
        if (scanf("%d", &d))
            linkList.alter(d);
        else {
            scanf("%c", &c);
            if (c == 'a') {
                if (scanf("%d", &i) && scanf("%d", &d))
                    linkList.alter(i, d);
            } else
                start();
        }
    } else if (c == 's') {
        scanf("%c", &c);
        if (c == 'f')
            printf("%d\n", linkList.select_front());
        else if (c == 'b')
            printf("%d\n", linkList.select_back());
        else if (c == 's') {
            if (scanf("%d", &i))
                printf("%d\n", linkList.select(i));
        } else
            start();
    }
}

int main() {
    printf(">");
    while (scanf("%c", &c) != EOF)
        start();
    return 0;
}