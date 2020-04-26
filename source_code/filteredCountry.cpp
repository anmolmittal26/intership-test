#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0)
#define File freopen("filteredCountry.csv" , "r" , stdin); freopen("lowestPrice.csv" , "w" , stdout)
#define mod 1000000007
#define pi pair<ll, ll>
#define pb(x) push_back(x);

void read_record() {

  File;
  std::string row = "";
  ll k = 0;
  std::vector<std::string> v;

  while ((getline(cin, row))) {

    if(k == 0){
      std::cout << row << '\n';
    }
    else{

      ll j = row.size() - 1;
      std::string xx = "";

      while (row[j] != ',') {
        xx += row[j];
        --j;
      }
      reverse(xx.begin(), xx.end());
      if(xx.size() >= 3 && xx[0] == 'U' && xx[1] == 'S' && xx[2] == 'A')
      std::cout << row << '\n';
    }
    ++k;
  }
}

int main(int argc, char const *argv[]) {

  read_record();
}
