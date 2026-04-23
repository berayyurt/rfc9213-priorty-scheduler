# PriorityFlow – RFC 9213 API Scheduler

## Proje Tanımı

Bu proje, API Gateway’e gelen HTTP isteklerini RFC 9213 standardına göre önceliklendirerek işleyen bir Priority Request Scheduler sistemidir.

İstekler, `Priority: u=x` formatındaki header’dan parse edilir ve Min-Heap tabanlı bir Priority Queue içinde saklanır. En küçük öncelik değerine sahip istek önce işlenir.

---

## Amaç

* Priority Queue veri yapısını uygulamak
* Min-Heap algoritmasını kullanmak
* Modüler C mimarisi kurmak
* Güvenli bellek yönetimi sağlamak

---

## Kullanılan Yapılar

* C dili
* Min-Heap (Binary Heap)
* Dinamik bellek yönetimi (`malloc`, `realloc`, `free`)
* RFC 9213 öncelik parse işlemi

---

## Mimari Yapı

Sistem üç katmandan oluşur:

1. **Parser**
   HTTP header’dan öncelik değeri çıkarır

2. **Priority Queue (Heap)**
   Min-Heap ile istekleri sıralar

3. **Main**
   Sistemi çalıştırır ve test eder

---

## Proje Yapısı

```
project/
├── main.c
├── parser.c
├── parser.h
├── heap.c
├── heap.h
├── request.h
```

---

## Derleme ve Çalıştırma

Derleme:

```
gcc main.c heap.c parser.c -o scheduler
```

Çalıştırma:

```
./scheduler
```

---

## Algoritma Analizi

* Insert: O(log n)
* Extract Min: O(log n)
* Peek: O(1)

---

## Neden Min-Heap

Min-Heap, en küçük öncelikli elemana sabit zamanda erişim sağlar ve ekleme/silme işlemlerini logaritmik zamanda gerçekleştirir. Array tabanlı yaklaşımlara göre daha verimlidir.

---

## Bellek Yönetimi

* malloc ile başlangıç tahsisi
* realloc ile dinamik büyütme
* realloc işlemi geçici pointer ile kontrol edilmiştir
* free ile bellek serbest bırakılmıştır

---

## Demo

Örnek giriş:

```
u=3, u=1, u=5, u=2, u=0
```

Örnek çıktı:

```
Request 5 (priority 0)
Request 2 (priority 1)
Request 4 (priority 2)
Request 1 (priority 3)
Request 3 (priority 5)
```

---

## Sonuç

Sistem modüler, genişletilebilir ve performans odaklıdır. RFC 9213 uyumlu bir önceliklendirme mekanizması başarıyla uygulanmıştır.
