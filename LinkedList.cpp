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
   
   첫번째 노드를 헤드(Head,머리)라고하고 맨 끝번째 노드를 테일(Tail, 꼬리)이라고 부른다고 함.
*/

class Node{
public:
    string data; /* 데이터임*/
    Node* link; /* 다음 노드를 가리키는 포인터임*/
};

/* Singly Linked List: SLL*/
class SLL{
public:
    Node* Head; /* SLL에는 헤드만 필드에 둠*/
    
    /* 생성자에*/
    SLL(){
        Head = NULL; /* 헤드를 NULL로 초기화*/
    }

    /* 노드를 추가하는 함수인 appendNode */
    /* appendNode 함수는 SLL 클래스 선언 영역에 집어 넣음.*/
    void appendNode(string data){
        Node* newNode = new Node(); /* 새 노드 생성*/

        newNode->data = data; /* 인자의 데이터를 주입하여 초기화*/
        newNode->link = NULL; /* NULL로 초기화*/

        Node* tempPoint = Head; /* 임시 포인터 이 포인터에 Head의 주소값을 주입하여 초기화*/

        if(tempPoint != NULL){ /* 임시포인터가 널이 아니라면 (즉 노드를 처음 추가하는게 아니면)*/

            /* 끝번째인 즉 꼬리 노드를 구하기 위해 임시포인터의 link가 null일때까지 루프*/
            while(tempPoint->link != NULL) tempPoint = tempPoint->link;

            /* 끝번째라서 루프를 빠져나가면 즉 마지막 노드가 새로 추가된 노드를 가리킴*/
            tempPoint->link = newNode;

        }else Head = newNode; /* 임시포인터가 널이면 (즉 노드를 처음 추가하는거라면) 주입된 노드를 머리로 지정함.*/
    }

};

void List::linkedList(){
    SLL sll;
    
    sll.appendNode("dd");
    sll.appendNode("ff");
  
}