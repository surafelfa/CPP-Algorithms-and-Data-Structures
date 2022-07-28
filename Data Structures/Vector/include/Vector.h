#ifndef VECTOR_H
#define VECTOR_H


class Vector
{
    public:
        ///default constructor with no parameter which creates the empty vector.
        DynamicArray()
        {
            DynamicArray::db= new T[0];
            DynamicArray::size=0;
            DynamicArray::numberOfElements=0;
            //std::cout<<"called"<<std::endl;
        }
        /**A parameter constructor that create the array with specified size and
         with an initial default value.*/
        DynamicArray(int size, T initialValue)
        {
            DynamicArray::size=size;
            DynamicArray::db=new (std::nothrow) T[size];
            DynamicArray::numberOfElements=0;
            if(DynamicArray::db)
            {
                for(int i=0;i<size;i++)
                    DynamicArray::db[i]=initialValue;
            }
            else
            {
                std::cout << "Insufficient memory!!!"<<endl;
                system("pause");
            }


        }
        ///a copy constructor that creates a vector from already existing constructor.
        DynamicArray(const DynamicArray& other)
        {
            DynamicArray::size=other.size;
            DynamicArray::db=new (std::nothrow) T[other.size];
            if(DynamicArray::db)
            {
                for(int i=0;i<other.size;i++)
                    DynamicArray::db[i]=other.db[i];
                DynamicArray::numberOfElements=other.numberOfElements;
            }
            else
            {
                std::cout << "Insufficient memory!!!"<<endl;
                system("pause");
            }

        }
        ///a destructor the destroys the vector when it is out of scope
        ~DynamicArray()
        {
            delete [] DynamicArray::db;
        }
        ///insert before given index
        int Insert(T element, int index)
        {
            if(!DynamicArray::Full())
            {
                if(DynamicArray::numberOfElements>index && index >= 0){
                    for(int i=DynamicArray::numberOfElements;i>index;i--)
                        DynamicArray::db[i]=DynamicArray::db[i-1];
                    DynamicArray::db[index]=element;
                    DynamicArray::numberOfElements++;
                    return index;
                }
                //if the index is greater than or equal to the number of element in the
                //vector, the new element will be inserted at index [numberofelement].
                else if(DynamicArray::numberOfElements<=index&&DynamicArray::size>index){
                    DynamicArray::db[DynamicArray::numberOfElements]=element;
                    return DynamicArray::numberOfElements++;
                }
                return -1;
            }
            else
            {
                //when the database is full
                return -2;
            }
        }
        ///Erase element at a given position

        T Erase(int index)
        {
            if(DynamicArray::numberOfElements>index && index>=0){
                T erasedElement=DynamicArray::db[index];
                for(int i=index;i<numberOfElements-1;i++){
                    DynamicArray::db[i]=db[i+1];
                }
                DynamicArray::numberOfElements--;
                return erasedElement;
            }
            return NULL;
        }
        ///Erase range of elements between two index

        bool Erase(int fromIndex, int toIndex)
        {
            if(DynamicArray::numberOfElements > toIndex && fromIndex>=0 && (toIndex-fromIndex >= 0)){
                int numShift = (DynamicArray::numberOfElements-1)-toIndex;
                int i=0;
                while(numShift!=0){
                    DynamicArray::db[fromIndex+i] = DynamicArray::db[toIndex+i+1];
                    i++;
                    numShift--;
                }
                DynamicArray::numberOfElements = DynamicArray::numberOfElements-(toIndex-fromIndex+1);
                return true;// erasedElements;
            }
            return false;//NULL;
        }

        ///clear all elements
        void Clear()
        {
            for(int i=0;i<DynamicArray::numberOfElements;i++)
                DynamicArray::db[i]=0;
            DynamicArray::numberOfElements=0;
        }
        ///add an element at the end
        int Push_back(T element)
        {
            return DynamicArray<T>::Insert(element, DynamicArray::numberOfElements);
        }
        ///add an element to the beginning

        int Push_front(T element)
        {
            return DynamicArray<T>::Insert(element, 0);
        }
        ///remove from back

        T Pop_back()
        {
            T popedElement = DynamicArray::Erase(DynamicArray::numberOfElements-1);
            if(popedElement != NULL)
                return popedElement;
            return NULL;
        }
        ///remove from front

        T Pop_front()
        {
            T popedElement = DynamicArray::Erase(0);
            if(popedElement != NULL)
                return popedElement;
            return NULL;
        }
        /// get element at specified index

        T At(int index)
        {
            if(DynamicArray::numberOfElements > index && index >= 0)
                return DynamicArray::db[index];
            return NULL;
        }
        ///overloading [] operator
        T operator [](int index)
        {
            if(index>=DynamicArray::numberOfElements || index<0)
                return NULL;
            return DynamicArray::db[index];
        }

        ///check if vector is empty

        bool Empty()
        {
            if(DynamicArray::numberOfElements==0)
                return true;
            return false;
        }
        ///determining how many elements the vector support

        int Capacity()
        {
            return DynamicArray::size;
        }
        ///determining the number of element in the vector

        int Size()
        {
            return DynamicArray::numberOfElements;
        }
        ///check if the vector is full

        bool Full()
        {
            if(DynamicArray::numberOfElements == DynamicArray::size)
                return true;
            return false;
        }
        ///reserves a new memory destroying the previous vector

        bool Reserve(int size)
        {
            delete [] DynamicArray::db;
            DynamicArray::size=size;
            DynamicArray::db=new (std::nothrow) T[size];
            DynamicArray::numberOfElements=0;
            if(DynamicArray::db)
            {
                for(int i=0;i<size;i++)
                    DynamicArray::db[i]=0;
                return true;
            }
            else
            {
                //std::cout << "Insufficient memory!!!"<<endl;
                system("pause");
                return false;
            }

           // return true;
        }
        ///available space

        int Available()
        {
            return DynamicArray::size - DynamicArray::numberOfElements;
        }
        ///resize the capacity of the vector by n number

        bool Resize(int size)
        {
            T *temp = new (std::nothrow) T[DynamicArray::size+size];
            if(temp != NULL)
            {
                for(int i=0;i<DynamicArray::size;i++)
                {
                    temp[i]=DynamicArray::db[i];
                }
                delete [] DynamicArray::db;
                DynamicArray::db = temp;
                DynamicArray::size+=size;
                return true;
            }
            std::cout << "Insufficient memory!!!"<<endl;
            system("pause");
            return false;
        }
        ///reversing the elements

        void Reverse()
        {
            int i=0,j=DynamicArray::numberOfElements-1;
            T temp;
            while(i<=j){
                temp=DynamicArray::db[i];
                DynamicArray::db[i]=DynamicArray::db[j];
                DynamicArray::db[j]=temp;
                i++;
                j--;
            }
        }
        ///overloading the assignment operator

        bool operator = (const DynamicArray &other)
        {
            if(DynamicArray::size >= other.size)
            {
                for(int i=0;i<other.numberOfElements;i++)
                {
                    DynamicArray::db[i] = other.db[i];
                }
                DynamicArray::numberOfElements = other.numberOfElements;
                return true;
            }
            return false;
        }
        ///sorting the db using insertion sort

        void Sort()
        {
            T value;
            int tobe;
            for(int inserted=1;inserted<DynamicArray::numberOfElements;inserted++){
                value=DynamicArray::db[inserted];
                tobe=inserted;
                for(;tobe>0&&value<DynamicArray::db[tobe-1];tobe--){
                    DynamicArray::db[tobe] = DynamicArray::db[tobe-1];
                }
                DynamicArray::db[tobe] = value;
            }
        }
        ///returns the last element

        T Back()
        {
            return DynamicArray::db[DynamicArray::numberOfElements-1];
        }
        ///returns the first element

        T Front()
        {
            return DynamicArray::db[0];
        }
        ///destroy the current vector and create a new one with specified size and initial value

        bool Assign(int size, T initialValue)
        {
            delete [] DynamicArray::db;
            DynamicArray::size=size;
            DynamicArray::db=new (std::nothrow) T[size];
            DynamicArray::numberOfElements=0;
            if(DynamicArray::db)
            {
                for(int i=0;i<size;i++)
                    DynamicArray::db[i]=initialValue;
                return true;
            }
            else
            {
                //std::cout << "Insufficient memory!!!"<<endl;
                system("pause");
                return false;
            }

        }
        ///destroy the current vector and create a new one by taking all elements from another vector.

        bool Assign(const DynamicArray &other)
        {
            delete [] DynamicArray::db;
            DynamicArray::size=other.size;
            DynamicArray::db=new (std::nothrow) T[other.size];
            if(DynamicArray::db)
            {
                for(int i=0;i<other.size;i++)
                    DynamicArray::db[i]=other.db[i];
                DynamicArray::numberOfElements=other.numberOfElements;
                return true;
            }
            else
            {
                //std::cout << "Insufficient memory!!!"<<endl;
                system("pause");
                return false;
            }

        }
        ///destroy the current vector and create a new one by taking all elements from start index

        bool Assign(const DynamicArray &other, int startIndex)
        {
            delete [] DynamicArray::db;
            DynamicArray::size=other.size;
            DynamicArray::db= new (nothrow) T[other.size];
            if(DynamicArray::db)
            {
                if(startIndex>=0 && startIndex<other.numberOfElements)
                {
                    int i=0;
                    for(int j=startIndex;j<other.numberOfElements;i++,j++)
                    {
                        DynamicArray::db[i]=other.db[j];
                    }
                    DynamicArray::numberOfElements=i;
                    return true;
                }
                else
                {
                    //cout<<"index can not be negative.";
                    return false;
                }
            }
            else
            {
                //std::cout << "Insufficient memory!!!"<<endl;
                system("pause");
                return false;
            }

        }
        ///destroy the current vector and create a new one by taking all elements from start index to last index

        bool Assign(const DynamicArray &other, int startIndex, int lastIndex)
        {
            delete [] DynamicArray::db;
            DynamicArray::size=other.size;
            DynamicArray::db= new (nothrow) T[other.size];
            if(DynamicArray::db)
            {
                if(lastIndex>=startIndex && lastIndex>=0 && startIndex >=0 && lastIndex<other.numberOfElements)
                {
                   int i=0;
                   for(int j=startIndex;j<=lastIndex;i++,j++)
                    {
                        DynamicArray::db[i]=other.db[j];
                    }
                    DynamicArray::numberOfElements=i;
                    return true;
                }
                else
                {
                    //cout<<"index can not be negative.";
                    return false;
                }

            }
            else
            {
                //std::cout << "Insufficient memory!!!"<<endl;
                system("pause");
                return false;
            }

        }
    private:
        int numberOfElements=0,size;
        T *db;
};

#endif // VECTOR_H
