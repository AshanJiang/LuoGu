//P6473未了,先从大到小对魔法排序，然后累加使用各个魔法后的时间就行了
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	//n,L,v分别表示魔法的种类数，山坡的长度，Sisyphus的速度,q表示宙斯的询问个数
	long long n, L, v, tmp, q;
	cin >> n >> L >>v;
	vector <long long> magic; //magic存储魔法
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		magic.push_back(tmp);
	}
	sort(magic.begin(), magic.end(), [](const long long a, const long long b) {return a > b; });
	vector <double> totalTime; //totalTime存储使用i个魔法后，上山的总时间
	totalTime.push_back(1.0 * L / v);
	for (int i = 1; i <= n; i++)
	{
		totalTime.push_back(totalTime[i - 1] + 1.0 * magic[i - 1] / v);
	}
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> tmp;
		auto up = upper_bound(totalTime.begin(), totalTime.end(), tmp);
		auto pos = up - totalTime.begin();
		if (pos == n + 1) 
		{
			cout << "-1\n";
		}
		else
		{
			cout << pos << "\n";
		}
	}
	
	return 0;
}