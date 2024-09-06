#include <stdio.h>
#include "head.h"
#include <stdlib.h>

// 노드 생성 함수

// 자동 메모리(스택)
// Node* CreateNode_stack(int data)
// {
//   Node NewNode; // 1. 스택 영역에 자기 자신을 선언함으로써 함수 안에서 사용될 수 있는 새로운 노드 선언
//   NewNode.data = data; // 2. 위에서 선언된 노드가 있으니 Node 구조체의 data 영역에 값 삽입
//   NewNode.NextNode = NULL; // 3. 꼬리부분은 비워놓기

//   return &NewNode; // 주소가 반환되므로 주소가 담길 공간을 포인터로 선언하여 만들어줌.
// }

// 자유 저장소(힙)
Node* CreateNode_heap(int data)
{
  Node* NewNode = (Node*)malloc(sizeof(Node));
  NewNode->data = data;
  NewNode->NextNode = NULL;

  return NewNode;
}

// 노드 소멸 함수
Node* Destroy_Node(Node* Node)
{
  free(Node);
  return 0;
}

// 노드 추가 연산(append)
Node* AppendNode(Node** Head, Node* NewNode) // Node 구조체
{
  
}

int main()
{
  // Node* myNode = NewNode_auto(300); // 자동메모리로 만들어졌기 때문에 값이 저장된 메모리 주소를 반환받을 수 없게 됐다. 따라서 동적 메모리 할당으로 만들어져야 함을 알게 되었다.
  Node* myNode = CreateNode_heap(1300);
  printf("%p", myNode);
  Destroy_Node(myNode);
  return 0;
}