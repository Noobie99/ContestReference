struct sat2 {
	int n; // + scc variablen
	vector<int> sol;

	sat2(int vars) : n(vars*2), adjlist(vars*2) {};

	static int var(int i) {return i << 1;} // use this!

	void addImpl(int a, int b) {
		adjlist[a].push_back(b);
		adjlist[1^b].push_back(1^a);
	}
	void addEquiv(int a, int b) {addImpl(a, b); addImpl(b, a);}
	void addOr(int a, int b) {addImpl(1^a, b);}
	void addXor(int a, int b) {addOr(a, b); addOr(1^a, 1^b);}
	void addTrue(int a) {addImpl(1^a, a);}
	void addFalse(int a) {addTrue(1^a);}
	void addAnd(int a, int b) {addTrue(a); addTrue(b);}
	void addNand(int a, int b) {addOr(1^a, 1^b);}

	bool solvable() {
		scc(); //scc code von oben
		for (int i = 0; i < n; i += 2) {
			if (idx[i] == idx[i + 1]) return false;
		}
		return true;
	}

	void assign() {
		sol.assign(n, -1);
		for (int i = 0; i < sccCounter; i++) {
			if (sol[sccs[i][0]] == -1) {
				for (int v : sccs[i]) {
					sol[v] = 1;
					sol[1^v] = 0;
	}}}}
};
