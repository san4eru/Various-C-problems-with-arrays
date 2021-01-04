#include<stdio.h>
#include<stdlib.h>

int read_num_A() {
    int k = 0;
    FILE *ptrfile;
    int s;
    ptrfile=fopen("ina.txt","r+");
    if (ptrfile == NULL) return -1;
    while ((fscanf(ptrfile, "%d",&s)!=EOF))
    {    if(!ptrfile) break;
            k+=1;
    }
    fclose(ptrfile);
    return k;
}

int read_num_B() {
    int k = 0;
    FILE *ptrfile;
    int s;
    ptrfile=fopen("inb.txt","r+");
    if (ptrfile == NULL) return -1;
    while ((fscanf(ptrfile, "%d",&s)!=EOF))
    {    if(!ptrfile) break;
            k+=1;
    }
    fclose(ptrfile);
    return k;
}

int MaxRepear(int *A, int n_a){
    int count = 0,count1 = 0,max = 0;
    for (int i = 0; i < n_a; i++){
        for (int j = 0; j < i; j++){
            if (A[i] == A[j])
                count++;
        }
        if (count == 0){
            for (int k = i; k < n_a; k++){
                if (A[k] == A[i]){
                    count1++;
                }
            }
            if (count1 > max)
                max = count1;
            count1 = 0;
        }
        count = 0;
    }
    return max;
}

int one (int *A, int n_a, int *B, int n_b){
    int flag = -2;
    int a, b;
    a = MaxRepear(A, n_a);
    b = MaxRepear(B, n_b);
    if (a > b) flag = 1;
    else
        if (a < b) flag = -1;
        else flag = 0;
    return flag;
}

int out_rez(int ans){
    FILE *mf;
    mf=fopen ("output.txt","w");
    if (mf == NULL) return -1;
    fprintf (mf,"%d", ans);
    fclose (mf);
    return 0;
}

int main()
{
    int n_a = read_num_A();
    if (n_a == -1) return -1;
    int n_b = read_num_B();
    if (n_b == -1) return -1;
    int *A = (int*) malloc(n_a*sizeof(int));
    FILE *ptrfile;
    ptrfile=fopen("ina.txt","r+");
    if (ptrfile == NULL) return -1;
    for(int i=0;i<n_a;i++)
    {
        fscanf(ptrfile, "%d",&A[i]);
    }
    fclose(ptrfile);

    int *B = (int*) malloc(n_b*sizeof(int));
    int k;
    ptrfile=fopen("inb.txt","r+");
    if (ptrfile == NULL) return -1;
    for(int i=0;i<n_b;i++)
    {
        fscanf(ptrfile, "%d",&B[i]);
    }
    fclose(ptrfile);

    int ans;
    ans = one(A, n_a, B, n_b);

    out_rez(ans);
    if (out_rez(ans) == -1) return -1;
    return 0;
}
