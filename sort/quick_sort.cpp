#include<iostream>
using namespace std;

const int N = 1e6 + 10;
int n;
int q[N];

void quick_sort(int q[], int l, int r){
    if(l >= r) return; //注意是大于等于
    int x = q[l], i = l - 1, j = r + 1; //1.确定分界点；首先注意中间值取q[l]，递归的时候用j 
    while(i < j){ //2.调整区间
        do i++; while(q[i] < x);
        do j--; while(q[j] > x);
        if(i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l , j); //3.递归处理左右两段；递归的时候两个区间分别为[l, j]和[j + 1, r]
    quick_sort(q, j + 1, r);
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &q[i]);
    quick_sort(q, 0, n - 1);
    for(int i = 0; i < n; i++) printf("%d ", q[i]);
    return 0;
}
