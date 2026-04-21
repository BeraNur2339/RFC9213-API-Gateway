#include "rfc_parser.h"

int parse_rfc9213_urgency(const char *header) {
    int urgency = 3; 
    const char *ptr = strstr(header, "u=");
    if (ptr) {
        urgency = atoi(ptr + 2);
    }
    if (urgency < 0) urgency = 0;
    if (urgency > 7) urgency = 7;
    return urgency;
}