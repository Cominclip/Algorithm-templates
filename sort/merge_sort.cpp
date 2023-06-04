#include<iostream>
using namespace std;

const int N = 1e6 + 10;
int n;
int q[N], tmp[N];

void merge_sort(int q[], int l, int r)
{
    if(l >= r) return;
    int mid = l + r >> 1; //1.确定分界点，直接选中点
    merge_sort(q, l, mid); //2.通过递归对分界点左右两段进行排序
    merge_sort(q, mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while(i <= mid && j <= r) //3. 归并，合二为一
    {
        if(q[i] <= q[j]) tmp[k++] = q[i++];
        else tmp[k++] = q[j++];
    }
    while(i <= mid) tmp[k++] = q[i++];
    while(j <= r) tmp[k++] = q[j++];
    for(int i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j]; //特别注意i与j的初值以及终值
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) scanf("%d", &q[i]);
    merge_sort(q, 0, n - 1);
    for(int i = 0; i < n; i ++) printf("%d ", q[i]);
    return 0;
}