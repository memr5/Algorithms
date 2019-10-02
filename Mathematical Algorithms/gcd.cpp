long long int gcd_func(long long int a, long long int b) {
  if (b == 0)
    return a;
  return gcd_func(b, a % b);
}
