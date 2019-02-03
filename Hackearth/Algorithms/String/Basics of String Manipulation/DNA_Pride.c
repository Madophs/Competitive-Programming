#include <stdio.h>
#include <stdbool.h>

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int length;
        scanf("%d",&length);
        char str[++length];
        scanf("%s",&str);
        bool rna = false;
        for(int x=0; x<length-1 && !rna; x++){
            if(str[x] == 'A'){
                str[x] = 'T';
            }else if(str[x] == 'T'){
                str[x] = 'A';
            }else if(str[x] == 'C'){
                str[x] = 'G';
            }else if(str[x] == 'G'){
                str[x] = 'C';
            }else{
                rna = true;
            }
        }
        if(rna){
            printf("Error RNA nucleobases found!\n");
        }else{
            printf("%s\n",str);
        }
    }
    return 0;
}