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

// 링크드 리스트 생성 함수
LinkedList* Linked_list()
{
  LinkedList* linked_list = (LinkedList*)malloc(sizeof(LinkedList));
  linked_list->Head = NULL;
  return linked_list;
}

// 노드 소멸 함수
Node* Destroy_Node(Node* Node)
{
  free(Node);

  return 0;
}

// 노드 추가 함수(append)
Node* AppendNode(LinkedList* list, Node* NewNode) // 링크드 리스트 헤드 노드의 주소를 넘김. 싱글 포인터로 넘기게 되면 원본 포인터의 복사본 자체(데이터)를 넘기게 되지만, 더블포인터로 넘기면 원본 포인터의 "주소"를 넘김
{
  if (list->Head == NULL)
    list->Head = NewNode;
  else
  {
    Node* current = list->Head; // 현재 노드를 헤드로 초기화
    while (current->NextNode != NULL)
      current = current->NextNode;
    list->Head = current;
  }
  return list->Head;
}

// 노드 탐색 함수
Node* SearchNode(LinkedList* list, int idx)
{
  Node* current = list->Head;
  while (current != NULL && idx-- > 0)
    current = current->NextNode;
  
  return current;
}

// 노드 삭제 함수
Node* DeleteNode(LinkedList* list, Node* delNode)
{
  Node* current = list->Head;
  Node* previous = NULL;

  while (current != NULL && current != delNode)
  {
    previous = current;
    current = current->NextNode;
  }
  
  if (current != NULL)
  {
    if (previous == NULL)
      list->Head = current->NextNode;
    else
      previous->NextNode = current->NextNode;
    free(current);
  }
  return list->Head;
}

// 노드 삽입 함수
Node* InsertNode(LinkedList* list, Node* insNode, int idx)
{
  Node* current = list->Head;
  Node* previous = NULL;

  // 삽입할 위치까지 이동
  while (current != NULL && idx-- > 0)
  {
    previous = current;
    current = current->NextNode;
  }

  // 삽입할 위치에 도달한 경우
  if (previous == NULL) // 삽입할 위치가 헤드인 경우
  {
    insNode->NextNode = list->Head;
    list->Head = insNode;
  }
  else // 삽입할 위치가 헤드가 아닌 경우
  {
    insNode->NextNode = current;
    previous->NextNode = insNode;
  }

  return list->Head; // 수정된 리스트의 헤드를 반환
}



int main()
{
  // Node* myNode = NewNode_auto(300); // 자동메모리로 만들어졌기 때문에 값이 저장된 메모리 주소를 반환받을 수 없게 됐다. 따라서 동적 메모리 할당으로 만들어져야 함을 알게 되었다.
  // Node* myNode = CreateNode_heap(1300);

  // Node* List = NULL;
  // Node* NewNode = NULL;
  // NewNode = CreateNode_heap(117);
  // AppendNode(&List, NewNode);
  // NewNode = CreateNode_heap(300);
  // AppendNode(&List, NewNode);
  // printf("%p", myNode);
  // Destroy_Node(myNode);

  return 0;
}
