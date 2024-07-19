void del(int data)
{
    struct node *tmp, *q;
    if (start->info == data) // deletion of first node
    {
        tmp = start;
        start = start->link;
        free(tmp);
        return;
    }
    q = start;
    while (q->link->link != null) // deletion in between
    {
        if (q->link->info == data)
        {
            tmp = q->link;
            q->link = tmp->link;
            free(tmp);
            return;
        }
        q = q->link;
    }
    if (q->link->info == data) // deletion of last element
    {
        tmp = q->link;
        free(tmp);
        q->link = null;
        return;
    }
    printf("Element not found");
}

// insersion at beginnning
void(int data)
{
    struct node *tmp;
    tmp = (void *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = start;
    start = tmp;
}

// insersion in between

void(int data int pos)
{
    struct node *tmp, *q;
    int i;
    q = start;
    tmp = (void *)malloc(sizeof(struct node));
    for (i = 0; i < pos - 1; i++)
    {
        q = q->link;
    }
    tmp->info = data;
    tmp->link = q->link;
    q->link = tmp;
}