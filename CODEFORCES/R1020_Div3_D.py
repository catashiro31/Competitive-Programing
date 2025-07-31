INF = int(1e9 + 5)

T = int(input())
for _ in range(T):
    N, M = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    # backwards_match[i] lưu vị trí cuối cùng trong a để ghép b[i..M-1]
    backwards_match = [0] * M
    j = N - 1
    for i in range(M - 1, -1, -1):
        while j >= 0 and a[j] < b[i]:
            j -= 1
        backwards_match[i] = j
        j -= 1

    # forwards_match[i] lưu vị trí trong a để ghép b[0..i]
    forwards_match = [0] * M
    j = 0
    for i in range(M):
        while j < N and a[j] < b[i]:
            j += 1
        forwards_match[i] = j
        j += 1

    # Nếu có thể khớp toàn bộ b từ đầu mà không cần xóa gì
    if forwards_match[-1] < N:
        print(0)
        continue

    # Tìm b[i] nhỏ nhất có thể xóa để khớp lại b[0..i-1] và b[i+1..M-1]
    ans = INF
    for i in range(M):
        match_previous = -1 if i == 0 else forwards_match[i - 1]
        match_next = N if i + 1 == M else backwards_match[i + 1]
        if match_next > match_previous:
            ans = min(ans, b[i])

    print(-1 if ans == INF else ans)