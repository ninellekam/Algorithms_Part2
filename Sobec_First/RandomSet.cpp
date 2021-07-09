#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <vector>

using namespace std;


class RandomizedSet {
public:
	/** Initialize your data structure here. */
	//we will require to store the element in an array such that getRandom() will be don in O(1) time
	vector<int> v;
	//we will need a map to store key value and corresponding index of the array
	unordered_map<int,int> u;
	RandomizedSet() {

	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if(u.find(val) != u.end())
			return false;
		v.push_back(val);
		u[val]=v.size()-1;
		return true;

	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if(u.find(val) == u.end())
			return false;
		int i=u[val];
	   swap(v[i],v[v.size()-1]);
		v.pop_back();
		u[v[u[val]]]=i;
		u.erase(val);
		return true;


	}

	/** Get a random element from the set. */
	int getRandom() {
		int random = rand()%(v.size());
		return v[random];

	}
};