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
* ft_strlcpy
* ft_strncmp
* ft_strndup
* ft_strnstr
* ft_strrchr

##### stdlib

* ft_atoi
* ft_calloc

### Part 2 - Additional functions

#### ft_itoa
> Allocates (with malloc(3)) and returns a string
> representing the input integer.
> Negative numbers are supported.
> Returns NULL if allocation fails.

#### ft_strmapi

#### ft_split
> Allocates (with malloc(3)) and returns an array of strings obtained by
> separating the input string with the input character used as the delimiter.
> The resulting array is terminated with a NULL pointer.
> Returns NULL if allocation fails.

#### ft_strjoin
> Allocates (with malloc(3)) and returns a new string resulting from
> the concatenation of two strings.
> Returns NULL if allocation fails.

#### ft_strtrim
> Allocates (with malloc(3)) and returns a copy of the input string without
> the set's characters at the beginning and at the end.
> Returns NULL if allocation fails.

#### ft_substr
> Allocates (with malloc(3)) and returns a substring from the original string.
> This new string starts at the input index.
> Returns NULL if allocation fails.
