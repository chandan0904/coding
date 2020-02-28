#include<iostream>
#include<stack>
using namespace std;
bool balpara (char str[], int sPos, stack <char> &stc){
    if (str[sPos]=='\0'){
        if (stc.empty()) return true;
        else return false;
    }
    if (str[sPos]=='('|| str[sPos]=='['||str[sPos]=='{'){
            stc.push(str[sPos]);
            return balpara(str,sPos+1,stc);
        }
    if (str[sPos]==')' || str[sPos]==']' || str[sPos]=='}'){
        if((stc.top() == '(' && str[sPos]== ')' ) || ( stc.top() == '{' && str[sPos]== '}' )|| (stc.top() == '[' &&str[sPos]== ']') )
        {
            stc.pop();
            return balpara(str,sPos+1,stc);
        }

        return 0;

    }
     return balpara(str, sPos+1,stc);
}
int main(){
    char str[]="[]";
    stack <char> s;
    cout<<balpara(str,0,s);
}

