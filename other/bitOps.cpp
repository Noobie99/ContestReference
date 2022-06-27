// Iteriert über alle Teilmengen einer Bitmaske
// (außer der leeren Menge).
for (int subset = bitmask; subset > 0;
		 subset = (subset - 1) & bitmask)

// Zählt Anzahl der gesetzten Bits.
int numberOfSetBits(int i) {
	i = i - ((i >> 1) & 0x55555555);
	i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

// Nächste Permutation in Bitmaske
// (z.B. 00111 => 01011 => 01101 => ...)
ll nextPerm(ll v) {
	ll t = v | (v - 1);
	return (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctzll(v) + 1));
}
