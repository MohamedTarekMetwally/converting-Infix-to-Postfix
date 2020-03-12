#include <bits/stdc++.h>
#include "stack.h"
#include <math.h>

using namespace std;


bool isInfix(string s){
    int counter=0;
    if(s.empty())return false;
    if(s.length()==0)return false;
        // n-(n/2)
    for(int i=0;i<s.length();i++){
        if(!isdigit(s[i]) )counter++;
    }
    if( counter==(s.length()-ceil(s.length()/2)) )return true;
    else return false;

}
int validation(char c){
    if(c=='+' || c=='-')
        return 1;
    else if(c=='*' || c=='/')
        return 2;
    else if(c=='^')
        return 3;

    return 0;
}

int main()
{
    cout<<"\t\t>>  W E L C O M E  <<\n\n1- Infix to Postfix.\n2- Postfix Notation.";
    int n;
    cin>>n;
    string s;

    if(n==1){ // infix to postfix
        cout<<"please enter equation in infix to convert it to postfix.";
        cin>>s;
        string n;
        char b;
        int j=0;
        Stack m= initStack();
        for(int i=0;i<s.length();i++){

            if(s[i]==' ')continue;
            else if(isdigit(s[i]) ||isalpha(s[i])){
                n[j++]=s[i];

            }
            else if(s[i]=='('){
                push(m,s[i]);
            }
            else if(s[i]==')'){
                int z=0;
                do{
                     b=pop(m);
                    n[j++]=b;

                }while(b!=')');
                pop(m); // removing the (


            }
            else {

                while(validation(s[i])<= validation(peek(m)) && !emptyStack(m)) { //why it's not valid !! peek
                    n[j++]=peek(m);
                    pop(m);
                }
                push(m,s[i]);


            }


        }

        while(!emptyStack(m)){
            n[j++]=pop(s);

        }


        cout<<n;
    }
    else if(n==2){ // Postfix evaluation.
        cout<<"Please enter equation in Postfix to evualate it .";
        cin>>s;

        if(!isInfix(s)){
            cout<<"The Expression you entered is not in postfix notation.\nPlease Enter String in Postfix expression\nPress 0 to leave.";
            while(s!="0"){
                cin>>s;

                if(isInfix(s))break;
                else{
                    cout<<"If you want to leave Press 0";
                }
            }
        }
        if(s=="0")return -1;


        Stack m= initStack();
        int sum=0,b;
        for(int i=0;i<s.length();i++){
            if(s[i]=='+' || s[i]=='-' || s[i]=='*'|| s[i]=='/'){
                int m1=pop(m);
                int m2=pop(m);
                if(s[i]=='+')
                    b=m1+m2;
                else if(s[i]=='-')
                    b=m1-m2;
                 else if(s[i]=='*')
                    b=m1*m2;
                else if(s[i]=='/')
                    b=m1/m2;

                sum+=b;
            }
            else if(isdigit(s[i]))  push(s[i]);

        }

        cout<<sum;

    }




    return 0;
}
