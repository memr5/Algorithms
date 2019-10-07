
import java.util.*;
import java.io.*;

public class sieveOfEratosthenes {

	public static void main(String[] args) throws NumberFormatException, IOException {
		
		sieveOfEratosthenes s = new sieveOfEratosthenes();
			int n = 1000;
			s.sieve(n);
			
		
		
	}

	static void sieve(int n) {
		
		boolean prime[] = new boolean[n+1];
		for(int i=0;i<=n;i++)
			prime[i] =  true;
		for(int p=2;p*p<=n;p++) {
			
			if(prime[p]== true) {
				for(int i = p*p;i<=n;i=i+p) {
					prime[i]=false;
				}
			}
			
		}

		for(int i=2;i<=n;i++) {
			if(prime[i]==true)
				System.out.print(i + " ");
		}
		System.out.println();
	}
	
}
