#include <iostream>

using namespace std;

//Precondicion: 0<=n<=long(v) and Paratodo i : 0<=i<n : v[i] >= 0
//Postcondicion: #k : 0<=k<n : Paratodo j : k < j < n : a[k] > numero(v,j)
//numero(v,k) = max(Paratodo l : k<l<n : v[l])  

int calculaAbadias(int v[], int n, int &abadias) {
	abadias = 0;
	int numero = 0;
	for (int i = n; i > 0; i--) {
		if ((v[i-1] > v[i] && v[i-1] > numero) || i == n) {
			numero = v[i-1];
			abadias++;
		}
	}

	return abadias;
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

	int abadias;
	calculaAbadias(v, n, abadias);

	cout << abadias << endl;

	return true;
}

int main() {

	while (resuelve()) {
		;
	}

	return 0;
}