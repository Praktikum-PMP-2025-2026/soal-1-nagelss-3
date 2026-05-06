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

struct Pasien{
    char id[10];
    int waktu;
    struct Pasien* next;
};

struct Pasien* head = NULL;

void tambah_pasien(char* id, int waktu){
    struct Pasien* baru = (struct Pasien*)malloc(sizeof(struct Pasien));
    strcpy(baru->id, id);
    baru->waktu = waktu;
    
    if (head==NULL){
        head = baru;
        return;
    }
    struct Pasien* temp = head;
    while (temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = baru;
    return;
}

void print_order(){
    struct Pasien* temp = head;
    printf("ORDER ");
    while (temp != NULL) {
        printf("%s",temp->id);
        if (temp->next!=NULL){
            printf(" ");
        }
        temp = temp->next;
    }
    printf("\n");
}

void print_wait(int n){
    struct Pasien* temp = head;
    printf("WAIT ");
    int sum = 0;
    int i = 1;
    while (temp->next!=NULL){
        sum += (temp->waktu)*(n-i);
        i++;
        temp = temp->next;
    }
    printf("%d",sum);
    return;
}
int main(){
    int N;
    scanf("%d",&N);

    char id_s[10];
    int waktu_s;
    for (int i=0;i<N;i++){
        scanf("%s",&id_s);
        scanf("%d",&waktu_s);
        tambah_pasien(id_s, waktu_s);
    }
    print_order();
    print_wait(N);
    return 0;
}
