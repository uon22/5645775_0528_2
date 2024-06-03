#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;

ListNode* init_list() {
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head->link = head;
    return head;
}

void insert_first(ListNode* head, element data) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    node->link = head->link;
    head->link = node;
}

void insert_last(ListNode* head, element data) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    node->link = head;
    ListNode* p = head;
    while (p->link != head) {
        p = p->link;
    }
    p->link = node;
}

void delete_first(ListNode* head) {
    if (head->link == head) {
        printf("리스트가 비어 있습니다.\n");
        return;
    }
    ListNode* removed = head->link;
    head->link = removed->link;
    free(removed);
}

void delete_last(ListNode* head) {
    if (head->link == head) {
        printf("리스트가 비어 있습니다.\n");
        return;
    }
    ListNode* prev = head;
    ListNode* curr = head->link;
    while (curr->link != head) {
        prev = curr;
        curr = curr->link;
    }
    prev->link = head;
    free(curr);
}

void print_list(ListNode* head) {
    if (head->link == head) {
        printf("리스트가 비어 있습니다.\n");
        return;
    }
    ListNode* p = head->link;
    do {
        printf("%d -> ", p->data);
        p = p->link;
    } while (p != head);
    printf("(head)\n");
}

void menu() {
    printf("메뉴:\n");
    printf("1. 숫자 입력 받아서 리스트 처음에 추가\n");
    printf("2. 숫자 입력 받아서 리스트 마지막에 추가\n");
    printf("3. 리스트 처음 노드 삭제\n");
    printf("4. 리스트 마지막 노드 삭제\n");
    printf("5. 리스트 프린트\n");
    printf("6. 종료\n");
}

int main() {
    ListNode* head = init_list();
    int choice;
    element data;

    while (1) {
        menu();
        printf("메뉴를 선택하세요: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("추가할 숫자를 입력하세요: ");
            scanf("%d", &data);
            insert_first(head, data);
            break;
        case 2:
            printf("추가할 숫자를 입력하세요: ");
            scanf("%d", &data);
            insert_last(head, data);
            break;
        case 3:
            delete_first(head);
            break;
        case 4:
            delete_last(head);
            break;
        case 5:
            print_list(head);
            break;
        case 6:
            printf("프로그램을 종료합니다.\n");
            exit(0);
        default:
            printf("잘못된 입력입니다.\n");
            break;
        }
    }

    return 0;
}
