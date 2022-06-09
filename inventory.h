FILE *inventory_file;

bool insert_item(char *file, char *code, char *name, int count, char *date) {
    bool status = true;
    char buffer[100];

    inventory_file = fopen(file, "r");
    while(fgets(buffer, 100, inventory_file)) {
        char *value = strtok(buffer, ";");
        if(strcmp(value, code) == 0) {
            return 0;
            status = false;
            break;
        }
    }
    fclose(inventory_file);

    if(status) {
        inventory_file = fopen(file, "a+");
        fprintf(inventory_file, "%s;%s;%d;%s;\n", code, name, count, date);
        fclose(inventory_file);
    }
    fclose(inventory_file);
}

void showData(char *file) {
    char buffer[100];
    int count = 0;

    printf("\nData barang terekam:\n");
    inventory_file = fopen(file, "r");
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
    fclose(inventory_file);
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
