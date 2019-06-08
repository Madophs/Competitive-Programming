/*
                                                        Hoang Linh
    
    solution : math
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <time.h>


#define fi "10023.inp"
#define fo "10023.out"
/**/
using namespace std;
/**/
char str[2000],kq[2000],y[2000];
char s[1000][4];
int lstr,len,ds;
/**/
bool chia()
{
    int i;
    int l;
    l = strlen(y);
    
    if(l == 1 && y[0] == '0')
        return true;
    ds = i = 0;
    if(l % 2 != 0)
    {
        s[ds][0] = y[i++];
        s[ds][1] = 0;
        ds++;
    }
    while(i < l)
    {
        s[ds][0] = y[i++];
        s[ds][1] = y[i++];
        s[ds][2] = 0;
        ds++;
    }
    return false;
}
/**/
void addstr(char s2[])
{
    int i,j;
    i = 0;
    
    while(s2[i])
        str[lstr++] = s2[i++];
    
    str[lstr] = 0;
    
    for(i=0;i<lstr;i++)
        if(str[i] != '0')
        {
            for(j=0;i<lstr;j++,i++)
                str[j] = str[i];
            str[j] = 0;
            lstr = j;
            break;
        }
    if(str[0] == '0')
        lstr = 0;
}
/**/
int mul(char s1[],char s2[],int l1,int l2,char s3[])
{
    int i,j;
    int l;
    int arr[2000];
    
    l = l1 + l2 + 5;
    for(i=l;i>=0;i--)
        arr[i] = 0;
    l1--;
    l2--;
    
    for(i=0;i<=l1;i++)
        for(j=0;j<=l2;j++)
        {
            arr[i+j] += (s1[l1-i] - 48) * (s2[l2-j] - 48);
            if(arr[i+j] > 9)
            {
                arr[i+j+1] += arr[i+j] / 10;
                arr[i+j] %= 10;
            }
        }
    for(i=l;i>=0;i--)
        if(arr[i] != 0)
        {
            for(j=i;j>=0;j--)
                s3[i-j] = arr[j] + '0';
            s3[i+1] = 0;
            return (i+1);    
        }
        
    return 0;
}
/**/
bool chk(char s1[],char s2[],int l1,int l2)
{
    int i;
    if(l1 > l2)
        return true;
    if(l1 < l2)
        return false;
    i = 0;
    while(s1[i])
    {
        if(s1[i] > s2[i])
            return true;
        if(s2[i] > s1[i])
            return false;
        i++;
    }
    return false;
}
/**/
int tryadd(char s1[],int l)
{
    int i,j;
    int ltg;
    char tmp[2000];

    i = 0;
    while(i < 10)
    {
        sprintf(tmp,"%ld",i);
        ltg = l;
        j = 0;
        while(tmp[j])    
            s1[ltg++] = tmp[j++];
        //printf("Value of parameters: %s, %s, %d, %d, %s\n",s1, tmp, ltg, j, tmp);
        j = mul(s1,tmp,ltg,j,tmp);
        //printf("value of j %d\n",j);
        if(chk(tmp,str,j,lstr))
            break;
        i++;
    }
    i--;
    
    if(!i)
    {
        kq[len++] = '0';
        return 0;
    }
    sprintf(tmp,"%d",i);
    j = 0;
    printf("%s\n",tmp);
    while(tmp[j])
    {
        s1[l++] = tmp[j];
        kq[len++] = tmp[j];
        j++;
    }
    l = mul(s1,tmp,l,j,s1);
    return l;
}
/**/
int sub(char s1[],char s2[],int l1,int l2, char s3[])
{
    int i,j;
    int arr[2000];
    
    for(i=l1;i>=0;i--)
        arr[i] = 0;
    l1--;
    l2--;
    for(i=0;i<=l1;i++)
    {
        if(l2 >= 0)
        {
            arr[i] += (s1[l1-i] - 48) - (s2[l2] - 48);
            if(arr[i] < 0)
            {
                arr[i+1]--;
                arr[i] += 10;
            }
            l2--;
        }
        else
        {
            arr[i] += (s1[l1-i] - 48);
            if(arr[i] < 0)
            {
                arr[i+1]--;
                arr[i] += 10;
            }
        }
    }
    
    for(i=l1;i>=0;i--)
        if(arr[i] > 0)
        {
            for(j=i;j>=0;j--)
                s3[i-j] = arr[j] + 48;
            return (i+1);
        }
    s3[0] = '0';
    s3[1] = 0;
    return 1;
}
/**/
void solve()
{
    int i;
    int val;
    int ltmp,ltwo;
    char tmp[2000],two[3];
    
    if(chia()) 
    {
        printf("0\n");
        return;
    }
    
    i = 0;
    ltmp = 0;
    len = 0;
    lstr = 0;
    two[0] = '2';
    ltwo = 1;
    while(i < ds)
    {
        addstr(s[i]);
        //printf("What tha &#&Q$& is this, %s, %d, %d, %s\n", two, len, ltwo, tmp);
        ltmp = mul(kq,two,len,ltwo,tmp);
        //printf("ltmp %d\n",&ltmp);
        ltmp = tryadd(tmp,ltmp); // add number z after number tmp and mul z - > tmp_z * z  & update square root
        
        printf("Testing %s\n",kq);
        lstr = sub(str,tmp,lstr,ltmp,str);
        i++;        
    }
    kq[len] = 0;
    printf("%s\n",kq);
}
/**/
void input()
{
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%s",&y);
        solve();
        if(ntest)
            printf("\n");
    }
}
/**/

void generateCases(){
    int num = 50;
    srand(time(0));
    cout<<50<<endl<<endl;
    while(num--){
        int numdigits = (int) (rand()%1000)+1;
        bool firstDigit = true;
        int digitPos = 0;
        string bigNum = "";
        while(numdigits--){
            char c;
            if(firstDigit){
                while(true){
                    int digit = (int) (rand()%10);
                    if(!digit) continue;
                    c = digit+'0';
                    break;
                }
                firstDigit = false;
            }else{
                int digit = (int) (rand()%10);
                c = digit+'0';
            }
            bigNum = c + bigNum;
        }
        cout<<bigNum<<"\n\n";
    }
}

int main()
{
    //generateCases();
    input();
    return 0;
}