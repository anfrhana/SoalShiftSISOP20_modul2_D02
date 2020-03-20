Kelompok D02
- 5111840000120	-	Aflakah Nur Farhana
- 5111840000165	-	Muhammad Fikri Rabbani


**Soal 1**

Buatlah program C yang menyerupai crontab untuk menjalankan script bash dengan
ketentuan sebagai berikut:
- a. Program menerima 4 argumen berupa:
- i. Detik: 0-59 atau * (any value)
- ii. Menit: 0-59 atau * (any value)
- iii. Jam: 0-23 atau * (any value)
- iv. Path file .sh

- b. Program akan mengeluarkan pesan error jika argumen yang diberikan tidak
sesuai
- c. Program hanya menerima 1 config cron
- d. Program berjalan di background (daemon)
- e. Tidak boleh menggunakan fungsi system()

Contoh: ./program \* 34 7 /home/somi/test.sh
Program dengan argumen seperti contoh di atas akan menjalankan script test.sh setiap
detik pada jam 07:34.


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

