#include <iostream>
using namespace std;

int parent[7] = { 0,1,1,1,4,4,4 };

int Find_Parent(int i)
{
	if (i == parent[i])
		return i;
	parent[i] = Find_Parent(parent[i]);
	return parent[i];
}

bool Find(int i, int j)
{
	return Find_Parent(i) == Find_Parent(j);
}

void Union(int i, int j)
{
	parent[Find_Parent(i)] = Find_Parent(j);
}

int main()
{
	Union(3, 6);
	cout << Find(2,6) << "\n";
	return 0;
}