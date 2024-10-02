#include <stdio.h>
#include <stdlib.h>

struct node {
    float coeff;
    int expo;
    struct node* link;
};

// Function to insert a new term in descending order of exponent
struct node* insert(struct node* head, float coeff, int expo) {
    struct node* temp = malloc(sizeof(struct node));
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return head;  // Return unchanged list if malloc fails
    }
    temp->coeff = coeff;
    temp->expo = expo;
    temp->link = NULL;

    // Insert at the correct position based on exponent
    if (head == NULL || head->expo < expo) {
        temp->link = head;
        head = temp;
    } else {
        struct node* temp1 = head;
        while (temp1->link != NULL && temp1->link->expo >= expo) {
            temp1 = temp1->link;
        }
        // If the exponent already exists, just add the coefficients
        if (temp1->expo == expo) {
            temp1->coeff += coeff;
            free(temp);  // Free temp as we are not using it
        } else {
            temp->link = temp1->link;
            temp1->link = temp;
        }
    }
    return head;
}

// Function to add two polynomial linked lists
struct node* add(struct node* head, struct node* head1) {
    struct node* temp = head;
    struct node* temp1 = head1;
    struct node* head2 = NULL;

    while (temp != NULL && temp1 != NULL) {
        if (temp->expo == temp1->expo) {
            head2 = insert(head2, temp->coeff + temp1->coeff, temp->expo);
            temp = temp->link;
            temp1 = temp1->link;
        } else if (temp->expo > temp1->expo) {
            head2 = insert(head2, temp->coeff, temp->expo);
            temp = temp->link;
        } else {
            head2 = insert(head2, temp1->coeff, temp1->expo);
            temp1 = temp1->link;
        }
    }

    // Add remaining terms
    while (temp != NULL) {
        head2 = insert(head2, temp->coeff, temp->expo);
        temp = temp->link;
    }
    while (temp1 != NULL) {
        head2 = insert(head2, temp1->coeff, temp1->expo);
        temp1 = temp1->link;
    }
    return head2;
}

// Function to create a polynomial from user input
struct node* create(struct node* head) {
    int n, expo;
    float coeff;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("\nEnter the coefficient of term %d: ", i + 1);
        scanf("%f", &coeff);
        printf("Enter the exponent of term %d: ", i + 1);
        scanf("%d", &expo);
        head = insert(head, coeff, expo);
    }
    return head;
}

// Main function to demonstrate polynomial addition
int main() {
    struct node* head = NULL;
    struct node* head1 = NULL;
    struct node* head2 = NULL;

    printf("Creating first polynomial:\n");
    head = create(head);
    printf("Creating second polynomial:\n");
    head1 = create(head1);
    head2 = add(head, head1);

    // Display the resulting polynomial
    struct node* ptr = head2;
    while (ptr != NULL) {
        printf("(%.1fx^%d)", ptr->coeff, ptr->expo);
        ptr = ptr->link;
        if (ptr != NULL) {
            printf(" + ");
        } else {
            printf("\n");
        }
    }

    // Free memory (this part is omitted but should be implemented for real applications)

    return 0;
}
