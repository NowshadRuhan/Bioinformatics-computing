#include<bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    int k;

    cin>> str;
    cin>> k;

    map<string, int> k_mer;
    map<string, int>::iterator iterator1;
    int l = str.size();


    int max1 = 0;
    for(int i=0; i<=(l-k); i++){

        string check = "";
        for(int j=i; j<i+k; j++){

            check.push_back(str[j]);
        }

        k_mer[check]++;

        if(max1 <k_mer[check]){

            max1 = k_mer[check];
        }

    }
    cout<<"Max k-mer item is :"<<max1<<endl;
    for(iterator1=k_mer.begin(); iterator1!=k_mer.end(); iterator1++ ){

        if(iterator1->second==max1){
            cout<<"k-mer String :"<<iterator1->first<<endl;
        }
    }

    return 0;
}
