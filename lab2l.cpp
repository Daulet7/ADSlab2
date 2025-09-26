# include <iostream>
# include <algorithm>
# include <cassert>
 
using namespace std;
 
struct Node {
  int val;
  Node *next;
 
  Node() {
    val = 0;
    next = NULL;
  }
 
};
 
 
 
int findMaxSum(int n, Node *head) {
	int sum = head->val;
    int maxsum = head->val;
    Node *c = head->next;
    for(int i = 0; i<n-1; i++){
        sum = max(c->val, sum+c->val);
        maxsum = max(maxsum, sum);
        c=c->next;
    }
    return maxsum;
 
}
 
int main() {
  int n;
  cin >> n;
 
  Node *head, *tail;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    Node *cur = new Node();
    cur -> val = x;
 
    if (i == 1) {
      head = tail = cur;
    } else {
      tail -> next = cur;
      tail = cur;
    }
  }
 
  cout << findMaxSum(n, head) << "\n";
  return 0;
}