#include <iostream>  
using namespace std;  
  
struct ListNode  
{  
    int m_nValue;  
    ListNode *m_pNext;  
};  
  
//合并两个有序链表,递归方法  
ListNode *MergeTwoList(ListNode *pListOneHead, ListNode *pListTwoHead)  
{  
    if (pListOneHead == NULL)  
    {  
        return pListTwoHead;  
    }  
  
    if (pListTwoHead == NULL)  
    {  
        return pListOneHead;  
    }  
  
    ListNode *pMergeListHead = NULL;  
  
    if (pListOneHead->m_nValue < pListTwoHead->m_nValue)  
    {  
        pMergeListHead = pListOneHead;  
        pMergeListHead->m_pNext = MergeTwoList(pMergeListHead->m_pNext, pListTwoHead);  
    }  
    else  
    {  
        pMergeListHead = pListTwoHead;  
        pMergeListHead->m_pNext = MergeTwoList(pListOneHead, pMergeListHead->m_pNext);  
    }  
  
    return pMergeListHead;  
}  
  
//创建一个链表，输入从头到尾结点的值，输入-1表示结束  
void CreateList(ListNode *& pHead)  
{     
    ListNode *pListNode = NULL;  
    ListNode *pCurLastNode = NULL;  
    bool isHead = true;  
  
    while (1)  
    {  
        if (isHead)  
        {     
            pHead = new ListNode();  
            cin >> pHead->m_nValue;  
            if (pHead->m_nValue == -1)  
            {  
                pHead = NULL;  
                break;  
            }  
            pHead->m_pNext = NULL;  
            isHead = false;  
            pCurLastNode = pHead;  
        }  
        else  
        {  
            pListNode = new ListNode();  
            cin >> pListNode->m_nValue;  
            if (pListNode->m_nValue == -1)  
            {  
                break;  
            }  
            pListNode->m_pNext = NULL;  
            pCurLastNode->m_pNext = pListNode;  
            pCurLastNode = pListNode;     
        }             
    }  
}  
  
//从头到尾打印链表  
void PrintList(ListNode *&pHead)  
{  
    if (pHead != NULL)  
    {  
        ListNode *pCur = pHead;  
        while (pCur != NULL)  
        {  
            cout << pCur->m_nValue << " ";  
            pCur = pCur->m_pNext;  
        }  
        cout << endl;  
    }  
    else  
    {  
        cout << "链表为空！" << endl;  
    }  
}  
  
int main()  
{  
    ListNode *pList1Head = NULL;  
    CreateList(pList1Head);  
    PrintList(pList1Head);  
  
    ListNode *pList2Head = NULL;  
    CreateList(pList2Head);  
    PrintList(pList2Head);  
  
    ListNode *pMergeListHead = MergeTwoList(pList1Head, pList2Head);  
    if (pMergeListHead != NULL)  
    {  
        cout << pMergeListHead->m_nValue << endl;  
    }     
    PrintList(pMergeListHead);  
  
    system("pause");  
    return 0;  
}  