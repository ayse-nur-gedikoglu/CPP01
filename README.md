# CPP01

Memory allocation, pointers to members, references, switch statement

## Genel Bakış

Memory allocation, pointers to members,
references and switch statements

## Bellek Tahsisi: C vs C++

- C'de dinamik bellek tahsisi için `malloc`/`free` kullanılır.
- C++'ta ise `new`/`delete` ve `new[]`/`delete[]` kullanılır.

## Örnekler

### C Kodu

```c
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int *ptr;

    ptr = malloc(10 * sizeof(int));
    if (ptr == NULL) {
        perror("malloc failed");
        return 1;
    }

    for (int i = 0; i < 10; ++i)
        ptr[i] = i;

    free(ptr);
    return 0;
}
```

### C++ Kodu

```cpp
#include <iostream>

int main()
{
    int *ptr = new int[10];

    for (int i = 0; i < 10; ++i)
        ptr[i] = i;

    delete[] ptr;
    return 0;
}
```

Bu iki kod parçası aynı mantıksal işi yapar: 10 tamsayılık bir blok ayırır, kullanır ve serbest bırakır. Ancak C ve C++'ta hata yönetimi ve dil özellikleri farklıdır.

