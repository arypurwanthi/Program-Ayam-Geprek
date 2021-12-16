# Program-Ayam-Geprek
Program Kasir dengan Bahasa C
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct kasir{
	char nama[20];
	char alamat[20];
	int umur;
	char telp[15];
	char user[20];
	char pass[20];
};

void regis(){
struct kasir k1;
  printf("Nama		:");
	scanf("%s", &k1.nama);
	printf("Alamat		:");
	scanf("%s", &k1.alamat);
	printf("Umur		:");
	scanf("%d", &k1.umur);
	printf("No Hp		:");
	scanf("%s", &k1.telp);
	printf("Buat Username	:");
	scanf("%s", &k1.user);
	printf("Buat Password	:");
	scanf("%s", &k1.pass);
}
  
int main(){
  char user[20]; 	//input user pegawai
  char pass[20]; 	//input password pegawai
  char ulang;		//mengulangi proses login ketika salah username dan atau password
  char kembali;		//kembali mengulang kasir
}
