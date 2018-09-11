/* 
 Seive of eratosthenes implementation
 by  @prnjl-g
*/

/* Fuction to find all the primes upto 10^7    (the limit can be change but should be less then 10^7*/
void soa()
{
    
    for(ll i=0;i<1e7+1;i++)
    primes[i]=true;
    primes[0]=false;
    primes[1]=false;
    for(ll i=2;i*i<1e7+1;i++)
    {
        if(!primes[i])
        continue;
        for(ll j=i*i;j<1e7+1;j+=i)
        {
            primes[j]=false;
        }
    }
}
