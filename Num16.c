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

int arrayUnique(int *ar, int size)
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

void one (int *A, int new_n_a, int *B, int new_n_b, FILE *mf){
    int flag = -1;
    for (int i = 0; i < new_n_a; i++){
        flag = -1;
        for(int j = 0; j < new_n_b; j++){
            if (A[i] == B[j]) flag = 1;
        }
        if (flag == -1){
            out_rez(mf, A[i]);
        }
    }
}

int out_rez(FILE *mf,int ans){
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

    Sort(A, n_a);
    Sort(B, n_b);

    int new_n_a, new_n_b;
    new_n_a = arrayUnique(A, n_a);
    new_n_b = arrayUnique(B, n_b);

    FILE *mf;
    mf=fopen ("output.txt","w");
    if (mf == NULL) return -1;
    out_rez(mf, new_n_a);
    out_rez(mf, new_n_b);

    one(A, new_n_a, B, new_n_b, mf);
    fclose (mf);
    return 0;
}
