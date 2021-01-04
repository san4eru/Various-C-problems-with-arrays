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

void Sort(float *A, size_t size) {
    size_t i, j;
    float tmp;
    for (i = 1; i < size; i++) {
        for (j = 1; j < size; j++) {
            if (A[j] > A[j-1]) {
                tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
            }
        }
    }
}

int min (int a, int b){
    if (a < b) return a;
    else return b;
}

int one (float *A, int n_a, float *B, int n_b){
    int flag = -1;
    int c1 = 0;
    for (int i = 0; i < min(n_a, n_b); i++){
        if (A[i] < B[i]) c1++;
    }
    flag = c1;
    return flag;
}

int two (float *A, int n_a, float *B, int n_b){
    int flag = -1;
    int c2 = 0;
    for (int i = 0; i < min(n_a, n_b); i++){
        if (A[i] > B[i]) c2++;
    }
    flag = c2;
    return flag;
}

int out_rez(FILE *mf, int ans){
    if (mf == NULL) return -1;
    fprintf (mf,"%d\n", ans);
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

    Sort(A, n_a);
    Sort(B, n_b);

    int ans1, ans2;
    ans1 = one(A, n_a, B, n_b);
    ans2 = two(A, n_a, B, n_b);
    FILE *mf;
    mf=fopen ("output.txt","w");
    out_rez(mf, ans1);
    out_rez(mf, ans2);
    fclose (mf);
    return 0;
}
