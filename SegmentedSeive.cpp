/*
Implementation of Segmented Seive
by @prnjl-g*/




#define MAX 100001

/* Function to calcualte primes by normal Seive of eratosthenes*/

vector<long long int>* soa()
{
    bool isPrimes[MAX];
    for(long long int i=0;i<MAX;i++)
    isPrimes[i]=true;
    isPrimes[0]=false;
    isPrimes[1]=false;
    for(long long int i=2;i*i<MAX;i++)
    {
        if(isPrimes[i])
        {
            for(long long int j=i*i;j<MAX;j+=i)
            isPrimes[j]=false;
        }
    }
    vector<long long int> * primes=new vector<long long int>();
    primes->push_back(2);
    for(long long int i=3;i<MAX;i++)
    {
        if(isPrimes[i])
        primes->push_back(i);
    }
    
    return primes;
}

/*Define this function 
  according to your requirement */
long long process(int right_range,int left_range,bool segSoa[])
{
    long long ans=1;
    for(long long int i=0;i<=right_range-left_range;i++)
    {
          if(segSoa[i])
              {
                    ans=((ans%1000000007)*((i+left_range)%1000000007))%1000000007;
              }
    }
}
/* Fuction for Segmented Seive*/
long long int segSeive(vector<long long int>* primes,long long left_range,long long right_range)
{
    bool segSoa[right_range-left_range+1];
    for(long long int i=0;i<=right_range-left_range;i++)
         segSoa[i]=true;
    
    for(long long int i=0;primes->at(i)*(long long)primes->at(i)<=right_range;i++)
    {
        long long int currPrime=primes->at(i);
        long long int base=(left_range/currPrime)*currPrime;
        if(base<left_range)
          {
            base+=currPrime;
          }
        for(long long int j=base;j<=right_range;j+=currPrime)
        {
            segSoa[j-left_range]=false;
        }
        if(base==currPrime)
          {
            segSoa[base-left_range]=true;
          }
    }
    long long ans=process(right_range,left_range,segSoa);
    
    return ans;
}
/*int main()
{
    vector<long long int>* arr=soa(); // to calculate all possible primes for the given range
    long long t;
    cin>>t;
    while(t--)
    {
        long long int left_range,right_range;
        cin>>l>>r;
        long long int ans=segSeive(arr,left_range,right_range);  //Segmented seive
        cout<<ans<<endl;
        
    }
    return 0;
}*/
