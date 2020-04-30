//P6475 [NOI Online #2 入门组]建设城市
#include <iostream>
typedef long long ll;

using namespace std;

const ll MOD_NUM = 998244353;
const ll max_n = 200000 + 5;
ll factorial[max_n]; //阶乘
ll inv[max_n]; //逆元

//返回a在模mod下的逆元，a^-1=a^(p-2)
ll inverseElement(ll a, ll mod)
{
	ll p = mod - 2;
	ll res = 1;
	while (p > 0)
	{
		if (p & 1) res = (res * a) % mod;
		a = a * a % mod;
		p >>= 1;
	}
	return res % mod;
}

//预处理,计算阶乘和逆元，注意inv[i]代表的是i!的逆，不是i的逆
void pre()
{
	factorial[0] = 1;
	inv[0] = 1;
	for (int i = 1; i < max_n; i++)
	{
		factorial[i] = (factorial[i - 1] * i) % MOD_NUM;
	}
	for (int i = 1; i < max_n; i++)
	{
		inv[i] = inverseElement(factorial[i], MOD_NUM);
	}
}

//计算n座楼，m楼高组成的单调不增（不减）序列的组合数C(n+m-1,m-1)模MOD_NUM的值
//a/b(mod p) = a*(b^-1) mod p => a/bc = a*(b^-1)*(c^-1) mod p
ll combination(ll n, ll m)
{
	ll res = factorial[n + m - 1] * inv[m - 1] % MOD_NUM * inv[n] % MOD_NUM;
	//cout << "f(" << n << "," << m << ")=" << res << "\n";
	return res;
}

int main()
{
	pre();
	ll m, n, x, y;
	ll res = 0;
	cin >> m >> n >> x >> y;
	//1.x,y在同侧,x,y之间所有楼就退化成一座楼
	if ((x <= n && y <= n) || (n <= x && x <= 2 * n && n <= y && y <= 2 * n))
	{
		res = combination(n - (y - x), m) * combination(n, m);
	}
	else //2.x,y在异侧，把所有楼以x,y,n为界分为四段，分别求解
	{
		for (int i = 1; i <= m; i++) 
		{
			//x,y固定高度枚举,特别注意m-i+1和y-n-1的写法，不要算错了
			res += combination(x - 1, i) * combination(n - x, m - i + 1) % MOD_NUM //m-i+1意味着，将x的高度i看作基准高度
				* combination(y - n - 1, m - i + 1) % MOD_NUM
				* combination(2 * n - y, i) % MOD_NUM; //注意要对乘法每一步都取模
		}
	}
	cout << res % MOD_NUM << '\n';
	return 0;
}