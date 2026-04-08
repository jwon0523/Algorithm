import Foundation

while let input = readLine(), let n = Int(input) {
  var remainder = 1
  var length = 1

  // 나누어 떨어지는 경우 탈출 -> n의 배수
  while remainder % n != 0 {
    remainder = (remainder * 10 + 1) % n
    length += 1
  }

  print(length)  
}
