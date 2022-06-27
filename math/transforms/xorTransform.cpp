void fft(vector<ll>& a, bool inverse = 0) {
	int n = sz(a);
	for (int i = 0, j = 1; j < n - 1; ++j) {
		for (int k = n >> 1; k > (i ^= k); k >>= 1);
		if (j < i) swap(a[i], a[j]);
	}
	for (int s = 1; s < n; s *= 2) {
		for (int j = 0; j < n; j+= 2 * s) {
			for (int k = 0; k < s; k++) {
				ll u = a[j + k], t = a[j + s + k];
				a[j + k] = u + t;
				a[j + s + k] = u - t;
	}}}
	if (inverse) {
		for (ll i = 0; i < n; i++) {
			a[i] /= n;
}}}
