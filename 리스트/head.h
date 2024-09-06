#ifndef HEAD_H
#define HEAD_H

typedef struct Node{
  int data; // 정수형 데이터가 담길 공간
  struct Node* NextNode; // 다음 노드. 자기 자신을 가리킴
} Node;

#endif