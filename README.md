Denetimsiz Öğrenme kütüphanesi

Bu küçük çaplı denetimsiz öğrenme kütüphane uygulamasında KMEANS, KMEANS++, KMEDIAN, Least Square,
Hierarchical Clustering, DBSCAN algoritmaları uygulanmıştır. Kütüphane için yardımı olabilecek operasyonlar
geliştirilmiştir. Bunlardan birisi dosya okuma .csv, .txt vb. verilerini doğru formatta okuyup işlenebilecek
hale getirmeye yaramaktadır, bir diğeri ise komut satırına verilerin doğru ve güzel bir şekilde yazılmasını
sağlamak için geliştirilmiştir. Son olarak yardımcı olarak mesafe algoritmaları ve matris manipülasyonu
yapılmıştır. Uygulamanın integrasyon testleride yapılmış ve uygulamanın senaryolar üzerinde çalışması test
edilmiştir. Uygulama bir CMake projesidir. Herhangi bir CMake projesi build eder gibi proje build edilebilir.
Visual Studio code ortamında CMake, C++ desteği var ise kolaylıkla githubdan alınabilir ve geliştirilebilir.

K-Base Algoritmalar:
K-Means++, K-Median, K-Means benzer özelliklere sahip algoritmalar oldukları için bu uygulamada kbase sınıfının
altında tanımlanmışlardır. Rastgele orta nokta atama ve orta noktaları güncelleme işlemleri her ksınıfı
algoritma için farklı imzalarla tekrar yazılmıştır. K sınıfı algoritmaları aralarındaki fark bu şekilde
sağlanmıştır.

Agglomerative Algoritmalar:
Hiyerarşik sıralama algoritması x ve y için 2 boyutlu tanımlamaları yapılmıştır. Örnek bir algoritmadır 2 boyut
destekleyen, algoritmanın anlaşılabilirliğini arttırıyor. Bir diğer uygulanmasında ise tüm boyutları destekleyen
bir şekilde gerçekleştirilmiştir.

Least Squares Regression:
2 Boyut data ile çalışmayı destekleyecek bir şekilded uygulması yapılmıştır. 3 boyutlu kullanımı desteklemez.

DBSCAN Algoritması:
Algoritma tanımlanmış eps ve minPoint değerlerine göre tüm boyutlardaki datalar ile çalışmayı mümkün kılar bir
haldedir.