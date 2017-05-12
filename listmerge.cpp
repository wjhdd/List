#include <iostream>  
using namespace std;  
  
struct ListNode  
{  
    int m_nValue;  
    ListNode *m_pNext;  
};  
  
//�ϲ�������������,�ǵݹ鷽��  
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
  
    ListNode *pNode1 = pListOneHead;  
    ListNode *pNode2 = pListTwoHead;  
    ListNode *pMergeListHead = NULL;  
    ListNode *pCurLastNode = NULL;  
  
    if (pNode1->m_nValue < pNode2->m_nValue)  
    {             
        pMergeListHead = pListOneHead;  
        pNode1 = pNode1->m_pNext;  
        pCurLastNode = pMergeListHead;  
    }  
    else  
    {  
        pMergeListHead = pListTwoHead;  
        pNode2 = pNode2->m_pNext;  
        pCurLastNode = pMergeListHead;  
    }  
  
    while (pNode1 != NULL && pNode2 != NULL)  
    {  
        if (pNode1->m_nValue < pNode2->m_nValue)  
        {     
            pCurLastNode->m_pNext = pNode1;  
            pCurLastNode = pNode1;  
            pNode1 = pNode1->m_pNext;              
        }  
        else  
        {  
            pCurLastNode->m_pNext = pNode2;  
            pCurLastNode = pNode2;  
            pNode2 = pNode2->m_pNext;              
        }  
  
        if (pNode1 == NULL)  
        {  
            pCurLastNode->m_pNext = pNode2;                
        }  
          
        if (pNode2 == NULL)  
        {  
            pCurLastNode->m_pNext = pNode1;            
        }  
    }  
  
    return pMergeListHead;  
}  
  
//����һ�����������ͷ��β����ֵ������-1��ʾ����  
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
  
//��ͷ��β��ӡ����  
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
        cout << "����Ϊ�գ�" << endl;  
    }  
}  
  
int main()  //int argc, _TCHAR* argv[]
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