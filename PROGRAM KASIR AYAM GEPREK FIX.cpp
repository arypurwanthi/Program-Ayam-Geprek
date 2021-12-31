#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
void regis();		//deklarasi fungsi regis
void login();		//deklarasi fungsi login
void menu();		//deklarasi fungsi menu
void pesan();		//deklarasi fungsi pesan

struct kasir{
	char nama[20];		//nama kasir yang registrasi
	char alamat[20];	//alamat kasir yang registrasi
	int umur;		//umur kasir yang registrasi
	char telp[15];		//no HP kasir yang registrasi
	char user[20];		//username yang dibuat oleh kasir yang registrasi
	char pass[20];		//password yang dibuat oleh kasir yang registrasi
};

/*fungsi dengan argumen untuk proses registrasi*/
void regis(){
	char simpan;	        //untuk memilih simpan data registrasi atau tidak
	FILE*freg;
	freg=fopen("dafregis.txt","a");
	
	isi_data:		//identifier isi_data
	struct kasir k1;
	printf("\t\t\t\t===================================\n\n");
	printf("\t\t\t\tREGISTRASI KASIR AYAM GEPREK '86'\n\n");
	printf("\t\t\t\t===================================\n\n");
	printf("\t\t\t\tMasukkan Data Diri Anda\n");
	printf("\t\t\t\t------------------------------------\n");
	printf("\t\t\t\tNama		:");
	scanf("%s", &k1.nama);
	fflush(stdin);
	fprintf(freg, "Nama		:%s\n",k1.nama);
	printf("\t\t\t\tAlamat		:");
	scanf("%s", &k1.alamat);
	fflush(stdin);
	fprintf(freg, "Alamat		:%s\n",k1.alamat);
	printf("\t\t\t\tUmur		:");
	scanf("%d", &k1.umur);
	fflush(stdin);
	fprintf(freg, "Umur		:%d\n",k1.umur);
	printf("\t\t\t\tNo Hp		:");
	scanf("%s", &k1.telp);
	fflush(stdin);
	fprintf(freg, "No HP		:%s\n",k1.telp);
	printf("\t\t\t\tBuat Username	:");
	scanf("%s", &k1.user);
	fflush(stdin);
	fprintf(freg, "Username	:%s\n",k1.user);
	printf("\t\t\t\tBuat Password	:");
	scanf("%s", &k1.pass);
	fflush(stdin);
	fprintf(freg, "Password	:%s\n\n",k1.pass);
	printf("\t\t\t\t-----------------------------------\n");
	
	printf("\t\t\t\tSimpan Data (Y) Atau Ulang (U) ?");
	scanf("%s", &simpan);
	fflush(stdin);
	if(simpan=='Y'|| simpan=='y'){
		printf("\n");
		printf("\t\t\t\t============================\n");
		printf("\t\t\t\tData Anda Telah Disimpan\n");
		printf("\t\t\t\t============================\n");
	}
	else {
		system("cls");
		goto isi_data;
	}
}


/*fungsi dengan argumen untuk login kasir*/
void login(){
	char user[20]; 	         //input user pegawai
  	char pass[20]; 	         //input password pegawai
  	char ulang;	         //mengulangi proses login ketika salah username dan atau password
	do{
		printf("\t\t\t\t************Login Kasir**************\n\n");
		printf("\t\t\t\tMasukan Username	: ");
		scanf ("%s", user);
		printf("\n");
		printf("\t\t\t\tMasukan Password	: ");
		scanf ("%s", pass);
		printf("\n");
		printf("\t\t\t\t*************************************\n");

		if ((strcmp(user,"kasir1") == 0 && strcmp(pass, "ary")==0) || (strcmp(user,"kasir2") == 0 && strcmp(pass, "asty") == 0)){  
		printf("\n");
		printf ("\t\t\t\t=========Akses diterima==========\n\n");
	
		system ("\t\t\t\t\npause");
		system("cls");
		menu();
		pesan();
		}
		else if((strcmp(user,"kasir1")!=0 && strcmp(pass, "ary")!=0) || (strcmp(user,"kasir2")!=0 && strcmp(pass, "asty")!=0)){
		printf("\n");	
		printf ("\t\t\t\t===========================\n");
		printf ("\t\t\t\tUsername atau Password salah \n");
		printf ("\t\t\t\t===========================\n\n");
		printf ("\t\t\t\tCoba lagi ? \n"); 
		printf ("\t\t\t\tYa atau Tidak (Y/T): "); 
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


/*fungsi dengan argumen untuk menampilkan menu makanan yang diambil dari file dmenu.txt*/
void menu(){
	char buff[100];
	FILE*in;
	if((in=fopen("dmenu.txt", "r"))==NULL){
		printf("File Kosong!");
	}
	while(fgets(buff, sizeof(buff), in)){
		printf("%s",buff);
	}
	fclose(in);
}


/*Fungsi dengan argumen untuk pemesanan dan struk*/
void pesan(){
  int jmlh_pesan;	//banyaknya pesanan berdasarkan jenis menu
  int i;		//variavel looping untuk pemesanan
  int kode;		//kode menu yang dipesanan
  int jumlah[10];	//jumlah pesanan per menu yang dipesan
  int harga_satuan[10];	//harga satuan menu
  int harga[20];	//harga satuan dikalikan jumlah pesan
  char nama[10][10];	//nama menu pesanan
  char kasir[10];	//nama kasir
  int total=0;		//total pembayaran semua pesanan
  time_t t;		//waktu pembayaran di kasir
  int cash;		//jumlah uang yang diberikan pembeli
  int kembalian;	//kembalian dari uang yang dibayar pembeli
  char kembali;		//kembali mengulang kasir untuk pembayaran kasir berikutnya
  FILE*out;
  out=fopen("buktrans.txt","a");
	
  printf("\nJumlah jenis pesanan 	:");
  scanf("%d",&jmlh_pesan);
  printf("-----------------------------");
  for(i=0;i<jmlh_pesan;i++){
  	pesan:				// identifier pesan
  	printf("\n");
  	printf("\nKode pesanan 	:");
	scanf("%d", &kode);
    switch(kode){
	case 1:
	 	printf ("Nama pesanan 	:");
	  	scanf  ("%s", &nama[i]);
		fflush (stdin);
	  	printf ("Jumlah pesanan	:");
	  	scanf  ("%d", &jumlah[i]);
      	  	harga_satuan[i]=10000;
	  	printf ("Harga satuan	:Rp.%d\n", harga_satuan[i]);
	    	harga[i]= harga_satuan[i]*jumlah[i];
	    	printf ("Harga 		:Rp.%d\n", harga[i]);
	    	break;
    	case 2:
      		printf ("Nama pesanan 	:");
      		scanf  ("%s", &nama[i]);
		fflush (stdin);
	    	printf ("Jumlah pesanan 	:");
	    	scanf  ("%d", &jumlah[i]);
      		harga_satuan[i]=8000;
	    	printf ("Harga satuan 	:Rp.%d\n", harga_satuan[i]);
	    	harga[i]= harga_satuan[i]*jumlah[i];
	    	printf ("Harga 		:Rp.%d\n", harga[i]);
	    	break;
    	case 3:
      		printf ("Nama pesanan 	:");
      		scanf  ("%s", &nama[i]);
		fflush (stdin);
	    	printf ("Jumlah pesanan 	:");
	    	scanf  ("%d", &jumlah[i]);
      		harga_satuan[i]=6000;
	    	printf ("Harga satuan 	:Rp.%d\n", harga_satuan[i]);
	    	harga[i]= harga_satuan[i]*jumlah[i];
	    	printf ("Harga 		:Rp.%d\n", harga[i]);
	    	break;
    	case 4:
      		printf ("Nama pesanan 	:");
      		scanf  ("%s", &nama[i]);
		fflush (stdin);
	    	printf ("Jumlah pesanan 	:");
	    	scanf  ("%d", &jumlah[i]);
      		harga_satuan[i]=5000;
	    	printf ("Harga satuan 	:Rp.%d\n", harga_satuan[i]);
	    	harga[i]= harga_satuan[i]*jumlah[i];
	    	printf ("Harga 		:Rp.%d\n", harga[i]);
	    	break;
    	case 5:
      		printf ("Nama pesanan 	:");
      		scanf  ("%s", &nama[i]);
		fflush (stdin);
	    	printf ("Jumlah pesanan 	:");
	    	scanf  ("%d", &jumlah[i]);
       		harga_satuan[i]=3000;
	    	printf ("Harga satuan 	:Rp.%d\n", harga_satuan[i]);
	    	harga[i]= harga_satuan[i]*jumlah[i];
	    	printf ("Harga 		:Rp.%d\n", harga[i]);
	    	break;
    	default :
		printf("Kode menu salah!, ulangi input kode");
		goto pesan;
   } 
   total+=harga[i];
  }
  printf("\n");
  system("pause");
  system("cls");
  
  	
	/*Struk belanja*/
  	printf("\n");
	printf("\t\t\t\t===================================\n");
	printf("\t\t\t\t||        AYAM GEPREK'86         ||\n");
	printf("\t\t\t\t||      JL. ANTASURA-DENPASAR    ||\n");
	printf("\t\t\t\t===================================\n");
	printf("\t\t\t\tKasir :");
	scanf("%s", &kasir[10]);
	fflush(stdin);
	fprintf(out,"Kasir bertugas : %s\n", kasir);
	time(&t);
	printf("\t\t\t\t%s", ctime(&t));
	fprintf(out,"%s\n", ctime(&t));
	printf("\t\t\t\t-----------------------------------\n");
  	printf("\t\t\t\tPesanan   	Jumlah     	Harga\n");
	fprintf(out,"Pesanan		Jumlah		Harga\n");
  	for(i=0; i<jmlh_pesan; i++){
    		printf("\t\t\t\t%s      	%d x %d    	%d", nama[i], jumlah[i], harga_satuan[i], harga[i]);
    		printf("\n");
		fprintf(out,"%s		%d X %d	%d", nama[i], jumlah[i], harga_satuan[i], harga[i]);
    		fprintf(out,"\n");
  	}
	
	printf("\t\t\t\t-----------------------------------\n");
  	printf("\t\t\t\ttotal		:Rp %d\n", total);
	fprintf(out,"Total 		: %d\n", total);
	printf("\t\t\t\tcash		:Rp ");
	scanf("%d", &cash);
	fprintf(out,"Chas 		: %d\n", cash);
	kembalian= cash-total;
	printf("\t\t\t\tkembalian	:Rp %d\n",kembalian);
	fprintf(out,"Kembalian	: %d\n", kembalian);
	fprintf(out, "--------------------------------------------------------\n\n");
	fclose(out);
	printf("\t\t\t\t-----------------------------------\n");
	printf("\t\t\t\tTERIMA KASIH TELAH BERBELANJA!\n");
	printf("\t\t\t\tSilahkan Berbelanja Kembali!!\n");
	printf("\t\t\t\t-----------------------------------\n");
	printf("\n");
	
	/*repetisi ketika ingin mengulang pembayaran di kasir tanpa perlu login kembali*/
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



/*fungsi utama*/
int main(){
  	int tujuan;	        //pilihan menu tujuan registrasi atau login
  	char ke_login;	        //untuk memilih setelah regis ke menu login atau keluar
  	
  	awal:			//identifier awal
  	printf("\t\t\t\t-----------------------------------------\n");
  	printf("\t\t\t\t|    		AYAM GEPREK '86'	|\n");
  	printf("\t\t\t\t-----------------------------------------\n");
  	printf("\t\t\t\t|1. Menu Registrasi kasir		|\n");
  	printf("\t\t\t\t|2. Menu Login Kasir	 		|\n");
  	printf("\t\t\t\t|3. Keluar		 		|\n");
  	printf("\t\t\t\t-----------------------------------------\n\n");
  	printf("\t\t\t\tMasukan Pilihan Anda :");
  	scanf("%d", &tujuan);
  	system("cls");
  	switch(tujuan){
  		case 1:
  			regis();
  			printf("\n");
  			printf("\t\t\t\t------------------------\n");
  			printf("\t\t\t\tLogin Kasir (Y/T)?");
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
			printf("\t\t\t\t----------------------------\n");
			printf("\t\t\t\tMenu pulihan anda salah!\n");
			printf("\t\t\t\tTekan ENTER untuk mengulang\n");
			printf("\t\t\t\t----------------------------\n");
			system("\t\t\t\tpause");
			system("cls");
			goto awal;
			break;
	}
 	return (0);
}  	


