## ATM 문제 - 11399

https://www.acmicpc.net/problem/11399

## 문제 정의

총 대기시간이 최소가 되도록 하는 것이므로 오름차순 정렬하여 문제 풀이함

## 문제 풀이

문제에서 [3, 1, 4, 3, 2] 이렇게 줄을 선다면, [2, 5, 1, 4, 3]로 줄을 대기시간 순으로 정렬하여 최소 시간을 구하였다. 

정렬된 줄의 대기 시간에서 첫번째 사람은 1분, 두번째 사람은 1+2=3분, 마지막 사람은 앞의 사람을 모두 기다려 13분을 대기하게 된다. 즉, 앞에서부터 수를 더한 것이다. 그래서 생각해낸 풀이는 다음과 같다.

```swift 
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
```
간단히 정리하면 배열을 정렬한 후, 앞의 값을 누적해서 다음 값에 더해주는 방식이다.

또 다른 풀이 방법은 없을까 하고 구글링을 해봤고, 나와 다른 방법으로 푼 사람을 발견했다.

[참고한 블로그](https://icksw.tistory.com/74)

이 글에서는 각 사람마다 대기 시간의 규칙성을 발견하여 풀이했다.

```
1번째: 1
2번째: 1 + 2
3번쨰: 1 + 2 + 3
4번째: 1 + 2 + 3 + 3
5번째: 1 + 2 + 3 + 3 + 4
```

나는 주어진 문제대로 각 사람마다의 대기시간을 구한 후 합했다면, 해당 블로그에서는 각 사람마다의 대기 시간 합을 계산하지 않고, 각 사람의 입장에서 자신이 줄에 선 위치 기준으로 몇 번 반복되는지를 곱하는 방식으로 풀었다. 가장 앞에 선 사람은 모든 사람들의 대기시간에 영향을 주기 때문이다.

```swift
import Foundation

func solution() -> Int {
  let n = Int(readLine()!)!
  var people = readLine()!.split(separator: " ").map { Int($0)! }
  people.sort()

  var result = 0

  for (index, value) in people.enumerated() {
    result += (value * (n - index))
  }

  return result
}

print(solution())
```

## 느낀점

문제 풀이를 떠올리는데 오래 걸렸던 문제가 아니었기에 금방 풀이했다. 나는 단순히 누적합 방식으로 풀었지만, 문제 속 규칙성을 찾아내어 풀어낸 방식을 보며 새로운 접근 방식도 익혔다. 이렇게 직접 푼 문제여도 다른 사람들의 풀이를 찾아보는건 언제나 큰 도움이 됨을 느낀다.