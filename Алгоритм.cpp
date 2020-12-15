#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;



int nod(int a, int b)          // считаем НОД
{
	while (a > 0 && b > 0)
		if (a > b)  a %= b;
		else b %=a;
	return a + b;
}


int lll(int t, int p)           //если по модулю получили отрицательное число, преобразуем в положитеньное   
{
	do { t = t + p; } while (t < 0);
	return t;
}


void process(int q, int n)
{
	int x, y, a, b;
	for (x = 0; x <= n; x++)
		for (y = 0; y <= n; y++)
			for (a = 0; a <= n; a++)
			{
				int this1 = pow(y, 2);
				int this2 = pow(x, 3);
				b = (this1 - this2 - a * x) % n;   // b = y ^ 2−x ^ 3−ax(mod n)
				if (b < 0) b=lll(b, n); 
				int temp = 4 * pow(a, 3) + 27 * pow(b, 2);
				q = nod(n, temp);     // q = НОД(n, 4a ^ 3 + 27b ^ 2)
				if (q != n)        // Выписываем результат, только если  q не равно n
				{

					if ((1 < q) && (q < n)) {
						cout << "x = ";
						cout << x;
						cout << "     y =";
						cout << y;
						cout << "     a =";
						cout << a;
						cout << "     b =";
						cout << b;
						cout << "    q = ";
						cout << q;
						cout << endl;
					}
					/*else {
						q = 1; -- если продолжаем алгоритм
					};*/
				}
			}

}

int main()
{
	setlocale(LC_CTYPE, "Russian");
    int n, q;
	cout << "n= ";   //n=45
	cin >> n;
	q = n;  // пусть будет так, в функции q все равно изменится перед проверкой
	process(q,n);
    
	
	// 1) n = 45 (вводим это число);    q будут получаться либо= 9, либо=5   (за исключением ситуации, когда q=1)
	// 2)рандомные x,y,a из [0;n-1]  (в цикле)
	// 3)b=y^2−x^3−ax(mod n)
	//   q = НОД (n, 4a^3 + 27b^2)
	//   Если q=n , возвращаемся к п.2 
	//   Если 1<q<n, прекращаем вычисление, делитель найден
}

