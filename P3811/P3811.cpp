//P3811 乘法逆元模板（常用于模数除法）
#include <cstdio>
typedef long long ll;

using namespace std;

//快速幂,返回a^b
ll binPow(ll a, ll b)
{
	ll res = 1;
	while (b > 0)
	{
		if (b & 1)res = res * a;
		a *= a;
		b >>= 1;
	}
	return res;
}

//乘法逆元，费马小定理，返回a在模p下的逆元
//不能直接先算幂再取模，否则会溢出，需要每一步都取模
ll inverseElement(ll a, ll p, ll mod)
{
	ll res = 1;
	while (p > 0)
	{
		if (p & 1) res = (res * a) % mod;
		a = a * a % mod; //!这里也有可能溢出
		p >>= 1;
	}
	return res % mod;
}

ll inv[20000528 + 5];

int main()
{
	//给定n,p求1~n中所有整数在模p意义下的乘法逆元。
	/*ll n, p;
	cin >> n >> p;
	for (int i = 1; i <= n; i++)
	{
		printf("%lld\n", inverseElement(i, p - 2, p));
	}*/
	int n, p;
	scanf("%d%d", &n, &p);
	inv[1] = 1;//1的逆元恒为1
	printf("%d\n", inv[1]);
	for (int i = 2; i <= n; i++)
	{
		// 线性推逆元，O(n)
		inv[i] = (ll)p - (p / i) * inv[p % i] % p;
		printf("%d\n", inv[i]);
	}
	return 0;
}