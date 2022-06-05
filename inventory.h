FILE *inventory_file;

bool insert_item(char *file, char *code, char *name, int count, char *date) {
    bool status = true;
    char buffer[100];

    inventory_file = fopen(file, "r");
    while(fgets(buffer, 100, inventory_file)) {
        char *value = strtok(buffer, ";");
        if(strcmp(value, code) == 0) {
            printf("%s", "\nKode barang sudah digunakan, coba nama barang lain.\n");
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