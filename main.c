/* Basic implementation of AES in C
 *
 * Warning: THIS CODE IS ONLY FOR LEARNING PURPOSES
 *          NOT RECOMMENDED TO USE IT IN ANY PRODUCTS
 */


#include <stdio.h>
#include <string.h>
#include "aes.h"
#include "utility.h"


//TODO const correctness yapmayı unutma
//TODO dosyların açılma modlarını kullanışlı hale getir
//TODO - buffer boyunutlarını gerekli boyuta ayarla



//TODO BU ÇALIŞMAYA DEVAM EDECEKKEN TAHMİNEN HEXADECİMAL ŞEKİLDE ORNEK DOSYASINI OKUYACAK SONRASINDA HEXADECİMAL KAYIT YAPMAN GEREKECEK
// TEKRAR İLK ANA DOSYAYA BAKARAK KAYITLARINI KONTROL ETMELİSİN ORDA NORMALSE HATA SENDE DEMEKTİR!!!


//for (i = 0; i < 16; i++)
//{
//// Print characters in HEX format, 16 chars per line
//printf("%2.2x%c", key[i], ((i + 1) % 16) ? ' ' : '\n');
//}


int main()
{
    // the expanded keySize
    int expandedKeySize = EXPANDEDKEYSIZE;

    // the cipher key size
    enum keySize size = SIZE_16;

    int choose;
    printf("What are you want :\n1) Encrypting my file\n2) Decrypting my file\n");
    scanf("%d", &choose);

    Node* root = NULL;

    if (choose == 1)
    {

        printf("Please enter directory:\n");
        char plain_text_directory[MAXLIMIT];
        scanf("%s", &plain_text_directory);

        FILE* plain_text_path = fopen(plain_text_directory, "r");
        unsigned char plain_buffer[FILENAME_MAX];
        size_t plain_text_buffer_length = fread(plain_buffer, sizeof(unsigned char), EXPANDEDKEYSIZE, plain_text_path);

        if (ferror(plain_text_path))
        {
            fprintf(stderr, "Error reading plain file");
            exit(1);
        }
        else
        {
            plain_buffer[ plain_text_buffer_length++ ] = '\0'; /* Just to be safe. */
        }

        printf("Please enter key:\n");
        char key_buffer[MAXLIMIT];
        scanf("%s", &key_buffer);

        root = control_text(root, plain_text_directory);
        print_list(root);
        crypting_text(root, key_buffer);
        print_list(root);

        deleteAll(&root);
        fclose(plain_text_path);

    }
    else
    {

        printf("Please enter directory:\n");
        char plain_text_directory[MAXLIMIT];
        scanf("%s", &plain_text_directory);

        FILE* plain_text_path = fopen(plain_text_directory, "r");
        unsigned char plain_buffer[FILENAME_MAX];
        size_t plain_text_buffer_length = fread(plain_buffer, sizeof(unsigned char), EXPANDEDKEYSIZE, plain_text_path);

        if (ferror(plain_text_path))
        {
            fprintf(stderr, "Error reading plain file");
            exit(1);
        }
        else
        {
            plain_buffer[ plain_text_buffer_length++ ] = '\0'; /* Just to be safe. */
        }


        printf("Please enter key:\n");
        char key_buffer[MAXLIMIT];
        scanf("%s", &key_buffer);


        root = control_text(root, plain_text_directory);
        print_list(root);
        decrypting_text(root, key_buffer);
        print_list(root);

        deleteAll(&root);
        fclose(plain_text_path);

    }


//    unsigned char expanded_key_buffer[FILENAME_MAX];
//    FILE* expanded_key_text_path = fopen("E:\\C_Projects\\MyProject\\AES\\expanded_key.txt", "w+");
//
//    unsigned char cipher_buffer[FILENAME_MAX];
//    FILE* cipher_text_path = fopen("E:\\C_Projects\\MyProject\\AES\\cipher.txt", "w+");
//
//    unsigned char decrypted_buffer[FILENAME_MAX];
//    FILE* decrypted_text_path = fopen("E:\\C_Projects\\MyProject\\AES\\decrypted.txt", "w+");
//




//    printf("expandedkey");
//    expanded_key_creating(root, key_buffer);



//    printf("crypted");
//    crypting(root, key_buffer);
//    print_list(root);


//    printf("decrypted");
//    decrypting(root, key_buffer);
//    print_list(root);


//    Dosyalara yazma işlemleri
//    fwrite(expanded_key_buffer, sizeof(expanded_key_buffer), 1, expanded_key_text_path);
//    fwrite(cipher_buffer, sizeof (cipher_buffer), 1, cipher_text_path);
//    fwrite(decrypted_buffer, sizeof (decrypted_buffer), 1, decrypted_text_path);
//
//
//    Tüm doyaları kapatmalar

//    fclose(expanded_key_text_path);
//    fclose(cipher_text_path);
//    fclose(decrypted_text_path);
//
//

    return 0;
}







