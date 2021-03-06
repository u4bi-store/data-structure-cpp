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

    /* 노드를 제거하는 함수인 deleteNode*/
    
    /* deleteNode 함수는 data를 우선 인자로 받고 넘겨받은 인자인 data를 통해
       각 노드의 data와 비교하는데 그둘이 일치하면 그 노드를 리스트에서 제외시킨다고 함
       
       그 후 삭제한 노드가 가지고 있는 다음 주소값을 그 삭제한 노드의 뒤에 놈이 물려받아 이어가는 형태임
       즉 삭제한 놈을 바라보면서 가리키고 있는 노드놈이 가리킬 놈이 없어지잖음
       그러면 안되니까 그 앞앞놈을 가리키는거임. */
    
    void deleteNode(string data){
        Node* tempPoint = Head; /* 임시 포인터에 헤드의 주소값으로 초기화 함 */

        if(tempPoint == NULL) return; /* 한번도 추가한적이 없으면 그냥 리턴*/
        
        if(tempPoint->link ==NULL){ /* 노드가 하나만 존재하면 그 노드만 삭제함*/
            delete tempPoint; /* tempPoint를 메모리 공간에서 해제시킴*/
            Head = NULL; /* 헤드도 빼버림 아무것도 가리키지 않게*/
        }else{ /*노드가 하나만 존재하는게 아니라면 */
            Node *prevNode; /* 이전 노드에 담을 Node 클래스임*/
            /* 두 와일문 돌림*/
            do{/* 조건*/
                /* data와 tempPoint->data와 비교해서 일치하면 루프 빠짐*/
                if(data.compare(tempPoint->data) == 0) break;
                
                /* 일치하지 않으면 아래*/
                prevNode = tempPoint; /* 이전 노드에다 임시포인터 주소값 넘김*/
                tempPoint = tempPoint->link; /* 임시노드에 다음 노드 주소값을 대입함*/
            }while(tempPoint != NULL); /* 그런후 임시포인터의 주소값이 NULL이 될때까지 루프 돌림*/
            /*조건과 일치하면 빠지고*/
            prevNode->link = tempPoint->link; /* 이전노드의 link에 임시포인터의 link를 넘김*/
            /* 암튼 이전 노드가! 즉 지금 삭제되는 노드의 다음을 가리키게 하는거임*/
            delete tempPoint;
            /* 메모리 공간 버려줌*/
        }
    }
    
    /* 노드의 리스트를 출력하는 함수인 printNode */
    void printNode(){
        Node* tempPoint = Head; /* 임시 포인터를 생성함 그리고 여기에 헤드의 주소값을 대입함*/
        
        if(tempPoint == NULL){
            /* 노드가 하나도 존재하지 않으면 리턴*/
            cout << "리스트 비어있음" << endl;
            return;
        }
        
        if(tempPoint -> link == NULL) cout << tempPoint->data << endl; /* 노드가 하나만 존재하면 출력*/
        else{ /* 그게 아니고 하나 이상이면 */
            while(tempPoint != NULL){ /* 임시 포인터가 NULL이 될때까지 루프돌림*/
                cout << tempPoint->data << " "; /* 임시포인트의 데이터를 출력*/
                tempPoint = tempPoint-> link; /* 임시포인터의 link 즉 다음 노드의 주소값을 주입함*/
                /* 주입했으니 루프*/
            }
            /* 널이되어서 와일 빠져나가면 끝*/
            cout << endl; /* 개행해줌*/
        }
    }

};

void List::linkedList(){
    cout << "singly linked List go" << endl;
    SLL sll;
    /* 싱글 링크드 리스트 즉 단순 연결 리스트는*/
    sll.appendNode("dd");
    sll.appendNode("ff");
    sll.appendNode("gg");
    sll.printNode();
  
    sll.deleteNode("gg"); /* 꼬리부터 삭제해야함*/
    sll.deleteNode("ff");
    sll.deleteNode("dd");
    sll.printNode();
    /* 노드를 추가하고 제거하는 순서를 보임 (dd ff gg 추가했으면 노드를 잡아서 삭제해야함 gg부터)
       앞순을 삭제하려면 Segmentation fault 세그폴트 오류가 일어남) */
  
    /* 세그멘테이션 오류 https://ko.wikipedia.org/wiki/세그멘테이션_오류
    */
  
   /* 즉 단순 연결 리스트는 어떠한 위치에 있는 노드를 얻기 위해서 드는 부담도 크고 속도도 느리다는 단점이 있음.
      왜냐? 머리부터 시작해서 꼬리까지 차례차례 노드를 탐색하기 때문임.
      물론 장점도 있긴함. 새로 노드 추가하려면 추가 삭제가 간단함*/
}