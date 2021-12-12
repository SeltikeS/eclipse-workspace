//============================================================================
// Name        : Sqr.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <sstream>
using namespace std;

template<typename T> T Sqr(T x);

template<typename T>
vector<T> Sqr(const vector<T>&);

template<typename Key, typename Value>
map<Key, Value> Sqr(const map<Key, Value>&);

template<typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second>&);











template<typename T>
T Sqr(T x)
{
    return x * x;
}

template<typename T>
vector<T> Sqr(const vector<T>& v)
{
    vector<T> new_v;
    for(const auto& i : v)
    {
        new_v.push_back(Sqr(i));
    }
    return new_v;
}

template<typename Key, typename Value>
map<Key, Value> Sqr(const map<Key, Value>& m)
{
    map<Key, Value> new_m;
    for(const auto& i : m)
    {
        new_m[i.first] = Sqr(i.second);
    }
    return new_m;
}

template<typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second>& p)
{
    pair<First, Second> new_p =  { Sqr(p.first), Sqr(p.second) };
    return new_p;
}

//template<typename T> string Join(const T&, char);
//
//template<typename T> string Join(const T& c, char d) {
//    stringstream ss;
//    bool first = true;
//    for(const auto& i : c) {
//        if(!first) {
//            ss << d;
//        }
//        first = false;
//        ss << i;
//    }
//    return ss.str();
//}
//
//template <typename First, typename Second>
//ostream& operator<<(ostream& out, const pair<First, Second>& p) {
//
//    return out << '(' << p.first << ',' << p.second << ')';
//}
//
//template <typename T>
//ostream& operator<<(ostream& out, const vector<T>& v) {
//    return out << '[' << Join(v, ',') << ']';
//}
//
//template <typename First, typename Second>
//ostream& operator<<(ostream& out, const map<First, Second>& m) {
//    return out << '{' << Join(m, ',') << '}';
//}
//


int main()
{
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
      cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
      {4, {2, 2}},
      {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
      cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
    return 0;
}
