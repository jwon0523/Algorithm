import Foundation

let input = readLine()!.split(separator: " ").map { Int($0)! }
let n = input[0] // 정점의 개수
let m = input[1] // 간선의 개수
let start = input[2] // 탐색을 시작할 정점의 번호

// 그래프의 리스트화를 위한 2차원 배열 생성(노드는 1부터 카운팅 되기 때문에 n+1)
var arrayList = [[Int]](repeating: [Int](), count: n + 1)
var sortedDFS = [Int]()
var sortedBFS = [Int]()

// 간선 크기만큼 반복하면서 인접 행렬 생성
for _ in 0..<m {
  let value = readLine()!.split(separator: " ").map { Int($0)! }
  let s = value[0]
  let e = value[1]
  // 양방향 연결이므로 s, e 모두 연결
  arrayList[s].append(e)
  arrayList[e].append(s)
}

// 오름차순으로 정렬
for i in 0...n {
  arrayList[i].sort()
}

func excuteDFS(_ node: Int) {
  // 방문한 노드를 저장할 배열
  var visitedValue = Array(repeating: false, count: n + 1)
  DFS_Recursive(start, &visitedValue)
}

// 재귀 사용한 DFS
func DFS_Recursive(_ node: Int, _ visitedValue: inout [Bool]) {
  visitedValue[node] = true
  sortedDFS.append(node)
  for i in arrayList[node] {
    if !visitedValue[i] {
      DFS_Recursive(i, &visitedValue)
    }
  }
}

func BFS(_ node: Int) {
  var visited = Array(repeating: false, count: n+1)

  var queue = [Int]()
  queue.append(node)

  visited[node] = true

  while !queue.isEmpty {
    let currentNode = queue.removeFirst()
    
    sortedBFS.append(currentNode)
    visited[node] = true

    for i in arrayList[currentNode] {
      if !visited[i] {
        visited[i] = true
        queue.append(i)
      }
    }
  }
}

excuteDFS(start)
BFS(start)

print(sortedDFS.map { String($0) }.joined(separator: " "))
print(sortedBFS.map { String($0) }.joined(separator: " "))