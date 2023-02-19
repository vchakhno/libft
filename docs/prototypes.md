# Prototypes guidelines

## Allocation
```C
bool	ft_type_alloc(t_type *type);
```
- The boolean result should never be ignored.

## Borrowing
```C
t_type	ft_type_borrow(t_type type);
```

## Duplication
```C
bool	ft_type_dup(t_type type, t_type *dupped);
```
- Same as allocation, the boolean result should never be ignored.

## Freeing
```C
void	ft_type_free(t_type *type);
```
- Free cannot fail.
