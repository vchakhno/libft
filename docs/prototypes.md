# Prototypes guidelines

## Allocation
```C
bool	ft_type_alloc(t_type *type);
```
- The boolean result should never be ignored.

## Borrowing
```C
t_type	ft_type_borrow(t_type type, t_type *out);
```
- The out parameter is the same as the return.
You can ignore it and use NULL instead.

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

## Faillible get
```C
t_maybe_btype	ft_type_get_btype(t_type *type, size_t index, t_btype *out);
```
- t_maybe_btype can be ignored and used as t_btype when you're sure get worked.
- Out is the same as the t_btype part of the result, and you can pass NULL instead to ignore it.

## Faillible set
```C
bool	ft_type_get_btype(t_type *type, t_btype btype, size_t index);
```
- Nothing special here actually. You can ignore the return if you're sure set worked.