/* Algo to find prime number in a range */
void fill(vector<int>&prime,int n){
    for(int i=2;i<n;i++){
        if(prime[i]==0)prime[i]=1;
        else continue;
        for(int j=i+i;j<51;j+=i){
            prime[j]=2;
        }
    }
}
