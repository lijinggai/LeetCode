#include<iostream>
#include"UnionFindSet.hpp"
#include<string>

using namespace std;

int main()
{
	vector<int> v{ 1,23,432,5345,8,712,44,534,645,73,862,3 };
	UnionFindSet<int> ufs(v);

	ufs.Union(1, 534);
	ufs.Union(1, 534);
	ufs.Union(73, 534);
	ufs.Union(1, 4);
	ufs.Union(23, 8);
	ufs.Union(862, 73);
	ufs.Union(3,3);
	return 0;
}