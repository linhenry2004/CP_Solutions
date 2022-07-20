#include <iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

// Traditional way to declare and ordered set: 
// When using in actual code, use ordered_set *data_structure_name*
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// Better way to declare and ordered set: 
// That way, we can store all kinds of datatypes inside the ordered set. 
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
  ordered_set<int> t;
  t.insert(8);
  t.insert(16);
  t.insert(4);
  t.insert(2);
  t.insert(10);
  t.insert(20);
  // 2 4 8 10 16 20

  // find the ith element
  cout << *t.find_by_order(1) << endl;
  // find the order of 8 (2 because 8 is the 2nd element)
  cout << t.order_of_key(8) << endl;
}