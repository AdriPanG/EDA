#include <iostream>

using namespace std;

//Precondicion: 0 <= long(v) <= n
//int pico (int v[], int p, int u) return int pico;
/*pico(v, p, u) = {E i : 0 <= i < n : (Paratodo p : 0 <= p < i : v[p] <= v[p+1]) ^
					(Paratodo u : i <= u < n-1 : v[u] >= v[u-1])}*/
int pico(int v[], int p, int u) {
	if (p >= u) {
		return p;
	}
	else {
		if (v[p] <= v[p + 1]) {
			return pico(v, p + 1, u);
		}
		else if (v[u] <= v[u - 1]) {
			return pico(v, p, u - 1);
		}
	}
	return p;
}


bool resuelve() {
	int n, v[100000];
	cin >> n;

	if (n == 0) {
		return false;
	}
	else {
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		cout << pico(v, 0, n - 1) << endl;
	}

	return true;
}

int main() {

	while (resuelve()) {
		;
	}

	return 0;
}