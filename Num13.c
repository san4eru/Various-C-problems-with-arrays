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

int maximum(int *A, size_t size)
{
    int max = A[0];
    for(int i = 0; i < size; ++i)
    {
        if(A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}

int minimum(int *A, size_t size)
{
    int min = A[0];
    for(int i = 0; i < size; ++i)
    {
        if(A[i] < min)
        {
            min = A[i];
        }
    }
    return min;
}

int one (int *A, int n_a, int *B, int n_b){
    int flag = -1;
    int a1 , b1, a2 , b2, mina, maxb;
    a1 = minimum(A, n_a);
    b1 = maximum(A, n_a);
    a2 = minimum(B, n_b);
    b2 = maximum(B, n_b);

    if (a1 < a2) mina = a1;
    else mina = a2;
    if (b1 > b2) maxb = b1;
    else maxb = b2;
    int flag_a, flag_b;
    int count = 0;
    for (int i = mina; i <= maxb; i++){
        flag_a = -1;
        flag_b = -1;
        for (int j = 0; j < n_a; j++){
            if (A[j] == i){
              flag_a = 1;
              break;
            }
        }
        for (int k = 0; k < n_b; k++){
            if (B[k] == i){
              flag_b = 1;
              break;
            }
        }
        if (flag_a + flag_b != -2){
            count++;
        }
    }
    int num = 0;
    if ((mina <= 0) && (maxb <= 0)){
        num = abs(maxb - mina) + 1;
    }
    else if ((mina <= 0) && (maxb > 0)){
        num = maxb - mina + 1;
    }
    else{
        num = maxb - mina + 1;
    }

    if (count == num) flag = 1;
    return flag;
}

int out_rez(int ans){
    FILE *mf;
    mf=fopen ("output.txt","w");
    if (mf == NULL) return -1;
    if (ans == 1) fprintf (mf,"YES");
    else fprintf (mf,"NO");
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
