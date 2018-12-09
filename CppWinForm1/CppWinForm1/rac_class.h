#pragma once

#include <iostream> 
#include <string>

using namespace std;
class rac;






class rac
{

public:

	rac DoubleToRational(double a);


	long long int m;
	long long int n;

	rac()
	{
		m = 0;
		n = 1;
	}

	rac(int _m)
	{
		m = _m;
		n = 1;
	}

	rac(double _a)
	{
		
	
		int minus = 1;

		if (_a < 0)
			minus = -1;
		_a *= minus;





		if (_a > 0.002 & _a < 0.003)
		{
			int x = 3 / 3 * 4;
			for (int l = 0; l < 3; l++);
		}





		if (_a == 0)
		{

			m = 0;
			n = 1;
			return;
		}

		float p = _a;
		long long int c = 1;
		int d = 0;

		p /= 100;
		p *= 100;

		while (p != (int)p)
		{
			p *= 10;
			d += 1;
		}


		for (int k = 0; k < d; k++)
		{
			c *= 10;
		}


		long long int k = gcd(p, c);
		
		m = (p) / k * minus;
		n = (c) / k;

	}


	void simple()
	{

		int g = gcd(m, n);
		m /= g;
		n /= g;
	}

	rac operator+(rac b)
	{
		rac out;
		int mn;
		out.n = this->n * b.n;
		out.m = m * b.n + b.m * n;
		//simple
		out.simple();
		return out;
	}

	rac operator-(rac b)
	{
		rac out;
		int mn;
		out.n = this->n * b.n;
		out.m = m * b.n - b.m * n;
		//simple
		out.simple();
		return out;
	}

	rac operator*(rac b)
	{
		rac out;
		out.m = m * b.m;
		out.n = n * b.n;
		//simple;
		out.simple();
		return out;
	}


	rac operator*(double d)
	{
		rac out(d);

		out = out * *this;

		out.simple();

		return out;
	}



	rac operator/(rac b)
	{
		rac out;
		out.m = m * b.n;
		out.n = n * b.m;
		//simple;
		out.simple();
		return out;
	}

	friend ostream& operator<<(ostream& os, const rac& rc);




	long long int gcd(long long int a, long long int b)
	{
		if (b == 0)
			return a;
		else
			return gcd(b, a%b);
	}


	string to_string()
	{
		return string(std::to_string(m) + "/" + std::to_string(n));
	}

	string to_string(rac a)
	{
		return string(std::to_string(a.m) + "/" + std::to_string(a.n));
	}

/*	operator double() const
	{
		return m / n;
	}
	*/

	operator double() const
	{
		return m / n;
	}


	


};

string to_string(rac a)
{
	return string(std::to_string(a.m) + "/" + std::to_string(a.n));
}


rac operator*(double d, rac r)
{
	rac o = r * d;
	o.simple();
	return o;
}


rac operator/(double d, rac r)
{
	rac o = r / rac(d);
	o.simple();
	return o;
}



ostream& operator<<(ostream& os, const rac& rc)
{
	os << rc.m << '/' << rc.n;
	return os;
}


istream& operator >> (istream& is, rac& rc)
{
	double d;
	is >> d;
	rac t(d);
	rc.m = t.m;
	rc.n = t.n;
	return is;
}





void mult_vect(double * v, int n, double d)
{

	for (int i = 0; i < n; i++)
		v[i] *= d;
}

void mult_vect(rac * v, int n, rac d)
{

	for (int i = 0; i < n; i++)
		v[i] = v[i] * d;
}






void subsc_vect(double *u, double * v, int n)
{
	for (int i = 0; i < n; i++)
		u[i] = u[i] - v[i];
}


void subsc_vect(rac *u, rac * v, int n)
{
	for (int i = 0; i < n; i++)
		u[i] = u[i] - v[i];
}


int main_2()
{
/*
	rac rc(3.8);
	cout << rc << "\n";

	//	DoubleToRational(98.7);



	cout << "Enter N ";
	cin >> n;
	x = new rac[n + 2];
	y = new rac[n + 2];
	a = new rac[n + 2];
	b = new rac[n + 2];
	c = new rac[n + 2];
	d = new rac[n + 2];
	h = new rac[n + 2];
	cv = new rac[n + 2];
	r = new rac[n + 2];


	ch = new rac *[n + 2];





	for (int i = 0; i < n + 2; i++)
		ch[i] = new rac[n + 2];


	for (int i = 0; i < n + 2; i++)
	{
		for (int j = 0; j < n + 2; j++)
			ch[i][j] = 0;
	}




	for (int i = 0; i < n + 2; i++)
	{
		cv[i] = 1;
		c[i] = 0;
		d[i] = 0;
		b[i] = 0;
	}

	cv[2] = 0;
	cv[n + 1] = 0;


	for (int i = 0; i < n; i++)
		cin >> x[i + 1] >> y[i + 1];

	for (int i = 2; i < n; i++)
		h[i] = x[i] - x[i - 1];

	for (int i = 2; i <= n; i++)
	{
		h[i] = x[i] - x[i - 1];
	}


	for (int i = 2; i <= n - 1; i++)
		r[i] = 3 * ((y[i + 1] - y[i]) / h[i + 1] - (y[i] - y[i - 1]) / h[i]);


	for (int i = 2; i <= n - 1; i++)
	{
		ch[i][i] = h[i] * cv[i];
		ch[i][i + 1] = (h[i] + h[i + 1]) * 2 * cv[i + 1];
		ch[i][i + 2] = h[i + 1] * cv[i + 2];
	}


	for (int i = 2; i <= n - 1; i++)
	{
		for (int j = 3; j <= n; j++)
			//cout << ch[i][j] << "*c" << j << " ";
			cout << ch[i][j] << " ";
		cout << "	|	" << r[i] << "\n";
	}

	for (int i = 2; i < n - 1; i++)
	{
		// Рассчитатиь коэффицент для стрчки
		rac coeff;
		coeff = ch[i + 1][i + 1] / ch[i][i + 1];
		mult_vect(ch[i], n + 2, coeff);
		r[i] = r[i] * coeff;
		subsc_vect(ch[i + 1], ch[i], n + 2);
		r[i + 1] = r[i + 1] - r[i];
	}




	cout << "---------------------------";
	cout << "\n";

	for (int i = 2; i <= n - 1; i++)
	{
		for (int j = 3; j <= n; j++)
			//cout << ch[i][j] << "*c" << j << " ";
			cout << ch[i][j] << "	";
		cout << "	|	" << r[i] << "\n";
	}




	for (int i = n - 1; i > 2; i--)
	{
		// Рассчитатиь коэффицент для стрчки
		rac coeff;
		coeff = ch[i - 1][i + 1] / ch[i][i + 1];
		mult_vect(ch[i], n + 2, coeff);
		r[i] = r[i] * coeff;
		subsc_vect(ch[i - 1], ch[i], n + 2);
		r[i - 1] = r[i - 1] - r[i];
	}








	cout << "---------------------------";
	cout << "\n";

	for (int i = 2; i <= n - 1; i++)
	{
		for (int j = 3; j <= n; j++)
			//cout << ch[i][j] << "*c" << j << " ";
			cout << ch[i][j] << "	";
		cout << "	|	" << r[i] << "\n";
	}



	for (int i = 2; i <= n - 1; i++) {
		int x = 9;
		r[i] = r[i] * 1 / ch[i][i + 1];
		mult_vect(ch[i], n + 2, 1 / ch[i][i + 1]);
	}


	cout << "---------------------------";
	cout << "\n";

	for (int i = 2; i <= n - 1; i++)
	{
		for (int j = 3; j <= n; j++)
			//cout << ch[i][j] << "*c" << j << " ";
			cout << ch[i][j] << "	";
		cout << "	|	" << r[i] << "\n";
	}


	for (int i = 3; i <= n; i++)
	{
		c[i] = r[i - 1];
	}


	for (int i = 2; i <= n; i++)
	{
		d[i] = (c[i + 1] - c[i]) / (3 * h[i]);
		a[i] = y[i - 1];
		b[i] = ((y[i] - y[i - 1]) / h[i]) - (c[i] * h[i] + (c[i + 1] - c[i])*h[i] / 3);
	}

	for (int i = 2; i <= n; i++)
		cout << a[i] << "	";
	cout << "\n";

	for (int i = 2; i <= n; i++)
		cout << b[i] << "	";
	cout << "\n";

	for (int i = 2; i <= n; i++)
		cout << c[i] << "	";
	cout << "\n";

	for (int i = 2; i <= n; i++)
		cout << d[i] << "	";
	cout << "\n";


	for (int i = 2; i <= n; i++)
	{
		string out = "";
		out += "(" + to_string(a[i].m) + "/" + to_string(a[i].n) + ") + "
			+ "(" + to_string(b[i].m) + "/" + to_string(b[i].n) + ") * (x - (" + to_string(x[i - 1].m) + "/" + to_string(x[i - 1].n) + ")) + "
			+ "(" + to_string(c[i].m) + "/" + to_string(c[i].n) + ") * (x - (" + to_string(x[i - 1].m) + "/" + to_string(x[i - 1].n) + "))^2 + "
			+ "(" + to_string(d[i].m) + "/" + to_string(d[i].n) + ") * (x - (" + to_string(x[i - 1].m) + "/" + to_string(x[i - 1].n) + "))^3";
		cout << out << "\n";
	}

	*/
	return 0;
}


template <class T>
class polinom
{
	public:

	T a, b, c, d;
	double lb, rb;
	string st_pol;
	T x;
	
	double calck(double xi)
	{
		return a + b * (xi - x) + c * (xi - x) * (xi - x) + d  * (xi - x) * (xi - x) * (xi - x);
	}

};




template <class T>
class cube_polinom
{
public:


	T *x;
	T *y;

	T *c, *d, *a, *b;
	T *h; T *r;
	T **ch;

	T *cv;



	polinom<T> * polArr;
	int polinom_count;
	int point_count;



	cube_polinom(int n)
	{
		polArr = new polinom<T>[n - 1];
		point_count = n;
		polinom_count = n - 1;
		x = new T[point_count + 2];
		y = new T[point_count + 2];
	}
	
	
	void init(double * _x, double * _y, int n)
	{
		for (int i = 0; i < point_count; i++)
		{
			if (point_count != n) return;
			x[i + 1] = _x[i + 1]; y[i + 1] = _y[i + 1];
		}
			
		
	}

	void iterpolate()
	{
		
		a = new T[point_count + 2];
		b = new T[point_count + 2];
		c = new T[point_count + 2];
		d = new T[point_count + 2];
		h = new T[point_count + 2];
		cv = new T[point_count + 2];
		r = new T[point_count + 2];


		ch = new T *[point_count + 2];


		for (int i = 0; i < point_count + 2; i++)
			ch[i] = new T[point_count + 2];


		for (int i = 0; i < point_count + 2; i++)
		{
			for (int j = 0; j < point_count + 2; j++)
				ch[i][j] = 0;
		}




		for (int i = 0; i < point_count + 2; i++)
		{
			cv[i] = 1;
			c[i] = 0;
			d[i] = 0;
			b[i] = 0;
		}

		cv[2] = 0;
		cv[point_count + 1] = 0;



// void init
//		for (int i = 0; i < point_count; i++)
//			cin >> x[i + 1] >> y[i + 1];

		for (int i = 2; i < point_count; i++)
			h[i] = x[i] - x[i - 1];

		for (int i = 2; i <= point_count; i++)
		{
			h[i] = x[i] - x[i - 1];
		}


		for (int i = 2; i <= point_count - 1; i++)
			r[i] = T(3) * ((y[i + 1] - y[i]) / h[i + 1] - (y[i] - y[i - 1]) / h[i]);


		for (int i = 2; i <= point_count - 1; i++)
		{
			ch[i][i] = h[i] * cv[i];
			ch[i][i + 1] = (h[i] + h[i + 1]) * T(2) * cv[i + 1];
			ch[i][i + 2] = h[i + 1] * cv[i + 2];
		}


		for (int i = 2; i <= point_count - 1; i++)
		{
			for (int j = 3; j <= point_count; j++)
				//cout << ch[i][j] << "*c" << j << " ";
				cout << ch[i][j] << " ";
			cout << "	|	" << r[i] << "\n";
		}

		for (int i = 2; i < point_count - 1; i++)
		{
			// Рассчитатиь коэффицент для стрчки
			T coeff;
			coeff = ch[i + 1][i + 1] / ch[i][i + 1];
			mult_vect(ch[i], point_count + 2, coeff);
			r[i] = r[i] * coeff;
			subsc_vect(ch[i + 1], ch[i], point_count + 2);
			r[i + 1] = r[i + 1] - r[i];
		}




		cout << "---------------------------";
		cout << "\n";

		for (int i = 2; i <= point_count - 1; i++)
		{
			for (int j = 3; j <= point_count; j++)
				//cout << ch[i][j] << "*c" << j << " ";
				cout << ch[i][j] << "	";
			cout << "	|	" << r[i] << "\n";
		}




		for (int i = point_count - 1; i > 2; i--)
		{
			// Рассчитатиь коэффицент для стрчки
			T coeff;
			coeff = ch[i - 1][i + 1] / ch[i][i + 1];
			mult_vect(ch[i], point_count + 2, coeff);
			r[i] = r[i] * coeff;
			subsc_vect(ch[i - 1], ch[i], point_count + 2);
			r[i - 1] = r[i - 1] - r[i];
		}








		cout << "---------------------------";
		cout << "\n";

		for (int i = 2; i <= point_count - 1; i++)
		{
			for (int j = 3; j <= point_count; j++)
				//cout << ch[i][j] << "*c" << j << " ";
				cout << ch[i][j] << "	";
			cout << "	|	" << r[i] << "\n";
		}



		for (int i = 2; i <= point_count - 1; i++) {
			int x = 9;
			r[i] = r[i] * T(1) / ch[i][i + 1];
			mult_vect(ch[i], point_count + 2, T(1) / ch[i][i + 1]);
		}


		cout << "---------------------------";
		cout << "\n";

		for (int i = 2; i <= point_count - 1; i++)
		{
			for (int j = 3; j <= point_count; j++)
				//cout << ch[i][j] << "*c" << j << " ";
				cout << ch[i][j] << "	";
			cout << "	|	" << r[i] << "\n";
		}


		for (int i = 3; i <= point_count; i++)
		{
			c[i] = r[i - 1];
		}


		for (int i = 2; i <= point_count; i++)
		{
			d[i] = (c[i + 1] - c[i]) / (T(3) * h[i]);
			a[i] = y[i - 1];
			b[i] = ((y[i] - y[i - 1]) / h[i]) - (c[i] * h[i] + (c[i + 1] - c[i])*h[i] / T(3));
		}

		for (int i = 2; i <= point_count; i++)
			cout << a[i] << "	";
		cout << "\n";

		for (int i = 2; i <= point_count; i++)
			cout << b[i] << "	";
		cout << "\n";

		for (int i = 2; i <= point_count; i++)
			cout << c[i] << "	";
		cout << "\n";

		for (int i = 2; i <= point_count; i++)
			cout << d[i] << "	";
		cout << "\n";


		for (int i = 2; i <= point_count; i++)
		{
			string out = "";
			out += "(" + to_string(a[i]) + ") + "
				+ "(" + to_string(b[i]) + ") * (x - (" + to_string(x[i - 1]) + ")) + "
				+ "(" + to_string(c[i]) + ") * (x - (" + to_string(x[i - 1]) + "))^2 + "
				+ "(" + to_string(d[i]) + ") * (x - (" + to_string(x[i - 1]) + "))^3";
		//	cout << out << "\n";
			(polArr + i - 2)->a = a[i];
			(polArr + i - 2)->b = b[i];
			(polArr + i - 2)->c = c[i];
			(polArr + i - 2)->d = d[i];
			(polArr + i - 2)->x = x[i - 1];
			(polArr + i - 2)->st_pol = out;
		}

		
	
	
	}



};

