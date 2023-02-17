#pragma once
//Node.h
//#ifndef Node_H

//#define Node_H
typedef struct Node {
    int num;
    Node* prev;
} Box;

typedef Box* BoxPtr;

BoxPtr Init(int n);
void PushBox(BoxPtr, BoxPtr&);
void PrintStack(BoxPtr);
BoxPtr  DeleteBox(int idx, BoxPtr);
//#endif