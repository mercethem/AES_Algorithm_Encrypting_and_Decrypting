#include <stdio.h>
#include "aes.h"
#include "utility.h"


int main()
{
    int expandedKeySize = EXPANDEDKEYSIZE;
    enum keySize size = SIZE_16;

    //What do you want to do
    int choose;
    printf("What are you want :\n1) Encrypting my file\n2) Decrypting my file\n");
    scanf("%d", &choose);

    Node* root = NULL;

    if (choose == 1) //Encrypting choose
    {
        //Directory entry for encrypting
        printf("Please enter directory:\n");
        char plain_text_directory[MAXLIMIT];
        scanf("%s", plain_text_directory);

        FILE* plain_text_path = fopen(plain_text_directory, "r");
        unsigned char plain_buffer[MAXLIMIT];
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
        scanf("%s", key_buffer);

        root = control_text(root, (unsigned char*) plain_text_directory);
        print_list(root);
        encrypting_text(root, (unsigned char*) key_buffer);
        print_list(root);
        fclose(plain_text_path);
    }
    else //Decrypting choose
    {
        //Directory entry for decrypting
        printf("Please enter directory:\n");
        char cipher_text_directory[MAXLIMIT];
        scanf("%s", cipher_text_directory);

        //
        FILE* cipher_text_path = fopen(cipher_text_directory, "r");
        unsigned char plain_buffer[MAXLIMIT];
        size_t cipher_text_buffer_length = fread(plain_buffer, sizeof(unsigned char), EXPANDEDKEYSIZE, cipher_text_path);

        if (ferror(cipher_text_path))
        {
            fprintf(stderr, "Error reading plain file");
            exit(1);
        }
        else
        {
            plain_buffer[ cipher_text_buffer_length++ ] = '\0';
        }

        //Entry key for decryption
        printf("Please enter key:\n");
        char key_buffer[MAXLIMIT];
        scanf("%s", key_buffer);

        root = control_text(root, (unsigned char*) cipher_text_directory);
        print_list(root);

        decrypting_text(root, (unsigned char*) key_buffer);
        print_list(root);

        fclose(cipher_text_path);
    }
    deleteAll(&root);

    return 0;
}
