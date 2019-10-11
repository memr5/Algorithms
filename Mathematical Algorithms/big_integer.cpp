#include <bits/stdc++.h>
#include<iostream>
#include<string>
#define p 1
#define n 0

#define gt 1
#define lt -1
#define eq 0

using namespace std;

int comparison(string a,string b);
string add(string first,string second);
string subtract(string first,string second);
void form_int(int *a,string str,int len);
string digit_multiply(int *a,int digit,int len);

string multiply(string first,string second);

string divide(string a,string b);
string gcd(string a,string b);

int main(){

    int t;
    cin>>t;
    while(t--){
        string first,second;
        cin>>first;
        cin>>second;
        string ans;
        int first_sign=p,second_sign=p;
        if(first[0] == '-'){
            first_sign=n;
            first=first.substr(1);
        }
        if(second[0] == '-'){
            second_sign=n;
            second=second.substr(1);
        }
        int op;
        cin>>op;

        if(op == 2){
            second_sign = (second_sign+1)%2;
        }
        //cout<<first<<" "<<second<<"\n";
        int status=comparison(first,second);
        if(((op==1)||(op==2)) && status == lt){
            swap(first,second);
            swap(first_sign,second_sign);
        }
        if(op==1 || op ==2){
            if(first_sign != second_sign){
                ans=subtract(first,second);
            }
            else{
                ans=add(first,second);
            }
            if(first_sign == n && ans!="0"){
                ans="-"+ans;
            }
        }
        else if(op == 3){
            ans=multiply(first,second);
            if(first_sign != second_sign){
                ans="-"+ans;
            }
        }
        else if(op == 4){
            //cout<<first<<" " <<second<<"\n";
            if(second == "0"){
                continue;
            }
            ans=divide(first,second);
            //string perfect=multiply(second,divisor);
            //cout<<perfect<<"\n";
            //string remainder=subtract(first,perfect);
            if(first_sign != second_sign){
                ans="-"+ans;
            }
        }
        else{
            ans=gcd(first,second);
        }
        cout<<ans<<"\n";
    }

    return 0;

}


string gcd(string a,string b){
    if(b=="0"){
        return a;
    }
    string div=divide(a,b);
    string prd=multiply(div,b);
    string rema=subtract(a,prd);
    return gcd(b,rema);
}

string divide(string a,string b){
    int count=0;
    while(comparison(a,b) == gt || comparison(a,b) == eq ){
        a=subtract(a,b);
        count++;
    }
    stringstream ss;
    ss << count;
    string ret=ss.str();
    return ret;
}

string multiply(string first,string second){
    string ans="0";
    if(second == "0" || first=="0"){
        ans="0";
        return ans;
    }
    int a[first.length()];
    form_int(a,first,first.length());

    for(int i=second.length()-1;i>=0;i--){
        string cur=digit_multiply(a,second[i]-'0',first.length());
        cur=cur+string(second.length()-1-i,'0');
        ans=add(ans,cur);
    }
    return ans;
}

string digit_multiply(int *a,int digit,int len){
    int sz=len+1;
    int res[sz];
    int carry=0;
    int ind=len;
    for(int i=len-1;i>=0;i--){
        int val=a[i]*digit + carry;
        res[ind--]=val%10;
        carry=val/10;
    }
    res[ind]=carry;

    char ch[sz+1];
    ind=0;
    if(res[0]!=0){
        ch[0]=res[0]+'0';
        ind++;
    }
    for(int i=1;i<sz;i++){
        ch[ind++]=res[i]+'0';
    }
    ch[ind]='\0';
    return string(ch);
}

void form_int(int *a,string str,int len){
    for(int i=0;i<len;i++){
            a[i]=str[i]-'0';
        }
}

string add(string first,string second){
    int a_len=first.length();
    int b_len=second.length();
    int a[a_len];
    int b[b_len];

    form_int(a,first,a_len);
    form_int(b,second,b_len);

    int sz=max(a_len,b_len)+1;
    int ans[sz];
    int i,j;
    int ind=sz-1;
    int carry=0;
    for(i=a_len-1,j=b_len-1;i>=0 && j>=0;i--,j--){
        int sum=carry + a[i] + b[j];
        carry=sum/10;
        ans[ind]=sum%10;
        ind--;
    }
    /*
    for(int it=0;it<sz;it++){
        cout<<ans[ind];
    }
    */
    if(i>=0){
        while(i>=0){
          int sum=carry+a[i--];
          carry=sum/10;
          ans[ind--]=sum%10;
        }
    }
    if(j>=0){
        while(j>=0){
            int sum=carry+b[j--];
            carry=sum/10;
            ans[ind--]=sum%10;
        }
    }
    ans[ind]=carry;
    char ch[sz+1];
    ind=0;
    if(ans[0]!=0){
        ch[0]=ans[0]+'0';
        ind++;
    }
    for(int i=1;i<sz;i++){
        ch[ind++]=ans[i]+'0';
    }
    ch[ind]='\0';
    return string(ch);
}

string subtract(string first,string second){
    if(comparison(first,second) == eq){
        return "0";
    }
    int a_len=first.length();
    int b_len=second.length();
    int diff=first.length()-second.length();
    second=string(diff, '0') + second;
    b_len=second.length();

    int a[a_len];
    int b[b_len];

    form_int(a,first,a_len);
    form_int(b,second,b_len);

    int ans[a_len];

    int carry=0;
    for(int i=a_len-1;i>=0;i--){
        a[i]-=carry;
        if(a[i]>=b[i]){
            ans[i]=a[i]-b[i];
            carry=0;
        }
        else{
            carry=1;
            a[i]=carry*10+a[i];
            ans[i]=a[i]-b[i];
        }
    }

   /*
    for(int it=0;it<a_len;it++){
        cout<<ans[it];
    }
    */
    char ch[a_len+1];
    for(int i=0;i<a_len;i++){
        ch[i]=ans[i]+'0';
    }
    ch[a_len]='\0';
    string res=string(ch);
    int ind=0;
    while(ch[ind] == '0'){
        ind++;
    }
    res=res.substr(ind);
    return res;
}

int comparison(string a,string b){
    int a_len=a.length();
    int b_len=b.length();
    if(a_len > b_len){
        return gt;
    }
    else if( a_len < b_len){
        return lt;
    }
    else{
        for(int i=0;i<a_len;i++){
            if(a[i]-'0' > b[i]-'0'){
                return gt;
            }
            else if(a[i]-'0' < b[i]-'0'){
                return lt;
            }
        }
        return eq;
    }
}


