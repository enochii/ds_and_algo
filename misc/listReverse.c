#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
	ElementType Data;
	PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print(List L); /* 细节在此不表 */

List Reverse(List L);

int main()
{
	List L1, L2;
	L1 = Read();
	L2 = Reverse(L1);
	Print(L1);
	Print(L2);
	return 0;
}

/* 你的代码将被嵌在这里 */
List link(List L);
#define nullptr 0

List Reverse(List L)
{
	if (L == nullptr || L->Next == nullptr)
	{
		return L;
	}
	List L1 = link(L);
	L->Next = nullptr;
	return L1;
}

List link(List L)
{
	/*检查size>=2*/
	if (L->Next->Next == nullptr)
	{
		L->Next->Next = L;
		return L->Next;
	}

	List res = link(L->Next);
	L->Next->Next = L;
	return res;
}