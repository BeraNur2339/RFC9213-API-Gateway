🚀 RFC 9213 API Gateway Simulation (Min-Heap)
Bu proje, Veri Yapıları ve Algoritmaları dersi kapsamında, modern ağ protokollerini (RFC 9213) temel alarak geliştirilmiş bir Öncelikli API Gateway simülasyonudur. Sistem, gelen ağ isteklerini önem derecelerine göre sıralayarak en kritik işlemin (örneğin ödeme işlemleri) her zaman en önce işlenmesini garanti eder.

🛠 Teknik Mimari
Proje, yüksek performans ve ölçeklenebilirlik için Binary Min-Heap veri yapısını kullanır.

Veri Yapısı: Min-Heap (Dinamik Dizi tabanlı).

Zaman Karmaşıklığı: * Ekleme (Push): O(logn)

En Öncelikliyi Çekme (Pop): O(logn)

En Öncelikliyi Görüntüleme: O(1)

Protokol Desteği: HTTP Extensible Priorities (RFC 9213) u= parametre parsing.

📂 Proje Yapısı
Proje, modüler programlama prensiplerine uygun olarak 5 ana dosyadan oluşmaktadır:

main.c: Sistem simülasyonunu başlatan ve test senaryolarını yürüten ana motor.

priority_queue.c/h: Heap algoritmaları, realloc ile dinamik bellek yönetimi ve kuyruk operasyonları.

rfc_parser.c/h: Ham HTTP header verilerinden öncelik değerlerini ayıklayan protokol katmanı.

💻 Kurulum ve Çalıştırma
MacBook veya herhangi bir GCC yüklü sistemde projeyi derlemek için:

📊 Örnek Çıktı Analizi
Sisteme sırasıyla /log (u=5), /payment (u=0), /data (u=3) ve /auth (u=1) istekleri gönderildiğinde; algoritma bunları otomatik olarak şu öncelikle işler:

u=0 (En Acil): /payment

u=1: /auth

u=3: /data

u=5 (En Düşük): /log

🎓 Akademik Kazanımlar
Dinamik bellek yönetimi ve malloc/realloc/free kullanımı.

Logaritmik zaman karmaşıklığına sahip veri yapılarının implementasyonu.

Modüler kod mimarisi ve başlık dosyası yönetimi.

Geliştiren: Bera Nur Tursun

Kurum: Kırklareli Üniversitesi - Yazılım Mühendisliği
