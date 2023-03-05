#include <cstdio>
#define MaxSize 50
typedef struct{
	int data[MaxSize];
	int length;
}SqList;
bool ListInsert(SqList &L, int i, int e){
	if(i<1 || i>L.length+1){
		return false;
	}
	if(L.length >= MaxSize){
		return false;
	}
	for(int j=L.length; j>=i; --j){
		L.data[j] = L.data[j-1];
	}
	L.data[i-1] = e;
	L.length++;
	return true;
}
bool ListDelete(SqList &L, int i, int &e){
	if(i<1 || i>L.length){
		return false;
	}
	e = L.data[i-1];
	for(int j=i; j<L.length; ++j){
		L.data[j-1] = L.data[j];
	}
	L.length--;
	return true;
}

int LocateElem(SqList L, int e){
	int i;
	for(i=0; i<L.length; ++i){
		if(L.data[i] == e){
			return i+1;
		}
	}
	return 0;
}
void InitSqList(SqList &L){
	L.length = 0;
	for(int i=0; i<=10; ++i){
		L.data[i] = i+1;
		L.length++;
	}
}
void PrintSqList(SqList L){
	for(int i=0; i<L.length; ++i){
		printf("%d ", L.data[i]);
	}
	printf("\n");
}
int main(){
	SqList L;
	InitSqList(L);
	PrintSqList(L);
	bool p;
	p = ListInsert(L, 3, 20);
	if(p){
		printf("插入成功\n");
	}
	else{
		printf("插入失败\n");
	}
	PrintSqList(L);
	int e;
	p = ListDelete(L, 6, e);
	if(p){
		printf("删除成功\n");
	}
	else{
		printf("删除失败\n");
	}
	printf("删除的元素：%d\n", e);
	PrintSqList(L);
	int k = LocateElem(L, 7);
	printf("位序：%d\n", k);
	return 0;
}


