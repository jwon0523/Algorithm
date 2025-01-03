import Foundation

// 1. 입력 받기
let k = Int(readLine()!)! // 약수의 개수
// 약수 배열
let divisors = readLine()!.split(separator: " ").map { Int($0)! }
// 2. 정렬하여 최소값과 최대값 찾기
let minDivisor = divisors.min()! // 가장 작은 약수
let maxDivisor = divisors.max()! // 가장 큰 약수

// 3. 최소값과 최대값 곱하기
let n = minDivisor * maxDivisor

// 4. 결과 출력
print(n)
