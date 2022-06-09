FILE *inventory_file;

struct Data {
    char code[50];
    char name[100];
    char count[3];
    char date[10];
    struct Data *next;
};

char buffer[100];

bool insert_item(char *file, char *code, char *name, int count, char *date);
void showData(char *file);
void deleteItem(char *file, char *code);

bool insert_item(char *file, char *code, char *name, int count, char *date) {
    bool status = true;

    inventory_file = fopen(file, "r");
    if(!inventory_file) {
        printf("\nData barang tidak tersedia, hubungi admin.\n");
        system("pause");
        exit(0);
    } else {
        while(fgets(buffer, 100, inventory_file)) {
            char *value = strtok(buffer, ";");
            if(strcmp(value, code) == 0) {
                return 0;
                status = false;
                break;
            }
        }
    }
    fclose(inventory_file);

    if(status) {
        inventory_file = fopen(file, "a+");
        fprintf(inventory_file, "%s;%s;%d;%s;\n", code, name, count, date);
        fclose(inventory_file);
        return 1;
    }

}

void showData(char *file) {
    int count = 0;

    printf("\nData barang terekam:\n");
    inventory_file = fopen(file, "r");
    if(!inventory_file) {
        printf("\nData barang tidak tersedia, hubungi admin.\n");
        system("pause");
        exit(0);
    } else {
        while(fgets(buffer, 100, inventory_file)) {
            count++;
            printf("Barang ke-%d\n", count);

            char *value = strtok(buffer, ";");
            printf("Kode\t: %s\n", value);
            value = strtok(NULL, ";");
            printf("Nama\t: %s\n", value);
            value = strtok(NULL, ";");
            printf("Banyak\t: %s\n", value);
            value = strtok(NULL, ";");
            printf("Tanggal\t: %s\n\n", value);
        }
    }

    fclose(inventory_file);
}

void deleteItem(char *file, char *code) {
    bool status = false;
    struct Data *head = NULL;
    struct Data *tail = NULL;

    inventory_file = fopen(file, "r");
    if(!inventory_file) {
        printf("\nData barang tidak tersedia, hubungi admin.\n");
        system("pause");
        exit(0);
    } else {
        while(fgets(buffer, 100, inventory_file)) {
            struct Data *temp = (struct Data*)malloc(sizeof(struct Data));

            char *value = strtok(buffer, ";");
            strcpy(temp->code, value);
            if(strcmp(code, value) == 0) status = true;

            value = strtok(NULL, ";");
            strcpy(temp->name, value);

            value = strtok(NULL, ";");
            strcpy(temp->count, value);

            value = strtok(NULL, ";");
            strcpy(temp->date, value);

            temp->next = NULL;

            if(head == NULL) head = tail = temp;
            else {
                tail->next = temp;
                tail = temp;
            }

        }
    }
    fclose(inventory_file);


    struct Data *iterate = head;
    if(status) {
        inventory_file = fopen(file, "w");
        while(iterate != NULL) {
            if(strcmp(iterate->code, code) == 0) {
                printf("\nItem dihapus:\n");
                printf("Kode\t: %s\nNama\t: %s\nBanyak\t: %s\nTanggal\t: %s\n\n", iterate->code, iterate->name, iterate->count, iterate->date);
                printf("Berhasil dihapus.\n");
            } else {
                fprintf(inventory_file, "%s;%s;%s;%s;\n", iterate->code, iterate->name, iterate->count, iterate->date);
            }
            iterate = iterate->next;
        }
        fclose(inventory_file);
    } else printf("\nKode barang yang dimasukkan tidak tersedia.\n");
}



void cekBarang(char *file, char *cari){
    char buffer[100];
    int count = 0;
    bool check = false;
    inventory_file = fopen(file, "r");
    while(fgets(buffer, 100, inventory_file)) {
        char *value = strtok(buffer, ";");
        if(strcmp(cari,value) == 0){
            printf("Kode\t: %s\n", value);
            value = strtok(NULL, ";");
            printf("Nama\t: %s\n", value);
            value = strtok(NULL, ";");
            printf("Banyak\t: %s\n", value);
            value = strtok(NULL, ";");
            printf("Tanggal\t: %s\n\n", value);
            check=true;
        }
    }
    if(!check){
        printf("\n Barang Tidak Ditemukan \n");
    }
    fclose(inventory_file);

}

