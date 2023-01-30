vector<bool> SieveOfEratosthenes(int n)
{
   vector<bool> prime(n + 1, true);
 
    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
   return prime;
}
