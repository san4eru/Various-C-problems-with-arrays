#include<stdio.h>
#include<stdlib.h>

int read_num_A() {
    int k = 0;
    FILE *ptrfile;
    int s;
    ptrfile=fopen("ina.txt","r+");
    if (ptrfile == NULL) return -1;
    while ((fscanf(ptrfile, "%f",&s)!=EOF))
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
    while ((fscanf(ptrfile, "%f",&s)!=EOF))
    {    if(!ptrfile) break;
            k+=1;
    }
    fclose(ptrfile);
    return k;
}

float maximum(float *A, size_t size)
{
    float max = A[0];
    for(int i = 0; i < size; ++i)
    {
        if(A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}

float minimum(float *A, size_t size)
{
    float min = A[0];
    for(int i = 0; i < size; ++i)
    {
        if(A[i] < min)
        {
            min = A[i];
        }
    }
    return min;
}

int arrayUnique(float *ar, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size ; j++)
        {
            if ( ar[i] == ar[j] )
            {
                for (int k = j; k < size -1; k++)
                {
                    ar[k] = ar[k + 1];
                }
                size -= 1;

                if (ar[i] == ar[j])
                {
                 j--;
                }
            }
        }
    }
    return size;
}

int one (float *A, int n_a, float *B, int n_b){
    float a, b;
    int new_n_a, new_n_b;
    a = minimum(B, n_b);
    b = maximum(A, n_a);
    int k = 0, flag = -1;
    new_n_a = arrayUnique(A, n_a);
    new_n_b = arrayUnique(B, n_b);
    for (int i = 0; i < new_n_a; i++){
        flag = -1;
        if ((A[i] >= a) && (A[i] <= b)){
            for(int j = 0; j <new_n_b; j++){
                if (A[i] == B[j]) flag = 1;
            }
            if (flag == -1){
                k++;
            }
        }
    }
    for (int i = 0; i < new_n_b; i++){
        if ((B[i] >= a) && (B[i] <= b)){
                k++;
        }
    }
    return k;
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
    float *A = (float*) malloc(n_a*sizeof(float));
    FILE *ptrfile;
    ptrfile=fopen("ina.txt","r+");
    if (ptrfile == NULL) return -1;
    for(int i=0;i<n_a;i++)
    {
        fscanf(ptrfile, "%f",&A[i]);
    }
    fclose(ptrfile);

    float *B = (float*) malloc(n_b*sizeof(float));
    ptrfile=fopen("inb.txt","r+");
    if (ptrfile == NULL) return -1;
    for(int i=0;i<n_b;i++)
    {
        fscanf(ptrfile, "%f",&B[i]);
    }
    fclose(ptrfile);

    int ans;
    ans = one(A, n_a, B, n_b);

    out_rez(ans);
    if (out_rez(ans) == -1) return -1;
    return 0;
}
