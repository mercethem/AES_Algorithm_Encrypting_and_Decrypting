//PROJECT_UTILITY_H
#ifndef PROJECT_UTILITY_H
#define PROJECT_UTILITY_H


#include <stdio.h>

#define MAXLIMIT 10000
#define DECRYPTED_TEXT "E:\\C_Projects\\MyProject\\AES\\decrypted.txt"
#define CIPHER_TEXT "E:\\C_Projects\\MyProject\\AES\\cipher.txt"


struct Node
{
    unsigned char data[17];
    struct Node* next;
};


typedef struct Node Node;

Node* control_text(Node* root, unsigned char director[]);
void encrypting(Node* root, unsigned char key_buffer[]);
void decrypting(Node* root, unsigned char key_buffer[]);
void encrypting_text(Node* root, unsigned char key_buffer[]);
void decrypting_text(Node* root, unsigned char key_buffer[]);

Node* insert_contiguous(Node* root, unsigned char sval[]);
void deleteAll(Node** root);
void print_list(const Node* root);



#endif //PROJECT_UTILITY_H
