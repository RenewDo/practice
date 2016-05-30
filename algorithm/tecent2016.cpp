int Longest(string s)
{
   int n = s.size(); 
    vector<vector<int> > longsub(n+1,  vector<int>(n+1)) ;
    int res = 0 ;
    string str = s;
    reverse(s.begin(), s.end());

    for(int i=1; i<n+1; i++)
           for(int j=1; j<n+1; j++)
               if(s[i-1] == str[j-1])
                   longsub[i][j] = longsub[i-1][j-1] +1;
               else 
                   longsub[i][j] = max(longsub[i][j-1], longsub[i-1][j]);

    return longsub[n][n];
}
