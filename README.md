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










