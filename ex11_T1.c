// C program of above approach
#include<stdio.h>
#include<string.h>

// A utility function to get max of two integers
int max (int x, int y) { return (x > y)? x : y; }

// Returns the length of the longest palindromic subsequence in seq
int lps(char *seq, int i, int j)
{
// Base Case 1: If there is only 1 character
if (i == j)
	return 1;

// Base Case 2: If there are only 2 characters and both are same
if (seq[i] == seq[j] && i + 1 == j)
	return 2;

// If the first and last characters match
if (seq[i] == seq[j])
	return lps (seq, i+1, j-1) + 2;

// If the first and last characters do not match
return max( lps(seq, i, j-1), lps(seq, i+1, j) );
}

int lps_DP(char s[], int n){
	// n is the length of substring
	int j, L[n][n];
	// The diagonal of L denotes the string of length 1
	// They are of course palindrome of length 1
	for(int i = 0; i < n; i++){
		L[i][i] = 1;	// Fills the diagonal
	}
	for(int k = 2; k <= n; k++){
		for(int i = 0; i < n - k+1; i++){
			j = i + k -1;
			if(s[i] == s[j] && k == 2)
				L[i][j] = 2;
			else if(s[i] == s[j])
				L[i][j] = L[i+1][j-1] + 2;
			else
				L[i][j] = max(L[i][j-1], L[i+1][j]);
		}
	}
	return L[0][n-1];
}

/* Driver program to test above functions */
int main()
{
	char seq[] = "radar";
	int n = strlen(seq);
	printf ("The length of the LPS is %d\n", lps(seq, 0, n-1));
	printf ("The length of the LPS is %d\n", lps_DP(seq, n));
	return 0;
}
