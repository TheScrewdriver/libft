# libft
A C-library of usual functions

## Library content

### Part 1 - libc

##### ctype

* ft_isalnum
* ft_isalpha
* ft_isascii
* ft_isdigit
* ft_islower
* ft_isprint
* ft_isupper
* ft_tolower
* ft_toupper

##### strings

* ft_bzero
* ft_memchr
* ft_memcmp
* ft_memcpy
* ft_memmove
* ft_memset
* ft_strchr
* ft_strcpy
* ft_strdup
* ft_strlen
* ft_strlcat
* ft_strncmp
* ft_strlcpy
* ft_strnstr
* ft_strrchr 

##### stdlib

* ft_atoi
* ft_calloc

### Part 2 - Additional functions

#### ft_strjoin
> Allocate (with malloc(3)) and returns a new string resulting from
> the concatenation of two strings.
> Returns NULL if allocation fails.

#### ft_substr
> Allocate (with malloc(3)) and returns a substring from the original string.
> This new string starts at the input index.
> Returns NULL if allocation fails.
