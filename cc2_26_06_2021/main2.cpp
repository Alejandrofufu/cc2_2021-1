#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

//functores 

class Line{
    private:
        double a;
        double b;
    public:
        Line(int a_,int b_){
            a=a_;
            b=b_;
        }
        int operator()(int x){
            return a*x+b;
        }
};

template <class T>
class Less_tham{
    const T val;
    public:
    Less_tham(const T _val):val(_val){}
    bool operator()(const T x){return x<val;}
};

int increment(int x){return (x+1);}
class Incrementa{
private:
    int a;
public:
    Incrementa(int _a):a(_a){}
    int operator()(int x){return a+x;}
};

class Multiplo{
private:
    int x;
public:
    Multiplo(int _x):x(_x){};
    bool operator()(int y){
        if(y%x==0)
            return true;
        return false;
    }
};
template <typename T>
std::vector<int>find_matching_numbers(std::vector<int>vec,Multiplo m){
    std::vector<int> ret_vec;
    std::vector<int>::iterator itr= vec.begin(),end = vec.end();
    while(itr !=end){
        if(m(*itr))
            ret_vec.push_back(*itr);
        ++itr;            
    }
    return ret_vec;
};


int main(){
    Line linea(20.0,15.2);
    cout<<linea(15);
    //
    Less_tham <float >lt(100.3);
    bool b1= lt(50.2);
    cout<<b1<<"\n";
    //
    int arr[] = {1,2,3,4,5};

    Incrementa inc(3);
    //transform(arr,arr+5,arr,inc);
    for(int i = 0;i<5;i++){
        std::cout<<arr[i]<<" ";
    }
    cout<<"\n";
    //
    Multiplo m1(2);
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(4);
    vec.push_back(6);
    vec.push_back(9);
    //std::vector<int> r= find_matching_numbers(vec,m1);
    std::vector<int>::iterator itr = r.begin(),end=r.end();
    while(itr != end){
        std::cout<< *itr<<" ";
        ++itr;
    }
    std::cout<<"\n";

    return 0;
}
