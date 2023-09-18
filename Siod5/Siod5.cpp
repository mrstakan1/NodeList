#include "Node.h"

void insert(Node*& head, int value)
{
    Node* temp = new Node;
    temp->data = value;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        Node* p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

void display(Node* head)
{
    Node* p = head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void create_array(Node* head, Node** A)
{
    for (int i = 0; i < 10; i++)
    {
        A[i] = NULL;
    }

    Node* p = head;
    while (p != NULL)
    {
        int num = p->data;
        int index = 0;

        if (num < 10)
        {
            index = 0;
        }
        else
        {
            index = num / 10;
        }

        if (A[index] == NULL)
        {
            A[index] = new Node;
            A[index]->data = num;
            A[index]->next = NULL;
        }
        else
        {
            Node* temp = new Node;
            temp->data = num;
            temp->next = NULL;

            Node* q = A[index];
            while (q->next != NULL)
            {
                q = q->next;
            }
            q->next = temp;
        }

        p = p->next;
    }
}

void delete_list(Node*& head)
{
    Node* p = head;
    while (p != NULL)
    {
        Node* temp = p;
        p = p->next;
        delete temp;
    }
    head = NULL;
}

void create_list(Node** A, Node*& head)
{
    for (int i = 0; i < 10; i++)
    {
        Node* p = A[i];
        while (p != NULL)
        {
            insert(head, p->data);
            p = p->next;
        }
    }
}

void move(Node*& L)
{
    Node* last = nullptr;
    Node* first = L;

    while (first->next)
    {
        last = first;
        first = first->next;
    }

    last->next = 0;
    first->next = L;

    L = first;
}

int main()
{
    setlocale(LC_ALL, "ru-RU");
    cout << "Практическая работа №5. \"Однонаправленный динамический список\". ИКБО-07-22. Шилов Павел" << endl;

    Node* head = NULL;

    cout << "Односвязный список:\n";

    insert(head, 1);
    insert(head, 10);
    insert(head, 11);
    insert(head, 12);
    insert(head, 20);
    insert(head, 21);
    insert(head, 22);
    insert(head, 30);
    insert(head, 31);
    insert(head, 32);
    insert(head, 33);
    insert(head, 40);
    insert(head, 41);
    insert(head, 42);
    insert(head, 43);
    insert(head, 44);
    insert(head, 50);
    insert(head, 51);
    insert(head, 52);
    insert(head, 53);
    insert(head, 54);
    insert(head, 55);
    insert(head, 65);

    display(head);

    Node** A = new Node * [10];

    int userInput;
    bool isArrayCreated = false;

    cout << "Выберите операцию:\n";
    cout << "1 - Создать массив А\n";
    cout << "2 - Удаление списка L\n";
    cout << "3 - Создать список L, включая в него списки массива A по индексам от 0 до 9\n";
    cout << "0 - выход\n";

    cin >> userInput;

    while (userInput != 0)
    {
        system("CLS");
        cout << "Выберите операцию:\n";
        cout << "1 - Создать массив А\n";
        cout << "2 - Удаление списка L\n";
        cout << "3 - Создать список L, включая в него списки массива A по индексам от 0 до 9\n";
        cout << "0 - выход\n";

        if (userInput == 1)
        {
            isArrayCreated = true;
            create_array(head, A);

            cout << "Array A:\n";

            for (int i = 0; i < 10; i++)
            {
                cout << "Array " << i << ": ";
                display(A[i]);
            }
        }

        if (userInput == 2)
        {
            delete_list(head);

            cout << "Список L удален.\n";
        }

        if (userInput == 3)
        {
            if (isArrayCreated == true)
            {
                create_list(A, head);
                cout << "Новый список L создан!\n";
                display(head);
            }
            else
            {
                cout << "Ошибка! Сначала создайте список A\n";
            }
        }

        cin >> userInput;
    }
}