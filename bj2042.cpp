/*
* 정답 확인용 제출 출처 : https://ongveloper.tistory.com/252
*/
#include <iostream>
#include <vector>
#include <math.h>

#define ll long long

using namespace std;
int n, m, k;
std::vector<ll> SegTree;
std::vector<ll> arr;

ll MakeSegmentTree(int node, int start, int end) 
{
	if (start == end) 
	    return SegTree[node] = arr[start];
	
	int mid = (start + end) / 2;

	return SegTree[node] = MakeSegmentTree(node * 2, start, mid) + MakeSegmentTree(node * 2 + 1, mid+1, end);
}

void UpdateSegmentTree(int node, int start, int end, int idx, ll diff) 
{
	if (idx<start || idx > end) 
        return;

	SegTree[node] += diff;

	if (start != end) 
    {
		int mid = (start + end) / 2;
		UpdateSegmentTree(node * 2, start, mid, idx, diff);
		UpdateSegmentTree(node * 2 + 1, mid + 1, end, idx, diff);
	}
}

ll SumSegmentTree(int node, int left, int right, int start, int end) 
{
	if (left > end || right < start) 
        return 0;
	if (left <= start && right >= end) 
        return SegTree[node];

	int mid = (start + end) / 2;
	return SumSegmentTree(node * 2, left, right, start, mid) + SumSegmentTree(node * 2 + 1, left, right, mid+1, end);
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
    arr.assign(n, 0);

	for (int i = 0; i < n; i++) 
		cin >> arr[i];

	int treeDepth = ceil(log2(n));
	int treeSize = 1 << (treeDepth + 1);
    SegTree.resize(treeSize);
	
	MakeSegmentTree(1,0,n-1);

	for (int i = 0; i < m + k; i++) 
    {
		int order, left;
		ll right;
		cin >> order>> left >> right;
		if (order == 1) 
        {
			UpdateSegmentTree(1, 0, n - 1, left - 1, right-arr[left - 1]);
			arr[left - 1] = right;
		}
		else 
        {
			cout << SumSegmentTree(1, left-1, right-1, 0, n - 1)<<'\n';
		}
	}
	return 0;
}