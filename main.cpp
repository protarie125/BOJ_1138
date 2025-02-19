#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

ll n;
vl ct;
list<ll> ans;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n;
  ct = vl(n);
  for (auto&& x : ct) {
    cin >> x;
  }

  ans = list<ll>{};
  ans.push_back(n);
  for (auto i = n - 1; 1 <= i; --i) {
    const auto& j = i - 1;
    const auto& x = ct[j];
    if (ans.size() == x) {
      ans.push_back(i);
    } else {
      const auto& w = next(ans.begin(), x);
      ans.insert(w, i);
    }
  }

  for (const auto& p : ans) {
    cout << p << ' ';
  }

  return 0;
}