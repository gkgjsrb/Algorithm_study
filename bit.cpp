#include <stdio.h>
#include <string.h>
int main(){
 	int T,testcase,i,run,count;
    char input[50]; 
    char remem;

    scanf("%d",&T);
    for(testcase=1;testcase<=T;testcase++){
        count=0;
        scanf("%s",input); // 입력을 받음
        remem='0'; // 모든 비트가 0인걸로 시작하기 때문에 0으로 초기화
        run=strlen(input);
        for(i=0;i<run;i++){ 
            if(remem!=input[i]){ // 현재 뒤에 존재하는 비트와 다르다면 비트를 바꿔주고 
                remem=*(input+i);
               count++;          
            } 
        }
        
        printf("#%d %d\n",testcase,count);
    }
    return 0;
}
