# Data structure prototypes guidelines

These guidelines represent roughly what common functions I write for allocated/collection types. They aren't strict rules, just an organization I try to stick to, to make my code more uniform.

## Allocation
These functions should be present on types that have to reserve and release ressources.
This includes:
- data on the heap
- pointers from a library (for example the mlx)
- file descriptors
```C
// Allocates the object.
// Once an object has been allocated, it is fully operational.
// Initialization is done in the same step as allocation.
// The return value indicates if the allocation failed.
// For dup and alloc, the return value should never be ignored.
bool			ft_type_alloc(t_allocated_type *type, ...)
				__attribute__((warn_unused_result));
// The duplicated object should be completely separate from the original, with each inner ressource duplicated as well.
bool			ft_type_dup(t_any_type *type, t_allocated_type *dupped)
				__attribute__((warn_unused_result));
// For every allocation done, there is a *same level* free
// - no matter the code path.
// Which implies there should also be frees on each failure path,
// for example if reserve of push fails.
void			ft_type_free(t_allocated_type *type);

// Borrowed objects (of type t_borrowed_type) are not owning their data.
// They can still mutate the data, but they cannot reallocate it.
// Borrowed objects don't need to free anything,
// and so don't have any free function.
t_borrowed_type	ft_type_borrow(t_any_type *type);
```

## Capacity
These functions are reserved to collections that can grow, such as vector or string.
```C
// Alloc_empty if a variant of alloc for types supposed to grow
// The allocation is just a simple empty-initialization but
// it *must still be coupled with a free*.
void			ft_type_alloc_empty(t_allocated_type *type, ...);

// Reserves extra memory in advance so that N extra elements
// can be pushed without any reallocation.
// The return value should never be ignored.
// The object is still usable if reserve returned false,
// the extra memory just couldn't be reserved.
bool			ft_type_reserve(t_allocated_type *type, t_u32 additionnal);
				__attribute__((warn_unused_result));
// Reallocates the object in the smallest space possible, removing
// all the extra memory proviously reserved.
// The return value should never be ignored.
bool			ft_type_compact(t_allocated_type *type);
				__attribute__((warn_unused_result));
```

## Search
These functions apply to any collection of elements.
```C
// Returns true if the collection contains the element
bool	ft_type_contains(t_any_type *type, t_element element);
// Returns the number of times element appears in the collection
t_u32	ft_type_count(t_any_type *type, t_element element);
// Returns the position of the first (or last for rfind)
// occurence of the element in the collection.
// Here the prototypes assume the collection is indexed,
// otherwise pos returns directly a pointer to the element or its node
bool	ft_type_find(t_any_type *type, t_element element, t_u32 *pos);
bool	ft_type_rfind(t_any_type *type, t_element element, t_u32 *pos);
```
All the above functions can also have a comparator as parameter, like in vector.