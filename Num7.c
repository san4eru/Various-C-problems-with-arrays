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

void Sort(int *A, size_t size) {
    size_t i, j;
    int tmp;
    for (i = 1; i < size; i++) {
        for (j = 1; j < size; j++) {
            if (A[j] < A[j-1]) {
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

int one (int *A, int n_a, int *B, int n_b){
    int flag = 0;
    int con = A[0] - B[0];
    for (int i = 0; i < min(n_a, n_b); i++){
        if ((A[i] - B[i]) != con){
            flag = -1;
            break;
        }
        else flag = 1;
    }
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
    float *A = (float*) malloc(n_a*sizeof(float));
    FILE *ptrfile;
    ptrfile=fopen("ina.txt","r+");
    if (ptrfile == NULL) return -1;
    for(int i=0;i<n_a;i++)
    {
        fscanf(ptrfile, "%d",&A[i]);
    }
    fclose(ptrfile);

    float *B = (float*) malloc(n_b*sizeof(float));
    ptrfile=fopen("inb.txt","r+");
    if (ptrfile == NULL) return -1;
    for(int i=0;i<n_b;i++)
    {
        fscanf(ptrfile, "%d",&B[i]);
    }
    fclose(ptrfile);

    Sort(A, n_a);
    Sort(B, n_b);

    int ans;
    ans = one(A, n_a, B, n_b);

    out_rez(ans);
    if (out_rez(ans) == -1) return -1;
    return 0;
}
