#include <iostream>
using namespace std;

long long Euclid(long long, long long);
void extended_Eiclid(long long &d, long long &y, long long, long long);
long long pow_bin(long long, long long, long long);

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  string messege;
  long long p, q, e_start, e;
  cin >> p >> q >> e_start >> messege;
  long long n = p * q;
  long long f = (p - 1) * (q - 1);
  for (e_start; ; e_start++){
    if (Euclid(f, e_start) == 1){
      e = e_start;
      break;
    }
  }
  long long d = 0, y = 0, answer = 0;
  extended_Eiclid(d, y, f, e);
  cout << "Private: " << ((d % f + f) % f) << " " << n << endl;
  cout << "Public: " << e  << " " << n << endl;
  cout << "Initial bytes: ";
  for (int i : messege){
    cout << i << " ";
    answer = (answer << 8) + i;
  }
  cout << "\n";
  answer = pow_bin(answer, e, n);

  long long count = -1;
  for (long long i = answer; i; i >>= 8){
    count += 1;
  }
  cout << "Encrypted bytes: ";
  while (count >= 0){
    cout << (answer >> (8*count)) % 256 << " ";
    count -= 1;
  }
  return 0;
}

void extended_Eiclid(long long &d, long long &y, long long a, long long b){
  if (b == 0){
      d = 0; 
      y = 1;
      return;
    }
    extended_Eiclid(d, y, b, a % b);
    long long del = d;
    d = y - ((a / b) * d); 
    y = del;
}
long long Euclid(long long a, long long b){
  if (b == 0)
    return a;
  else
    return Euclid(b, a % b);
}

long long pow_bin(long long x, long long y, long long n){
  long long answer = 1;
  while (y){
    if (y % 2)
      answer  = ((__int128)answer * x) % n;
    x = ((__int128)x * x) % n;
    y /= 2;
  }
  return answer;
}