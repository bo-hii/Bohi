//آزمون پایانترم برنامه نوبسي
// بهاره دهقاني
//40011973
//۱۴۰۰/۱۱/۵
//سوال سوم

#include <string.h>
#include <iostream>
using namespace std;
//-------------------------
void original_key(char lock[], char o_key[]);
bool key_open_lock_or_no(char lock[], char key[]);
//--------------------------
int main()
{
    int n;
    char lock[50], key[50][50];
    cout<<"enyrt lock : ";
    cin >> lock;
    cout<<"\n enyrt number of keys : ";
    cin >> n;
    cout<<"\n enter keys : \n";
    for (int i = 0; i < n; i++)
    {
        cin >> key[i];
    }
    cout<<"\nkeys : \n";
    for (int i = 0; i < n; i++)
    {
        if (key_open_lock_or_no(lock, key[i]))
            cout << key[i] <<"\t";
    }
    return 0;
}
//----------------------------
bool key_open_lock_or_no(char lock[], char key[])
{
    bool val;
    char o_key[50];
    int j = 0;
    original_key(lock, o_key);
    for (int i = 0; lock[i] != '\0' && key[j] != '\0'; i++)
    {
        if (o_key[i] == key[j])
        {
            j++;
        }
        else if(j>0)
        {
            i-=j;
            j = 0;
        }
    }
    if (j == strlen(key))
        return true;

    return false;
}
//-------------------------------
void original_key(char lock[], char o_key[])
{
    int i;
    for (i = 0; lock[i] != '\0'; i++)
    {
        if (lock[i] == 'X')
            o_key[i] = '_';
        else
            o_key[i] = 'A';
    }
    o_key[i] = '\0';
}