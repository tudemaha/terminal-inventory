bool insert_item(char *code, char *name, int count, char *date) {
    bool status = true;
    char buffer[100];
    FILE *inventory_file;

    inventory_file = fopen("inventory-db.csv", "r");
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
        inventory_file = fopen("inventory-db.csv", "a+");
        fprintf(inventory_file, "%s;%s;%d;%s;\n", code, name, count, date);
        fclose(inventory_file);
    }
    fclose(inventory_file);
}