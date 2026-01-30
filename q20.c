#include <stdio.h>
#include <string.h>

char pairs(char a){
    if(a == '(')    return ')';
    if(a == '[')    return ']';
    if(a == '{')    return '}';
    return 0;
}

int isValid(char* s){
    int stack[256], top = 0;
    int n = strlen(s);
    for(int i = 0; i < n; i++){
        stack[top++] = *(s + i);
        if(top > 1 && stack[top - 1] == pairs(stack[top - 2]))
            top -= 2;
    }
    return !top;
}

int main(){
    char s[] = "()[]{}";
    printf("%d",isValid(s));
}