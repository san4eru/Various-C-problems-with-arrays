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

int one (int *A, int n_a, int *B, int n_b){
    int c = 0;
    int flag = 1;
    for (int i = 0; i < n_a; i++){
        c = A[i] - B[i];
        for (int j = i+1; j < n_a; j++){
            if (c = A[j] - B[j]){
                flag = -1;
                break;
            }
        }
    }
    if (flag == 1) return 1;
    else return 0;
}

int out_rez(FILE *mf, int ans){
    if (mf == NULL) return -1;
    if (ans == 1){
        fprintf (mf,"YES ");
    }
    else{
        fprintf (mf,"NO ");
    }
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
    ptrfile=fopen("inb.txt","r+");
    if (ptrfile == NULL) return -1;
    for(int i=0;i<n_b;i++)
    {
        fscanf(ptrfile, "%d",&B[i]);
    }
    fclose(ptrfile);

    int anw;

    FILE *mf;
    mf=fopen ("output.txt","w");

    anw = one(A, n_a, B, n_b);
    out_rez(mf, anw);

    Sort(A, n_a);
    Sort(B, n_b);

    anw = one(A, n_a, B, n_b);
    out_rez(mf, anw);

    fclose (mf);
    return 0;
}
