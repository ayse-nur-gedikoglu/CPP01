
Memory allocation, pointers to members, references, switch statement

## Genel Bakış

Memory allocation, pointers to members,
references and switch statements

## Bellek Tahsisi: C vs C++

C'de memory allocation için `malloc()` ve `free()` kullanıyorduk. `malloc` ve `free` C++'da da kullanılabilir, ancak bunu yapmak iyi bir fikir değildir. Çünkü bir obje için `malloc` ile yer ayırdığınızda **Constructor çağrılmayacaktır**. Aynı şekilde, `free` kullandığımızda **Destructor çağrılmaz**.

Bundan dolayı, C++ objeleri için allocation yaparken bunun yerine **`new`** ve **`delete`** kullanacağız.

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

ex00: You have to determine in which case it is better to allocate zombies on the stack or the heap.

ex01: Nesne Dizisi Oluşturmanın Kuralı

C++'da bir sınıftan (class) bir dizi oluşturduğunuzda (örneğin: Nesne* dizi = new Nesne[10];), derleyici her bir dizi elemanı için parametresiz (varsayılan) yapıcıyı çağırmak zorundadır.

Bunun temel nedeni şudur: new[] operatörü, oluşturulan her bir elemana farklı parametreler göndermenize izin vermez. Her eleman için aynı başlangıç prosedürünü uygular.


Peki ya olmazsa?

Eğer bir sınıfta sadece parametreli bir yapıcı tanımladıysanız (örneğin: Nesne(int x)), derleyici sizin yerinize otomatik olarak oluşturduğu "gizli" varsayılan yapıcıyı iptal eder.

Bu durumda:

Nesne n(5); diyerek tek bir nesne oluşturabilirsiniz.

Ancak Nesne* dizi = new Nesne[5]; dediğinizde kod derlenmez. Çünkü derleyici, bu 5 nesneyi oluştururken hangi x değerini kullanacağını bilemez ve "uygun bir varsayılan yapıcı bulunamadı" hatası verir.

ex02: C++'da referans, halihazırda var olan bir değişkenin diğer adıdır (alias). Bir değişkene referans atadığında, artık o değişkene ulaşmak için iki farklı ismin olur.

Kısa cevap: Hayır, C dilinde referans yoktur. C'de bir verinin adresine ulaşmak veya onu bir fonksiyona göndermek için sadece Pointer (İşaretçi) kullanabilirsin. Referanslar C++ ile birlikte hayatımıza girmiştir.

Hadi referansı biraz daha yakından tanıyalım:

1. Referansın Mantığı Nedir?

Referansı bir insanın "lakabı" gibi düşünebilirsin. Örneğin, ismi "Ayşe" olan birine arkadaşları "A" diyorsa, her iki isim de aynı kişiyi temsil eder. "A"ya bir şey ikram edersen, "Ayşe" yemiş olur.

2. Referans ve Pointer Arasındaki 3 Dev Fark

C'den gelen biri için referans başta gereksiz görünebilir, ama şu farklar onu çok güçlü kılar:

NULL Olamazlar: Bir referans oluşturduğun anda onu bir değişkene bağlamak zorundasın. int &ref; diyerek boş bırakamazsın. Pointerlar ise NULL olabilir.

Adres Değiştiremezler: Bir referans bir değişkene bağlandığında, artık ölene kadar o değişkene aittir. Onu söküp başka bir değişkene bağlayamazsın. Pointerlar ise her an başka bir adresi gösterebilir.

Sözdizimi (Syntax) Kolaylığı: Referansı kullanırken * veya -> gibi işaretlerle uğraşmazsın. Sanki normal bir değişkenmiş gibi davranır.

3. C'de Neden Yok, C++'da Neden Var?

C Dili: "Her şeyi açıkça yap" felsefesini savunur. Eğer bir adrese erişeceksen bunu işaretçi (*) ile yapmalısın.

