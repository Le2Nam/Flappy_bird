# Flappy_bird

1. Hướng dẫn cài đặt: cách lấy chương trình về, tất cả các câu lệnh, cài đặt để có thể chạy được chương trình

Lấy chương trình về: Fork repo về tài khoản GitHub và Clone code về

Vào Terminal gõ lệnh mingw32-make và .\main.exe để chơi thử

https://pie-cheque-188.notion.site/C-i-t-h-a-C-Windows-ef0a99a8dcae4dae86a39dc1cbc35980

2. Mô tả chung về trò chơi, các ý tưởng chính
 
Con chim sẽ rơi xuống theo quán tính, dùng phím Space hoặc mũi tên lên để khéo léo điều khiển con chim bay lên nhằm di chuyển con chim đi qua các ống nước, điểm người chơi sẽ hiện suốt quá trình chơi.

Mỗi lần thua sẽ hiện điểm số cao nhất đã đạt được cùng nút cho phép người chơi chơi lại.

Các đối tượng chính có trong game:

 •  nhân vật: con chim;
 
 •  thử thách: các cặp ống nước úp vào nhau với khe hở ở giữa để con chim bay qua;
 
 •  Điểm số, điểm cao nhất;
 
 •  Âm thanh;
 
 •  Sử dụng các thư viện của SDL;

3. Mô tả các chức năng đã cài đặt, kèm video minh họa (chèn link video youtube)

File Cfuntion.h: 

     •  Khai báo các thư viện cần dùng
     
File Texture.h: Thực hiện việc định nghĩa lớp cha là LTexture gồm các chức năng:

     •  Khởi tạo các biến
     
     •  Tải hình ảnh tại đường dẫn được chỉ định
     
     •  Tạo hình ảnh từ chuỗi phông chữ
     
     •  Hiển thị hình ảnh
     
File Flappy_bird.h: 

     •  Khai báo các hàm cần dùng trong file chính main.cpp
     
     •  Khai báo toàn bộ các biến cần dùng trong file chính main.cpp
     
file main.cpp

     • Toàn bộ code chính để chạy trò chơi
     
Link video youtube chơi demo: https://www.youtube.com/watch?v=RK-fkuha_kA

Các chức năng đã cài đặt:

• Điều khiển chim bay bằng phím cách (hoặc mũi tên lên) vượt qua cách ống nước được đặt độ cao thấp ngẫu nhiên trong màn hình

• Hiện thị điểm số trong suốt quá trình chơi (mỗi lần vượt qua ống tăng một điểm số)

• Hiện thị ảnh Game Over, điểm cao nhất và nút cho phép chơi lại mỗi lần chết

• Âm thanh nền, âm thanh khi chim bay lên, khi chim được cộng điểm và khi chim chết

• Hình ảnh con chim chân thực, có độ quay khi chim bay lên hay rơi xuống, có hoạt hình của chim

• Tăng độ khó dần dần bằng cách cứ mỗi 10 điểm, việc kiểm soát con chim bay lên sẽ gặp khó khăn hơn

Link video mô tả các chức năng đã cài đặt:

Phần 1: https://www.youtube.com/watch?v=oIz3YFbldU8

phần 2: https://www.youtube.com/watch?v=4Riy1c6wl-E

4. Các kỹ thuật lập trình được sử dụng trong chương trình (mảng, con trỏ, cấu trúc, lớp, đồ họa ...)

• SDL2

    Load hình ảnh, âm thanh, animation đơn giản,...

    Sử dụng các hàm trong thư viện SDL/SDL2

• C++

    sử dụng con trỏ, mảng, đồ họa để chạy và tối ưu hóa game
    
    dùng class, vận dụng tính đóng gói, kế thừa ...

• kĩ thuật khác

    Tính toán, căn chỉnh các đối tượng

    Vận dụng toán học để áp dụng tính vật lý cho game

5. Kết luận, hướng phát triển và các điều tâm đắc rút ra được sau khi hoàn thiện chương trình

• Kết luận:

Đây là 1 game cơ bản nhưng vẫn đầy đủ các chức năng cần thiết để người dùng có thể trải nghiệm 1 cách thoải mái nhất, giàu tính giải trí và rèn tính kiên trì, nhẫn nại cùng với sự thú vị cho người chơi

• Hướng phát triển:

Hướng phát triển tiếp theo của game :
  
   +)	Tạo một menu hoàn chỉnh, đẹp mắt cho phép vào chơi, exit game cùng các tính năng phụ khác
    
   +) Thực hiện được việc pause giữa game và nút cho phép trở về menu
  
   +)	Tiếp tục tối ưu các biến trong game, không để biến cố định để người nâng cấp game có thể tiện sửa chữa và tăng độ khó
   
   +)	Tạo ra đối tượng các item giữa các cột để mỗi lần chim chạm vào được ăn điểm, item này sẽ có tỉ lệ xuất hiện nhất định (không phải ở cột nào cũng có)
   
   +) Cho cột có độ rung lắc lên xuống nhẹ, tạo ra thêm trải nghiệm thú vị cho người chơi, 

• Điều tâm đắc sau khi hoàn thiện chương trình:

 Học được cách quản lý và liên kết các file trong 1 chương trình lớn
 
 Tự mình code từng bước một game hoàn chỉnh có thể chạy được
 
 Tối ưu hóa và clean code
 
 Cài các thư viện bên ngoài ide vào để thực hiện chương trình
 
 ** Các nguồn tham khảo để thực hiện game: Lazyfoo (https://lazyfoo.net/tutorials/SDL/)
