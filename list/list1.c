/* File : list1.c */
/* Deskripsi : Implementasi dari ADT List Berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060123120037/Juan Dito Siregar*/
/* Tanggal : 2 November 2024 */


#include <stdio.h>
#include <stdlib.h>
#include "list1.h"

/**************** OPERATOR ALOKASI ****************/
/****************** Manajemen Memori ******************/
/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
//representasi fisik fungsi
address Alokasi(infotype E) {
    address P = (address)malloc(sizeof(Elm));
    if (P != NIL) {
        info(P) = E;
        next(P) = NIL;
    }
    return P;
}

/* procedure Dealokasi (input/output P:address) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke NIL  
	Proses: Melakukan pengosongan address P} */
void Dealokasi(address P) {
    free(P);
}

/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List1)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList(List1 *L) {
    First(*L) = NIL;
}

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:List1) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList(List1 L) {
    return (First(L) == NIL);
}

/**************** PENELUSURAN ****************/
/*procedure PrintList(input L:List1)
{I.S. L terdefinisi; F.S. :-}
{Proses: menampilkan info semua elemen list L} */
void PrintList(List1 L) {
    address P = First(L);
    while (P != NIL) {
        printf("%c", info(P));
        P = next(P);
    }
    printf("\n");
}

/*function NbElm(L:List1) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List1 L) {
    int count = 0;
    address P = First(L);
    while (P != NIL) {
        count++;
        P = next(P);
    }
    return count;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List1, input V:infotype )
{ I.S. L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */

void InsertVFirst(List1 *L, infotype V) {
    address P = Alokasi(V);
    if (P != NIL) {
        next(P) = First(*L);
        First(*L) = P;
    }
}

/*Procedure InsertVLast(input/output L:List1, input V:infotype )
{ I.S. L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/

void InsertVLast(List1 *L, infotype V) {
    address P = Alokasi(V);
    if (P != NIL) {
        if (IsEmptyList(*L)) {
            First(*L) = P;
        } else {
            address Q = First(*L);
            while (next(Q) != NIL)
            {
                Q = next(Q);
            }
            next(Q) = P;
        }
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List1, output V:infotype )
{ I.S. L terdefinisi,  }
{ F.S. L tetap, atau berkurang elemen pertamanya.
Proses: Elemen pertama list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. default nilai V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama yang baru adalah elemen sesudah elemen pertama yang lama. } */

void DeleteVFirst(List1 *L, infotype *V) {
    if (!IsEmptyList(*L)) {
        address P = First(*L);
        *V = info(P);
        First(*L) = next(P);
        Dealokasi(P);
    } else {
        *V = '#';  
    }
}

/*Procedure DeleteVLast(input/output L:List1, output V:infotype )
{ I.S. L terdefinisi }
{ F.S. L tetap atau berkurang elemen terakhirnya.
Proses: Elemen terakhir list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. default nilai V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir yang baru adalah elemen sebelum elemen terakhir yang lama. }*/

void DeleteVLast(List1 *L, infotype *V) {
    if (!IsEmptyList(*L)) {
        address P = First(*L);
        if (next(P) == NIL) {
            *V = info(P);
            First(*L) = NIL;
            Dealokasi(P);
        } else {
            address Q = NIL;
            while (next(P) != NIL) {
                Q = P;
                P = next(P);
            }
            *V = info(P);
            next(Q) = NIL;
            Dealokasi(P);
        }
    } else {
        *V = '#';
    }
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List1, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Proses: Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(List1 *L, infotype X, infotype Y) {
    address P = First(*L);
    while (P != NIL) {
        if (info(P) == X) {
            info(P) = Y;
            return;
        }
        P = next(P);
    }
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List1, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Proses: Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/

void SearchX(List1 L, infotype X, address Y) {
    address P = First(L);
    Y = NIL;
    while (P != NIL && info(P) != X) {
        P = next(P);
    }
    if (P != NIL) {
        Y = P;
    }
}

/*Procedure Invers(input/output L:List1)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {'i','t','u'} menjadi {'u','t','i'} }*/

void Invers(List1 *L) {
    address P = First(*L);
    address Prev = NIL, Next = NIL;
    while (P != NIL) {
        Next = next(P);
        next(P) = Prev;
        Prev = P;
        P = Next;
    }
    First(*L) = Prev;
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*function CountX(L:List1, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/

int CountX(List1 L, infotype X) {
    int count = 0;
    address P = First(L);
    while (P != NIL) {
        if (info(P) == X) {
            count++;
        }
        P = next(P);
    }
    return count;
}

/*function FrekuensiX(L:List1, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List1 L, infotype X) {
    int total = NbElm(L);
    if (total == 0) return 0.0;
    return (float)CountX(L, X) / total;
}

/*Procedure SearchAllX(input L:List1, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi (1,2,3,...nbElm(L)) kemunculan elemen X dalam list L }*/
void SearchAllX(List1 L, infotype X) {
    address P = First(L);
    int pos = 1;
    while (P != NIL) {
        if (info(P) == X) {
            printf("Posisi %d\n", pos);
        }
        P = next(P);
        pos++;
    }
}

/*Procedure UpdateAllX(input/output L:List1, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau semua elemen bernilai X berubah menjadi Y. 
Proses : mengganti semua elemen bernilai X menjadi Y}*/

void UpdateAllX(List1 *L, infotype X, infotype Y) {
    address P = First(*L);
    while (P != NIL) {
        if (info(P) == X) {
            info(P) = Y;
        }
        P = next(P);
    }
}

/* Procedure InsertVAfter(input/output L:List1, input V:infotype, input VA:infotype )
{ I.S. List L mungkin kosong, V, S terdefinisi }
{ F.S. L tetap, atau bertambah 1 elemen (VA) pada posisi setelah elemen berinfo V}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=VA sebagai elemen setelah elemen V list linier L yg mungkin kosong } */

void InsertVAfter(List1 *L, infotype V, infotype VA) {
    address P = First(*L);
    while (P != NIL && info(P) != V) {
        P = next(P);
    }
    if (P != NIL) {
        address newElm = Alokasi(VA);
        if (newElm != NIL) {
            next(newElm) = next(P);
            next(P) = newElm;
        }
    }
}

/*function MaxMember(L:List1) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/

int MaxMember(List1 L) {
    int maxCount = 0;
    address P = First(L);
    while (P != NIL) {
        int count = CountX(L, info(P));
        if (count > maxCount) {
            maxCount = count;
        }
        P = next(P);
    }
    return maxCount;
}

/*function Modus(L:List1) -> infotype */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/

infotype Modus(List1 L) {
    int maxCount = 0;
    infotype modus = '\0';
    address P = First(L);
    while (P != NIL) {
        int count = CountX(L, info(P));
        if (count > maxCount) {
            maxCount = count;
            modus = info(P);
        }
        P = next(P);
    }
    return modus;
}

/*OPERASI BANYAK LIST*/
/* Procedure ConcatList(input L1:List1, input L2:List1, output L:List1)
   {I.S.: L1, L2 terdefinisi; 
    F.S.: L menjadi gabungan dari L1 dan L2} */

void ConcatList(List1 L1, List1 L2, List1 *L) {
    CreateList(L);
    address P = First(L1);
    while (P != NIL) {
        InsertVLast(L, info(P));
        P = next(P);
    }
    P = First(L2);
    while (P != NIL) {
        InsertVLast(L, info(P));
        P = next(P);
    }
}

/* Procedure CopyList(input L1:List1, output L2:List1)
   {I.S.: L1 terdefinisi;  
    F.S.: L2 menjadi salinan L1} */

void CopyList(List1 L1, List1 *L2) {
    CreateList(L2);
    address P = First(L1);
    while (P != NIL) {
        InsertVLast(L2, info(P));
        P = next(P);
    }
}

/* Procedure SplitList(input L:List1, output L1:List1, output L2:List1)
   {I.S.: L terdefinisi ; 
    F.S.: L1, L2 hasil pemecahan L} */
void SplitList(List1 L, List1 *L1, List1 *L2) {
    CreateList(L1);
    CreateList(L2);
    int mid = NbElm(L) / 2;
    int count = 0;
    address P = First(L);
    while (P != NIL) {
        if (count < mid) {
            InsertVLast(L1, info(P));
        } else {
            InsertVLast(L2, info(P));
        }
        count++;
        P = next(P);
    }
}


