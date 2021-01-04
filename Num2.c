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

int one (float *A, int n_a, float *B, int n_b){
    int flag = -1;
    int k_y = 0, k_n = 0;
    if (n_a == n_b){
        for (int i = 0; i < n_a; i++){
            if (A[i]<B[i]) k_y++;
            else{
                k_n++;
            }
        }
    }
    else{
        if(n_a > n_b){
            for (int i = 0; i < n_b; i++){
                if (A[i]<B[i]) k_y++;
                else{
                    k_n++;
                }
            }
        }
        else{
            for (int i = 0; i < n_a; i++){
                if (A[i]<B[i]) k_y++;
                else{
                    k_n++;
                }
            }
        }
    }
    if (k_y > k_n) flag = 1;
    else flag = 0;
    return flag;
}

int out_rez(int ans){
    FILE *mf;
    mf=fopen ("output.txt","w");
    if (mf == NULL) return -1;
    if (ans == 1){
        fprintf (mf,"YES");
    }
    else{
        fprintf (mf,"NO");
    }
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

    Sort(A, n_a);
    Sort(B, n_b);
    int ans;
    ans = one(A, n_a, B, n_b);

    out_rez(ans);
    if (out_rez(ans) == -1) return -1;
    return 0;
}
