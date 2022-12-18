# String

## Introduction

This type provides a wrapper around C strings, and a bunch of utility functions to make dealing with strings easier and optimized.

## Layout

```C
typedef struct s_str
{
	char	*c_str;
	size_t	len;
	size_t	capacity;
}	t_str;
```

## Ownership

Strings can either own their data or borrow it.

Strings borrowing their data have no capacity. They are not garanted to be null-terminated, not garanted to be mutable, and cannot grow in length.

## Methods :

### Lifecycle/Memory
| Name			| Description
| -				| -
| alloc			| Allocates a new string, by duplicating the `char *` over a given length. The starting allocation depends on the given capacity.
| dup_c_str		| Allocates a new string, by duplicating the given `char *`. Its length and capacity are automatically deduced.
| from_int		| Allocates a new string, representing the given number in base 10. 
| reserve		| Reserve space for later, so that appending doesn't realloc. 
| free			| Frees up the space owned by the string.

### Accessing
| Name			| Description
| -				| -
| get_char		| Returns the char at the given index.
| get_slice		| Returns a slice of the given range.
| dup			| Duplicates the string over the given range.
| set_char		| Changes the char at the given index.
| set_slice		| Changes the chars in a given range.
| at			| Points to the char at the given index.
| first			| Points to the first char.
| last			| Points to the last char.

### Finding
| Name			| Description
| -				| -
| find_char		| Searches for a char and returns its address in the string.
| find_str		| Searches for a substring and returns its address in the string.
| index_char	| Searches for a char and returns its index.
| index_str		| Searches for a substring and returns its index.

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

### Resizing
| Name
| -
| replace		| Replaces all instances of a substring by another.
| append		| Appends a suffix to the end of the string.
| insert		| Inserts a substring at a given index in the string.
| remove		| Removes a part of the string.
| filter		| Discards characters that don't match the filter's condition.
| crop			| 
| adjust

### Grouping
| Name
| -
| split
| join
