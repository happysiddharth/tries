#include<iostream>
using namespace std;
int main() {
	long long n1,n2;
	cin>>n1>>n2;
	long long gcd;
	for(int i=1;i<=n1 and i<=n2;i++){
		if(n1%i==0 and n2%i==0){
			gcd = i;
		}
	}
	cout<<gcd<<endl;
	return 0;
}
