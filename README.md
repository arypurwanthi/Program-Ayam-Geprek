# Program-Ayam-Geprek
Program Kasir dengan Bahasa C
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void regis();		//deklarasi fungsi regis	
void login();		//deklarasi fungsi login
void menu(void);	//deklarasi fungsi menu
void pesan();		//deklarasi fungsi pesan		

struct kasir{
	char nama[20];
	char alamat[20];
	int umur;
	char telp[15];
	char user[20];
	char pass[20];
};

/*fungsi dengan argumen untuk proses registrasi*/
void regis(){
char simpan;	//untuk memilih simpan data registrasi atau tidak
	
isi_data:	//identifier isi_data
struct kasir k1;
	printf("\nREGISTRASI KASIR AYAM GEPREK '86'\n\n");
	printf("Masukkan Data Diri Anda\n");
	printf("---------------------------------------\n");
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
	printf("---------------------------------------\n");
	printf("\nSimpan Data (Y) Atau Ulang (U) ?");
	scanf("%s", &simpan);
	if(simpan=='Y'|| simpan=='y'){
		printf("Data Anda Telah Disimpan\n");
	}
	else {
		system("cls");
		goto isi_data;
	}
}

/*fungsi dengan argumen untuk login kasir*/
void login(){
	char user[20]; 	//input user pegawai
  	char pass[20]; 	//input password pegawai
  	char ulang;	//mengulangi proses login ketika salah username dan atau password
	do{
		printf("************Login Kasir**************\n");
		printf("\n Masukan Username	: ");
		scanf ("%s", user);
		printf("\n Masukan Password	: ");
		scanf ("%s", pass);
		printf("*************************************\n");

		if ((strcmp(user,"kasir1") == 0 && strcmp(pass, "ary")==0) || (strcmp(user,"kasir2") == 0 && strcmp(pass, "asty") == 0)){  
		printf ("\n=========Akses diterima==========\n\n");
		printf("Tekan ENTER untuk lanjut\n");
		system ("pause");
		system("cls");
		menu();
		pesan();
		}
		else if((strcmp(user,"kasir1")!=0 && strcmp(pass, "ary")!=0) || (strcmp(user,"kasir2")!=0 && strcmp(pass, "asty")!=0)){
		printf ("\nUsername atau Password salah \n");
		printf ("Coba lagi ? \n"); 
		printf ("Ya atau Tidak (Y/T): "); 
		scanf ("%s", &ulang);
			if(ulang=='Y'|| ulang=='y'){
			system("cls");
			}
			else{
				exit(0);
			}
		}
	}
	while (ulang=='Y'|| ulang=='y'); 
}

/*fungsi tanpa argumen untuk menampilkan menu makanan*/
void menu(void){
	printf(" Selamat Datang di Ayam Geprek'86' \n");
	printf("===================================\n");
	printf("|               MENU              |\n");
	printf("===================================\n");
	printf("|1. Dada                Rp 10.000 |\n");
	printf("|2. Paha                Rp 8.000  |\n");
	printf("|3. Sayap               Rp 6.000  |\n");
	printf("|4. Nasi                Rp 5.000  |\n");
	printf("|5. Minuman(EsTeh)      Rp 3.000  |\n");
	printf("===================================\n");
}

/*Fungsi dengan argumen untuk pemesanan dan struk*/
void pesan(){
  int jmlh_pesan;		//banyaknya pesanan berdasarkan jenis menu
  int i;			//variavel looping untuk pemesanan
  int kode;			//kode menu yang dipesanan
  int jumlah[10];		//jumlah pesanan per menu yang dipesan
  int harga_satuan[10];		//harga satuan menu
  int harga[20];		//harga satuan dikalikan jumlah pesan
  char nama[10][10];		//nama menu pesanan
  char kasir[10];		//nama kasir
  int total=0;			//total pembayaran semua pesanan
  time_t t;			//waktu pembayaran di kasir
  int cash;			//jumlah uang yang diberikan pembeli
  int kembalian;		//kembalian dari uang yang dibayar pembeli
  char kembali;			//kembali mengulang kasir untuk pembayaran kasir berikutnya		

  printf("\nJumlah jenis pesanan 	:");
  scanf("%d",&jmlh_pesan);
  for(i=0;i<jmlh_pesan;i++){
  	pesan:			// identifier pesan		
  	printf("\n");
  	printf("\nKode pesanan 		:");
	scanf("%d", &kode);
    	switch(kode){
	case 1:
	  printf("Nama pesanan 		:");
	  scanf("%s", &nama[i]);
	  printf("Jumlah pesanan	:");
	  scanf("%d", &jumlah[i]);
      	  harga_satuan[i]=10000;
	  printf("Harga satuan		:%d\n", harga_satuan[i]);
	  harga[i]= harga_satuan[i]*jumlah[i];
	  printf("Harga 		:%d\n", harga[i]);
	  break;
    	case 2:
      	  printf("Nama pesanan 		:");
      	  scanf("%s", &nama[i]);
	  printf("Jumlah pesanan 	:");
	  scanf("%d", &jumlah[i]);
      	  harga_satuan[i]=8000;
	  printf("Harga satuan 		:%d\n", harga_satuan[i]);
	  harga[i]= harga_satuan[i]*jumlah[i];
	  printf("Harga 		:%d\n", harga[i]);
	  break;
        case 3:
          printf("Nama pesanan 		:");
      	  scanf("%s", &nama[i]);
	  printf("Jumlah pesanan 	:");
	  scanf("%d", &jumlah[i]);
      	  harga_satuan[i]=6000;
	  printf("Harga satuan 		:%d\n", harga_satuan[i]);
	  harga[i]= harga_satuan[i]*jumlah[i];
	  printf("Harga 		:%d\n", harga[i]);
	  break;
	case 4:
	  printf("Nama pesanan 		:");
	  scanf("%s", &nama[i]);
	  printf("Jumlah pesanan 	:");
	  scanf("%d", &jumlah[i]);
      	  harga_satuan[i]=5000;
	  printf("Harga satuan 		:%d\n", harga_satuan[i]);
	  harga[i]= harga_satuan[i]*jumlah[i];
	  printf("Harga 		:%d\n", harga[i]);
	  break;
    	case 5:
      	  printf("Nama pesanan 		:");
      	  scanf("%s", &nama[i]);
	  printf("Jumlah pesanan 	:");
	  scanf("%d", &jumlah[i]);
       	  harga_satuan[i]=3000;
	  printf("Harga satuan 		:%d\n", harga_satuan[i]);
	  harga[i]= harga_satuan[i]*jumlah[i];
	  printf("Harga 		:%d\n", harga[i]);
	  break;
    	default :
	  printf("Kode menu salah!, ulangi input kode");
	  goto pesan;
   } 
   total+=harga[i];
  }
  printf("\n");
  
  /*Struk belanja*/
  	printf("\n");
	printf("===================================\n");
	printf("||        AYAM GEPREK'86         ||\n");
	printf("||      JL. ANTASURA-DENPASAR    ||\n");
	printf("===================================\n");
	printf("Kasir :");
	scanf("%s", &kasir[10]);
	time(&t);
	printf("%s", ctime(&t));
	printf("-----------------------------------\n");
  	printf("Pesanan   	Jumlah     	Harga\n");
  	for(i=0; i<jmlh_pesan; i++){
    	printf("%s      	%d x %d    	%d", nama[i], jumlah[i], harga_satuan[i], harga[i]);
    	printf("\n");
  	}
	printf("-----------------------------------\n");
  	printf("total		:Rp %d\n", total);
	printf("cash		:Rp ");
	scanf("%d", &cash);
	kembalian= cash-total;
	printf("kembalian	:Rp %d\n",kembalian);
	printf("-----------------------------------\n");
	printf("TERIMA KASIH TELAH BERBELANJA!\n");
	printf("Silahkan Berbelanja Kembali!!");
	printf("\n");
	
do{
	printf("\n");
	printf("Ulangi kasir (Y/T) ?");
	scanf("%s",&kembali);
	if(kembali=='Y'|| kembali=='y'){
		system("cls");
	  	menu();
	  	pesan();
 	}
  	else{
  		exit(0);
 	}
}
	while(kembali=='y'||kembali=='Y');
}
	
	
int main(){

  	int tujuan;		
  	char ke_login;	
	awal:			
  	printf("--------------------------\n");
  	printf("|    AYAM GEPREK '86'	  |\n");
  	printf("--------------------------\n");
  	printf("|1. Menu Registrasi kasir|\n");
  	printf("|2. Menu Login Kasir	 |\n");
  	printf("|3. Keluar		 |\n");
  	printf("--------------------------\n\n");
  	printf("Masukan Pilihan Anda :");
  	scanf("%d", &tujuan);
  	system("cls");
  	switch(tujuan){
  		case 1:
  			regis();
  			printf("\nLogin Kasir (Y/T)?");
  			scanf("%s", &ke_login);
  			if (ke_login=='Y'||ke_login=='y'){
  				system("cls");
  				login();	
			}
			else{
				exit(0);
			}
  			break;
  		case 2:
  			login();
			break;
		case 3:
			exit(0);
			break;
		default:
			printf("Menu pulihan anda salah!\n");
			printf("Tekan ENTER untuk mengulang\n");
			system("pause");
			system("cls");
			goto awal;
			break;
	}
 	return (0);
}  
