/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 4
 *   Hari dan Tanggal    : Rabu, 6 Mei 2026
 *   Nama (NIM)          : Hufnagel Ruben Lenard Situmorang (13224015)
 *   Nama File           : soal1.c
 *   Deskripsi           : Menghitung total waktu antrian pasien
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int queue[100];

typedef struct Pasien{
    char id[10];
    int waktu;
} Pasien;

int rekursi(int n){
    int sum = 0;
    for (int i=0;i<n;i++){
        sum += queue[i];
    }
    return sum;
}

int main(){
    int N;
    scanf("%d",&N);

    Pasien listpasien[N];
    for (int i=0;i<N;i++){
        scanf("%s",&listpasien[i].id);
        scanf("%d",&listpasien[i].waktu);
        queue[i] = listpasien[i].waktu;
    }

    printf("ORDER ");
    for (int i=0;i<N;i++){
        printf("%s",listpasien[i].id);
        if (i!=N-1){
            printf(" ");
        }
    }
    
    int sum = 0;
    for (int i=0;i<N;i++){
        sum += rekursi(i);
    }
    printf("\nWAIT %d",sum);
    return 0;

}
