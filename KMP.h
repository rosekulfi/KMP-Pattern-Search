#ifndef KMP_H_
#define KMP_H_

// Fills lps[] for given patttern pat[0..M-1] 
void computePiArray(string pat, int M, int* pi) 
{ 
    //Finish this function
	int j=1
	int k=0;
	pi[0] = 0;
	
	while(j < M)
	{
		//found match
		if(pat[j] == pat[k])
		{
			k++;
			pi[j] = k;
			j++;
		}

		//first char does not match
		else if(k==0)
		{
			pi[j] = 0;
			j++;
		}

		else{
			k = pi[k-1];
		}
	}
}   

// Prints occurrences of txt[] in pat[] 
void KMPSearch(string pat, string txt) 
{ 
    int M = pat.length(); 
    int N = txt.length(); 
  
    int pi[M]; 
  
    // Preprocess the pattern (calculate lps[] array) 
    computePiArray(pat, M, pi); 
  
    // Finish the function...
	int x=0
	int y=0;
	while(x < N )
	{
		if(pat[y] == txt[x])
		{
			x++;
			y++;
		}
		if(y == M)
		{
			cout << "Found pattern at index " << x-y << endl;
			y = pi[y-1];
		}
		else if(x<N && pat[y]!=txt[x])
		{
			if(y!=0) y = pi[y-1];
			else x++;
		}
	}
	return;

} 
  

#endif
