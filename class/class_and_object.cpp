#include <iostream>
using namespace std;

class ayam {
	public:
		string warna;
		ayam(){}
		void coklat(){ cout<<"ayam coklat\n"; }
		void putih();
		void bedawarna(){ cout<<"ayam "<<warna<<endl; }
		~ayam(){}
};

void ayam::putih() {
	cout<<"ayam putih";
}

main() {
	ayam Ayam;
	Ayam.coklat();
	Ayam.warna = "hitam";
	Ayam.bedawarna();
}
