#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "895.c"

/*
static inline void dump(FreqStack * freqStack){
    void qDump(Q * q, int indent){
        if( !q )
            return;
        qDump(q->right, indent+1);
        for(int i=0; i<indent; ++i)
            printf("  ");
        printf("val=%d, time=", q->val);
        for(int i=q->sp-1; i>=0; --i)
            printf("%d ", q->time[i]);
        puts("");
        qDump(q->left, indent+1);
    }
    qDump(freqStack->q, 0);
}
*/

int main(){
    FreqStack * freqStack = freqStackCreate();
    for(int k=0; k<2; ++k)
        for(int i=0; i<10000; ++i){
            freqStackPush(freqStack, i);
            //dump(freqStack);
            //puts("---------------");
        }
    return 0;
}