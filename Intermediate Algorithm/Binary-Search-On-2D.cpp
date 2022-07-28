#include<iostream>
///Name: Surafel Fantu ID: VN2703

using namespace std;

/**7C Can we design a better algorithm than these?
This is additional assignment. You have to provide the code.*/

void binarySearch(int **matrix, int r1, int r2,int c1, int c2, int sk,int &r,int &c)
{
        int i = r1 + (r2-r1 )/2;
        int j = c1 + (c2-c1 )/2;
        if (matrix[i][j] == sk){
            r=i;
            c=j;
        }
        else
        {
            if (i != r2 || j != c1)
                binarySearch(matrix, r1, i, j, c2, sk,r,c);
            if (r1 == r2 && c1 + 1 == c2) {
                if (matrix[r1][c2] == sk){
                    r=r1;
                    c=c2;
                }

            }
            if (matrix[i][j] < sk){
                if (i + 1 <= r2)
                    binarySearch(matrix, i + 1, r2, c1, c2, sk,r,c);
            }
            else
            {
                if (j - 1 >= c1)
                    binarySearch(matrix, r1, r2, c1, j - 1,sk,r,c);
            }

        }
    }
int main()
{
    int **a, r,c;
    a= new int *[7];
    for(int i=0; i<7; i++)
        a[i]= new int[6];
    a[0][0]=1;a[0][1]=33; a[0][2]=55; a[0][3]=78; a[0][4]=100; a[0][5]=131;
    a[1][0]=10;a[1][1]=36; a[1][2]=57; a[1][3]=80; a[1][4]=106; a[1][5]=136;
    a[2][0]=17;a[2][1]=39; a[2][2]=61; a[2][3]=83; a[2][4]=107; a[2][5]=149;
    a[3][0]=23;a[3][1]=45; a[3][2]=67; a[3][3]=84; a[3][4]=110; a[3][5]=153;
    a[4][0]=27;a[4][1]=49; a[4][2]=70; a[4][3]=87; a[4][4]=115; a[4][5]=158;
    a[5][0]=30;a[5][1]=51; a[5][2]=74; a[5][3]=93; a[5][4]=121; a[5][5]=162;
    a[6][0]=32;a[6][1]=53; a[6][2]=76; a[6][3]=97; a[6][4]=127; a[6][5]=167;
    int sk = 76;

    binarySearch(a, 0, 7 - 1, 0, 6 - 1, sk,r,c) ;
    (r<=6&&c<=7)?cout<<sk<<" is found  at row "<< r <<" and column " << c<<endl:cout<<"NOT FOUND";
    return 0;
}

