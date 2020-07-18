//세그먼트 트리를 이용해 O(nlogn) 만에 LIS를 하는 거

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int _size = 0;
int treeLen = 0;
vector<int> input;
vector<int> segment;

void Init();
void Update(vector<int>& segment, int node, int start, int end, int index, int diff);
int Query(vector<int>& segment, int node, int start, int end, int front, int rear);
void LIS();

int main(void)
{
	Init();

	LIS();

	cout << Query(segment, 1, 0, treeLen - 1, 0, treeLen - 1);

	return 0;
}


void Init()
{
	cin >> _size;
	input.resize(_size);
	for (int i = 0; i < _size; i++)
	{
		cin >> input[i];
		if (treeLen < input[i])
		{
			treeLen = input[i];
		}
	}
	treeLen++;
	int h = (int)ceil(log2(treeLen));
	int tree_size = 1 << (h + 1);
	segment.resize(tree_size);
}

//index : 바꿀 위치 / diff : 바꿀 값
void Update(vector<int> &segment, int node, int start, int end, int index, int diff)
{
	if (index < start || index > end)
	{
		return;
	}
	else if (index == start && index == end)
	{
		segment[node] = diff;
	}
	else
	{
		if (segment[node] < diff)
		{
			segment[node] = diff;
		}
		Update(segment, node * 2, start, (start + end) / 2, index, diff);
		Update(segment, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

//front : 구하는 값의 앞부분 인덱스 / start : 현재 범위의 앞부분
int Query(vector<int> &segment, int node, int start, int end, int front, int rear)
{
	if (start >= front && end <= rear)
	{
		return segment[node];
	}
	else if (end < front || start > rear) 
	{
		return 0;
	}
	else
	{
		int a = Query(segment, node * 2, start, (start + end) / 2, front, rear);
		int b = Query(segment, node * 2 + 1, (start + end) / 2 + 1, end, front, rear);
		return a > b ? a : b;
	}
}

void LIS()
{
	for (int i = 0; i < _size; i++)
	{
		int max_len = Query(segment, 1, 0, treeLen - 1, 0, input[i] - 1) + 1;
		Update(segment, 1, 0, treeLen - 1, input[i], max_len);
	}
}