#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

// Author: Alienkrishn [Anon4You]
// Github: https://github.com/Anon4You


// Function to display the banner
void banner() {
    printf("\n");
    printf(" ____________\n");
    printf("< ENC-HELPER > \n");
    printf(" ------------\n");
    printf("        \\   ^__^\n");
    printf("         \\  (oo)\\_______\n");
    printf("            (__)\\       )\\/\\\n");
    printf("                ||----w |\n");
    printf("                ||     || ver-1.0\n");
    printf("\n    Encrypt and decrypt strings\n\n");
}

// Function to reverse a string
void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Function to encode a string to base64
char *base64_encode(const char *input, int length) {
    const char *base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    char *encoded = (char *)malloc(((length + 2) / 3) * 4 + 1);
    int i = 0, j = 0;

    while (length--) {
        int octet_a = (i < length) ? (unsigned char)input[i++] : 0;
        int octet_b = (i < length) ? (unsigned char)input[i++] : 0;
        int octet_c = (i < length) ? (unsigned char)input[i++] : 0;

        int triple = (octet_a << 0x10) + (octet_b << 0x08) + octet_c;

        encoded[j++] = base64_chars[(triple >> 3 * 6) & 0x3F];
        encoded[j++] = base64_chars[(triple >> 2 * 6) & 0x3F];
        encoded[j++] = base64_chars[(triple >> 1 * 6) & 0x3F];
        encoded[j++] = base64_chars[(triple >> 0 * 6) & 0x3F];
    }

    for (int k = 0; k < (length % 3); k++) {
        encoded[j - 1 - k] = '=';
    }
    encoded[j] = '\0';
    return encoded;
}

// Function to decode a base64 string
char *base64_decode(const char *input, int length) {
    const char *base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    int i = 0, j = 0, octet_a, octet_b, octet_c, octet_d;
    char *decoded = (char *)malloc(length); // Allocate memory for the decoded string
    int decoded_length = 0;

    while (length && (input[length - 1] == '=')) {
        length--; // Remove padding '='
    }

    while (length--) {
        octet_a = (input[i] == '=') ? 0 : strchr(base64_chars, input[i]) - base64_chars;
        octet_b = (input[++i] == '=') ? 0 : strchr(base64_chars, input[i]) - base64_chars;
        octet_c = (input[++i] == '=') ? 0 : strchr(base64_chars, input[i]) - base64_chars;
        octet_d = (input[++i] == '=') ? 0 : strchr(base64_chars, input[i]) - base64_chars;

        decoded[decoded_length++] = (octet_a << 2) + (octet_b >> 4);
        if (octet_c < 64) {
            decoded[decoded_length++] = (octet_b << 4) + (octet_c >> 2);
        }
        if (octet_d < 64) {
            decoded[decoded_length++] = (octet_c << 6) + octet_d;
        }
    }
    decoded[decoded_length] = '\0';
    return decoded;
}

// Function for ROT13 encoding
void rot13_encode(char *str) {
    for (char *p = str; *p; p++) {
        if (isalpha(*p)) {
            char offset = islower(*p) ? 'a' : 'A';
            *p = (*p - offset + 13) % 26 + offset;
        }
    }
}

// Function to display usage
void usage() {
    banner();
    printf("USAGE:\n");
    printf("rev [String] - To reverse strings\n");
    printf("b64e [String] - Base64 encode\n");
    printf("b64d [String] - Base64 decode\n");
    printf("rot [String] - Rotate strings using ROT13 method\n");
    printf("help/h - To show this message\n");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        usage();
        return 1;
    }

    banner(); // Display the banner at the start

    char *option = argv[1];
    char *input_string = argv[2];

    if (strcmp(option, "rev") == 0) {
        reverse_string(input_string);
        printf("Reversed Text: %s\n", input_string);
    } else if (strcmp(option, "b64e") == 0) {
        char *encoded = base64_encode(input_string, strlen(input_string));
        printf("Encoded Text: %s\n", encoded);
        free(encoded);
    } else if (strcmp(option, "b64d") == 0) {
        char *decoded = base64_decode(input_string, strlen(input_string));
        printf("Decoded Text: %s\n", decoded);
        free(decoded);
    } else if (strcmp(option, "rot") == 0) {
        rot13_encode(input_string);
        printf("ROT13 Text: %s\n", input_string);
    } else if (strcmp(option, "help") == 0 || strcmp(option, "h") == 0) {
        usage();
    } else {
        printf("Invalid option: %s\n", option);
        usage();
        return 1;
    }

    return 0;
}
