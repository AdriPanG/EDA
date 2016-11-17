#include <iostream>

using namespace std;

//Precondicion: 0<=n<=long(v) ^ suma = suma(v,n)
//Postcondicion: cuantas = #w : 0 <= w < n : (suma(v,n) - acumulador( v,w) == acumulador(v,w))
//acumulador(v,i)= sumatorio de k : 0<=k<=i : v[k]

int cuantas(int v[], int n, int suma) {
	int cont = 0;
	int res = 0;
	
	for (int i = 0; i < n; i++) {
		if (res == suma - res) {
			cont++;
		}
		res += v[i];
	}
	if (res == suma - res) {
		cont++;
	}

	return cont;
}

//Precondicion: 0<=n<=long(v)
//Postcondicion: res = (Sumatorio k : 0<=k<n : v[k])
//Invariante: 0 <= i <= n ^ res = Sumatorio de j : 0 <= j < i : v[j])
//Cota: n-i

int suma(int v[], int n) {
	int res = 0;

	for (int i = 0; i < n; i++) {
		res += v[i];
	}

	return res;
}

bool resuelve() {
	int n;
	int v[100000];
	cin >> n;

	if (n == 0)
		return false;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int res = suma(v, n);

	cout << cuantas(v, n, res) << endl;

	return true;
}

int main() {

	while (resuelve()) {
		;
	}

	return 0;
}