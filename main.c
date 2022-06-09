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

    char cari[80];
    char choice, code[50];
    struct itemData newItem;

    start:
    system("cls");
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
            insert_item:
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
            else printf("%s", "\nKode barang sudah digunakan, coba nama barang lain.\n");

            _insert_option_:
            printf("\nIngin memasukkan barang lagi? (y/n): ");
            scanf(" %c", &choice);
            if(choice == 'y' || choice == 'Y') goto insert_item;
            else if(choice == 'n' || choice == 'N') goto start;
            else goto _insert_option_;
            system("pause");
            break;

        case '2':
            delete_item:
            printf("\nMasukkan kode barang yang akan dihapus: ");
            fflush(stdin);
            fgets(code, 50, stdin);
            code[strcspn(code, "\n")] = 0;

            delete_confirmation:
            printf("\nYakin menghapus barang berkode %s? (y/n): ", code);
            scanf(" %c", &choice);
            if(choice == 'y' || choice == 'Y') deleteItem("inventory-db.csv", code);
            else if(choice == 'n' || choice == 'N') goto start;
            else goto delete_confirmation;

            _delete_option_:
            printf("\nIngin menghapus barang lagi? (y/n): ");
            scanf(" %c", &choice);
            if(choice == 'y' || choice == 'Y') goto delete_item;
            else if(choice == 'n' || choice == 'N') goto start;
            else goto _delete_option_;
            system("pause");
            break;

        case '3':
            check_item:
            printf("\nMasukan kode barang yang dicari: ");
            fflush(stdin);
            gets(cari);
            cekBarang("inventory-db.csv", cari);

            _check_option_:
            printf("\nIngin mengecek barang lagi? (y/n): ");
            scanf(" %c", &choice);
            if(choice == 'y' || choice == 'Y') goto check_item;
            else if(choice == 'n' || choice == 'N') goto start;
            else goto _check_option_;
            system("pause");
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
