vector<vector<int>> idx;
vector<int> to, validIdx, cycle;
vector<bool> used;

void addEdge(int a, int b) {
	idx[a].push_back(sz(to));
	to.push_back(b);
	used.push_back(false);
	idx[b].push_back(sz(to)); //für ungerichtet
	to.push_back(a);
	used.push_back(false);
}

// Findet Eulerzyklus an Knoten n startend.
// init idx und validIdx
void euler(int n) {
	for (;validIdx[n] < sz(idx[n]); validIdx[n]++) {
		if (!used[idx[n][validIdx[n]]]) {
			int nn = to[idx[n][validIdx[n]]];
			used[idx[n][validIdx[n]]] = true;
			used[idx[n][validIdx[n]] ^ 1] = true; //für ungerichtet
			euler(nn);
	}}
	// Zyklus in cycle in umgekehrter Reihenfolge.
	cycle.push_back(n);
}
