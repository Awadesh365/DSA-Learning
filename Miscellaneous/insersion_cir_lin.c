// insersion function in circular linkedlist
void add_after(int data, int pos)
{
    struct node *tmp, *q;
    int i;
    q = last->link;
    for (i = 0; i < pos - 1; i++)
    {
        q = q->link;
        if (q == last->link)
        {
            prinf("there are less than %d elements\n");
            return;
        }
    }
    tmp = (void *)malloc(sizeof(struct node));
    tmp->link = q->link;
    tmp->info = data;
    q->link = tmp;
    if (q == last)
        last = tmp;
}