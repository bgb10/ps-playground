#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* link; // node 구조체의 정의가 끝나지 않았으므로 이렇게 명시해야 한다.
};

struct HeadNode {
    Node* head;
};

class SingleList {
    public: 

    HeadNode* createList() {
        HeadNode* H = new HeadNode;
        H->head = NULL;
        return H;
    }

    // 리스트의 맨 뒤에 노드 추가(조회 O(N) -> 추가 O(1))
    void addNode(HeadNode* H, int x) {
        Node* NewNode = new Node; // 새로 만들 노드
        Node* LastNode; // 원래 있던 노드의 마지막 노드

        NewNode->data = x;
        NewNode->link = NULL;

        if(H->head == NULL) {
            H->head = NewNode;
            return;
        }

        LastNode = H->head;
        while(LastNode->link != NULL) {
            LastNode = LastNode -> link;
        }

        LastNode->link = NewNode;
    }

    // 리스트의 맨 뒤에 노드 삭제(조회 O(N) -> 삭제 O(1))
    void deleteNode(HeadNode* H) {
        Node* prevNode;
        Node* delNode;

        if(H->head == NULL) return; // 리스트가 빈 경우
        if(H->head->link == NULL) { // 한 개의 노드만 가진 경우
            delete H->head;

            H->head = NULL;

            return;
        }
        prevNode = H->head;
        delNode = H->head->link;

        while(delNode->link != NULL) {
            prevNode = delNode;
            delNode = delNode->link;
        }

        free(delNode);
        prevNode->link = NULL;
    }

    // 리스트의 특정 노드 삭제(조회 O(k) -> 삭제 O(1))
    void deleteThisNode(HeadNode* H, int where) {
        Node* delNode;
        Node* prevNode;
        prevNode = H->head;

        while(prevNode->link->data != where) {
            prevNode = prevNode->link;
        }

        delNode = prevNode->link;
        prevNode->link = delNode->link;
        free(delNode);

        cout << where << " 데이터 값을 가진 노드가 삭제되었습니다.";
    }

    // 리스트의 특정 노드 추가(조회 O(k) -> 삭제 O(1))
    void addThisNode(HeadNode* H, int where, int data) {
        Node* prevNode;
        prevNode = H->head;

        while(prevNode->data != where) {
            prevNode = prevNode->link;
        }

        Node* NewNode = new Node;
        NewNode->data = data;
        NewNode->link = prevNode->link;
        prevNode->link = NewNode;
        return;
    }

    // 리스트의 특정 노드 검색(조회 O(k))
    void searchNode(HeadNode* H, int where) {
        Node* searchNode;
        searchNode = H->head;

        while(searchNode->data != where) {
            searchNode = searchNode->link;
        }

        cout << where << " 데이터를 검색하는데 성공했습니다" << "\n";
    }

    // 연결 리스트 출력
    void printList(HeadNode* L) {
        //노드 순서대로 리스트 출력
        Node* p;
        cout << "연결리스트 목록 = ( ";
        p = L->head;

        while (p != NULL) {
            cout << p->data;
            p = p -> link;
            if(p != NULL) cout << " --> ";
        }
        cout << " )" << endl;
    }
};

int main()
{
	SingleList list;
	HeadNode* L;
	L = list.createList();

	cout << "1. 빈 연결 리스트를 생성했습니다." << endl << endl;

	int data1, data2, data3;
	cout << "2. 연결 리스트에 추가할 노드의 데이터를 3개 정해주세요: ";
	cin >> data1 >> data2 >> data3;
	list.addNode(L, data1);
	list.printList(L);
	list.addNode(L, data2);
	list.printList(L);
	list.addNode(L, data3);
	list.printList(L);
	cout << endl;

	cout << "3. 탐색할 노드의 데이터를 정해주세요 : ";
	int data4;
	cin >> data4;
	list.searchNode(L, data4);

	cout << endl;
	cout << "4-1. 어떤 노드 뒤에 노드를 추가할건가요? ";
	int data5, data6;
	cin >> data5;
	cout << "4-2. 그 노드 뒤에 어떤 데이터를 가진 노드를 추가할건가요? ";
	cin >> data6;
	list.addThisNode(L, data5, data6);
	list.printList(L);
	cout << endl;

	cout << "5. 삭제하고자 하는 노드를 알려주세요 : ";
	int data7;
	cin >> data7;
	list.deleteThisNode(L, data7);
	list.printList(L);
	cout << endl;

	cout << "6. 마지막 노드를 삭제합니다." << endl;
	list.deleteNode(L);
	list.printList(L);
	cout << endl;

	cout << "피곤하니까 연산을 끝내겠습니다." << endl;

    return 0;
}