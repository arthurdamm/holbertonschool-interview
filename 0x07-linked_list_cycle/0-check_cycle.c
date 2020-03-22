#include "lists.h"

/**
 * check_cycle - check if linked list is cyclical
 * @list: pointer to head of list
 * Return: 1 if cyclical else 0
 */
int check_cycle(listint_t *list)
{
	listint_t *fast, *slow;

	fast = slow = list;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return (1);
	}
	return (0);	
}
