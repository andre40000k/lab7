#include <iostream>
#include <stack>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	stack<char> stk;
	bool isOk = true;
	char c;
	cout << "Введите обратну польскую запись: ";
	do 
	{	
		while (c = cin.peek(), c == ' ' || c == '\t') cin.get();
		if (c == '\n' || c == '=' || 'A' <= c && c <= 'Z')
		{
			isOk = false;
			cin.get();
		}
		else 
		{
			int t;
			cin >> t;
			if (cin.fail())
			{
				//получаем операнды
				int a, b;
				b = stk.top();
				stk.pop();
				a = stk.top();
				stk.pop();
				//вычисляем
				switch (c) 
				{
				case '+':
					a += b;
					break;
				case '-':
					a -= b;
					break;
				case '*':
					a *= b;
					break;
				case '/':
					a /= b;
					break;
				default:
					break;
				}
				stk.push(a);
				//восстанавливаем чтение, выносим знак операции из потока ввода
				cin.clear();
				if (c = cin.peek(),  c != '\n' && c != '=') cin.get();
			}
			else
				stk.push(t);
		}
	} while (isOk);

	cout << stk.top() << endl;

	system("pause");
	return 0;
}