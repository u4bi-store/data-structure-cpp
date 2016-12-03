#include <iostream>
#include <cstring>
#include "list.h"
using namespace std;

/* 링크드 리스트(Linked List)
   
   이 링크드 리스트는 노드(Node)라는 요소로 구성되어 있음.
   즉 노드를 연결하여 만들어지는 리스트라고 보면 된다고 함. 이 노드는 데이터와 포인터를 가짐
   
   여기서 말하는 데이터는 말 그대로 데이터임 포인터는 말 그대로 노드를 가리키는 포인터임
   말그대로 연결 리스트임
*/

/* 쉽게 설명하면 내가 내앞에 있는 놈 집 주소를 알아서 찾아갈 수 있음. */

/* 예로 12 99 37 수가 있음.

   3개의 노드라 부를 수 있음.
   각각 노드에는 데이터와 다음 노드를 가리키는 포인터가 들어있음.

*/

class Node{
public:
  string data; /* 데이터임*/
  Node* link; /* 다음 노드를 가리키는 포인터임*/
};

void List::linkedList(){
  
}