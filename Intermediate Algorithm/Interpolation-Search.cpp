#include <iostream>
#include <ctime>
///Name: Surafel Fantu ID: VN2703

using namespace std;

/**18.An interpolation search is a rarely used search. This search assumes that the
data must not only be sorted, but it must also be fairly uniformly distributed.
For example, a phone book is fairly uniformly distributed. The interpolation search
requires that we spend more time to make an accurate guess of where the item might be.
The binary search always uses the midpoint. However, searching for Bekele Dawit  in
the middle of the phone book would be silly; somewhere near the start clearly would be
more appropriate. Thus, instead of mid, we use next to indicate the next item that we
will try to access. The applicable formula is

            next=low+[(x-a[low])/(a[high]-a[low] )*[high-low-1]

The subtraction of 1 is a technical adjustment that performs well in practice.
Write the interpolation search algorithm. And analyze the algo performance.
*/
int interpolationSearch(int db[], int size, int sk)
{
    int low = 0, high = (size - 1);///1+2=3
   // int count=0;
    while (low <= high && sk >= db[low] && sk<= db[high])///11
    {
        //cout<<++count<<endl;
        if (low == high){///1
            if (db[low] == sk)///4
                return low;
            return -1;
        }
        int position = low + (((double)(high - low-1) / (db[high] - db[low])) * (sk - db[low]));///19
        //cout<<"position "<<position<<endl;
        if (db[position] == sk)///4
            return position;

        (db[position] < sk)?low = position + 1:high = position - 1;///6

    }
    return -1;///1
}
int main()
{
    int *db,sk,size,i;
    cout<<"Number of elements in the array: ";
    cin>>size;
    db=new int[size];
    if(!db){
        cout << "Insufficient memory!!!"<<endl;
        system("pause");
        return 1;
    }
    for(i=0;i<size;i++)
        db[i]=i*2;
    cout<<"\nChoose an element to be searched in the range from "<<0<<" to "<<(i-1)*2<<": ";
    cin>>sk;
    int index = interpolationSearch(db, size, sk);
    (index != -1)?cout << "\nElement found at index " << index:cout << "\nElement not found.";
    cout<<endl;
    return 0;
}
