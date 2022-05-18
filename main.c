#include <stdio.h>
#include <stdlib.h>

int main() {
    char choice;

    start:
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
            break;
        case '2':
            break;
        case '3':
            break;
        case '4':
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