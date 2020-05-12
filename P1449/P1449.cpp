//P1449 后缀表达式
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	string expr, token = "";
	cin >> expr;
	stack <int> s;
	int op1, op2;
	for (char& c : expr)
	{
		if (c == '+')
		{
			op1 = s.top();
			s.pop();
			op2 = s.top();
			s.pop();
			s.push(op2 + op1);
		}
		else if (c == '-')
		{
			op1 = s.top();
			s.pop();
			op2 = s.top();
			s.pop();
			s.push(op2 - op1);
		}
		else if (c == '*')
		{
			op1 = s.top();
			s.pop();
			op2 = s.top();
			s.pop();
			s.push(op2 * op1);
		}
		else if (c == '/')
		{
			op1 = s.top();
			s.pop();
			op2 = s.top();
			s.pop();
			s.push(op2 / op1);
		}
		else
		{
			if (c != '.')
			{
				token += c;
			}
			else
			{
				s.push(stoi(token));
				token = "";
			}
		}
	}
	cout << s.top() << '\n';
	return 0;
}