# Đồ án môn học: OOP

# Mô tả game play

## Nhân vật

### Danh sách nhân vật
  Được lưu trong ListHero.txt
### Các chỉ số của nhân vật
  Mỗi Hero có tất cả 4 chỉ số đó là:
  - Máu: nếu chỉ số máu về 0 thì nhân vật sẽ tính là chết.
  - Công: là sức mạnh sát thương gây lên đối phương.
  - Thủ: khả năng kháng một phần sức mạnh công của đối phương.
  - Tốc độ đánh: Là thời gian cho 1 chu kì ra đòn của Hero, chỉ số này càng nhỏ thì tốc độ đánh càng nhanh và ngược lại.
### Thuộc tính của nhân vật
  Mỗi Hero sẽ thuộc về một loại thuộc tính trong ngũ hành kim/mộc/thủy/hỏa/thổ (Fire/Water/Metal/Earth/Wood). Tuân theo quy luật tương sinh tương khắch mà các Hero sẽ buff chỉ số hoặc khắc chế nhau khi đấu đối kháng hoặc cùng trong đội.

### Cùng đội
  - Tương khắc: theo hướng mũi tên thì Hero bị khắc thì chỉ số thời gian ra đòn sẽ tăng lên 10%
  - Tương sinh: theo hướng mũi tên nếu hai Hero tương sinh thì Hero được sinh sẽ tăng thêm chỉ số máu 15%
### Đối kháng
Nếu Hero khắc tần công Hero bị khắc thì chỉ số thủ của Hero bị khắc sẽ giảm 50% và công của Hero thuộc tính khắc sẽ được cộng thêm 10%.

## Hiệp đấu

### Xử lý thắng thua
Các HERO sẽ đấu theo từng cặp, tuân theo thứ tự sắp xếp ban đầu. Team thắng là team cho nhiều Hero sống sót hơn.
### Thời gian.
Nếu đấu với NPC thì thời gian mặc định của một trận đấu là 1 phút. Nếu 2 người chơi đấu nhau thì thời gian hiệp đấu sẽ do 2 người chơi thỏa thuận nhập vào từ bàn phím.
### Môi trường
Sau khi hai bên chọn xong danh sách tướng thì hệ thống sẽ chọn gẫu nhiên môi trường cho hiệp đầu trong 5 thuộc tính (Kim/mộc/thủy/hỏa/thổ). Như vậy các chỉ số của các tướng sẽ thay đổi theo quy tắc sau:
- Trùng nhau: Các chỉ số giữ nguyên như mặc định
- Tương sinh: Chỉ số máu sẽ tăng thêm 5%, Chỉ số tốc độ sẽ giảm đi 10%
- Trương khắc: Chỉ số máu sẽ giảm 3%


## User đấu với NPC.
NPC sẽ chọn ngẫu nhiên 3 tướng từ trong danh sách Hero được load từ file ListHero.txt. Hệ thống in ra danh sách Hero cho người chơi lựa chọn. Người chơi sẽ lựa chọn 3 tướng bằng cách nhập số thứ tự trước dòng của Hero đó từ bàn phím


## User đấu với User.
Thao tác trên cùng một giao diện trên cùng 1 PC
- User 1 sau khi đăng nhập sẽ chọn phương thức User đấu User
- User 1 chọn 3 tướng
- User 2 chọn 3 tướng
- User 1/2 chọn time cho hiệp đấu: có 3 lựa chọn 1 phút (1000); 2 phút (2000); và 5 (5000)phút.

## Kết quả
- Kết quả sẽ được in ra màn hình và tự động lưu vào vào file Log.txt.
- Mỗi dòng là thông tin của 1 hiệp đấu.
- Thông tin được lưu trữ theo cấu trúc sau: <thời gian gio/phut/giay/ngày/tháng/nam><Ten người chơi 1|NPC><Danh sách Hero của người chơi 1|NPC><Người chơi 2>< Danh sách Hero của người chơi 2><kết quả>
- Người chơi có thể xem lịch sử lưu trong file log (chỉ in thời gian ra màn hinh); nếu muốn xem chi tiết thông tin của hiệp đấu nào đó, thì người chơi cung cấp thời gian từ bàn phím.
