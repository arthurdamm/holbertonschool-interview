#include "lists.h"

/**
 * find_listint_loop - uses floyd's algo to find loop
 * @head: pointer to head node of list
 * Return: pointer to node where loop starts
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *fast = head, *slow = head;

	if (!head)
		return (NULL);
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			fast = head;
			while (fast && fast->next)
			{
				fast = fast->next->next;
				slow = slow->next;
				if (fast == slow)
				{
					return (slow);
				}
			}
		}
	}
	return (NULL);
}
