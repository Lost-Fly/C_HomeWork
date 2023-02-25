//Node.h
#pragma once

typedef struct Node {
    int num;
    Node* prev;
} Box;

typedef Box* BoxPtr;

BoxPtr Init(int n);
void PushBox(BoxPtr, BoxPtr&);
void PrintStack(BoxPtr);
void  DeleteBox(int idx, BoxPtr&);
