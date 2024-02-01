#include "utility.h"
#include <stdlib.h>
#include <dirent.h>
#include "aes.h"

void print_list(Node* root)
{
    printf("\nYour Linked List :\n\n");

    while (root)
    {
//        printf("%02x ", root->data);
//        printf("%2.2x%c", root->data, ((i + 1) % 16) ? ' ');
        printf("%s", root->data);
        root = root->next;
    }
    printf("\n");
}


void deleteAll(struct Node** root)
{
    struct Node* iter = *root;
    struct Node* next;

    while (iter != NULL)
    {
        next = iter->next;
        free(iter);
        iter = next;
    }
    *root = NULL;
}


Node* insert_contiguous(Node* root, unsigned char sval[])
{
    if (root == NULL)
    {
        root = (Node*) malloc(sizeof(Node));
        strcpy(root->data, sval);
        root->next = NULL;
        return root;
    }

    Node* iter = root;

    while (iter->next != NULL)
    {
        iter = iter->next;
    }

    Node* temp = (Node*) malloc(sizeof(Node));
    temp->next = iter->next;
    iter->next = temp;
    strcpy(temp->data, sval);
    return root;
}

Node* control_text(Node* root, unsigned char directory[])
{
    unsigned char ornek_buffer[MAXLIMIT];

    FILE* ornek_path = fopen(directory, "r");
    size_t ornek_buffer_length = fread(ornek_buffer, sizeof(unsigned char), MAXLIMIT, ornek_path);

    if (ferror(ornek_path))
    {
        fprintf(stderr, "Error reading file");
        exit(1);
    }
    else
    {
        ornek_buffer[ ornek_buffer_length++ ] = '\0'; /* Just to be safe. */
    }
    fclose(ornek_path);


    int count = 0;
    for (int i = 0; i < ornek_buffer_length / 16 + 1; ++i)
    {
        unsigned char tempstr[17] = "";
        strncpy(tempstr, ornek_buffer + count, 16);

        count += 16;

        root = insert_contiguous(root, tempstr);
    }

    return root;
}


void crypting(Node* root, unsigned char key_buffer[])
{
    unsigned char cipher_buffer[16];
    while (root->next != NULL)
    {
        aes_encrypt(root->data, cipher_buffer, key_buffer, SIZE);
        strncpy(root->data, cipher_buffer, 16);
        root = root->next;
    }
}

void decrypting(Node* root, unsigned char key_buffer[])
{
    unsigned char decryption_buffer[16];
    while (root->next != NULL)
    {
        aes_decrypt(root->data, decryption_buffer, key_buffer, SIZE);
        strncpy(root->data, decryption_buffer, 16);
        root = root->next;
    }
}

void crypting_text(Node* root, unsigned char key_buffer[])
{
    unsigned char cipher_buffer[FILENAME_MAX];
    FILE* cipher_text_path = fopen("E:\\C_Projects\\MyProject\\AES\\cipher.txt", "w+");
    crypting(root, key_buffer);

    while (root->next != NULL)
    {
        fprintf(cipher_text_path, "%s", root->data);
        root = root->next;
    }

    fclose(cipher_text_path);
}

void decrypting_text(Node* root, unsigned char key_buffer[])
{
    unsigned char decrypted_buffer[FILENAME_MAX];
    FILE* decrypted_text_path = fopen("E:\\C_Projects\\MyProject\\AES\\decrypted.txt", "w+");
//    root = control_text(root, decrypted_text_path);

    decrypting(root, key_buffer);
    while (root->next != NULL)
    {
        fprintf(decrypted_text_path, "%s", root->data);
        root = root->next;
    }
    fclose(decrypted_text_path);
}


void expanded_key_creating(Node* root, unsigned char key_buffer[])
{
    unsigned char expanded_key_buffer[EXPANDEDKEYSIZE];
    expandKey(expanded_key_buffer, key_buffer, SIZE_16, EXPANDEDKEYSIZE);
    strncpy(root->data, expanded_key_buffer, EXPANDEDKEYSIZE);
}


void print_text(Node* root)
{
    while (root->next != NULL)
    {
        printf("%s", root->data);
        root = root->next;
    }
}




