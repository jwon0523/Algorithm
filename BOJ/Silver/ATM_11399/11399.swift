// 직접 푼 풀이

import Foundation

let n = Int(readLine()!)!
var arr: [Int] = []

arr = readLine()!.split(separator: " ").map { Int($0)! }
arr.sort()

var sum = 0

for i in 0..<n-1 {
  arr[i+1] = arr[i+1] + arr[i]
}

// 1, 2, 3, 3, 4 
// 1, 3, 6, 9, 13
/*
for i in arr {
 sum += i 
}
print(sum)
*/

print(arr.reduce(0, +))