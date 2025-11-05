# 📚 Program Pengelolaan Data 20 Siswa

## Tujuan Program
Program ini digunakan untuk **mengelola data 20 siswa**, termasuk nama depan, nama belakang, nilai ulangan (0–100), serta nilai huruf (A–E). Program meminta pengguna untuk memasukkan data setiap siswa, memastikan input valid (**tidak duplikat** dan **tanpa angka dalam nama**), kemudian menampilkan hasil dalam bentuk tabel serta siswa dengan nilai tertinggi.

---

## 🛠️ Struktur Data: `struct studentType`

Bagian ini mendefinisikan struktur untuk menyimpan data tiap siswa. Struktur ini membantu mengelompokkan semua informasi yang berkaitan dengan satu siswa ke dalam satu wadah.

Struktur berisi:
* `studentFName`: nama depan siswa
* `studentLName`: nama belakang siswa
* `testScore`: nilai ulangan dalam bentuk angka (0–100)
* `grade`: nilai huruf berdasarkan skor (A sampai E)

---

## 💻 Detail Fungsi Program

### 1. `Fungsi isDuplicateName`
Fungsi ini digunakan untuk memeriksa apakah nama siswa sudah pernah dimasukkan sebelumnya. Fungsinya akan membandingkan nama depan dan nama belakang dari data baru dengan data yang sudah ada di array. Jika ditemukan nama yang sama, fungsi mengembalikan **true** (artinya duplikat), jika tidak maka **false**. Hal ini mencegah pengguna memasukkan data siswa yang sama dua kali.

### 2. `Fungsi readStudentData`
Fungsi ini bertugas untuk membaca data semua siswa dari *input* pengguna. Program meminta pengguna mengetik data dengan format: **`FirstName LastName Score`**.

Setiap data yang dimasukkan akan dicek terlebih dahulu:
* Apakah format *input* sudah benar (nama dan angka).
* Apakah skor berada dalam rentang **0–100**.
* Apakah nama tidak mengandung angka.
* Apakah nama belum pernah dimasukkan sebelumnya.

Jika ada kesalahan, program menampilkan pesan *error* dan meminta pengguna untuk mengetik ulang data siswa tersebut. Fungsi ini memastikan bahwa semua data yang masuk **valid** sebelum disimpan ke dalam *array*.

### 3. `Fungsi assignGrades`
Setelah semua nilai angka dimasukkan, fungsi ini akan mengonversi nilai angka menjadi huruf berdasarkan kriteria:
* **90–100** → **A**
* **80–89** → **B**
* **70–79** → **C**
* **60–69** → **D**
* **Di bawah 60** → **E**

Fungsi ini akan memproses setiap elemen dalam *array* dan memberikan nilai huruf yang sesuai untuk masing-masing siswa.

### 4. `Fungsi findHighestScore`
Fungsi ini mencari nilai ulangan **tertinggi** dari seluruh siswa. Fungsi tersebut membandingkan nilai setiap siswa dan menyimpan nilai terbesar yang ditemukan. Nilai maksimum ini kemudian dikembalikan ke fungsi `main()` untuk digunakan pada bagian selanjutnya.

### 5. `Fungsi printHighestScorers`
Setelah nilai tertinggi ditemukan, fungsi ini akan menampilkan **semua siswa** yang memiliki nilai tersebut. *Output* ditampilkan dalam format tabel sederhana dengan kolom:
* Nama siswa (format: **`LastName, FirstName`**)
* Nilai ulangan

Jika ada lebih dari satu siswa yang memiliki nilai tertinggi, semuanya akan ditampilkan.

### 6. `Fungsi printStudentResults`
Fungsi ini menampilkan **daftar lengkap semua siswa** beserta nilai angka dan nilai hurufnya dalam bentuk **tabel rapi**. Nama ditampilkan dalam format “`NamaBelakang, NamaDepan`”, diikuti dengan kolom skor dan *grade*. Ini berfungsi sebagai laporan akhir seluruh kelas.

### 7. `Fungsi main`
Fungsi utama ini mengatur urutan jalannya program:
1.  Mendeklarasikan *array* `classList` untuk menampung maksimal **20 siswa**.
2.  Memanggil `readStudentData()` untuk membaca dan memvalidasi data.
3.  Menjalankan `assignGrades()` untuk memberi nilai huruf.
4.  Menampilkan tabel seluruh hasil melalui `printStudentResults()`.
5.  Menemukan nilai tertinggi menggunakan `findHighestScore()`.
6.  Menampilkan siswa dengan nilai tertinggi melalui `printHighestScorers()`.

---

## 💡 Kesimpulan
Program ini merupakan contoh penerapan `struct` dan *array* dalam C++. Melalui penggunaan fungsi-fungsi terpisah, kode menjadi lebih **terstruktur** dan **mudah dibaca**. Selain itu, adanya **validasi *input*** memastikan bahwa data yang dimasukkan pengguna selalu benar sebelum diproses lebih lanjut.
