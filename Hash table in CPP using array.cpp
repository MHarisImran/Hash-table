#include<iostream>
#include<string>
using namespace std;
class hashtable
{
    int size = 16;
    int arr[16];
    int count = 0;
public:
    void startArray()
        //Starts up the array
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = -9999;
        }
    }
    int hashFunction(int k)
        //used to get key value
    {
        return k % size;
    }
    void add(int k, int v)
    {
        int x = hashFunction(k);
        //For Inserting value on an Empty index
        if (arr[x] == -9999)
        {
            arr[x] = v;
            count++;
        }
        else {
            //Linear Probing due to collision
            for (int i = 0; i < size; i++)
            {
                if (arr[x] != -9999)
                {
                    while (arr[x + 1] == -9999)
                    {
                        x++;
                    }
                    arr[x] = v;
                }
            }
            count++;
        }
    }
    void Search(int k)
    {
        int x = hashFunction(k);
        if (arr[x] != -9999)
        {
            //Value Found 
            cout << "The value is : " << arr[x] << endl;
        }
        else {
            //Value Not Found Exception
            cout << "No value Found" << endl;
        }
    }
    void print()
    {
        cout << "Sr No." << endl;
        for (int i = 0; i < size; i++)
        {
            //Printing Values in regular way by showing their indeces 
            cout << i << ":- " << arr[i] << "\n";
        }
    }
    void deleteElement(int k)
    {
        int x = hashFunction(k);
        if (arr[x] == -9999)
        {
            //Already Empty space Exception
            cout << "The space is Already Empty . Nothing found ." << endl;
        }
        else {
            int y = arr[x];
            arr[x] = -9999;
            cout << "The element \"" << y << "\" is successfully deleted." << endl;
            count--;
        }
    }
  
};
int main()
{
    hashtable ht;  
    ht.startArray();
    //Adding key value Pair
    ht.add(0, 5);
    ht.add(1, 4);
    ht.add(4, 6);
    ht.add(5, 0);
    ht.add(8, 4);
    ht.add(13, 5);
    ht.add(11, 2);
    ht.add(12, 2);
    ht.add(15, 6);
    ht.print();
    //Searching on key base
    ht.Search(5);
    ht.Search(8);
    ht.Search(1);
    
    //Delete on key base
    ht.deleteElement(12);
    ht.print();
    
    return 0;
}