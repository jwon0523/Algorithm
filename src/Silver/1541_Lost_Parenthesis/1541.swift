import Foundation
// ex)55-50+40

let input = readLine()!

// -를 기준으로 두 개의 덩어리(배열)로 만들어줌
let minusParts = input.components(separatedBy: "-").map {
  $0.components(separatedBy: "+").map { Int($0)! }
}
// minusParts: [[55], [50, 40]]

/// 첫 번째 덩어리 모두 더해줌
/// reduce(0, +): 0부터 시작해서 배열의 요소 모두 더하는 작업(0 + 55)
var result = minusParts[0].reduce(0, +) 

for part in minusParts.dropFirst() { // dropFirst(): 첫번째 배열은 버리고 나머지 배열 반환
	/// 두번째 덩어리 모두 더한 후 빼기 진행
  result -= part.reduce(0, +) 
}

print(result)