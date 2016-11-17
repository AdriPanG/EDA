#include <iostream>

using namespace std;

bool resuelve() {
	int b = 0, n = 0;
	int cont = 0;
	cin >> b >> n;
	if (b <= 1 || n <= 0) {
		return false;
	}
	
	int aux = b;

	while (n >= aux) {
		aux = aux * b;
		cont++;
	}

	cout << cont << endl;

	return true;

}

int main() {
	int casos;

	cin >> casos;

	for (int i = 0; i < casos; i++) {
		resuelve();
	}


	return 0;
}