#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0)
#define File freopen("filteredCountry.csv" , "r" , stdin); freopen("lowestPrice.csv" , "w" , stdout)
#define mod 1000000007
#define pi pair<ll, ll>
#define pb(x) push_back(x);

void read_record() {

  freopen("filteredCountry.csv" , "r" , stdin);
  freopen("lowestPrice.csv" , "w" , stdout);
  
  std::map<ll, multiset<double>> mp;
  std::string row = "";
  ll k = 0;
  std::vector<std::string> v;

  while ((getline(cin, row))) {

    if (k == 0) {
      std::cout << "SKU,FIRST_MINIMUM_PRICE,SECOND_MINIMUM_PRICE" << '\n';
    } else {

      ll count = 0;
      std::string xx = "";
      ll sku, price;

      for (ll i = 0; row[i]; i++) {
        if(row[i] == '"'){
          ll j = i+1;
          while (row[j] != '"') {
            ++j;
          }
          i = j;
        }
        else{
          if (row[i] == ',') {

            ++count;
            if(count == 1){

              xx = "";
              ll j = i-1;

              while (j >= 0 && row[j] != ',') {
                xx += row[j];
                --j;
              }
              reverse(xx.begin(), xx.end());
              sku = stoi(xx);
            }
            else if(count == 6){
              xx = "";
              ll j = i-1;

              while (j >= 0 && row[j] != ',') {
                xx += row[j];
                --j;
              }
              reverse(xx.begin(), xx.end());
              string temp = "";

              for(ll i = 1; xx[i]; i++){
                temp += xx[i];
              }
              mp[sku].insert(stof(temp));
              break;
            }
          }
        }
      }
    }
    ++k;
  }
  auto it = mp.begin();
  while(it != mp.end()){

    std::cout << it->first<<",";

    auto tt = mp[it->first].begin();

    if(mp[it->first].size() == 1)
    std::cout << (*tt)<<","<<(*tt);
    else{
      std::cout << (*tt)<<",";
      ++tt;
      std::cout << (*tt);
    }
    std::cout << '\n';
    ++it;
  }
}

int main(int argc, char const *argv[]) {

  read_record();
}
