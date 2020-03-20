Kelompok D02
- 5111840000120	-	Aflakah Nur Farhana
- 5111840000165	-	Muhammad Fikri Rabbani


**Soal 1**

Buatlah program C yang menyerupai crontab untuk menjalankan script bash dengan
ketentuan sebagai berikut:

 a. Program menerima 4 argumen berupa:
- i. Detik: 0-59 atau * (any value)
- ii. Menit: 0-59 atau * (any value)
- iii. Jam: 0-23 atau * (any value)
- iv. Path file .sh

b. Program akan mengeluarkan pesan error jika argumen yang diberikan tidak
sesuai
- c. Program hanya menerima 1 config cron
- d. Program berjalan di background (daemon)
- e. Tidak boleh menggunakan fungsi system()

Contoh: ./program \* 34 7 /home/somi/test.sh
Program dengan argumen seperti contoh di atas akan menjalankan script test.sh setiap
detik pada jam 07:34.

Pada soal 1 diminta untuk membuat crontab di bash menggunakan c dan tidak boleh menggunakan fungsi system.
- 1.a Menerima input berupa Detik Menit Jam Serta Path file .sh

Pertama dilakukan pengecekan dari argumen yang di inputkan yaitu berupa :
```
	if(argc < 5 || argc > 5)
  	{
    	  printf("Argumen wajib 4!!!\n");
    	  exit(EXIT_FAILURE);
  	}

  	else if(argc == 5)
  	{
    	  int arr[4];

   	for (i = 1; i < 4; i++)
	{
	  if (batas(argv[i]))
	  {
	    arr[i] = atoi(argv[i]);
	  }
	  else if (cek(argv[i]))
	  {
	    arr[i] = -1;
	  }
	  else 
	  {
	    printf("Argumen %d salah!!!\n", i);
  	    exit(EXIT_FAILURE);
	  }
	}
```
Argumen yang di cek harus berjumlah 5 jika berjumlah kurang atau lebih maka dia akan exit. Pengecekan yang dilakukan adalah berupa mengecek apakah input berupa angka atau bintang, pengecekan terjadi dalam 
```
      if (batas(argv[i])) //Mengecek apakah input berupa angka
      {
        arr[i] = atoi(argv[i]);
      }
      else if (cek(argv[i])) //Mengecek apakah input berupa bintang(*)
      {
        arr[i] = -1;
      }
```
Yang mana fungsi cek dan batasnya berupa 
```
int batas(char arr[])
{
  int i;
  for (i = 0; i < strlen(arr); i++)
  {
    if (arr[i] < '0' || arr[i] > '9')
    {
      return 0;
    }
  }
  return 1;
}

int cek(char arr[])
{
  if((strcmp(arr, "*")) == 0)
  {
    return 1; 
  }
  return 0;
}
```
Setelah dicek maka akn dicek lagi apakah input yang diberikan tidak melebihi range dari waktu yang diberikan Detik: 0-59 atau * (any value), Menit: 0-59 atau * (any value), Jam: 0-23 atau * (any value)
```
    a = atoi(argv[1]);//Untuk merubah string menjadi integer
    b = atoi(argv[2]);
    c = atoi(argv[3]);

    if (a < 0 || a > 59)
    {
      printf("Range detik salah!!!\n detik harus 0 - 59. \n");
      exit(EXIT_FAILURE);
    }
    else if (b < 0 || b > 59)
    {
      printf("Range menit salah!!!\n menit harus 0 - 59. \n");
      exit(EXIT_FAILURE);
    }
    else if (c < 0 || c > 23)
    {
      printf("Range jam salah!!!\n jam harus 0 - 23. \n");
      exit(EXIT_FAILURE);
    }   
```
Kemudian untuk path file .sh nya dapat diperoleh dari
```
    char path[100];
    strncpy(path, argv[4], 99);
    path[100] = '\0';
```


**Soal 3**

Jaya adalah seorang programmer handal mahasiswa informatika. Suatu hari dia
memperoleh tugas yang banyak dan berbeda tetapi harus dikerjakan secara bersamaan
(multiprocessing).
a. Program buatan jaya harus bisa membuat dua direktori di“/home/[USER]/modul2/”. Direktori yang pertama diberi nama “indomie”, lalu lima detik kemudian membuat direktori yang kedua bernama “sedaap”.
b. Kemudian program tersebut harus meng-ekstrak file jpg.zip di direktori“/home/[USER]/modul2/”. Setelah tugas sebelumnya selesai, ternyata tidak hanya itu tugasnya.
c. Diberilah tugas baru yaitu setelah di ekstrak, hasil dari ekstrakan tersebut (di dalam direktori “home/[USER]/modul2/jpg/”) harus dipindahkan sesuai dengan pengelompokan, semua file harus dipindahkan ke “/home/[USER]/modul2/sedaap/” dan semua direktori harus dipindahkan ke “/home/[USER]/modul2/indomie/”.
d. Untuk setiap direktori yang dipindahkan ke “/home/[USER]/modul2/indomie/” harus membuat dua file kosong. File yang pertama diberi nama “coba1.txt”, lalu 3 detik kemudian membuat file bernama “coba2.txt”. (contoh : “/home/[USER]/modul2/indomie/{nama_folder}/coba1.txt”).
Karena Jaya terlalu banyak tugas dia jadi stress, jadi bantulah Jaya agar bisa membuat
program tersebut.
Catatan :
- Tidak boleh memakai system().
- Tidak boleh memakai function C mkdir() ataupun rename().
- Gunakan exec dan fork
- Direktori “.” dan “..” tidak termasuk

jawaban
3a. 
berikut merupakan program untuk membuat directori indomie didalam /home/hana/modul2 
```
if (pid < 0) {
	exit(EXIT_FAILURE); 
	}

	if (pid == 0) {
	char *argv[] = {"mkdir", "-p", "/home/hana/modul2/indomie", NULL};
	execv("/bin/mkdir", argv);	
	}
```
  
 berikut merupakan program untuk membuat directori sedaap didalam /home/hana/modul2 
 
```
while((wait(&status)) > 0);

	pid2 = fork();
  
	if (pid2 < 0) {
	exit(EXIT_FAILURE);
	}

	if (pid2 == 0) {
	char *argv[] = {"mkdir","-p", "/home/hana/modul2/sedaap", NULL};
	execv("/bin/mkdir", argv);
	}
```
3b.
berikut merupakan program untuk melakukan unzip pada file .zip
```
while((wait(&status)) > 0);
	
	pid3 = fork();
  
	if (pid3 < 0) {
	exit(EXIT_FAILURE); 
  	}

	if (pid3 == 0) {
	char *unzip[] = {"unzip", "/home/hana/modul2/jpg.zip", NULL};
     	execv("/usr/bin/unzip", unzip);
	}
  ```

