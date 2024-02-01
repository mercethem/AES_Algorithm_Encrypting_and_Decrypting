//
#ifndef PROJECT_UTILITY_H
#define PROJECT_UTILITY_H


#include <stdio.h>

#define MAXLIMIT 10000


struct Node
{
    unsigned char data[17];
    struct Node* next;
};


typedef struct Node Node;

Node* control_text(Node* root, unsigned char director[]);
void crypting(Node* root, unsigned char key_buffer[]);
void decrypting(Node* root, unsigned char key_buffer[]);
void expanded_key_creating(Node* root, unsigned char key_buffer[]);
void print_text(Node* root);
void crypting_text(Node* root, unsigned char key_buffer[]);
void decrypting_text(Node* root, unsigned char key_buffer[]);


Node* insert_contiguous(Node* root, unsigned char sval[]);
Node* control_files(Node* root);
void compare(Node* root);
void deleteAll(Node** root);
void hash_control(Node* root);
void print_list(Node* root);
void print_hash_list(Node* root);


#endif //PROJECT_UTILITY_H
