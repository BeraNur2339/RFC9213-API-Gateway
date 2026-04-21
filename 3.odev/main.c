#include "priority_queue.h"
#include "rfc_parser.h"

int main() {
    PriorityQueue *api_gateway = create_queue(10);

    const char *headers[] = {"u=5", "u=0", "u=3", "u=1"};
    const char *paths[] = {"/log", "/payment", "/data", "/auth"};

    printf("--- API Gateway Calisiyor ---\n");
    for (int i = 0; i < 4; i++) {
        Request req;
        req.id = i + 100;
        req.urgency = parse_rfc9213_urgency(headers[i]);
        strcpy(req.api_path, paths[i]);
        push(api_gateway, req);
    }

    printf("\nOncelik Sirasina Gore Islenen Istekler:\n");
    while (api_gateway->size > 0) {
        Request current = pop(api_gateway);
        printf("ID: %d | Urgency: %d | Path: %s\n", current.id, current.urgency, current.api_path);
    }

    free_queue(api_gateway);
    return 0;
}