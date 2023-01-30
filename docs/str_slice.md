# String slice

## Introduction

This type represents a string borrowed from another source. It is a non-owning variant of `t_str`.
Because `t_str_slice` doesn't own its data, you don't need to alloc nor to free it.
Any `t_str` can be converted to a `t_str_slice`. It's recommanded that functions that take a `t_str` as parameter but don't need to resize it take a `t_str_slice` instead.

## Layout

```C
typedef struct s_str_slice
{
	char	*c_str;
	size_t	len;
}	t_str_slice;
```

## Methods :

### Creation
| Name			| Description
| -				| -
| borrow_c_str	| Creates a `t_str_slice` from a char *
| slice			| Creates a `t_str_slice` from a char *

### Accessing
| Name			| Description
| -				| -
| get_char		| Returns the char at the given index.
| get_slice		| Returns a slice of the given range.
| dup			| Duplicates the string over the given range.
| set_char		| Changes the char at the given index.
| set_slice		| (Unsure?) Changes the chars in a given range.
| at			| Points to the char at the given index.
| first			| Points to the first char.
| last			| Points to the last char.

### Finding
| Name			| Description
| -				| -
| find_char		| Searches for a char and returns both its address and a pointer to it.
| find_str		| Searches for a char and returns both its address and a pointer to it.

### Comparison
| Name			| Description
| -				| -
| equal			| Check whether two strings are equal.
| compare		| Compare two strings alphabetically.
| startswith	| Check the strings starts with the given prefix.
| contains		| Check whether the string contains the given substring.

### Checking
| Name			| Description
| -				| -
| isalpha		| Checks whether the string contains only alphabetical characters.
| isalnum		| Checks whether the string contains only alphanumeric characters.
| islower		| Checks whether the string contains only lowercase characters.
| isprint		| Checks whether the string contains only printable characters.
| isupper		| Checks whether the string contains only uppercase characters.
| isblank		| Checks whether the string contains only whitespaces.

### Mutate
| Name			| Description
| -				| -
| encode		| Replaces characters by others. 
| tolower		| Puts every character in lowercase.
| toupper		| Puts every character in uppercase.
| capitalize	| Puts every first letter of an alphabetical word in uppercase, and the others in lowercase.
| map			| 

### Grouping
| Name
| -
| split
| join
