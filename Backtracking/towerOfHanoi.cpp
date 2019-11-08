#include<iostream>

using namespace std;

void toh(int n,char source,char helper,char dest)

{

        if(n==1)
    {

        cout<<"Moving ring "<<n<<" from "<<source<<" to "<<dest<<endl;

        return;

    }

        toh(n-1,source,dest,helper);



        toh(1,source,helper,dest);


        toh(n-1,helper,source,dest);



        return;

}

            int main()
            {
                int n;
                cin>>n;


            toh(n,'A','C','B');

            }
