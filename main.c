#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "inventory.h"

struct itemData {
    char code[50];
    char name[100];
    int count;
    char date[10];
};

int main() {
    char choice;
    struct itemData newItem;

    start:
    // system("cls");
    printf(
        "================================\n"
        "||     TERMINAL INVENTORY     ||\n"
        "================================\n\n"
    );

    printf("Menu:\n1. Tambah Barang\n2. Hapus Barang\n3. Cek Barang\n4. Lihat Barang\n5. Keluar\n");
    insert_choice:
    printf("Masukkan pilihan: ");
    scanf(" %c", &choice);

    switch(choice) {
        case '1':
            printf("\nMasukkan data barang:\n");
            printf("Nama Barang\t: ");
            fflush(stdin);
            gets(newItem.name);
            newItem.name[strcspn(newItem.name, "\n")] = 0;

            printf("Banyak Barang\t: ");
            scanf("%d", &newItem.count);

            printf("Tanggal Input (format: ddmmyyyy): ");
            fflush(stdin);
            gets(newItem.date);
            newItem.date[strcspn(newItem.date, "\n")] = 0;

            strcpy(newItem.code, "");
            strcat(newItem.code, newItem.name);
            strcat(newItem.code, newItem.date);

            if(insert_item("inventory-db.csv",newItem.code, newItem.name, newItem.count, newItem.date)) {
                printf("\nBerhasil merekam data.\n");
            }
            else printf("\nGagal memasukkan data!\n");
            system("pause");
            goto start;
            break;
        case '2':
            break;
        case '3':
            break;
        case '4':
            showData("inventory-db.csv");
            system("pause");
            goto start;
            break;
        case '5':
            printf("\n");
            insert_exit:
            printf("Yakin keluar? (y/n): ");
            scanf(" %c", &choice);
            if(choice == 'y' || choice == 'Y') exit(0);
            else if(choice == 'n' || choice == 'N') goto start;
            else goto insert_exit;
            break;
        default:
            goto insert_choice;
            break;
    }

    return 0;
}