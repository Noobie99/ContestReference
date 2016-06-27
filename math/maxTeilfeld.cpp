// N := Länge des Feldes.
// Laufzeit: O(N)
int maxStart = 1, maxLen = 0, curStart = 1, len = 0;
double maxValue = 0, sum = 0;
for (int pos = 0; pos < N; pos++) {
	sum += values[pos];
	len++;
	if (sum > maxValue) { // Neues Maximum.
		maxValue = sum; maxStart = curStart; maxLen = len;
	}
	if (sum < 0) { // Alles zurücksetzen.
		curStart = pos +2; len = 0; sum = 0;
	}
}
// maxSum := maximaler Wert, maxStart := Startposition, maxLen := Länge der Sequenz
