/**
 * @input A : Read only ( DON'T MODIFY ) 2D integer array
 * @input n11 : Integer array's ( A ) rows
 * @input n12 : Integer array's ( A ) columns
 *
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
int* spiralOrder(const int** A, int n11, int n12, int *len1) {
    *len1 = n11*n12;
    int* len=(int*)malloc(*len1 * sizeof(int));
    int i,j=0;
    int top=0,bottom=n11-1,left=0,right=n12-1;
    int dir=0;
    while(top<=bottom && left<=right){
        if(dir==0)
        {
            for(i=left;i<=right;i++)
            {
               len[j++] = A[top][i];
            }
            top++;
        }
        else if(dir==1)
        {
            for(i=top;i<=bottom;i++)
            {
               len[j++] = A[i][right];

            }
            right--;
        }
        else if(dir==2)
        {
            for(i=right;i>=left;i--)
            {
               len[j++] = A[bottom][i];

            }
            bottom--;
        }
        else if(dir==3)
        {
            for(i=bottom;i>=top;i--)
            {
               len[j++] = A[i][left];

            }
            left++;
        }
        dir=(dir+1)%4;
    }
    return len;
}
