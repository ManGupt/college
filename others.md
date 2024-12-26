```

#include <iostream>

namespace std {
	template<>
	void swap<int>(int &i, int &j) {
		using std::swap;
		std::cout << "My Swap in std\n";
		long tmp = i;
		i = j;
		j = tmp;
	}
}

void swap(long &i, long &j) {
	using std::swap;
	std::cout << "My Swap in ::\n";
	int ii = static_cast<int>(i);
	int jj = static_cast<int>(j);
	swap(ii, jj);
}

void swapint() {
	using std::swap;
	int a, b, c;
	a = 1;
	b = 2;
	c = 3;
	std::cout << "Start" << std::endl;
	std::cout << a << " " << b << " " << c << std::endl;
	swap(a, b);
	std::cout << a << " " << b << " " << c << std::endl;
	swap(b, c);
	std::cout << a << " " << b << " " << c << std::endl;
	swap(c, a);
	std::cout << a << " " << b << " " << c << std::endl;
	std::cout << "End" << std::endl;
}

void swaplong() {
	using std::swap;
	long a, b, c;
	a = 1;
	b = 2;
	c = 3;
	std::cout << "Start" << std::endl;
	std::cout << a << " " << b << " " << c << std::endl;
	::swap(a, b);
	std::cout << a << " " << b << " " << c << std::endl;
	swap(b, c);
	std::cout << a << " " << b << " " << c << std::endl;
	swap(c, a);
	std::cout << a << " " << b << " " << c << std::endl;
	std::cout << "End" << std::endl;
}

int main() {
	swapint();
	swaplong();
	return 0;
}

```
```
// Recursive C++ program to generate all binary strings
// formed by replacing each wildcard character by 0 or 1
#include <iostream>
using namespace std;

// Recursive function to generate all binary strings
// formed by replacing each wildcard character by 0 or 1
void print(string str, int index)
{
    if (index == str.size())
    {
        cout << str << endl;
        return;
    }

    if (str[index] == '?')
    {
        // replace '?' by '0' and recurse
        str[index] = '0';
        print(str, index + 1);

        // replace '?' by '1' and recurse
        str[index] = '1';
        print(str, index + 1);

        // No need to backtrack as string is passed
        // by value to the function
    }
    else
        print(str, index + 1);
}

// Driver code to test above function
int main()
{
    //string str = "1??0?101";
    string str = "????????";

    print(str, 0);

    return 0;
}

```
```
#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>

// Handle Excel columns
// replace ? in partial fill string
// Lexical order generation
// power set generation 

const int n = 2;
char ch[n+1] = "01";

std::string gen(uint64_t i, int s) {
	std::string res(s, '0');
	int x = 0;
	while (i) {
		res[x++] = ch[(i) % n];
		i /= n;
	}
	return res;
}

void print(std::string str) {
	std::vector<int> pos;
	size_t n = str.size();
	for (size_t i = 0; i < n; ++i) {
		if (str[i] == '?') {
			pos.push_back(i);
		}
	}
	size_t pn = pos.size(), pow = 1;
	size_t tmp = pn;
	while (tmp-- != 0) pow *= 2;
	for (size_t i = 0; i < pow; ++i) {
		std::string res = gen(i, pn);
		//std::cout << res << std::endl;
		for (size_t j = 0; j < res.size(); ++j) {
			str[pos[j]] = res[j];
		}
		std::cout << str << std::endl;
	}
}

int main() {
	std::string str = "????????";
	print(str);
	return 0;
}

```
```
// Iterative C++ program to generate all binary
// strings formed by replacing each wildcard
// character by 0 or 1
#include <iostream>
#include <queue>
using namespace std;

// Iterative function to generate all binary strings
// formed by replacing each wildcard character by 0
// or 1
void print(string str)
{
    queue<string> q;
    q.push(str);

    while (!q.empty())
    {
        string str = q.front();

        // find position of first occurrence of wildcard
        size_t index = str.find('?');

        // If no matches were found,
        // find returns string::npos
        if(index != string::npos)
        {
            // replace '?' by '0' and push string into queue
            str[index] = '0';
            q.push(str);

            // replace '?' by '1' and push string into queue
            str[index] = '1';
            q.push(str);
        }

        else
            // If no wildcard characters are left,
            // print the string.
            cout << str << endl;

        q.pop();
    }
}

// Driver code to test above function
int main()
{
    string str = "????????";

    print(str);

    return 0;
}

```
```
#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
    int p = 0;
    int mid, left = 0, right = nums.size()-1;
    // find pivot point
    while (p < right && nums[p] < nums[p+1]) p++;
        p++;
    left = p, right = nums.size()-1;
    // binary /reverse binary around pivot
    while (left <= right) {
        mid = left + (right-left)/2;
        if (target == nums[mid]) return mid;
        if (target < nums[mid]) right = mid-1;
        else left = mid +1;
    }
    left = 0; right = p;
    while (left <= right) {
        mid = left + (right-left)/2;
        if (target == nums[mid]) return mid;
        if (target < nums[mid]) right = mid-1;
        else left = mid+1;
    }
    return -1;
}

int main() {
	vector<int> nums;
	nums.push_back(2);
	cout << search(nums, 4) <<endl;
}

```
```
#include <iostream> 

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode *nhead = head->next;
    ListNode *tmp = head;
    while (tmp != nullptr && tmp->next != nullptr) {
        ListNode *prev = tmp->next;
        tmp->next = prev->next;
        prev->next = tmp;
        tmp = tmp->next;
    }
    return nhead;
}

void print(ListNode *head) {
    while (head != nullptr) {
        cout << head-> val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    print (swapPairs(head));
    return 0;
}
```
```
```
```
```