#include <stdio.h>
#include "list1.h"
#include "list1.c"

void printMenu() {
    printf("\n-----------------------------------------\n");
    printf("             MENU PROGRAM MLIST          \n");
    printf("-----------------------------------------\n");
    printf("1. Buat List Kosong\n");
    printf("2. Tambah Elemen di Awal\n");
    printf("3. Tambah Elemen di Akhir\n");
    printf("4. Hapus Elemen Pertama\n");
    printf("5. Hapus Elemen Terakhir\n");
    printf("6. Cari Elemen\n");
    printf("7. Perbarui Elemen\n");
    printf("8. Hitung Jumlah Elemen\n");
    printf("9. Invers List\n");
    printf("10. Hitung Kemunculan Elemen\n");
    printf("11. Frekuensi Elemen\n");
    printf("12. Posisi Semua Kemunculan Elemen\n");
    printf("13. Tambah Elemen Setelah Elemen Tertentu\n");
    printf("14. Modus Elemen\n");
    printf("15. Gabungkan List\n");
    printf("16. Pecah List\n");
    printf("17. Salin List\n");
    printf("18. Cetak List\n");
    printf("0. Keluar\n");
    printf("-----------------------------------------\n");
    printf("Pilih opsi: ");
}

int main() {
    List1 L, L1, L2, L3, L4, L5;
    infotype V, newV;
    address A;
    int choice, count;
    char searchElement, updateElement;

    CreateList(&L);

    printf("-----------------------------------------\n");
    printf("             MAIN PROGRAM MLIST          \n");
    printf("-----------------------------------------\n");

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                CreateList(&L);
                printf("List berhasil dibuat kosong.\n");
                break;

            case 2:
                printf("Masukkan elemen untuk ditambahkan di awal: ");
                scanf(" %c", &V);
                InsertVFirst(&L, V);
                PrintList(L);
                break;

            case 3:
                printf("Masukkan elemen untuk ditambahkan di akhir: ");
                scanf(" %c", &V);
                InsertVLast(&L, V);
                PrintList(L);
                break;

            case 4:
                if (!IsEmptyList(L)) {
                    DeleteVFirst(&L, &V);
                    printf("Elemen pertama '%c' berhasil dihapus.\n", V);
                } else {
                    printf("List kosong!\n");
                }
                PrintList(L);
                break;

            case 5:
                if (!IsEmptyList(L)) {
                    DeleteVLast(&L, &V);
                    printf("Elemen terakhir '%c' berhasil dihapus.\n", V);
                } else {
                    printf("List kosong!\n");
                }
                PrintList(L);
                break;

            case 6:
                printf("Masukkan elemen yang ingin dicari: ");
                scanf(" %c", &searchElement);
                SearchX(L, searchElement, A);
                if (A != NIL) {
                    printf("Elemen '%c' ditemukan di alamat %p\n", searchElement, A);
                } else {
                    printf("Elemen '%c' tidak ditemukan\n", searchElement);
                }
                break;

            case 7:
                printf("Masukkan elemen yang ingin diperbarui: ");
                scanf(" %c", &updateElement);
                printf("Masukkan nilai baru: ");
                scanf(" %c", &newV);
                UpdateX(&L, updateElement, newV);
                PrintList(L);
                break;

            case 8:
                printf("Jumlah elemen dalam list: %d\n", NbElm(L));
                break;

            case 9:
                Invers(&L);
                printf("List berhasil dibalik.\n");
                PrintList(L);
                break;

            case 10:
                printf("Masukkan elemen untuk dihitung kemunculannya: ");
                scanf(" %c", &V);
                count = CountX(L, V);
                printf("Elemen '%c' muncul %d kali.\n", V, count);
                break;

            case 11:
                printf("Masukkan elemen untuk dihitung frekuensinya: ");
                scanf(" %c", &V);
                printf("Frekuensi elemen '%c' dalam list: %.2f\n", V, FrekuensiX(L, V));
                break;

            case 12:
                printf("Masukkan elemen untuk menampilkan semua posisinya: ");
                scanf(" %c", &V);
                SearchAllX(L, V);
                break;

            case 13:
                printf("Masukkan elemen setelah elemen yang akan ditambahkan: ");
                scanf(" %c", &updateElement);
                printf("Masukkan elemen yang akan ditambahkan: ");
                scanf(" %c", &V);
                InsertVAfter(&L, updateElement, V);
                PrintList(L);
                break;

            case 14:
                printf("Elemen dengan kemunculan terbanyak: %c\n", Modus(L));
                break;

            case 15:
                CreateList(&L1);
                printf("Masukkan elemen untuk list kedua (akhiri dengan -1): ");
                while (1) {
                    scanf(" %c", &V);
                    if (V == -1) break;
                    InsertVLast(&L1, V);
                }
                ConcatList(L, L1, &L2);
                printf("List hasil penggabungan:\n");
                PrintList(L2);
                break;

            case 16:
                SplitList(L, &L3, &L4);
                printf("List L3:\n");
                PrintList(L3);
                printf("List L4:\n");
                PrintList(L4);
                break;

            case 17:
                CopyList(L, &L5);
                printf("Salinan list:\n");
                PrintList(L5);
                break;

            case 18:
                PrintList(L);
                break;

            case 0:
                printf("Terima kasih! Mauliate!\n");
                return 0;

            default:
                printf("Pilihan tidak valid! Silakan coba lagi.\n");
                break;
        }
    }

    return 0;
}
